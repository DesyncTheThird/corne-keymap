#include QMK_KEYBOARD_H

// #include "ps2_mouse.h"
// #include "ps2.h"

enum corne_layers {
    _QWERTY,
    _BASE,
    _BASIC,
    _STENO,
    _DATA,
    _PROGRAM,
    _SYMBOL,
    _EDIT,
    _MOUSE,
    _MOUSE_BTN,
    _NUMPAD,
    _UTILITY,
    _TOUHOU,
};


enum custom_keycodes {
    SELECT = SAFE_RANGE,

    REP,
    MAGIC,

    CS_COLN,
    CS_UNDS,
    CS_PIPE,
    CS_LT,
    CS_GT,
    CS_PERC,
    CS_ASTR,
    CS_DLR,
    CS_AMPR,
    CS_CIRC,
    CS_EXLM,
    CS_TILD,
    CS_PLUS,
    CS_HASH,
    CS_SLSH,
    CS_EQL,

    CS_AT,
    CS_DQUO,
    CS_POUN,
    CS_BSLS,
    
    CS_MINS,
    CS_DOT,
    CS_COMM,
    CS_QUES,
    CS_SCLN,
    
    COM_DOT,
    QUE_EXL,

    CS_END,
    CS_HOME,
    CS_TAB,

    BASIC,
    BASE,
    MENU,
    
    ALTTAB,
    CS_BOOT,

    MUTE,
    CS_VOLD,
    CS_VOLU,

    CS_VALU,
    CS_VALD,
    CS_RGBN,
    CS_RGBT,
    
    // Home block mods
    CS_RBRC,
    CS_RPRN,
    CS_LPRN,

    CLOCKUP,
    CLOCKDN,
    CLOCKNX,
    OLEDSAV,

    CM_MOUSE,

    CM_CIRC,
    CM_COMM,
    CM_DOT,
    CM_UNDS,
    CM_ASTR,
    CM_EQL,
    CM_PLUS,
    CM_MINS,
    
    CM_AMPR,
    CM_EXLM,
    
    CM_COLN,
    CM_SCLN,
};



// Home block mods
#define MT_S LGUI_T(KC_S)
#define MT_D LALT_T(KC_D)
#define MT_F LSFT_T(KC_F)
#define MT_C LCTL_T(KC_C)

#define MT_N RCTL_T(KC_N)
#define MT_J RSFT_T(KC_J)
#define MT_K LALT_T(KC_K)
#define MT_L RGUI_T(KC_L)

// Alt layout home block mods
#define MTA_R LGUI_T(KC_R)
#define MTA_T LALT_T(KC_T)
#define MTA_S LSFT_T(KC_S)
#define MTA_W LCTL_T(KC_W)

#define MTA_P RCTL_T(KC_P)
#define MTA_H RSFT_T(KC_H)
#define MTA_E LALT_T(KC_E)
#define MTA_I RGUI_T(KC_I)


// Symbol home block mods

#define MT_RBRC LT(0,CS_RBRC)
#define MT_RPRN LT(0,CS_RPRN)
#define MT_LPRN LT(0,CS_LPRN)
#define MT_UNDS LT(0,CS_UNDS)

#define MT_PLUS LT(0,CS_PLUS)
#define MT_MINS LT(0,CS_MINS)
#define MT_EQL  LT(0,CS_EQL)
#define MT_COMM LT(0,CS_COMM)



// Layer keys
#define CS_LT3 LT(_UTILITY,KC_ENT)
#define CS_LT2 LT(_EDIT,MAGIC)
#define CS_LT1 LT(_DATA,KC_SPC)

#define CS_RT1 LT(_SYMBOL,KC_BSPC)
#define CS_RT2 LT(_PROGRAM,REP)
#define CS_RT3 LT(_UTILITY,KC_SLSH)

#define CS_AL1 LT(_EDIT,KC_0)
#define CS_AL2 LT(_EDIT,CS_BSLS)
#define CS_AL3 LT(_EDIT,CS_SCLN)

// #define UNDO LCTL(KC_Z)
// #define REDO LCTL(KC_Y)
// #define CUT LCTL(KC_X)
// #define COPY LCTL(KC_C)
// #define PASTE LCTL(KC_V)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT( //0
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
           KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, CS_HASH,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          KC_LSFT,    KC_A,    MT_S,    MT_D,    MT_F,    KC_G,                         KC_H,    MT_J,    MT_K,    MT_L, KC_SCLN,  KC_TAB,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          KC_LCTL, CS_BSLS,    KC_Z,    KC_X,    MT_C,    KC_V,                         KC_B,    MT_N,    KC_M, COM_DOT, QUE_EXL, KC_QUOT,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                               CS_LT3,  CS_LT2,  CS_LT1,     CS_RT1,  CS_RT2,  CS_RT3
                                          //`--------------------------'  `--------------------------'
    ),

    [_BASE] = LAYOUT( //1
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
           KC_ESC,    KC_X,    KC_L,    KC_D,    KC_C,    KC_V,                         KC_J,    KC_F,    KC_O,    KC_U, KC_SCLN, CS_HASH,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          KC_LSFT,    KC_N,   MTA_R,   MTA_T,   MTA_S,    KC_G,                         KC_Y,   MTA_H,   MTA_E,   MTA_I,    KC_A,  KC_TAB,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          KC_LCTL,    KC_Z,    KC_Q,    KC_M,   MTA_W,    KC_B,                         KC_K,   MTA_P, KC_MINS, COM_DOT, QUE_EXL, KC_QUOT,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                               CS_LT3,  CS_LT2,  CS_LT1,     CS_RT1,  CS_RT2,  CS_RT3
                                          //`--------------------------'  `--------------------------'
    ),

    [_BASIC] = LAYOUT( //2
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
           KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, CS_HASH,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_TAB,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          KC_LCTL, CS_BSLS,    KC_Z,    KC_X,    KC_C,    KC_V,                         KC_B,    KC_N,    KC_M, COM_DOT, QUE_EXL, KC_QUOT,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              _______, _______,  KC_SPC,    _______, _______, _______
                                          //`--------------------------'  `--------------------------'
    ),

    [_STENO] = LAYOUT( //3
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
           KC_ESC,  STN_S1,  STN_TL,  STN_PL,  STN_HL, STN_ST1,                      STN_ST3,  STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          KC_LSFT,  STN_S2,  STN_KL,  STN_WL,  STN_RL, STN_ST2,                      STN_ST4,  STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          KC_LCTL,  STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,                       STN_N6,  STN_N7,  STN_N8,  STN_N9,  STN_NA,  KC_ENT,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                               STN_FN,   STN_A,   STN_O,      STN_E,   STN_U, STN_PWR
                                          //`--------------------------'  `--------------------------'
    ),

    [_DATA] = LAYOUT( //4
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
           KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       CS_EQL,    KC_7,    KC_8,    KC_9, CS_SCLN,  KC_DEL,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          KC_LSFT, CS_CIRC, MT_PLUS, MT_MINS,  MT_EQL, CS_PIPE,                        CS_LT,    KC_1,    KC_2,    KC_3, CS_EXLM,  KC_TAB,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          KC_LCTL, CS_TILD, CS_ASTR,  CS_DOT, MT_COMM, CS_POUN,                        CS_GT,    KC_4,    KC_5,    KC_6, CS_QUES,  KC_ENT,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              _______, _______, _______,    KC_BSPC,  CS_AL1, CS_SLSH
                                          //`--------------------------'  `--------------------------'
    ),

    [_SYMBOL] = LAYOUT( //6
      //,-----------------------------------------------------.                    ,---------------------------------------------------.
           KC_GRV, CS_PERC, CS_ASTR, CS_SLSH, CS_AMPR, CS_CIRC,                       CS_EQL, KC_RCBR, KC_LCBR, CS_CIRC, CS_SCLN,  KC_DEL,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          KC_LSFT, CS_PIPE,   CS_LT, CS_MINS,   CS_GT,  CS_EQL,                        CS_LT, KC_RPRN, KC_LPRN, CS_UNDS, CS_EXLM,  KC_TAB,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          KC_LCTL, CS_TILD, CS_COLN,  CS_DOT, CS_COMM,  CS_DLR,                        CS_GT, KC_RBRC, KC_LBRC, CS_TILD, CS_QUES,  KC_ENT,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              CS_UNDS,  CS_AL2,  KC_SPC,    _______, _______, _______
                                          //`--------------------------'  `--------------------------'
    ),

    [_PROGRAM] = LAYOUT( //7
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
           KC_GRV, CS_PERC, CS_EXLM, CS_DQUO,  CS_DLR, CS_COLN,                       CS_EQL, KC_RCBR, KC_LCBR, CS_CIRC, CS_SCLN,  KC_DEL,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          KC_LSFT, CS_CIRC, CS_PLUS, CS_MINS,  CS_EQL, CS_PIPE,                        CS_LT, KC_RPRN, KC_LPRN, CS_UNDS, CS_EXLM,  KC_TAB,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          KC_LCTL, CS_TILD, CS_ASTR, CS_SLSH, CS_HASH, CS_AMPR,                        CS_GT, KC_RBRC, KC_LBRC, CS_TILD, CS_QUES,  KC_ENT,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              CS_UNDS,  CS_AL3,  KC_SPC,    _______, _______, _______
                                          //`--------------------------'  `--------------------------'
    ),
    
    [_EDIT] = LAYOUT( //5
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
           KC_ESC, KC_PAUS, CS_HOME,   KC_UP,  CS_END,  KC_ENT,                       CS_EQL, KC_RCBR, KC_LCBR, CS_CIRC, CS_SCLN,  KC_DEL,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          KC_LSFT,  KC_INS, KC_LEFT, KC_DOWN, KC_RGHT,  KC_DEL,                        CS_LT, MT_RPRN, MT_LPRN, MT_UNDS, CS_EXLM,  KC_TAB,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          KC_LCTL,  KC_TAB, KC_PGUP, KC_PGDN, KC_CAPS,  SELECT,                        CS_GT, MT_RBRC, KC_LBRC, CS_TILD, CS_QUES,  KC_ENT,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              _______, _______, _______,    _______,    KC_0,  KC_SPC
                                          //`--------------------------'  `--------------------------'
    ),

    [_MOUSE] = LAYOUT( //8
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
           KC_ESC, XXXXXXX, KC_BTN4, KC_MS_U, KC_BTN5,  KC_TAB,                      _______, _______, _______, _______, _______, _______,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          KC_LSFT, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R,  KC_DEL,                      _______, _______, _______, _______, _______, _______,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          KC_LCTL, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R,  SELECT,                      _______, _______, _______, _______, _______, _______,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              KC_BTN3, KC_BTN2, KC_BTN1,    KC_ACL0, KC_ACL1, KC_ACL2
                                          //`--------------------------'  `--------------------------'
    ),

    [_MOUSE_BTN] = LAYOUT( //9
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
          _______, _______, KC_BTN4, _______, KC_BTN5,  KC_TAB,                      _______, _______, _______, _______, _______, _______,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          _______, _______, _______, _______, _______,  KC_DEL,                      _______, _______, _______, _______, _______, _______,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          _______, _______, _______, _______, _______,  SELECT,                      _______, _______, _______, _______, _______, _______,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              KC_BTN3, KC_BTN2, KC_BTN1,    _______, _______, _______
                                          //`--------------------------'  `--------------------------'
    ),

    [_NUMPAD] = LAYOUT( //10
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
          _______, _______, _______, _______, _______, _______,                       KC_NUM,   KC_P7,   KC_P8,   KC_P9, KC_CIRC,  KC_DEL,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          _______, _______, _______, _______, _______, _______,                      KC_PLUS,   KC_P4,   KC_P5,   KC_P6, KC_ASTR,  KC_TAB,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          _______, _______, _______, _______, _______, _______,                      KC_MINS,   KC_P1,   KC_P2,   KC_P3, KC_UNDS,  KC_ENT,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              _______, _______, _______,    _______,   KC_P0, _______
                                          //`--------------------------'  `--------------------------'
    ),
    
    [_UTILITY] = LAYOUT( //11
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
           ALTTAB, CLOCKUP, CS_VALD, CS_VOLU, CS_VALU, CS_RGBN,                      CS_BOOT,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_DEL,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          KC_LSFT, CLOCKDN, KC_MPRV, CS_VOLD, KC_MNXT, KC_PSCR,                        BASIC,   KC_F1,   KC_F2,   KC_F3,  KC_F11,  KC_TAB,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          KC_LCTL, CLOCKNX, OLEDSAV,    MUTE, KC_SCRL, CS_RGBT,                         BASE,   KC_F4,   KC_F5,   KC_F6,  KC_F12,  KC_ENT,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              KC_MSTP,    MUTE, KC_MPLY,    KC_MPLY,    MENU, KC_MSTP
                                          //`--------------------------'  `--------------------------'
    ),

    [_TOUHOU] = LAYOUT( //12
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
          _______, _______, _______,   KC_UP, _______, _______,                      _______, _______, _______, _______, _______,  KC_DEL,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______,                      _______,    KC_Z,    KC_X, _______, _______,  KC_TAB,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______,  KC_ENT,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              _______, _______, _______,    _______, _______, _______
                                          //`--------------------------'  `--------------------------'
    ),
};

