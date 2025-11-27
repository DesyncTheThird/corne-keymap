#include QMK_KEYBOARD_H
#include <math.h>
#include <raw_hid.h>

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
    TD_RESET,
    TD_BOOT
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

enum {
    NANOKEY,
};

static bool auto_layering = true;
static bool volume_mode = false;

static void reset_state(void) {
    auto_layering = true;
    volume_mode = false;
}

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

    if (state->count == 4) {
        return TD_RESET;
    }

    if (state->count >= 6) {
        return TD_BOOT;
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
        case TD_RESET: reset_state(); break;
        case TD_BOOT: reset_keyboard(); break;
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
        case TD_BOOT: break;
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

void raw_hid_receive(uint8_t *data, uint8_t length) {
    uint8_t response[length];
    memset(response, 0, length);

    dprintf("Trackball - Received HID data: %c\n", data[0]);
    
    switch (data[0]) {
        case 'S':
            toggle_drag_scroll();
            break;
        case 'V':
            volume_mode = true;
            break;
        case 'v':
            volume_mode = false;
            break;
        case 'T':
            auto_layering = !auto_layering;
            break;
        default:
            dprintf("Unknown HID command: %c\n", data[0]);
            break;
    }
}

#define VOL_STEP            40
#define VOL_REPEAT_DELAY    80

void volume_control(report_mouse_t mouse_report) {
    static int32_t accumulator = 0;
    static uint16_t last_event = 0;

    int16_t dy = mouse_report.y;

    accumulator += dy;

    if (timer_elapsed(last_event) < VOL_REPEAT_DELAY)
        return;

    while (accumulator >= VOL_STEP) {
        tap_code(KC_VOLD);
        accumulator -= VOL_STEP;
        last_event = timer_read();
    }

    while (accumulator <= -VOL_STEP) {
        tap_code(KC_VOLU);
        accumulator += VOL_STEP;
        last_event = timer_read();
    }
}

#define RAW_LENGTH 32

#define MOTION_TIMEOUT 20

void auto_layer(report_mouse_t mouse_report) {
    static bool moving = false;
    static uint32_t last_motion_time = 0;

    bool instant_motion = (mouse_report.x || mouse_report.y);
    uint32_t now = timer_read();

    if (instant_motion) {
        last_motion_time = now;
        if (!moving) {
            uint8_t msg[RAW_LENGTH] = {0};
            msg[0] = 'A';
            raw_hid_send(msg, RAW_LENGTH);
            moving = true;
        }
        return;
    }

    if (moving && timer_elapsed(last_motion_time) >= MOTION_TIMEOUT) {
        uint8_t msg[RAW_LENGTH] = {0};
        msg[0] = 'B';
        raw_hid_send(msg, RAW_LENGTH);
        moving = false;
    }
}

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (volume_mode) {
        volume_control(mouse_report);

        mouse_report.x = 0;
        mouse_report.y = 0;
        mouse_report.h = 0;
        mouse_report.v = 0;

        return mouse_report;
    }

    if (!auto_layering) {
        return mouse_report;
    }

    auto_layer(mouse_report);

    return mouse_report;
}