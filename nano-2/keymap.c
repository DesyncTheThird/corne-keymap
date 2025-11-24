#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT( DRAG_SCROLL )
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

// bool process_record_user(uint16_t keycode, keyrecord_t* record) {
//     if (keycode == DRAG_SCROLL) {
//         // test code to light up 'A' when drag scroll is active
//         if (record->event.pressed) {
//             register_code(KC_A);
//         } else {
//             unregister_code(KC_A);
//         }
//         return false;
//     }
//     return true;
// }

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
        if (caps_state_expected != host_keyboard_led_state().caps_lock) {
            tap_code(KC_CAPS);
        }
        last_resync = timer_read();
    }


    return mouse_report;
}