#include "features/achordion.h"

//==============================================================================
// Variables
//==============================================================================

static uint8_t time_setting = 0;
static uint8_t min = 0;
static uint8_t hrs = 0;
static uint8_t sec = 0;

// static uint8_t t_min = 0;
// static uint8_t t_hrs = 0;
// static uint8_t t_sec = 0;

static uint8_t menu = 0;

static bool static_display = false;

static bool muted = false;

static uint8_t set_rgb_mode = 5;


bool no_ctrl(void) {
    return !((get_mods() & MOD_BIT(KC_LCTL)) == MOD_BIT(KC_LCTL) || (get_mods() & MOD_BIT(KC_RCTL)) == MOD_BIT(KC_RCTL));
}

bool shifted(void) {
    return ((get_mods() & MOD_BIT(KC_LSFT)) == MOD_BIT(KC_LSFT));
}

//==============================================================================
// Trackpoint
//==============================================================================

// static uint8_t trackpoint_sensitivity = 90;

// void trackpoint_set_sensitivity(uint8_t sensitivity) {
//     PS2_MOUSE_SEND(0xE2, "trackpoint_set_sensitivity: 0xE2");
//     PS2_MOUSE_SEND(0x81, "trackpoint_set_sensitivity: 0x81");
//     PS2_MOUSE_SEND(0x4A, "trackpoint_set_sensitivity: 0x4A");
//     PS2_MOUSE_SEND(sensitivity, "trackpoint_set_sensitivity: xxx");
// }

// void trackpoint_reset(void) {
//     PS2_MOUSE_SEND(0xE2, "trackpoint_reset: 0xE2");
//     PS2_MOUSE_SEND(0x51, "trackpoint_reset: 0x51");
// }

// void ps2_mouse_init_user() {
//     // set TrackPoint sensitivity
//     trackpoint_set_sensitivity(trackpoint_sensitivity);
// }

// void ps2_regdump(void) {
//     println("Register dump:");
//     print("     ");
//     for (uint8_t addr = 0; addr <= 0xF; addr++) {
//         print_hex8(addr);
//         print(" ");
//     }
//     println("");
//     for (uint16_t addr = 0; addr <= 0xFF; addr++) {
//         uint8_t data;
//         if ((addr & 0xf) == 0) {
//             print_hex8(addr);
//             print(" | ");
//         }

//         ps2_host_send(0xE2);
//         ps2_host_send(0x80);
//         data = ps2_host_send((uint8_t)addr);
//         if (data == 0xFA) {
//             data = ps2_host_recv_response();
//             print_hex8(data);
//             print(" ");
//         } else {
//             print("xx ");
//         }
//         if ((addr & 0xf) == 0xf) {
//             println("");
//         }
//     }
//     println("");
// }

// static uint16_t mh_auto_buttons_timer;
// extern int tp_buttons; // mousekey button state set in action.c and used in ps2_mouse.c

// void ps2_mouse_moved_user(report_mouse_t *mouse_report) {
//     if (abs(mouse_report->x) <= 1 && abs(mouse_report->y) <= 1) {
//         // Ignore tiny mouse events
//         return;
//     }
//     if (mh_auto_buttons_timer) {
//         mh_auto_buttons_timer = timer_read();
//     } else {
//         if (!tp_buttons) {
//             layer_on(MH_AUTO_BUTTONS_LAYER);
//             mh_auto_buttons_timer = timer_read();
// #if defined CONSOLE_ENABLE
//             print("mh_auto_buttons: on\n");
// #endif
//         }
//     }
// }


//==============================================================================
// Timers
//==============================================================================

#define IDLE_TIMEOUT 10000

static bool alt_tab_active = false;
static bool oled_timeout = false;

void matrix_scan_user(void) {
    achordion_task();

    // if (mh_auto_buttons_timer && (timer_elapsed(mh_auto_buttons_timer) > MH_AUTO_BUTTONS_TIMEOUT)) {
    //     if (!tp_buttons) {
    //         layer_off(MH_AUTO_BUTTONS_LAYER);
    //         mh_auto_buttons_timer = 0;
    //     }
    // }

    if (get_highest_layer(layer_state) == _NUMPAD) {
        if (last_input_activity_elapsed() > IDLE_TIMEOUT) {
            layer_off(_NUMPAD);
        }
    }
    if (get_highest_layer(layer_state) == _TOUHOU) {
        if (last_input_activity_elapsed() > 900000) { //15 minute time out
            layer_off(_TOUHOU);
        }
    }
    if (alt_tab_active) {
        if (IS_LAYER_OFF(_UTILITY)) {
            unregister_code(KC_LALT);
            alt_tab_active = false;
        }
    }
    if (last_input_activity_elapsed() > 15000) {
        time_setting = 0;
        oled_timeout = true;
    }
    else {
        oled_timeout = false;
    }
}

//==============================================================================
// Tap/hold
//==============================================================================

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CS_LT3:
        case CS_LT2:
        case CS_LT1:

        case CS_RT1:
        case CS_RT2:
        case CS_RT3:
        
        case CS_AL1:
        case CS_AL2:
        case CS_AL3:
        
        case MT_S:
        case MT_D:
        case MT_F:
        case MT_C:
        case MT_N:
        case MT_J:
        case MT_K:
        case MT_L:

        case MTA_R:
        case MTA_T:
        case MTA_S:
        case MTA_W:
        case MTA_P:
        case MTA_H:
        case MTA_E:
        case MTA_I:

        case MT_RBRC:
        case MT_RPRN:
        case MT_LPRN:
        case MT_UNDS:

        case MT_PLUS:
        case MT_MINS:
        case MT_EQL:
        case MT_COMM:
            return 0;
        default:
            return TAPPING_TERM;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CS_LT3:
        case CS_LT2:
        case CS_LT1:
        case CS_RT1:
        case CS_RT2:
        case CS_RT3:
            return 150;
        default:
            return TAPPING_TERM;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CS_LT3:
        case CS_LT2:

        case CS_RT1:
        case CS_RT3:
 
        case CS_AL1:
        case CS_AL2:
        case CS_AL3:
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}


uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
    switch (tap_hold_keycode) {
        case CS_LT3:
        case CS_LT2:
        case CS_LT1:

        case CS_RT1:
        // case CS_RT2:
        case CS_RT3:

        case CS_AL1:
        case CS_AL2:
        case CS_AL3:
            return 0;

        default:
            return TAPPING_TERM;
    }
}

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
                     uint16_t other_keycode, keyrecord_t* other_record) {
    switch (tap_hold_keycode) {
        case MT_S:
        case MT_D:
        case MT_F:
        case MT_C:
        case MT_N:
        case MT_J:
        case MT_K:
        case MT_L:
        case MTA_R:
        case MTA_T:
        case MTA_S:
        case MTA_W:
        case MTA_P:
        case MTA_H:
        case MTA_E:
        case MTA_I:
        case CS_RT2:
            return achordion_opposite_hands(tap_hold_record, other_record);
        default:
            return true;
    }
}



bool process_cs_layer_tap(uint16_t keycode, keyrecord_t* record) {
    if (keycode == CS_AL2) {
        if (!record->tap.count && record->event.pressed) {
            layer_on(_EDIT);
        } else {
            layer_off(_EDIT);
        }
        if (record->tap.count && record->event.pressed) {
            const uint8_t mods = get_mods();
            del_mods(MOD_MASK_SHIFT);
            tap_code16(KC_NUBS);
            set_mods(mods);
        }
        return false;
    }
    if (keycode == CS_AL3) {
        if (!record->tap.count && record->event.pressed) {
            layer_on(_EDIT);
        } else {
            layer_off(_EDIT);
        }
        if (record->tap.count && record->event.pressed) {
            const uint8_t mods = get_mods();
            del_mods(MOD_MASK_SHIFT);
            tap_code16(KC_SCLN);
            set_mods(mods);
        }
        return false;
    }
    return true;
}
//==============================================================================
// Modifier+key overrides
//==============================================================================

// const key_override_t redo = ko_make_basic(MOD_MASK_CS, KC_Z, C(KC_Y));

const key_override_t undo    = ko_make_with_layers(MOD_MASK_CTRL, KC_Q, C(KC_Z), (1 << _BASE));
const key_override_t redo    = ko_make_with_layers(MOD_MASK_CTRL, KC_Z, C(KC_Y), (1 << _BASE));
const key_override_t cut     = ko_make_with_layers(MOD_MASK_CTRL, KC_M, C(KC_X), (1 << _BASE));
const key_override_t copy    = ko_make_with_layers(MOD_MASK_CTRL, MTA_W, C(KC_C), (1 << _BASE));
const key_override_t paste   = ko_make_with_layers(MOD_MASK_CTRL, KC_B, C(KC_V), (1 << _BASE));
const key_override_t find    = ko_make_with_layers(MOD_MASK_CTRL, MTA_S, C(KC_F), (1 << _BASE));
const key_override_t save    = ko_make_with_layers(MOD_MASK_CTRL, MTA_T, C(KC_S), (1 << _BASE));
const key_override_t all     = ko_make_with_layers(MOD_MASK_CTRL, MTA_R, C(KC_A), (1 << _BASE));
const key_override_t close   = ko_make_with_layers(MOD_MASK_CTRL, KC_D, C(KC_W), (1 << _BASE));
const key_override_t tab     = ko_make_with_layers(MOD_MASK_CTRL, KC_V, C(KC_T), (1 << _BASE));
const key_override_t window  = ko_make_with_layers(MOD_MASK_CTRL, KC_G, C(KC_N), (1 << _BASE));
const key_override_t refresh = ko_make_with_layers(MOD_MASK_CTRL, KC_C, C(KC_R), (1 << _BASE));

const key_override_t **key_overrides = (const key_override_t *[]){
    &undo,
    &redo,
    &cut,
    &copy,
    &paste,
    &find,
    &save,
    &all,
    &close,
    &tab,
    &window,
    &refresh,
    NULL
};

//==============================================================================
// Combos
//==============================================================================

enum combo_events {
    TOUHOU,
    STENO,
    MOUSE,
    MOUSE2,
    NUMPAD,

    L_EXPONENT,
    L_COMMA,
    L_DOT,
    L_UNDERSCORE,
    L_ASTERISK,
    L_PLUS,
    L_EQUALS,
    L_MINUS,

    EXCLAMATION,
    COLON,

    R_EXPONENT,
    R_COMMA,
    R_DOT,
    R_UNDERSCORE,
    R_ASTERISK,
    R_PLUS,
    R_EQUALS,
    R_MINUS,

    SEMICOLON,
    AMPERSAND,

    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM touhou[]         = {KC_P, CS_HASH, KC_ESC, COMBO_END};
const uint16_t PROGMEM steno[]          = {KC_P, CS_HASH, KC_SCLN, KC_TAB, COMBO_END};
const uint16_t PROGMEM numpad[]         = {KC_O, KC_P, CS_HASH, COMBO_END};
const uint16_t PROGMEM mouse[]          = {KC_SCLN, QUE_EXL, COMBO_END};
const uint16_t PROGMEM mouse2[]         = {KC_TAB, KC_QUOT, COMBO_END};

const uint16_t PROGMEM l_exponent[]     = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM l_comma[]        = {MT_D, MT_C, COMBO_END};
const uint16_t PROGMEM l_dot[]          = {MT_S, MT_D, COMBO_END};
const uint16_t PROGMEM l_underscore[]   = {KC_X, MT_C, COMBO_END};
const uint16_t PROGMEM l_asterisk[]     = {MT_F, KC_V, COMBO_END};
const uint16_t PROGMEM l_equals[]       = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM l_plus[]         = {MT_D, MT_F, COMBO_END};
const uint16_t PROGMEM l_minus[]        = {MT_F, KC_G, COMBO_END};

const uint16_t PROGMEM exclamation[]    = {MT_S, KC_E, COMBO_END};
const uint16_t PROGMEM colon[]          = {KC_E, MT_F, COMBO_END};

const uint16_t PROGMEM r_exponent[]     = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM r_comma[]        = {MT_N, MT_K, COMBO_END};
const uint16_t PROGMEM r_dot[]          = {MT_K, MT_L, COMBO_END};
const uint16_t PROGMEM r_underscore[]   = {MT_N, KC_M, COMBO_END};
const uint16_t PROGMEM r_asterisk[]     = {KC_B, MT_J, COMBO_END};
const uint16_t PROGMEM r_equals[]       = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM r_plus[]         = {MT_J, MT_K, COMBO_END};
const uint16_t PROGMEM r_minus[]        = {KC_H, MT_J, COMBO_END};

const uint16_t PROGMEM semicolon[]      = {MT_J, KC_I, COMBO_END};
const uint16_t PROGMEM ampersand[]      = {KC_I, MT_L, COMBO_END};

combo_t key_combos[] = {
    [TOUHOU]        = COMBO_ACTION(touhou),
    [STENO]         = COMBO_ACTION(steno),
    [NUMPAD]        = COMBO_ACTION(numpad),

    [MOUSE]         = COMBO(mouse,         CM_MOUSE),
    [MOUSE2]        = COMBO(mouse2,        CM_MOUSE),
    
    [L_EXPONENT]    = COMBO(l_exponent,    CM_CIRC),
    [L_COMMA]       = COMBO(l_comma,       CM_COMM),
    [L_DOT]         = COMBO(l_dot,         CM_DOT),
    [L_UNDERSCORE]  = COMBO(l_underscore,  CM_UNDS),
    [L_ASTERISK]    = COMBO(l_asterisk,    CM_ASTR),
    [L_EQUALS]      = COMBO(l_equals,      CM_EQL),
    [L_PLUS]        = COMBO(l_plus,        CM_PLUS),
    [L_MINUS]       = COMBO(l_minus,       CM_MINS),
    
    [EXCLAMATION]   = COMBO(exclamation,   CM_EXLM),
    [COLON]         = COMBO(colon,         CM_COLN),
    
    [R_EXPONENT]    = COMBO(r_exponent,    CM_CIRC),
    [R_COMMA]       = COMBO(r_comma,       CM_COMM),
    [R_DOT]         = COMBO(r_dot,         CM_DOT),
    [R_UNDERSCORE]  = COMBO(r_underscore,  CM_UNDS),
    [R_ASTERISK]    = COMBO(r_asterisk,    CM_ASTR),
    [R_EQUALS]      = COMBO(r_equals,      CM_EQL),
    [R_PLUS]        = COMBO(r_plus,        CM_PLUS),
    [R_MINUS]       = COMBO(r_minus,       CM_MINS),

    [SEMICOLON]     = COMBO(semicolon,     CM_SCLN),
    [AMPERSAND]     = COMBO(ampersand,     CM_AMPR),


};


void process_combo_event(uint16_t combo_index, bool pressed) {
    switch(combo_index) {
        case TOUHOU:
            if (pressed) {
                if (IS_LAYER_ON(_TOUHOU)) {
                    layer_off(_TOUHOU);
                }
                else {
                    layer_on(_TOUHOU);
                }
            }
            break;
        case NUMPAD:
            if (pressed) {
                if (IS_LAYER_ON(_NUMPAD)) {
                    layer_off(_NUMPAD);
                }
                else {
                    layer_on(_NUMPAD);
                }
            }
            break;
        case STENO:
            if (pressed) {
                if (IS_LAYER_ON(_STENO)) {
                    layer_off(_STENO);
                }
                else {
                    layer_on(_STENO);
                }
            }
            break;
    }
}

// 50ms default
uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    switch (index) {
        case L_UNDERSCORE:
        case R_UNDERSCORE:
            return 50;
            break;
        case MOUSE:
        case MOUSE2:
            return 75;
        default:
            return 30;
    }
}

