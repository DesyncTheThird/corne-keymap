#include QMK_KEYBOARD_H
#include <math.h>

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP,
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD,
    TD_RESET
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

enum {
    NANOKEY,
};

td_state_t cur_dance(tap_dance_state_t *state);

void nanokey_finished(tap_dance_state_t *state, void *user_data);
void nanokey_reset(tap_dance_state_t *state, void *user_data);

td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) {
            return TD_SINGLE_TAP;
        }
        return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) {
            return TD_DOUBLE_SINGLE_TAP;
        } else if (state->pressed) {
            return TD_DOUBLE_HOLD;
        }
        return TD_DOUBLE_TAP;
    }

    if (state->count == 3) {
        if (state->interrupted || !state->pressed) {
            return TD_TRIPLE_TAP;
        }
        return TD_TRIPLE_HOLD;
    }

    if (state->count == 5) {
        return TD_RESET;
    }
    
    return TD_UNKNOWN;
}

static td_tap_t tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void nanokey_finished(tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP: register_code(MS_BTN1); break;
        case TD_SINGLE_HOLD: toggle_drag_scroll(); break;
        case TD_DOUBLE_TAP: tap_code(MS_BTN1); register_code(MS_BTN1); break;
        case TD_DOUBLE_HOLD: tap_code(MS_BTN1); register_code(MS_BTN1); break;
        case TD_DOUBLE_SINGLE_TAP: tap_code(MS_BTN1); register_code(MS_BTN1); break;
        case TD_TRIPLE_TAP: register_code(MS_BTN2); break;
        case TD_TRIPLE_HOLD: register_code(MS_BTN2); break;
        case TD_RESET: reset_keyboard(); break;
        default: break;
    }
}

void nanokey_reset(tap_dance_state_t *state, void *user_data) {
    switch (tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(MS_BTN1); break;
        case TD_SINGLE_HOLD: toggle_drag_scroll(); break;
        case TD_DOUBLE_TAP: unregister_code(MS_BTN1); break;
        case TD_DOUBLE_HOLD: unregister_code(MS_BTN1); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(MS_BTN1); break;
        case TD_TRIPLE_TAP: unregister_code(MS_BTN2); break;
        case TD_TRIPLE_HOLD: unregister_code(MS_BTN2); break;
        case TD_RESET: break;
        default: break;
    }
    tap_state.state = TD_NONE;
}

tap_dance_action_t tap_dance_actions[] = {
    [NANOKEY] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, nanokey_finished, nanokey_reset)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT( TD(NANOKEY) )
};

static bool scroll_lock_now = false;
static bool scroll_lock_last = false;

static bool caps_state_expected = false;

void housekeeping_task_user(void) {
    led_t led_usb_state = host_keyboard_led_state();
    
    scroll_lock_now = led_usb_state.scroll_lock;

    if (scroll_lock_now != scroll_lock_last) {
        toggle_drag_scroll();
    }

    scroll_lock_last = scroll_lock_now;

    if (led_usb_state.caps_lock != caps_state_expected) {
        tap_code(KC_CAPS);
    }
}

#define ACCEL_REGION1_MAX    2.0f
#define ACCEL_REGION2_MAX    7.0f
#define ACCEL_REGION3_MAX   15.0f

#define GAIN_REGION1         1.0f
#define GAIN_REGION2         1.5f
#define GAIN_REGION3         3.0f
#define GAIN_CAP             4.0f

static inline void apply_windows_accel(report_mouse_t *m) {
    int16_t x = m->x;
    int16_t y = m->y;

    if (x == 0 && y == 0) return;

    float dx = (float)x;
    float dy = (float)y;
    float s  = fabsf(dx) + fabsf(dy);

    float gain = GAIN_REGION1;

    if (s <= ACCEL_REGION1_MAX) {
        gain = GAIN_REGION1;

    } else if (s <= ACCEL_REGION2_MAX) {
        float t = (s - ACCEL_REGION1_MAX) /
                  (ACCEL_REGION2_MAX - ACCEL_REGION1_MAX);
        gain = GAIN_REGION1 +
               t * (GAIN_REGION2 - GAIN_REGION1);

    } else if (s <= ACCEL_REGION3_MAX) {
        float t = (s - ACCEL_REGION2_MAX) /
                  (ACCEL_REGION3_MAX - ACCEL_REGION2_MAX);
        gain = GAIN_REGION2 +
               t * (GAIN_REGION3 - GAIN_REGION2);

    } else {
        gain = GAIN_CAP;
    }

    m->x = (int16_t)(dx * gain);
    m->y = (int16_t)(dy * gain);
}

#define MOTION_RISE_DELAY 20
#define MOTION_FALL_DELAY 500

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    static bool moving = false;
    static uint16_t last_nonzero = 0;

    bool raw_moving = (mouse_report.x || mouse_report.y);

    if (raw_moving) {
        last_nonzero = timer_read();
    }

    bool rise = (timer_elapsed(last_nonzero) < MOTION_RISE_DELAY);
    bool fall = (timer_elapsed(last_nonzero) >= MOTION_FALL_DELAY);

    if (!moving && rise) {
        if (!caps_state_expected) {
            tap_code(KC_CAPS);
            caps_state_expected = true;
        }
        moving = true;
    }

    if (moving && fall) {
        if (caps_state_expected) {
            tap_code(KC_CAPS);
            caps_state_expected = false;
        }
        moving = false;
    }

    static uint16_t last_resync = 0;
    if (timer_elapsed(last_resync) > 100) {
        if (raw_moving && !host_keyboard_led_state().caps_lock) {
            tap_code(KC_CAPS);
        }
        last_resync = timer_read();
    }
    
    apply_windows_accel(&mouse_report);

    return mouse_report;
}