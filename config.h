#pragma once

#define SPLIT_USB_DETECT
// #define SPLIT_WATCHDOG_ENABLE

// #define SPLIT_TRANSPORT_MIRROR
// #define SPLIT_MODS_ENABLE
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_OLED_ENABLE
#define SPLIT_WPM_ENABLE

#define SPLIT_TRANSACTION_IDS_USER USER_SYNC_A




#define WPM_SAMPLE_SECONDS 10
#define WPM_SAMPLE_PERIODS 50
#define WPM_LAUNCH_CONTROL


#define LAYER_LOCK_IDLE_TIMEOUT 900000

// #define OLED_SCROLL_TIMEOUT 0
// #define OLED_TIMEOUT 10000
/*
Animations/deferred executions seem to interfere
with last_input_activity_elapsed();
timeout managed manually in keymap instead.
*/

// #define OLED_UPDATE_INTERVAL 25

//#define USE_MATRIX_I2C
#define OLED_DISPLAY_64X128
// #define OLED_COLUMN_OFFSET 1


// #define MASTER_LEFT
#define MASTER_RIGHT
// #define EE_HANDS

//#define QUICK_TAP_TERM 0
//#define TAPPING_TERM 100

#ifdef RGB_MATRIX_ENABLE
    // #define RGB_MATRIX_KEYPRESSES
    // #define RGB_DISABLE_WHEN_USB_SUSPENDED
    // #define RGB_MATRIX_FRAMEBUFFER_EFFECTS
    #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 120
    #define RGB_MATRIX_HUE_STEP 8
    #define RGB_MATRIX_SAT_STEP 8
    #define RGB_MATRIX_VAL_STEP 8
    #define RGB_MATRIX_SPD_STEP 10

    // #define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_REACTIVE
    #define RGB_MATRIX_TIMEOUT 900000
    #define RGB_MATRIX_SLEEP
    
    #define ENABLE_RGB_MATRIX_BAND_VAL
    #define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
    #define ENABLE_RGB_MATRIX_RIVERFLOW
    #define ENABLE_RGB_MATRIX_TYPING_HEATMAP
    #define ENABLE_RGB_MATRIX_MULTISPLASH
    
    #define RGB_MATRIX_SOLID_REACTIVE_GRADIENT_MODE
#endif



#undef TAPPING_TOGGLE
#define TAPPING_TOGGLE 2

#undef ONESHOT_TAP_TOGGLE
#define ONESHOT_TAP_TOGGLE 3
#undef ONESHOT_TIMEOUT
#define ONESHOT_TIMEOUT 1000
// #define NO_ACTION_ONESHOT

//#define COMBO_TERM 20
#define COMBO_TERM_PER_COMBO
#define COMBO_SHOULD_TRIGGER
#define COMBO_ONLY_FROM_LAYER 0
#define COMBO_MUST_TAP_PER_COMBO
// #define COMBO_MUST_HOLD_PER_COMBO
// #define EXTRA_SHORT_COMBOS // Saves space, but only 6 keys per combo

#define COMBO_TERM_PER_COMBO
// #define COMBO_MUST_PRESS_IN_ORDER_PER_COMBO


// Timer for mod and layer taps
#undef TAPPING_TERM
#define TAPPING_TERM 150
#define TAPPING_TERM_PER_KEY

#define FLOW_TAP_TERM 100

// Perform hold action if other keys are pressed (nested/rolled activations).
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

// Perform hold action if other keys are pressed (nested only).
#define PERMISSIVE_HOLD_PER_KEY

#define CHORDAL_HOLD

// Disable repeating tap function on tap-hold keys.
// #define QUICK_TAP_TERM 0
#define QUICK_TAP_TERM_PER_KEY

// N-key rollover
#define NKRO_DEFAULT_ON true

// Auto Shift
// #define NO_AUTO_SHIFT_ALPHA
// #define NO_AUTO_SHIFT_NUMERIC
// #define NO_AUTO_SHIFT_SPECIAL
// #define AUTO_SHIFT_TIMEOUT TAPPING_TERM
// #define AUTO_SHIFT_NO_SETUP

// Auto Shift for modtaps
// #define RETRO_SHIFT 500 

// Mouse key speed and acceleration.
#define MK_COMBINED

#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY             0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL          8
#undef MOUSEKEY_MOVE_DELTA
#define MOUSEKEY_MOVE_DELTA        1
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED         32
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX       60
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY       0
#undef MOUSEKEY_WHEEL_INTERVAL
#define MOUSEKEY_WHEEL_INTERVAL    80
#undef MOUSEKEY_WHEEL_MAX_SPEED
#define MOUSEKEY_WHEEL_MAX_SPEED   8
#undef MOUSEKEY_WHEEL_TIME_TO_MAX
#define MOUSEKEY_WHEEL_TIME_TO_MAX 40



#define OLED_FONT_H "keyboards/crkbd/keymaps/desync/font.c"

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

// #define NO_ACTION_ONESHOT
#define NO_MUSIC_MODE
#define NO_ALT_REPEAT_KEY

// #define LAYER_STATE_8BIT
#define LAYER_STATE_16BIT



// #define PS2_CLOCK_PIN B5
// #define PS2_DATA_PIN  B4
// #define PS2_PIO_USE_PIO1
// #define PS2_MOUSE_ROTATE 90
// #define PS2_MOUSE_SCROLL_BTN_MASK 0

// #define PS2_MOUSE_DEBUG_RAW
// #define PS2_MOUSE_DEBUG_HID

// #define MH_AUTO_BUTTONS_LAYER _MOUSE_BTN
// #define MH_AUTO_BUTTONS_TIMEOUT 750