bool get_combo_must_tap(uint16_t index, combo_t *combo) {
    switch (index) {
        case MOUSE:
        case MOUSE2:
            return false;
        default:
            return true;

    }
}

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    switch (combo_index) {
        case TOUHOU:
        case MOUSE:
        case MOUSE2:
        case STENO:
        case NUMPAD:
            return true;
        default:
            if (!(layer_state_is(_BASIC) || layer_state_is(_TOUHOU) || layer_state_is(_MOUSE) || layer_state_is(_STENO))) {
                return true;
            }
    }
    return false;
}



//==============================================================================
// Repeat and Magic key
//==============================================================================

uint16_t last_key = KC_NO;
uint16_t repeat_key = KC_NO;

bool process_cs_repeat(uint16_t keycode, keyrecord_t* record) {
    if (keycode == CS_RT2) {
        if (!record->tap.count && record->event.pressed) {
            layer_on(_PROGRAM);
        } else {
            layer_off(_PROGRAM);
        }
        if (record->tap.count && record->event.pressed) {
            register_code(last_key);
        } else {
            unregister_code(last_key);
        }
        return false;
    }

    if (keycode == CS_LT2) {
        if (!record->tap.count && record->event.pressed) {
            layer_on(_EDIT);
        } else {
            layer_off(_EDIT);
        }
        
        if (IS_LAYER_ON(_QWERTY)|| IS_LAYER_ON(_BASIC)) {
            repeat_key = last_key;
        }
        else {
            switch (last_key) {
                case KC_E:
                    repeat_key = KC_O;
                    break;
                case KC_O:
                    repeat_key = KC_E;
                    break;

                case KC_I:
                    repeat_key = KC_U;
                    break;
                case KC_U:
                    repeat_key = KC_I;
                    break;

                case KC_P:
                    repeat_key = KC_H;
                    break;

                case KC_J:
                    repeat_key = KC_U;
                    break;



                case KC_T:
                    repeat_key = KC_D;
                    break;
                case KC_D:
                    repeat_key = KC_T;
                    break;



                case KC_S:
                    repeat_key = KC_C;
                    break;
                case KC_C:
                    repeat_key = KC_S;
                    break;
                case KC_V:
                    repeat_key = KC_S;
                    break;
                case KC_G:
                    repeat_key = KC_S;
                    break;
                case KC_B:
                    repeat_key = KC_S;
                    break;
                case KC_W:
                    repeat_key = KC_S;
                    break;

                case KC_R:
                    repeat_key = KC_L;
                    break;
                case KC_L:
                    repeat_key = KC_R;
                    break;

                case KC_N:
                    repeat_key = KC_A;
                    break;
                case KC_A:
                    repeat_key = KC_N;
                    break;

                default:
                    repeat_key = last_key;
            }
        }

        if (record->tap.count && record->event.pressed) {
            register_code(repeat_key);
        } else {
            unregister_code(repeat_key);
        }
        return false;
    }

    return true;
}

//==============================================================================
// Select word
//==============================================================================

enum { STATE_NONE, STATE_SELECTED, STATE_WORD, STATE_FIRST_LINE, STATE_LINE };
bool process_select_word(uint16_t keycode, keyrecord_t* record, uint16_t sel_keycode) {
    static uint8_t state = STATE_NONE;

    if (keycode == KC_LSFT || keycode == KC_RSFT || keycode == MO(2)) {
        return true;
    }

    if (keycode == sel_keycode && record->event.pressed) {  // On key press.
        const uint8_t mods = get_mods();
        const uint8_t all_mods = mods;
        if ((all_mods & MOD_MASK_SHIFT) == 0) {  // Select word.
            register_code(KC_LCTL);
            if (state == STATE_NONE) {
                SEND_STRING(SS_TAP(X_RGHT) SS_TAP(X_LEFT));
            }
            register_code(KC_LSFT);
            register_code(KC_RGHT);
            state = STATE_WORD;
        } else {  // Select line.
            if (state == STATE_NONE) {
                clear_mods();
                SEND_STRING(SS_TAP(X_HOME) SS_LSFT(SS_TAP(X_END)));
                set_mods(mods);
                state = STATE_FIRST_LINE;
            } else {
                register_code(KC_DOWN);
                state = STATE_LINE;
            }
        }
        return false;
    }

    // `sel_keycode` was released, or another key was pressed.
    switch (state) {
        case STATE_WORD:
            unregister_code(KC_RGHT);
            unregister_code(KC_LSFT);
            unregister_code(KC_LCTL);
            state = STATE_SELECTED;
            break;

        case STATE_FIRST_LINE:
            state = STATE_SELECTED;
            break;

        case STATE_LINE:
            unregister_code(KC_DOWN);
            state = STATE_SELECTED;
            break;

        case STATE_SELECTED:
        default:
        state = STATE_NONE;
    }
    return true;
}

//==============================================================================
// Deferred Executions
//==============================================================================

static bool VOLD_active = false;
static bool VOLU_active = false;
static deferred_token VOLD_token = INVALID_DEFERRED_TOKEN;
static deferred_token VOLU_token = INVALID_DEFERRED_TOKEN;

#define interval 15

static uint32_t VOLD_callback(uint32_t trigger_time, void* cb_arg) {
    if (!VOLD_active) {
        register_code16(KC_VOLD);
        VOLD_active = true;
    }
    else {
        unregister_code16(KC_VOLD);
        VOLD_active = false;
    }
    return interval;
}
static uint32_t VOLU_callback(uint32_t trigger_time, void* cb_arg) {
    if (!VOLU_active) {
        register_code16(KC_VOLU);
        VOLU_active = true;
    }
    else {
        unregister_code16(KC_VOLU);
        VOLU_active = false;
    }
    return interval * 1.5;
}

static void VOLD_start(void) {
    if (VOLD_token == INVALID_DEFERRED_TOKEN) {
        uint32_t delay = VOLD_callback(0, NULL);
        VOLD_token = defer_exec(delay, VOLD_callback, NULL);
    }
}
static void VOLU_start(void) {
    if (VOLU_token == INVALID_DEFERRED_TOKEN) {
        uint32_t delay = VOLU_callback(0, NULL);
        VOLU_token = defer_exec(delay, VOLU_callback, NULL);
    }
}

static void VOLD_stop(void) {
    if (VOLD_token != INVALID_DEFERRED_TOKEN) {
        cancel_deferred_exec(VOLD_token);
        VOLD_token = INVALID_DEFERRED_TOKEN;
        if (VOLD_active) {
            unregister_code16(KC_VOLD);
            VOLD_active = false;
        }
    }
}
static void VOLU_stop(void) {
    if (VOLU_token != INVALID_DEFERRED_TOKEN) {
        cancel_deferred_exec(VOLU_token);
        VOLU_token = INVALID_DEFERRED_TOKEN;
        if (VOLU_active) {
            unregister_code16(KC_VOLU);
            VOLU_active = false;
        }
    }
}

bool process_vol_repeat(uint16_t keycode, keyrecord_t* record) {
    if (keycode == CS_VOLD) {
        if (record->event.pressed) {
            muted = false;
            if (shifted()) {
                register_code16(KC_VOLD);
            }
            else {
                VOLD_start();
            }
        }
        else {
            VOLD_stop();
            unregister_code16(KC_VOLD);
        }
        return false;
    }
    if (keycode == CS_VOLU) {
        if (record->event.pressed) {
            muted = false;
            if (shifted()) {
                register_code16(KC_VOLU);
            }
            else {
                VOLU_start();
            }
        }
        else {
            VOLU_stop();
            unregister_code16(KC_VOLU);
        }
        return false;
    }
    return true;
}







uint32_t clock_callback(uint32_t trigger_time, void* cb_arg) {
    sec++;
    if (sec >= 60) {
        sec = 0;
        min++;
    }
    if (min >= 60) {
        min = 0;
        hrs++;
    }
    if (hrs >= 24) {
        hrs = 0;
    }
    return 1000;
}


bool process_clock(uint16_t keycode, keyrecord_t* record) {
    if (keycode == CLOCKUP) {
        if (record->event.pressed) {
            if (time_setting == 1) {
                if (hrs == 24) {
                    hrs = 0;
                } else {
                    hrs++;
                }
            }
            else if (time_setting == 2) {
                if (min == 60) {
                    min = 0;
                } else {
                    min++;
                }
            }
            else if (time_setting == 3) {
                if (sec == 60) {
                    sec = 0;
                } else {
                    sec++;
                }
            }
            // tick = timer_read();
        }
        return false;
    }
    if (keycode == CLOCKDN) {
        if (record->event.pressed) {
            if (time_setting == 1) {
                if (hrs == 0) {
                    hrs = 23;
                } else {
                    hrs--;
                }
            }
            else if (time_setting == 2) {
                if (min == 0) {
                    min = 59;
                } else {
                    min--;
                }
            }
            else if (time_setting == 3) {
                if (sec == 0) {
                    sec = 59;
                } else {
                    sec--;
                }
            }
            // tick = timer_read();
        }
        return false;
    }
    if (keycode == CLOCKNX) {
        if (record->event.pressed) {
            if (shifted()) {
                if (time_setting == 0) {
                    time_setting = 3;
                }
                else {
                    time_setting--;
                }
            }
            else {
                if (time_setting == 3) {
                    time_setting = 0;
                }
                else {
                    time_setting++;
                }
            }
        }
        return false;
    }
    return true;
}



