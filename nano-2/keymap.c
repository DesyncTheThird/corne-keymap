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

/**

Send:
A - layer on
B - layer off

Receive:
S - toggle scroll
V - toggle volume
T - toggle on/off

*/

static bool auto_layering = true;
static bool volume_mode = false;

void raw_hid_receive(uint8_t *data, uint8_t length) {
    uint8_t response[length];
    memset(response, 0, length);

    dprintf("Trackball - Received HID data: %c\n", data[0]);
    
    switch (data[0]) {
        case 'S':
            toggle_drag_scroll();
            break;
        case 'V':
            volume_mode = !volume_mode;
            break;
        case 'T':
            auto_layering = !auto_layering;
            break;
        default:
            dprintf("Unknown HID command: %c\n", data[0]);
            break;
    }
}

void volume_control(report_mouse_t mouse_report) {
    return;
    // WIP
}

#define RAW_LENGTH 32

#define MOTION_RISE_DELAY 20
#define MOTION_FALL_DELAY 500

void auto_layer(report_mouse_t mouse_report) {
    static bool was_moving = false;
    static uint32_t last_change = 0;

    bool is_moving = (mouse_report.x != 0 || mouse_report.y != 0);
    uint16_t delay = is_moving ? MOTION_RISE_DELAY : MOTION_FALL_DELAY;

    if (is_moving != was_moving) {
        if (timer_elapsed(last_change) >= delay) {
            uint8_t msg[RAW_LENGTH] = {0};
            memset(msg, 0, RAW_LENGTH);
            msg[0] = is_moving ? 'A' : 'B';
            raw_hid_send(msg, RAW_LENGTH);

            was_moving = is_moving;
            last_change = timer_read();
        }
    } else {
        last_change = timer_read();
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