void render_clock(uint8_t shift, uint8_t line) {
    // char time_str[11];
    char time_str[8];



    // time_str[8] = '\0';
    time_str[7] = '0' + sec % 10;
    time_str[6] = '0' + sec / 10;
    time_str[5] = ':';
    time_str[4] = '0' + min % 10;
    time_str[3] = '0' + min / 10;
    time_str[2] = ':';
    time_str[1] = '0' + hrs % 10;
    time_str[0] = '0' + hrs / 10;

    if (time_setting == 1) {
        oled_set_cursor(shift,line-1);
        oled_write_char(148,false);
        oled_write_char(149,false);
        oled_set_cursor(shift,line+1);
        oled_write_char(180,false);
        oled_write_char(181,false);
    }
    else if (time_setting == 2) {
        oled_set_cursor(shift+3,line-1);
        oled_write_char(148,false);
        oled_write_char(149,false);
        oled_set_cursor(shift+3,line+1);
        oled_write_char(180,false);
        oled_write_char(181,false);
    }
    else if (time_setting == 3) {
        oled_set_cursor(shift+6,line-1);
        oled_write_char(148,false);
        oled_write_char(149,false);
        oled_set_cursor(shift+6,line+1);
        oled_write_char(180,false);
        oled_write_char(181,false);
    }

    oled_set_cursor(shift,line);
    oled_write(time_str, false);
}








//==============================================================================
// Data Sync
//==============================================================================

#include "transactions.h"

typedef struct _master_to_slave_t {
    bool static_display_sync :1;
    bool oled_timeout_sync :1;
} master_to_slave_t;

master_to_slave_t sync_data;

void user_config_sync_handler(uint8_t initiator2target_buffer_size, const void* initiator2target_buffer,
                      uint8_t target2initiator_buffer_size, void* target2initiator_buffer) {
    if (initiator2target_buffer_size == sizeof(master_to_slave_t)) {
        memcpy(&sync_data, initiator2target_buffer, initiator2target_buffer_size);
    }
}

//==============================================================================
// Events
//==============================================================================

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_achordion(keycode, record)) { return false; }
    if (!process_select_word(keycode, record, SELECT)) { return false; }
    if (!process_vol_repeat(keycode, record)) { return false; }
    if (!process_clock(keycode, record)) { return false; }
    if (!process_cs_repeat(keycode, record)) { return false; }
    if (!process_cs_layer_tap(keycode, record)) { return false; }
    
    switch (keycode) {

        // =====================================================================
        // Misc control
        // =====================================================================

        case MENU:
            if (record->event.pressed) {
                if (menu == 0) {
                    menu = 1;
                }
                else if (menu == 1) {
                    menu = 0;
                }
            }
            break;

        case MUTE:
            if (record->event.pressed) {
                register_code(KC_MUTE);
                muted = !muted;
            } else {
                unregister_code(KC_MUTE);
            }
            break;

        case CS_VALU:
            if (record->event.pressed) {
                rgb_matrix_increase_val_noeeprom();
            }
            break;

        case CS_VALD:
            if (record->event.pressed) {
                rgb_matrix_decrease_val_noeeprom();
            }
            break;

        case CS_RGBN:
            if (record->event.pressed) {
                if (shifted()) {
                    if (set_rgb_mode < 6) {
                        set_rgb_mode += 1;
                        
                    } else {
                        set_rgb_mode = 2;
                    }
                } else {
                    if (set_rgb_mode > 2) {
                        set_rgb_mode -= 1;
                    } else {
                        set_rgb_mode = 6;
                    }
                }
                rgb_matrix_mode(set_rgb_mode);
            }
            break;

        case CS_RGBT:
            if (record->event.pressed) {
                rgb_matrix_toggle_noeeprom();
            }
            break;

        case ALTTAB:
            if (!alt_tab_active) {
                alt_tab_active = true;
                register_code(KC_LALT);
            }
            // alt_tab_timer = timer_read();
            if (record->event.pressed) {
                tap_code16(KC_TAB);
            }
            break;

        case OLEDSAV:
            if (record->event.pressed) {
                static_display = !static_display;
                if (!static_display) {
                    oled_clear();
                }
            }
            break;

        case BASE:
            if (record->event.pressed) {
                if (IS_LAYER_ON(_BASIC)) {
                    layer_off(_BASIC);
                }
                else if (IS_LAYER_ON(_BASE)) {
                    layer_on(_QWERTY);
                    layer_off(_BASE);
                }
                else {
                    layer_on(_BASE);
                    layer_off(_QWERTY);
                }
            }
            break;
        case BASIC:
            if (record->event.pressed) {
                if (IS_LAYER_ON(_BASIC)) {
                    layer_off(_BASIC);
                }
                else {
                    layer_on(_BASIC);
                }
            }
            break;
        case CS_BOOT:
            if (record->event.pressed) {
                if (shifted()) {
                    soft_reset_keyboard();
                }
                else {
                    reset_keyboard();
                }
            }
            break;

        // =====================================================================
        // Combos
        // =====================================================================

        case CM_MOUSE:
            if (record->event.pressed) {
                layer_on(_MOUSE);
            } else {
                layer_off(_MOUSE);
            }
            break;

        // Combo actions
        case CM_CIRC:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code16(KC_CIRC);
                set_mods(mods);
            }
            break;
        case CM_COMM:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code(KC_COMM);
                set_mods(mods);
            }
            break;
        case CM_DOT:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code(KC_DOT);
                set_mods(mods);
            }
            break;
        case CM_UNDS:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code16(KC_UNDS);
                set_mods(mods);
            }
            break;
        case CM_ASTR:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code16(KC_ASTR);
                set_mods(mods);
            }
            break;
        case CM_EQL:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code(KC_EQL);
                set_mods(mods);
            }
            break;
        case CM_PLUS:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code16(KC_PLUS);
                set_mods(mods);
            }
            break;
        case CM_MINS:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code(KC_MINS);
                set_mods(mods);
            }
            break;
            
        case CM_AMPR:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code16(KC_AMPR);
                set_mods(mods);
            }
            break;
        case CM_EXLM:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code16(KC_EXLM);
                set_mods(mods);
            }
            break;

        case CM_COLN:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code16(KC_COLN);
                set_mods(mods);
            }
            break;
        case CM_SCLN:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code(KC_SCLN);
                set_mods(mods);
            }
            break;

        // =====================================================================
        // Mod-taps
        // =====================================================================

        // Edit layer
        case MT_RBRC:
        {
            if (!record->tap.count && record->event.pressed) {
                register_mods(MOD_MASK_CTRL);
            } else {
                unregister_mods(MOD_MASK_CTRL);
            }
            if (record->tap.count && record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code16(KC_RBRC);
                set_mods(mods);
            }
            return false;
        }
            break;
        case MT_RPRN:
        {
            if (!record->tap.count && record->event.pressed) {
                register_mods(MOD_MASK_SHIFT);
            } else {
                unregister_mods(MOD_MASK_SHIFT);
            }
            if (record->tap.count && record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code16(KC_RPRN);
                set_mods(mods);
            }
            return false;
        }
            break;

        case MT_LPRN:
        {
            if (!record->tap.count && record->event.pressed) {
                register_mods(MOD_BIT(KC_LALT));
            } else {
                unregister_mods(MOD_BIT(KC_LALT));
            }
            if (record->tap.count && record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code16(KC_LPRN);
                set_mods(mods);
            }
            return false;
        }
            break;

        case MT_UNDS:
        {
            if (!record->tap.count && record->event.pressed) {
                register_mods(MOD_MASK_GUI);
            } else {
                unregister_mods(MOD_MASK_GUI);
            }
            if (record->tap.count && record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code16(KC_UNDS);
                set_mods(mods);
            }
            return false;
        }
            break;



        // Data layer
        case MT_COMM:
        {
            if (!record->tap.count && record->event.pressed) {
                register_mods(MOD_MASK_CTRL);
            } else {
                unregister_mods(MOD_MASK_CTRL);
            }
            if (record->tap.count && record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code16(KC_COMM);
                set_mods(mods);
            }
            return false;
        }
            break;
        case MT_EQL:
        {
            if (!record->tap.count && record->event.pressed) {
                register_mods(MOD_MASK_SHIFT);
            } else {
                unregister_mods(MOD_MASK_SHIFT);
            }
            if (record->tap.count && record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code16(KC_EQL);
                set_mods(mods);
            }
            return false;
        }
            break;

        case MT_MINS:
        {
            if (!record->tap.count && record->event.pressed) {
                register_mods(MOD_BIT(KC_LALT));
            } else {
                unregister_mods(MOD_BIT(KC_LALT));
            }
            if (record->tap.count && record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code16(KC_MINS);
                set_mods(mods);
            }
            return false;
        }
            break;

        case MT_PLUS:
        {
            if (!record->tap.count && record->event.pressed) {
                register_mods(MOD_MASK_GUI);
            } else {
                unregister_mods(MOD_MASK_GUI);
            }
            if (record->tap.count && record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code16(KC_PLUS);
                set_mods(mods);
            }
            return false;
        }
            break;

        // =====================================================================
        // Repeat key
        // =====================================================================

        case KC_A:
        // case MT_A:
            if (record->event.pressed && no_ctrl()) {
                last_key = KC_A;
            }
            break;
        case KC_B:
            if (record->event.pressed && no_ctrl()) {
                last_key = KC_B;
            }
            break;
        case KC_C:
        case MT_C:
            if (record->event.pressed && no_ctrl()) {
                last_key = KC_C;
            }
            break;
        case KC_D:
        case MT_D:
            if (record->event.pressed && no_ctrl()) {
                last_key = KC_D;
            }
            break;
        case KC_E:
        case MTA_E:
            if (record->event.pressed && no_ctrl()) {
                last_key = KC_E;
            }
            break;
        case KC_F:
        case MT_F:
            if (record->event.pressed && no_ctrl()) {
                last_key = KC_F;
            }
            break;
        case KC_G:
            if (record->event.pressed && no_ctrl()) {
                last_key = KC_G;
            }
            break;
        case KC_H:
        case MTA_H:
            if (record->event.pressed && no_ctrl()) {
                last_key = KC_H;
            }
            break;
        case KC_I:
        case MTA_I:
            if (record->event.pressed && no_ctrl()) {
                last_key = KC_I;
            }
            break;
        case KC_J:
        case MT_J:
            if (record->event.pressed && no_ctrl()) {
                last_key = KC_J;
            }
            break;
        case KC_K:
        case MT_K:
            if (record->event.pressed && no_ctrl()) {
                last_key = KC_K;
            }
            break;
        case KC_L:
        case MT_L:
            if (record->event.pressed && no_ctrl()) {
                last_key = KC_L;
            }
            break;
        case KC_M:
            if (record->event.pressed && no_ctrl()) {
                last_key = KC_M;
            }
            break;
        case KC_N:
        case MT_N:
            if (record->event.pressed && no_ctrl()) {
                last_key = KC_N;
            }
            break;
        case KC_O:
            if (record->event.pressed && no_ctrl()) {
                last_key = KC_O;
            }
            break;
        case KC_P:
        case MTA_P:
            if (record->event.pressed && no_ctrl()) {
                last_key = KC_P;
            }
            break;
        case KC_Q:
            if (record->event.pressed && no_ctrl()) {
                last_key = KC_Q;
            }
            break;
        case KC_R:
        case MTA_R:
            if (record->event.pressed && no_ctrl()) {
                last_key = KC_R;
            }
            break;
        case KC_S:
        case MT_S:
        case MTA_S:
            if (record->event.pressed && no_ctrl()) {
                last_key = KC_S;
            }
            break;
        case KC_T:
        case MTA_T:
            if (record->event.pressed && no_ctrl()) {
                last_key = KC_T;
            }
            break;
        case KC_U:
            if (record->event.pressed && no_ctrl()) {
                last_key = KC_U;
            }
            break;
        case KC_V:
            if (record->event.pressed && no_ctrl()) {
                last_key = KC_V;
            }
            break;
        case KC_W:
        case MTA_W:
            if (record->event.pressed && no_ctrl()) {
                last_key = KC_W;
            }
            break;
        case KC_X:
            if (record->event.pressed && no_ctrl()) {
                last_key = KC_X;
            }
            break;
        case KC_Y:
            if (record->event.pressed && no_ctrl()) {
                last_key = KC_Y;
            }
            break;
        case KC_Z:
            if (record->event.pressed && no_ctrl()) {
                last_key = KC_Z;
            }
            break;


        // =====================================================================
        // Custom symbol handling
        // =====================================================================

        case CS_COLN:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code16(KC_COLN);
                set_mods(mods);
            }
            break;
        case CS_UNDS:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code16(KC_UNDS);
                set_mods(mods);
            }
            break;
        case CS_PIPE:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code16(LSFT(KC_NUBS));
                set_mods(mods);
            }
            break;
        case CS_LT:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code16(KC_LT);
                set_mods(mods);
            }
            break;
        case CS_GT:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code16(KC_GT);
                set_mods(mods);
            }
            break;
        case CS_PERC:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code16(KC_PERC);
                set_mods(mods);
            }
            break;
        case CS_ASTR:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code16(KC_ASTR);
                set_mods(mods);
            }
            break;
        case CS_DLR:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code16(KC_DLR);
                set_mods(mods);
            }
            break;
        case CS_AMPR:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code16(KC_AMPR);
                set_mods(mods);
            }
            break;
        case CS_CIRC:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code16(KC_CIRC);
                set_mods(mods);
            }
            break;
        case CS_EXLM:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code16(KC_EXLM);
                set_mods(mods);
            }
            break;
        case CS_TILD:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code16(S(KC_NUHS));
                set_mods(mods);
            }
            break;
        case CS_PLUS:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code16(KC_PLUS);
                set_mods(mods);
            }
            break;
        case CS_HASH:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code(KC_NUHS);
                set_mods(mods);
            }
            break;
        case CS_SLSH:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code(KC_SLSH);
                set_mods(mods);
            }
            break;
        case CS_EQL:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code(KC_EQL);
                set_mods(mods);
            }
            break;
        case CS_AT:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code16(KC_DQUO);
                set_mods(mods);
            }
            break;
        case CS_DQUO:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code16(KC_AT);
                set_mods(mods);
            }
            break;
        case CS_POUN:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code16(KC_HASH);
                set_mods(mods);
            }
            break;
        case CS_BSLS:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code16(KC_NUBS);
                set_mods(mods);
            }
            break;
        case CS_MINS:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code(KC_MINS);
                set_mods(mods);
            }
            break;
        case CS_DOT:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code(KC_DOT);
                set_mods(mods);
            }
            break;
        case CS_COMM:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code(KC_COMM);
                set_mods(mods);
            }
            break;
        case CS_QUES:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code16(KC_QUES);
                set_mods(mods);
            }
            break;
        case CS_SCLN:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code(KC_SCLN);
                set_mods(mods);
            }
            break;

        case COM_DOT:
            if (record->event.pressed) {
                if (shifted()) {
                    const uint8_t mods = get_mods();
                    del_mods(MOD_MASK_SHIFT);
                    tap_code(KC_DOT);
                    set_mods(mods);
                }
                else {
                    const uint8_t mods = get_mods();
                    del_mods(MOD_MASK_SHIFT);
                    tap_code(KC_COMM);
                    set_mods(mods);
                }
            }
            break;

        case QUE_EXL:
            if (record->event.pressed) {
                if (shifted()) {
                    const uint8_t mods = get_mods();
                    del_mods(MOD_MASK_SHIFT);
                    tap_code16(KC_EXLM);
                    set_mods(mods);
                }
                else {
                    const uint8_t mods = get_mods();
                    del_mods(MOD_MASK_SHIFT);
                    tap_code16(KC_QUES);
                    set_mods(mods);
                }
            }
            break;

        case CS_END:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_CTRL);
                tap_code(KC_END);
                set_mods(mods);
            }
            break;
        case CS_HOME:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_CTRL);
                tap_code(KC_HOME);
                set_mods(mods);
            }
            break;
    }
    return true;
}

//==============================================================================
// OSM
//==============================================================================

// bool ONESHOT_SHIFT = false;
// void oneshot_mods_changed_user(uint8_t mods) {
//     if (mods & MOD_MASK_SHIFT) {
//         ONESHOT_SHIFT = true;
//     }
//     if (!mods) {
//         ONESHOT_SHIFT = false;
//     }
// }


//==============================================================================
// OLED
//==============================================================================

void render_wpm(void) {
    uint8_t n = get_current_wpm();
    char render_str[3];

    // render_str[3] = '\0';
    render_str[2] = '0' + n % 10;
    render_str[1] = '0' + (n /= 10) % 10;
    render_str[0] = '0' + n / 10;
    
    oled_write_P(PSTR("WPM: "), false);
    oled_write(render_str, false);
}

//------------
// Animation
//------------

static bool minor = true;
static bool major = false;
static uint8_t frame_count = 15;
static uint16_t render_timer;
static uint16_t anim_timer = 0;
static bool show_text = true;

#include "frames.c"

static uint8_t clean_frame = 0;

void render_stats(void) {
    oled_set_cursor(0,14);
    render_wpm();
    render_clock(0,15);
}

void render_text_clean(void) {
    oled_write_raw_P(text_clean[clean_frame], frame_size);
}

void render_text_major(void) {
    oled_write_raw_P(text_major[rand() % text_major_count], frame_size);
}


#define BIAS 2
void render_text_minor(bool can_be_major) {
    clean_frame = rand() % 2;
    uint8_t frame = can_be_major ? rand() % (BIAS*text_minor_count + text_major_count) : rand() % text_minor_count;
    if (frame < BIAS*text_minor_count) {
        oled_write_raw_P(text_minor[frame % text_minor_count], frame_size);
        return;
    }

    render_text_major();
}

void render_logo_clean(void) {
    oled_write_raw_P(logo_clean, frame_size);
    render_stats();
}

void render_logo_major(void) {
    oled_write_raw_P(logo_major[rand() % logo_major_count], frame_size);
}

void render_logo_minor(bool can_be_major) {
    uint8_t frame = can_be_major ? rand() % (logo_minor_count + logo_major_count) : rand() % logo_minor_count;
    if (frame < logo_minor_count) {
        oled_write_raw_P(logo_minor[frame], frame_size);

        return;
    }

    render_logo_major();
}


void render_draw(void) {
    if (sync_data.oled_timeout_sync) {
        return;
    }
    
    anim_timer = timer_elapsed(render_timer);
    if (anim_timer < 150) {
        show_text ? render_text_major() : render_logo_major();
        return;
    }
    if (anim_timer < 250) {
        show_text ? render_text_minor(true) : render_logo_minor(true);
        return;
    }
    if (anim_timer > 9750 && anim_timer < 9850) {
        show_text ? render_text_minor(true) : render_logo_minor(true);
        return;
    }
    if (anim_timer > 9850 && anim_timer < 10000) {
        show_text ? render_text_major() : render_logo_major();
        return;
    }
    if (anim_timer > 10000) {
        show_text = !show_text;
        render_timer = timer_read();
    }

    if (minor && 0 != frame_count) {
        frame_count--;
        show_text ? render_text_minor(true) : render_logo_minor(true);

        return;
    }

    minor = false;
    major = false;

    show_text ? render_text_clean() : render_logo_clean();

    if (1 == rand() % 60) {
        minor = true;
        frame_count = 1 + rand() % 4;

        return;
    }

    if (1 == rand() % 60) {
        minor = true;
        frame_count = 1 + rand() % 10;
        major = frame_count > 5;
    }
}






void render_linebreak(void) {
    oled_write_P(PSTR("__________"), false);
}

void render_mode(void) {
    if (IS_LAYER_ON(_NUMPAD)){
        oled_write_P(PSTR(" Numpad\n"), false);
    }
    else if (IS_LAYER_ON(_TOUHOU)){
        oled_write_P(PSTR(" Touhou\n"), false);
    }
    else if (IS_LAYER_ON(_BASIC)){
        oled_write_P(PSTR(" Basic\n"), false);
    }
    else if (IS_LAYER_ON(_STENO)){
        oled_write_P(PSTR(" Steno.\n"), false);
    }
    else if (IS_LAYER_ON(_QWERTY)){
        oled_write_P(PSTR(" QWERTY\n"), false);
    }
    else if (IS_LAYER_ON(_BASE)){
        oled_write_P(PSTR(" Base\n"), false);
    }
    else {
        oled_write_P(PSTR(" REEEE\n"), false);
    }
}

void render_layer(void) {
    if (IS_LAYER_ON(_DATA)) {
        oled_write_P(PSTR(">Data\n"), false);
    } else {
        oled_write_P(PSTR(" Data\n"), false);
    }
    if (IS_LAYER_ON(_SYMBOL)) {
        oled_write_P(PSTR(">Symbol\n"), false);
    } else {
        oled_write_P(PSTR(" Symbol\n"), false);
    }
    if (IS_LAYER_ON(_PROGRAM)) {
        oled_write_P(PSTR(">Program\n"), false);
    } else {
        oled_write_P(PSTR(" Program\n"), false);
    }
    if (IS_LAYER_ON(_EDIT)) {
        oled_write_P(PSTR(">Edit\n"), false);
    } else {
        oled_write_P(PSTR(" Edit\n"), false);
    }
    if (IS_LAYER_ON(_MOUSE) || IS_LAYER_ON(_MOUSE_BTN)) {
        oled_write_P(PSTR(">Mouse\n"), false);
    } else {
        oled_write_P(PSTR(" Mouse\n"), false);
    }
    if (IS_LAYER_ON(_UTILITY)) {
        oled_write_P(PSTR(">Utility\n"), false);
    } else {
        oled_write_P(PSTR(" Utility\n"), false);
    }
}





void render_locking_key_state(led_t led_usb_state) {
    if (led_usb_state.caps_lock) {
        oled_write_char(203,false);
        oled_write_char(204,false);
        oled_write_char(205,false);
    } else {
        oled_write_char(193,false);
        oled_write_char(194,false);
        oled_write_char(195,false);
    }

    if (led_usb_state.caps_lock && !led_usb_state.scroll_lock) {
        oled_write_char(206,false);
    }
    else if (led_usb_state.caps_lock && led_usb_state.scroll_lock) {
        oled_write_char(207,false);
    }
    else if (!led_usb_state.caps_lock && led_usb_state.scroll_lock) {
        oled_write_char(208,false);
    }
    else {
        oled_write_char(196,false);
    }
    
    if (led_usb_state.scroll_lock) {
        oled_write_char(209,false);
        oled_write_char(210,false);
    } else {
        oled_write_char(197,false);
        oled_write_char(198,false);
    }

    if (led_usb_state.scroll_lock && !led_usb_state.num_lock) {
        oled_write_char(211,false);
        oled_write_char(200,false);
    }
    else if (led_usb_state.scroll_lock && led_usb_state.num_lock) {
        oled_write_char(212,false);
        oled_write_char(213,false);
    }
    else if (!led_usb_state.scroll_lock && led_usb_state.num_lock) {
        oled_write_char(199,false);
        oled_write_char(214,false);
    }
    else {
        oled_write_char(199,false);
        oled_write_char(200,false);
    }
    
    if (led_usb_state.num_lock) {
        oled_write_char(215,false);
        oled_write_char(216,false);
    } else {
        oled_write_char(201,false);
        oled_write_char(202,false);
    }
}

void render_modifier_state(uint8_t line) {
    oled_set_cursor(0,line);
    if (get_mods() & MOD_MASK_GUI) {
        oled_write_char(137,false);
        oled_write_char(138,false);
        oled_set_cursor(0,line+1);
        oled_write_char(169,false);
        oled_write_char(170,false);

    } else {
        oled_write_char(129,false);
        oled_write_char(130,false);
        oled_set_cursor(0,line+1);
        oled_write_char(161,false);
        oled_write_char(162,false);
    }
    oled_set_cursor(2,line);
    if (get_mods() & MOD_MASK_ALT) {
        oled_write_char(139,false);
        oled_write_char(140,false);
        oled_set_cursor(2,line+1);
        oled_write_char(171,false);
        oled_write_char(172,false);
    } else {
        oled_write_char(131,false);
        oled_write_char(132,false);
        oled_set_cursor(2,line+1);
        oled_write_char(163,false);
        oled_write_char(164,false);
    }
    oled_set_cursor(4,line);
    if (get_mods() & MOD_MASK_SHIFT) {
        oled_write_char(141,false);
        oled_write_char(142,false);
        oled_set_cursor(4,line+1);
        oled_write_char(173,false);
        oled_write_char(174,false);
    } else {
        oled_write_char(133,false);
        oled_write_char(134,false);
        oled_set_cursor(4,line+1);
        oled_write_char(165,false);
        oled_write_char(166,false);
    }
    oled_set_cursor(6,line);
    if (get_mods() & MOD_MASK_CTRL) {
        oled_write_char(143,false);
        oled_write_char(144,false);
        oled_set_cursor(6,line+1);
        oled_write_char(175,false);
        oled_write_char(176,false);
    } else {
        oled_write_char(135,false);
        oled_write_char(136,false);
        oled_set_cursor(6,line+1);
        oled_write_char(167,false);
        oled_write_char(168,false);
    }

    oled_set_cursor(8,line);
    oled_write_char(145,false);
    oled_set_cursor(8,line+1);
    oled_write_char(177,false);
    oled_set_cursor(9,line);
    if (!muted) {
        oled_write_char(146,false);
        oled_set_cursor(9,line+1);
        oled_write_char(178,false);
    } else {
        oled_write_char(147,false);
        oled_set_cursor(9,line+1);
        oled_write_char(179,false);
    }
    oled_advance_page(false);
}


#include "menu.c"



void render_layout(void) {
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_raw_P(menu_layout_base, frame_size);
            break;
        case _DATA:
            oled_write_raw_P(menu_layout_data, frame_size);
            break;
        case _SYMBOL:
            oled_write_raw_P(menu_layout_symbol, frame_size);
            break;
        case _PROGRAM:
            oled_write_raw_P(menu_layout_program, frame_size);
            break;
        case _EDIT:
            oled_write_raw_P(menu_layout_edit, frame_size);
            break;
        case _BASIC:
        case _QWERTY:
            oled_write_raw_P(menu_layout_qwerty, frame_size);
            break;
        default:
            break;
    }
    // if (IS_LAYER_ON(_DATA)) {
        
    // }
    // if (IS_LAYER_ON(_SYMBOL)) {
        
    // }
    // if (IS_LAYER_ON(_PROGRAM)) {
        
    // }
    // if (IS_LAYER_ON(_EDIT)) {
        
    // }
}

static void render_status(void) {
    if (menu == 0) {
        oled_set_cursor(0,3);
        oled_write_ln_P(PSTR("Layer:"), false); // 1
        render_layer(); // 7
    }
    else if (menu == 1) {
        render_layout();
    }

    oled_set_cursor(0,0);
    oled_write_ln_P(PSTR("Mode:"), false); // 1
    render_mode(); // 1

    render_linebreak(); // 1


    
    
    oled_set_cursor(0,10);
    render_linebreak(); // 1
    oled_write_P(PSTR("\n"), false); // 1
    render_linebreak(); // 1

    render_locking_key_state(host_keyboard_led_state()); // 1
    render_modifier_state(14); // 2
    render_clock(1,11); // 1 (3)
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_0;
}

bool oled_task_user(void) {
    if (oled_timeout) {
        oled_off();
        return false;
    }
    if (is_keyboard_master()) {
        if (static_display) {
            oled_write_raw_P(static_right, frame_size);
        }
        else {
            render_status();
        }
    }
    else {
        if (static_display || sync_data.static_display_sync) {
            ;
            // oled_write_raw_P(static_left, frame_size);
        }
        else {
            render_draw();
        }
    }
    return false;
}


//==============================================================================
// RGB
//==============================================================================

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // Layers on underglow
    HSV underglow_hsv = (HSV){ 0, 0, 0 };
    RGB underglow_rgb = hsv_to_rgb(underglow_hsv);
    for (uint8_t i = 27; i < 33; i++) {
        switch (get_highest_layer(layer_state|default_layer_state)) {
            case _PROGRAM:
                underglow_hsv = (HSV){ 85, 255, 255 };
                underglow_rgb = hsv_to_rgb(underglow_hsv);
                rgb_matrix_set_color(i, underglow_rgb.r, underglow_rgb.g, underglow_rgb.b);
                rgb_matrix_set_color(i-27, underglow_rgb.r, underglow_rgb.g, underglow_rgb.b);
                break;
            case _DATA:
                underglow_hsv = (HSV){ 127, 255, 255 };
                underglow_rgb = hsv_to_rgb(underglow_hsv);
                rgb_matrix_set_color(i, underglow_rgb.r, underglow_rgb.g, underglow_rgb.b);
                rgb_matrix_set_color(i-27, underglow_rgb.r, underglow_rgb.g, underglow_rgb.b);
                break;
            case _EDIT:
                underglow_hsv = (HSV){ 0, 255, 255 };
                underglow_rgb = hsv_to_rgb(underglow_hsv);
                rgb_matrix_set_color(i, underglow_rgb.r, underglow_rgb.g, underglow_rgb.b);
                rgb_matrix_set_color(i-27, underglow_rgb.r, underglow_rgb.g, underglow_rgb.b);
                break;
            case _SYMBOL:
                underglow_hsv = (HSV){ 169, 255, 255 };
                underglow_rgb = hsv_to_rgb(underglow_hsv);
                rgb_matrix_set_color(i, underglow_rgb.r, underglow_rgb.g, underglow_rgb.b);
                rgb_matrix_set_color(i-27, underglow_rgb.r, underglow_rgb.g, underglow_rgb.b);
                break;
            case _MOUSE:
                underglow_hsv = (HSV){ 222, 255, 255 };
                underglow_rgb = hsv_to_rgb(underglow_hsv);
                rgb_matrix_set_color(i, underglow_rgb.r, underglow_rgb.g, underglow_rgb.b);
                rgb_matrix_set_color(i-27, underglow_rgb.r, underglow_rgb.g, underglow_rgb.b);
                break;
            case _NUMPAD:
                underglow_hsv = (HSV){ 43, 255, 255 };
                underglow_rgb = hsv_to_rgb(underglow_hsv);
                rgb_matrix_set_color(i, underglow_rgb.r, underglow_rgb.g, underglow_rgb.b);
                rgb_matrix_set_color(i-27, underglow_rgb.r, underglow_rgb.g, underglow_rgb.b);
                break;
            case _UTILITY:
                underglow_hsv = (HSV){ 201, 255, 255 };
                underglow_rgb = hsv_to_rgb(underglow_hsv);
                rgb_matrix_set_color(i, underglow_rgb.r, underglow_rgb.g, underglow_rgb.b);
                rgb_matrix_set_color(i-27, underglow_rgb.r, underglow_rgb.g, underglow_rgb.b);
                break;
            case _BASIC:
            case _TOUHOU:
            default:
                break;
        }
    }

    
    // if (get_mods() == 0) {
    //     rgb_matrix_sethsv_noeeprom(255,255,225);
    // } else {
    //     rgb_matrix_sethsv_noeeprom(255,255,255);
    // }

    // Thumbkeys
    // HSV mod_hsv = (HSV){ 0, 0, 0 };
    // RGB mod_rgb = hsv_to_rgb(mod_hsv);
    // int idxs[3] = { 33, 40, 41 };
    // for (uint8_t i = 0; i < 3; i++) {
    //     if ((get_mods() & MOD_BIT(KC_LGUI)) == MOD_BIT(KC_LGUI) || (get_mods() & MOD_BIT(KC_RGUI)) == MOD_BIT(KC_RGUI)) {
    //         mod_hsv = (HSV){ 000, 255, 128 };
    //         mod_rgb = hsv_to_rgb(mod_hsv);
    //         rgb_matrix_set_color(idxs[i], mod_rgb.r, mod_rgb.g, mod_rgb.b);
    //         rgb_matrix_set_color(idxs[i]-27, mod_rgb.r, mod_rgb.g, mod_rgb.b);
    //     }
    //     if ((get_mods() & MOD_BIT(KC_LALT)) == MOD_BIT(KC_LALT) || (get_mods() & MOD_BIT(KC_RALT)) == MOD_BIT(KC_RALT)) {
    //         mod_hsv = (HSV){ 201, 255, 128 };
    //         mod_rgb = hsv_to_rgb(mod_hsv);
    //         rgb_matrix_set_color(idxs[i], mod_rgb.r, mod_rgb.g, mod_rgb.b);
    //         rgb_matrix_set_color(idxs[i]-27, mod_rgb.r, mod_rgb.g, mod_rgb.b);
    //     }
    //     if ((get_mods() & MOD_BIT(KC_LSFT)) == MOD_BIT(KC_LSFT) || (get_mods() & MOD_BIT(KC_RSFT)) == MOD_BIT(KC_RSFT)) {
    //         mod_hsv = (HSV){ 127, 255, 96 };
    //         mod_rgb = hsv_to_rgb(mod_hsv);
    //         rgb_matrix_set_color(idxs[i], mod_rgb.r, mod_rgb.g, mod_rgb.b);
    //         rgb_matrix_set_color(idxs[i]-27, mod_rgb.r, mod_rgb.g, mod_rgb.b);

    //     }
    //     if ((get_mods() & MOD_BIT(KC_LCTL)) == MOD_BIT(KC_LCTL) || (get_mods() & MOD_BIT(KC_RCTL)) == MOD_BIT(KC_RCTL)) {
    //         mod_hsv = (HSV){ 169, 255, 128 };
    //         mod_rgb = hsv_to_rgb(mod_hsv);
    //         rgb_matrix_set_color(idxs[i], mod_rgb.r, mod_rgb.g, mod_rgb.b);
    //         rgb_matrix_set_color(idxs[i]-27, mod_rgb.r, mod_rgb.g, mod_rgb.b);
    //     }
    // }

    // Modifiers
    // if ((get_mods() & MOD_BIT(KC_LGUI)) == MOD_BIT(KC_LGUI) || (get_mods() & MOD_BIT(KC_RGUI)) == MOD_BIT(KC_RGUI)) {
    //     rgb_matrix_set_color(33, RGB_BLUE);
    // }
    // if ((get_mods() & MOD_BIT(KC_LALT)) == MOD_BIT(KC_LALT) || (get_mods() & MOD_BIT(KC_RALT)) == MOD_BIT(KC_RALT)) {
    //     rgb_matrix_set_color(40, RGB_PURPLE);

    // }
    // if ((get_mods() & MOD_BIT(KC_LSFT)) == MOD_BIT(KC_LSFT) || (get_mods() & MOD_BIT(KC_RSFT)) == MOD_BIT(KC_RSFT)) {
    //     rgb_matrix_set_color(41, RGB_PINK);

    // }
    // if ((get_mods() & MOD_BIT(KC_LCTL)) == MOD_BIT(KC_LCTL) || (get_mods() & MOD_BIT(KC_RCTL)) == MOD_BIT(KC_RCTL)) {
    //     rgb_matrix_set_color(41, RGB_PINK);
    // }

    return false;
}
//     ,-----------------------.
//      36, 37, 44, 45, 50, 51, 
//     |---+---+---+---+---+---|
//      35, 38, 43, 46, 49, 52,
//     |---+---+---+---+---+---|
//      34, 39, 42, 47, 48, 53
// |---+---+---+---+---+---+---|
//   33, 40, 41
// `-----------'
// Underglow: 27-32



layer_state_t layer_state_set_user(layer_state_t state) {
    if (IS_LAYER_ON_STATE(state, _BASIC)) {
        rgb_matrix_set_speed_noeeprom(48);
        rgb_matrix_mode_noeeprom(RGB_MATRIX_RAINBOW_PINWHEELS);
        rgb_matrix_sethsv_noeeprom(255,225,255);
    }
    else if (IS_LAYER_ON_STATE(state, _BASE)) {
        rgb_matrix_set_speed_noeeprom(64);
        rgb_matrix_mode_noeeprom(set_rgb_mode);
        rgb_matrix_sethsv_noeeprom(255,255,255);
    }
    return state;
}

// =============================================================================
// 
// =============================================================================

void keyboard_post_init_user(void) {
    debug_enable = true;
    // debug_matrix = true;
    // debug_keyboard = true;
    debug_mouse = true;
    rgb_matrix_set_speed_noeeprom(64);
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE);
    rgb_matrix_sethsv_noeeprom(255,255,255);

    defer_exec(clock_callback(0,NULL), clock_callback, NULL);

    transaction_register_rpc(USER_SYNC_A, user_config_sync_handler);

    layer_move(_BASE);
}

void housekeeping_task_user(void) {
    if (is_keyboard_master()) {
        static uint32_t last_sync = 0;
        if (timer_elapsed32(last_sync) > 500) { // Interact with slave every 500ms
            // master_to_slave_t m2s = { .static_display_sync = static_display };
            master_to_slave_t m2s = { .static_display_sync = static_display, .oled_timeout_sync = oled_timeout };
            if (transaction_rpc_send(USER_SYNC_A, sizeof(master_to_slave_t), &m2s)) {
                last_sync = timer_read32();
            } else {
                dprint("Slave sync failed!\n");
            }
        }
    }
    else { // slave side
        if (sync_data.static_display_sync) { 
            oled_write_raw_P(static_left, frame_size);
        }
        else {
            // render_draw();
        }
        if (sync_data.oled_timeout_sync) { 
            oled_off();
        }
        else {
            oled_on();
        }
    }
}
