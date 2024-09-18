#include QMK_KEYBOARD_H
#include "print.h"

// #include "ps2_mouse.h"
// #include "ps2.h"

enum corne_layers {
    _BASIC,
    _QWERTY,
    _BASE,
    _CONTROL,
    _STENO,
    _DATA,
    _PROGRAM,
    _SYMBOL,
    _EDIT,
    _MOUSE,
    // _MOUSE_BTN,
    _NUMPAD,
    _UTILITY,
    _TOUHOU,
};


enum custom_keycodes {
    SELECT = SAFE_RANGE,

    REP,
    MAGIC,
    NEWSENT,

    ALTTAB,
    BASIC,
    BASE,
    MENU,

    CS_END,
    CS_HOME,

    MUTE,
    MUTE_L,
    MUTE_R,
    CS_VOLD,
    CS_VOLU,

    CS_VALU,
    CS_VALD,
    CS_RGBN,
    CS_RGBT,
    
    CLOCKUP,
    CLOCKDN,
    CLOCKNX,

    OLEDSAV,

    // Custom Symbols
    COM_DOT,
    QUE_EXL,
    MINS_AT,
    APO_QUO,

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
    CS_QUOT,
    CS_DQUO,
    CS_POUN,
    CS_BSLS,
    CS_MINS,
    CS_DOT,
    CS_COMM,
    CS_QUES,
    CS_SCLN,

    // Home block mods
    CS_RBRC,
    CS_RPRN,
    CS_LPRN,

    // Combos
    CM_MOUSE,

    CM_BSPC_1,
    CM_BSPC_2,
    CM_BSPC_3,
};



// Home block mods
#define MT_S LGUI_T(KC_S)
#define MT_D LALT_T(KC_D)
#define MT_F LSFT_T(KC_F)
#define MT_V LCTL_T(KC_V)

#define MT_M RCTL_T(KC_M)
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

// Custom tap-hold keys
#define CS_BOOT LT(0,KC_ESC)
#define TAB_SFT RSFT_T(KC_TAB)

// Control keys
#define CS_LCTL LM(_CONTROL, MOD_LCTL)

#define UNDO LCTL(KC_Z)
#define REDO LCTL(KC_Y)
#define CUT LCTL(KC_X)
#define COPY LCTL(KC_C)
#define PASTE LCTL(KC_V)
#define FIND LCTL(KC_F)
#define SAVE LCTL(KC_S)
#define ALL LCTL(KC_A)
#define CLOSE LCTL(KC_W)
#define TAB LCTL(KC_T)
#define WINDOW LCTL(KC_N)
#define REFRESH LCTL(KC_R)
#define MERGE LCTL(KC_E)
#define BOLD LCTL(KC_B)
#define GROUP LCTL(KC_G)
#define LEVEL LCTL(KC_L)
#define DUPL LCTL(KC_J)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASIC] = LAYOUT( //3
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
           KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, CS_HASH,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_TAB,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_QUOT, COM_DOT, QUE_EXL, NEWSENT,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                               CS_LT3,  CS_LT2,  KC_SPC,     CS_RT1,  CS_RT2,  CS_RT3
                                          //`--------------------------'  `--------------------------'
    ), 
    [_QWERTY] = LAYOUT( //0
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
           KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, CS_HASH,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          KC_LSFT,    KC_A,    MT_S,    MT_D,    MT_F,    KC_G,                         KC_H,    MT_J,    MT_K,    MT_L, KC_SCLN, TAB_SFT,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          CS_LCTL,    KC_Z,    KC_X,    KC_C,    MT_V,    KC_B,                         KC_N,    MT_M, KC_QUOT, COM_DOT, QUE_EXL, NEWSENT,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                               CS_LT3,  CS_LT2,  CS_LT1,     CS_RT1,  CS_RT2,  CS_RT3
                                          //`--------------------------'  `--------------------------'
    ),

    [_BASE] = LAYOUT( //1
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
           KC_ESC,    KC_Z,    KC_L,    KC_D,    KC_C,    KC_B,                         KC_J,    KC_F,    KC_O,    KC_U, KC_SCLN, CS_HASH,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          KC_LSFT,    KC_N,   MTA_R,   MTA_T,   MTA_S,    KC_G,                         KC_Y,   MTA_H,   MTA_E,   MTA_I,    KC_A, TAB_SFT,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          CS_LCTL,    KC_Q,    KC_X,    KC_M,   MTA_W,    KC_V,                         KC_K,   MTA_P, KC_QUOT, COM_DOT, QUE_EXL, NEWSENT,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                               CS_LT3,  CS_LT2,  CS_LT1,     CS_RT1,  CS_RT2,  CS_RT3
                                          //`--------------------------'  `--------------------------'
    ),

    [_CONTROL] = LAYOUT( //2
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
          _______,   LEVEL,   MERGE,   CLOSE, REFRESH,     TAB,                         REDO, _______, _______, _______, _______, _______,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          _______,    DUPL,     ALL,    SAVE,    FIND,  WINDOW,                        GROUP, _______, _______, _______, _______, _______,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          _______,    REDO,    UNDO,     CUT,    COPY,   PASTE,                         BOLD, _______, _______, _______, _______, _______,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              _______, _______, _______,    _______, _______, _______
                                          //`--------------------------'  `--------------------------'
    ),

    [_STENO] = LAYOUT( //4
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

    [_DATA] = LAYOUT( //5
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
          _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       CS_EQL,    KC_7,    KC_8,    KC_9, CS_SCLN,  KC_DEL,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          _______, CS_CIRC, MT_PLUS, MT_MINS,  MT_EQL, CS_PIPE,                        CS_LT,    KC_1,    KC_2,    KC_3, CS_EXLM, TAB_SFT,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          _______, CS_TILD, CS_ASTR,  CS_DOT, MT_COMM, CS_POUN,                        CS_GT,    KC_4,    KC_5,    KC_6, CS_QUES,  KC_ENT,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              _______, _______, _______,    KC_BSPC,  CS_AL1, CS_SLSH
                                          //`--------------------------'  `--------------------------'
    ),

    [_SYMBOL] = LAYOUT( //6
      //,-----------------------------------------------------.                    ,---------------------------------------------------.
           KC_GRV, CS_PERC, CS_ASTR,  CS_DLR, CS_AMPR, CS_CIRC,                       CS_EQL, KC_RCBR, KC_LCBR, CS_CIRC, CS_SCLN,  KC_DEL,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          _______, CS_PIPE,   CS_LT, CS_MINS,   CS_GT,  CS_EQL,                        CS_LT, KC_RPRN, KC_LPRN, CS_UNDS, CS_EXLM, TAB_SFT,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          _______, CS_TILD, CS_COLN,  CS_DOT, CS_COMM, CS_UNDS,                        CS_GT, KC_RBRC, KC_LBRC, CS_TILD, CS_QUES,  KC_ENT,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              CS_SLSH,  CS_AL2,  KC_SPC,    _______, _______, _______
                                          //`--------------------------'  `--------------------------'
    ),

    [_PROGRAM] = LAYOUT( //7
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
           KC_GRV, CS_PERC, CS_EXLM, CS_DQUO,  CS_DLR, CS_COLN,                       CS_EQL, KC_RCBR, KC_LCBR, CS_CIRC, CS_SCLN,  KC_DEL,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          _______, CS_CIRC, CS_PLUS, CS_MINS,  CS_EQL, CS_PIPE,                        CS_LT, KC_RPRN, KC_LPRN, CS_UNDS, CS_EXLM, TAB_SFT,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          _______, CS_TILD, CS_ASTR, CS_SLSH, CS_HASH, CS_AMPR,                        CS_GT, KC_RBRC, KC_LBRC, CS_TILD, CS_QUES,  KC_ENT,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              CS_UNDS,  CS_AL3,  KC_SPC,    _______, _______, _______
                                          //`--------------------------'  `--------------------------'
    ),

    [_EDIT] = LAYOUT( //8
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
          _______, KC_PAUS, CS_HOME,   KC_UP,  CS_END,  KC_TAB,                       CS_EQL, KC_RCBR, KC_LCBR, CS_CIRC, CS_SCLN,  KC_DEL,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          _______,  KC_INS, KC_LEFT, KC_DOWN, KC_RGHT,  KC_DEL,                        CS_LT, MT_RPRN, MT_LPRN, MT_UNDS, CS_EXLM, TAB_SFT,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          _______, KC_PSCR, KC_PGUP, KC_PGDN, KC_CAPS,  SELECT,                        CS_GT, MT_RBRC, KC_LBRC, CS_TILD, CS_QUES,  KC_ENT,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              _______, _______, _______,    _______,    KC_0,  KC_SPC
                                          //`--------------------------'  `--------------------------'
    ),

    [_MOUSE] = LAYOUT( //9
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
          _______, XXXXXXX, KC_BTN4,   MS_UP, KC_BTN5,  KC_TAB,                      _______, _______, _______, _______, _______, _______,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          _______, XXXXXXX, MS_LEFT, MS_DOWN, MS_RGHT,  KC_DEL,                      _______, _______, _______, _______, _______, _______,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          _______, MS_WHLL, MS_WHLU, MS_WHLD, MS_WHLR,  SELECT,                      _______, _______, _______, _______, _______, _______,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              MS_BTN3, MS_BTN2, MS_BTN1,    MS_ACL0, MS_ACL1, MS_ACL2
                                          //`--------------------------'  `--------------------------'
    ),

    // [_MOUSE_BTN] = LAYOUT( //10
    //   //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    //       _______, _______, KC_BTN4, _______, KC_BTN5,  KC_TAB,                      _______, _______, _______, _______, _______, _______,
    //   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    //       _______, _______, _______, _______, _______,  KC_DEL,                      _______, _______, _______, _______, _______, _______,
    //   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    //       _______, _______, _______, _______, _______,  SELECT,                      _______, _______, _______, _______, _______, _______,
    //   //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
    //                                           KC_BTN3, KC_BTN2, KC_BTN1,    _______, _______, _______
    //                                       //`--------------------------'  `--------------------------'
    // ),

    [_NUMPAD] = LAYOUT( //11
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
          _______, _______, _______, _______, _______, _______,                       KC_NUM,   KC_P7,   KC_P8,   KC_P9, KC_CIRC,  KC_DEL,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          _______, _______, _______, _______, _______, _______,                      KC_PLUS,   KC_P4,   KC_P5,   KC_P6, KC_ASTR, TAB_SFT,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          _______, _______, _______, _______, _______, _______,                      KC_MINS,   KC_P1,   KC_P2,   KC_P3, KC_UNDS,  KC_ENT,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              _______, _______, _______,    _______,   KC_P0, _______
                                          //`--------------------------'  `--------------------------'
    ),
    
    [_UTILITY] = LAYOUT( //12
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
           ALTTAB, CLOCKUP, CS_VALD, CS_VOLU, CS_VALU, CS_RGBN,                      CS_BOOT,   KC_F7,   KC_F8,   KC_F9,  KC_F10, DB_TOGG,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          _______, CLOCKDN, KC_MPRV, CS_VOLD, KC_MNXT,    BASE,                        BASIC,   KC_F1,   KC_F2,   KC_F3,  KC_F11, TAB_SFT,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          _______, CLOCKNX, OLEDSAV,    MUTE, KC_SCRL,    MENU,                      CS_RGBT,   KC_F4,   KC_F5,   KC_F6,  KC_F12,  KC_ENT,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              KC_MSTP,  MUTE_L, KC_MPLY,    KC_MPLY,  MUTE_R, KC_MSTP
                                          //`--------------------------'  `--------------------------'
    ),

    [_TOUHOU] = LAYOUT( //13
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

uint8_t time_setting = 0;
uint8_t min = 0;
uint8_t hrs = 0;
uint8_t sec = 0;

// uint8_t t_min = 0;
// uint8_t t_hrs = 0;
// uint8_t t_sec = 0;

uint8_t menu = 0;

bool static_display = false;

bool left_active = false;
bool right_active = false;
bool muted = false;

uint8_t set_rgb_mode = 5;

bool ctrl_linger = false;

bool ctrl_on(void) {
    return ((get_mods() & MOD_BIT(KC_LCTL)) == MOD_BIT(KC_LCTL) || (get_mods() & MOD_BIT(KC_RCTL)) == MOD_BIT(KC_RCTL));
}

bool shifted(void) {
    return ((get_mods() & MOD_BIT(KC_LSFT)) == MOD_BIT(KC_LSFT) || (get_mods() & MOD_BIT(KC_RSFT)) == MOD_BIT(KC_RSFT));
}

bool is_alpha(uint16_t keycode) {
    if (keycode >= KC_A && keycode <= KC_Z) {
        return true;
    } else {
        return false;
    }
}

bool is_hrm(uint16_t keycode) {
    switch (keycode) {
        case MT_S:
        case MT_D:
        case MT_F:
        case MT_V:
        case MT_M:
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
            return true;
        default:
            return false;
    }
}

bool is_magic(uint16_t keycode) {
    if ((keycode == CS_LT2) || (keycode == CS_RT2)) {
        return true;
    } else {
        return false;
    }
}

bool is_bspc(uint16_t keycode) {
    if ((keycode == CS_RT1) || (keycode == KC_BSPC)) {
        return true;
    } else {
        return false;
    }
}

bool is_spc(uint16_t keycode) {
    if ((keycode == CS_RT1) || (keycode == KC_SPC)) {
        return true;
    } else {
        return false;
    }
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

#define IDLE_TIMEOUT 1000 * 60 * 5

static bool alt_tab_active = false;
static bool oled_timeout = false;

uint8_t char_count = 1;
uint16_t last_key = KC_NO;
uint16_t last_key_2 = KC_NO;

void matrix_scan_user(void) {
    achordion_task();

    // if (mh_auto_buttons_timer && (timer_elapsed(mh_auto_buttons_timer) > MH_AUTO_BUTTONS_TIMEOUT)) {
    //     if (!tp_buttons) {
    //         layer_off(MH_AUTO_BUTTONS_LAYER);
    //         mh_auto_buttons_timer = 0;
    //     }
    // }

    if (get_highest_layer(layer_state) == _NUMPAD) {
        if (last_input_activity_elapsed() > IDLE_TIMEOUT) { // Layer timeout
            layer_off(_NUMPAD);
            layer_off(_TOUHOU);
        }
    }
    if (alt_tab_active) {
        if (IS_LAYER_OFF(_UTILITY)) {
            unregister_code(KC_LALT);
            alt_tab_active = false;
        }
    }
    if (last_input_activity_elapsed() > 750) { // Reset magic keys
        char_count = 1;
        last_key = KC_NO;
        last_key_2 = KC_NO;
    }
    if (last_input_activity_elapsed() > 15000) { // OLED timeout
        time_setting = 0;
        oled_timeout = true;
    } else {
        oled_timeout = false;
    }
}

//==============================================================================
// Tap/hold
//==============================================================================

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    if (is_hrm(keycode)) {
        return 0;
    }

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

        case MT_RBRC:
        case MT_RPRN:
        case MT_LPRN:
        case MT_UNDS:

        case MT_PLUS:
        case MT_MINS:
        case MT_EQL:
        case MT_COMM:

        case TAB_SFT:
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

        // Shift mod-taps
        case MTA_S:
        case MTA_H:
            return 150;

        // Alt mod-taps
        case MTA_T:
        case MTA_E:
            return 225;

        // GUI mod-taps
        case MTA_R:
        case MTA_I:
            return 250;

        default:
            return TAPPING_TERM;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CS_LT3:
        case CS_LT2:
        // case CS_LT1:

        case CS_RT1:
        // case CS_RT2:
        case CS_RT3:
 
        // case CS_AL1:
        case CS_AL2:
        case CS_AL3:
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    return true;
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
    switch (tap_hold_keycode) {
        case CS_LT3:
        // case CS_LT2:
        case CS_LT1:

        case CS_RT1:
        // case CS_RT2:
        case CS_RT3:

        // case CS_AL1:
        case CS_AL2:
        case CS_AL3:
        
        case CS_BOOT:
            return 0;

        default:
            return 300;
    }
}

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
                     uint16_t other_keycode, keyrecord_t* other_record) {
    if (is_hrm(tap_hold_keycode)) {
        return achordion_opposite_hands(tap_hold_record, other_record);
    }

    switch (tap_hold_keycode) {
        case CS_RT2:
        case CS_AL1:

        case TAB_SFT:
            return achordion_opposite_hands(tap_hold_record, other_record);
        
        case CS_LT2:
        default:
            return true;
    }
}

uint16_t achordion_streak_chord_timeout( uint16_t tap_hold_keycode, uint16_t next_keycode) {
    uint8_t mod = mod_config(QK_MOD_TAP_GET_MODS(tap_hold_keycode));
    if ((next_keycode == CS_LCTL) || (next_keycode == KC_LCTL) || (next_keycode == KC_LSFT) || (next_keycode == TAB_SFT)) {
        return 0;
    }
    if (is_magic(tap_hold_keycode)) {
        return 75;
    }
    if (((mod & MOD_LSFT) != 0) || ((mod & MOD_RSFT) != 0)) {
        return 100;
    }
    return 250;
}

bool achordion_eager_mod(uint8_t mod) {
    switch (mod) {
        case MOD_LSFT:
        case MOD_RSFT:
        case MOD_LCTL:
        case MOD_RCTL:
        // case MOD_LALT:
        // case MOD_RALT:
            return true;

        default:
            return false;
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

    SPC_0,
    SPC_1,
    SPC_2,
    SPC_3,
    SPC_4,
    SPC_5,
    SPC_6,
    SPC_7,
    SPC_8,
    SPC_9,

    BSPC_1,
    BSPC_2,
    BSPC_3,

    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM touhou[]         = {KC_P, CS_HASH, KC_ESC, COMBO_END};
const uint16_t PROGMEM steno[]          = {KC_P, CS_HASH, KC_SCLN, KC_TAB, COMBO_END};
const uint16_t PROGMEM numpad[]         = {KC_O, KC_P, CS_HASH, COMBO_END};
const uint16_t PROGMEM mouse[]          = {KC_SCLN, QUE_EXL, COMBO_END};
const uint16_t PROGMEM mouse2[]         = {KC_TAB, NEWSENT, COMBO_END};

const uint16_t PROGMEM l_exponent[]     = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM l_comma[]        = {KC_D, KC_V, COMBO_END};
const uint16_t PROGMEM l_dot[]          = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM l_underscore[]   = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM l_asterisk[]     = {KC_F, KC_B, COMBO_END};
const uint16_t PROGMEM l_equals[]       = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM l_plus[]         = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM l_minus[]        = {KC_D, KC_F, COMBO_END};

const uint16_t PROGMEM ampersand[]      = {KC_S, KC_E, COMBO_END};
const uint16_t PROGMEM colon[]          = {KC_E, KC_F, COMBO_END};

const uint16_t PROGMEM r_exponent[]     = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM r_comma[]        = {KC_M, KC_K, COMBO_END};
const uint16_t PROGMEM r_dot[]          = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM r_underscore[]   = {KC_M, KC_QUOT, COMBO_END};
const uint16_t PROGMEM r_asterisk[]     = {KC_N, KC_J, COMBO_END};
const uint16_t PROGMEM r_equals[]       = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM r_plus[]         = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM r_minus[]        = {KC_J, KC_K, COMBO_END};

const uint16_t PROGMEM semicolon[]      = {KC_J, KC_I, COMBO_END};
const uint16_t PROGMEM exclamation[]    = {KC_I, KC_L, COMBO_END};

const uint16_t PROGMEM spc_0[]          = {KC_SPC, KC_A, COMBO_END};
const uint16_t PROGMEM spc_1[]          = {KC_SPC, KC_S, COMBO_END};
const uint16_t PROGMEM spc_2[]          = {KC_SPC, KC_D, COMBO_END};
const uint16_t PROGMEM spc_3[]          = {KC_SPC, KC_F, COMBO_END};
const uint16_t PROGMEM spc_4[]          = {KC_SPC, KC_X, COMBO_END};
const uint16_t PROGMEM spc_5[]          = {KC_SPC, KC_C, COMBO_END};
const uint16_t PROGMEM spc_6[]          = {KC_SPC, KC_V, COMBO_END};
const uint16_t PROGMEM spc_7[]          = {KC_SPC, KC_W, COMBO_END};
const uint16_t PROGMEM spc_8[]          = {KC_SPC, KC_E, COMBO_END};
const uint16_t PROGMEM spc_9[]          = {KC_SPC, KC_R, COMBO_END};

const uint16_t PROGMEM bspc_1[]         = {CS_RT1, KC_J, COMBO_END};
const uint16_t PROGMEM bspc_2[]         = {CS_RT1, KC_K, COMBO_END};
const uint16_t PROGMEM bspc_3[]         = {CS_RT1, KC_L, COMBO_END};

const uint16_t PROGMEM num_1[]          = {KC_Q, KC_A, COMBO_END};
const uint16_t PROGMEM num_2[]          = {KC_W, KC_S, COMBO_END};
const uint16_t PROGMEM num_3[]          = {KC_E, KC_D, COMBO_END};
const uint16_t PROGMEM num_4[]          = {KC_R, KC_F, COMBO_END};
const uint16_t PROGMEM num_5[]          = {KC_T, KC_G, COMBO_END};

combo_t key_combos[] = {
    [TOUHOU]        = COMBO_ACTION(touhou),
    [STENO]         = COMBO_ACTION(steno),
    [NUMPAD]        = COMBO_ACTION(numpad),

    [MOUSE]         = COMBO(mouse,         CM_MOUSE),
    [MOUSE2]        = COMBO(mouse2,        CM_MOUSE),

    [SPC_0]         = COMBO(spc_0,         KC_0),
    [SPC_1]         = COMBO(spc_1,         KC_1),
    [SPC_2]         = COMBO(spc_2,         KC_2),
    [SPC_3]         = COMBO(spc_3,         KC_3),
    [SPC_4]         = COMBO(spc_4,         KC_4),
    [SPC_5]         = COMBO(spc_5,         KC_5),
    [SPC_6]         = COMBO(spc_6,         KC_6),
    [SPC_7]         = COMBO(spc_7,         KC_7),
    [SPC_8]         = COMBO(spc_8,         KC_8),
    [SPC_9]         = COMBO(spc_9,         KC_9),
    
    [BSPC_1]        = COMBO(bspc_1,        CM_BSPC_1),
    [BSPC_2]        = COMBO(bspc_2,        CM_BSPC_2),
    [BSPC_3]        = COMBO(bspc_3,        CM_BSPC_3),
    
    [L_EXPONENT]    = COMBO(l_exponent,    CS_CIRC),
    [L_COMMA]       = COMBO(l_comma,       CS_COMM),
    [L_DOT]         = COMBO(l_dot,         CS_DOT),
    [L_UNDERSCORE]  = COMBO(l_underscore,  CS_UNDS),
    [L_ASTERISK]    = COMBO(l_asterisk,    CS_ASTR),
    [L_EQUALS]      = COMBO(l_equals,      CS_EQL),
    [L_PLUS]        = COMBO(l_plus,        CS_PLUS),
    [L_MINUS]       = COMBO(l_minus,       CS_MINS),
    
    [AMPERSAND]     = COMBO(ampersand,     CS_AMPR),
    [COLON]         = COMBO(colon,         CS_COLN),
    
    [R_EXPONENT]    = COMBO(r_exponent,    CS_CIRC),
    [R_COMMA]       = COMBO(r_comma,       CS_COMM),
    [R_DOT]         = COMBO(r_dot,         CS_DOT),
    [R_UNDERSCORE]  = COMBO(r_underscore,  CS_UNDS),
    [R_ASTERISK]    = COMBO(r_asterisk,    CS_ASTR),
    [R_EQUALS]      = COMBO(r_equals,      CS_EQL),
    [R_PLUS]        = COMBO(r_plus,        CS_PLUS),
    [R_MINUS]       = COMBO(r_minus,       CS_MINS),

    [SEMICOLON]     = COMBO(semicolon,     CS_SCLN),
    [EXCLAMATION]   = COMBO(exclamation,   CS_EXLM),
};


void process_combo_event(uint16_t combo_index, bool pressed) {
    switch(combo_index) {
        case TOUHOU:
            if (pressed) {
                menu = 1;
                if (IS_LAYER_ON(_TOUHOU)) {
                    layer_off(_TOUHOU);
                } else {
                    layer_on(_TOUHOU);
                }
            }
            break;
        case NUMPAD:
            if (pressed) {
                if (IS_LAYER_ON(_NUMPAD)) {
                    layer_off(_NUMPAD);
                } else {
                    layer_on(_NUMPAD);
                }
            }
            break;
        case STENO:
            if (pressed) {
                if (IS_LAYER_ON(_STENO)) {
                    layer_off(_STENO);
                } else {
                    layer_on(_STENO);
                }
            }
            break;
    }
}

// 50ms default
uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    switch (index) {
        case SPC_0:
        case SPC_1:
        case SPC_2:
        case SPC_3:
        case SPC_4:
        case SPC_5:
        case SPC_6:
        case SPC_7:
        case SPC_8:
        case SPC_9:

        case BSPC_1:
        case BSPC_2:
        case BSPC_3:

        case L_COMMA:
        case R_COMMA:
        case L_UNDERSCORE:
        case R_UNDERSCORE:
            return 30;

        case L_EXPONENT:
        case R_EXPONENT:
        case L_MINUS:
        case R_MINUS:
            return 15;

        case MOUSE:
        case MOUSE2:
            return 75;

        default:
            return 20;
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

void update_last_key(uint16_t new_keycode) {
    last_key_2 = last_key;
    last_key = new_keycode;

    char_count = 1;

    dprintf("updated keys!\n");
    dprintf("last_key:   %d\n", last_key);
    dprintf("last_key_2: %d\n", last_key_2);
    dprintf("char_count: %d\n", char_count);
}

void update_last_keys(uint16_t new_keycode, uint8_t new_count) {
    last_key_2 = last_key;
    last_key = new_keycode;

    char_count = new_count;
    dprintf("updated multiple keys!\n");
    dprintf("last_key:   %d\n", last_key);
    dprintf("last_key_2: %d\n", last_key_2);
    dprintf("char_count: %d\n", char_count);
}

void rollback_last_key(void) {
    last_key = last_key_2;
    dprintf("rolled back!\n");
    dprintf("last_key:   %d\n", last_key);
    dprintf("last_key_2: %d\n", last_key_2);
    dprintf("char_count: %d\n", char_count);
}

bool process_key_tracking(uint16_t keycode, keyrecord_t* record) {
    // Ignore tracking if ctrl is on and reset rollback counter
    if (ctrl_on()) {
        char_count = 1;
        return true;
    }
    

    // Track alpha keys
    if (is_alpha(keycode)) {
        if (record->event.pressed) {
            update_last_key(keycode);
        }
        return true;
    }
    // Track mod taps
    if (is_hrm(keycode)) {
        if (record->tap.count && record->event.pressed) {
            update_last_key(QK_MOD_TAP_GET_TAP_KEYCODE(keycode));
        }
        return true;
    }

    // Track spaces
    if (keycode == CS_LT1) {
        if (record->tap.count && record->event.pressed) {
            update_last_key(KC_SPC);
        }
        return true;
    }
    if (keycode == KC_SPC) {
        if (record->event.pressed) {
            update_last_key(KC_SPC);
        }
        return true;
    }
    // Track enter key
    if (keycode == KC_ENT) {
        if (record->event.pressed) {
            update_last_key(KC_NO);
        }
        return true;
    }

    // Handle deletes
    if (keycode == CS_RT1) {
        if (record->tap.count && record->event.pressed) {
            rollback_last_key();
            if (!shifted() && !ctrl_on()) {
                for (int i = 1; i < char_count; i++) {
                    tap_code(KC_BSPC);
                }
            }
        char_count = 1;
        }
        return true;
    }
    if (keycode == KC_BSPC) {
        if (record->event.pressed) {
            rollback_last_key();
            if (!shifted() && !ctrl_on()) {
                for (int i = 1; i < char_count; i++) {
                    tap_code(KC_BSPC);
                }
            }
        char_count = 1;
        }
        return true;
    }
    
    // Reset rollback counter and recorded key on any other keypress
    if (!(is_bspc(keycode) || is_spc(keycode) || is_alpha(keycode) || is_hrm(keycode) || is_magic(keycode) || keycode == KC_LSFT)) {
        if (record->event.pressed) {
            char_count = 1;
            last_key = KC_NO;
            last_key_2 = KC_NO;
        }
    }
    return true;
}

void send_the(bool space) {
    if (space) {
        tap_code(KC_SPC);
    }

    if (shifted()) {
        const uint8_t mods = get_mods();
        add_mods(MOD_MASK_SHIFT);
        tap_code(KC_T);
        del_mods(MOD_MASK_SHIFT);
        tap_code(KC_H);
        tap_code(KC_E);
        set_mods(mods);
    } else {
        SEND_STRING("the");
    }
}

bool process_magic(uint16_t keycode, keyrecord_t* record) {
    if (keycode == CS_LT2) {
        if (!record->tap.count && record->event.pressed) {
            layer_on(_EDIT);
        } else {
            layer_off(_EDIT);
        }
        if (record->tap.count && record->event.pressed) {
            if (IS_LAYER_ON(_QWERTY)|| IS_LAYER_ON(_BASIC)) {
                tap_code(last_key);
                update_last_key(last_key);
                return false;
            }

            switch (last_key) {
                // Left hand keys
                case KC_Z: tap_code(KC_N); update_last_key(KC_N); break;
                case KC_L: tap_code(KC_R); update_last_key(KC_R); break;
                case KC_D: tap_code(KC_T); update_last_key(KC_T); break;
                case KC_C: tap_code(KC_S); update_last_key(KC_S); break;
                case KC_B: tap_code(KC_S); update_last_key(KC_S); break;

                case KC_N: SEND_STRING(/*n*/"ion"); update_last_keys(KC_N, 3); break;
                case KC_R: tap_code(KC_L); update_last_key(KC_L); break;
                case KC_T: SEND_STRING(/*t*/"ion"); update_last_keys(KC_N, 3); break;
                case KC_S: tap_code(KC_C); update_last_key(KC_C); break;
                case KC_G: tap_code(KC_S); update_last_key(KC_S); break;
                
                case KC_Q: tap_code(KC_U); update_last_key(KC_U); break;
                case KC_X: tap_code(KC_C); update_last_key(KC_C) ;break;
                case KC_M: SEND_STRING(/*m*/"ent"); update_last_keys(KC_T, 3); break;
                case KC_W: tap_code(KC_S); update_last_key(KC_S); break;
                case KC_V: tap_code(KC_S); update_last_key(KC_S); break;

                // Right hand overrides
                case KC_J: SEND_STRING(/*j*/"ect"); update_last_keys(KC_T, 3); break;
                case KC_Y: SEND_STRING(/*y*/"ou"); update_last_keys(KC_U, 2); break;
                case KC_O: tap_code(KC_E); update_last_key(KC_E); break;
                case KC_H: SEND_STRING(/*h*/"ere"); update_last_keys(KC_E, 3); break;
                case KC_E: tap_code(KC_O); update_last_key(KC_O); break;
                case KC_I: SEND_STRING(/*i*/"um"); update_last_keys(KC_N, 2); break;
                case KC_K: SEND_STRING(/*k*/"ey"); update_last_keys(KC_Y, 2); break;

                case KC_NO:
                case KC_SPC: set_oneshot_mods(MOD_BIT(KC_LSFT)); break;
                case KC_COMM: SEND_STRING(" and"); update_last_keys(KC_D, 3); break;
                case KC_DOT: SEND_STRING("com"); update_last_keys(KC_D, 3); break;

                default: tap_code(last_key); update_last_key(last_key); break;
            }
        }
        return false;
    }

    if (keycode == CS_RT2) {
        if (!record->tap.count && record->event.pressed) {
            layer_on(_PROGRAM);
        } else {
            layer_off(_PROGRAM);
        }
        if (record->tap.count && record->event.pressed) {
            if (IS_LAYER_ON(_QWERTY)|| IS_LAYER_ON(_BASIC)) {
                tap_code(last_key);
                update_last_key(last_key);
                return false;
            }

            switch (last_key) {
                // Right hand keys
                case KC_J: SEND_STRING(/*j*/"ust"); update_last_keys(KC_T, 3); break;
                case KC_F: tap_code(KC_Y); update_last_key(KC_Y); break;
                case KC_O: tap_code(KC_O); update_last_key(KC_O); break;
                case KC_U: tap_code(KC_I); update_last_key(KC_I); break;

                case KC_Y: tap_code(KC_P); update_last_key(KC_P); break;
                case KC_H: tap_code(KC_Y); update_last_key(KC_Y); break;
                case KC_E: tap_code(KC_E); update_last_key(KC_E); break;
                case KC_I: tap_code(KC_U); update_last_key(KC_U); break;
                case KC_A: tap_code(KC_U); update_last_key(KC_U); break;

                case KC_K: tap_code(KC_Y); update_last_key(KC_Y); break;
                case KC_P: tap_code(KC_H); update_last_key(KC_H); break;

                // Left hand overrides
                case KC_Q: tap_code(KC_U); update_last_key(KC_U); break;
                case KC_V: SEND_STRING(/*v*/"er"); update_last_keys(KC_R, 2); break;
                case KC_W: SEND_STRING(/*w*/"ith"); update_last_keys(KC_H, 3); break;

                case KC_NO:
                case KC_SPC: send_the(false); update_last_keys(KC_E, 3); break;
                case KC_COMM: SEND_STRING(" but"); update_last_keys(KC_E, 3); break;
                case KC_DOT: SEND_STRING("com"); update_last_keys(KC_M, 3); break;

                default: tap_code(last_key); update_last_key(last_key); break;
            }
            return false;
        }
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

uint32_t ctrl_linger_callback(uint32_t trigger_time, void *cb_arg) {
    ctrl_linger = false;
    return 0;
}

bool process_lingering_mods(uint16_t keycode, keyrecord_t* record) {
        if (keycode == CS_LCTL) {
            if (record->event.pressed) {
                ctrl_linger = true;
                defer_exec(500, ctrl_linger_callback, NULL);
            }
            return true;
        }
        if (keycode == CS_RT1) {
            if (record->tap.count && record->event.pressed) {
                if (ctrl_linger) {
                    const uint8_t mods = get_mods();
                    register_mods(MOD_BIT(KC_LCTL));
                    tap_code(KC_BSPC);
                    set_mods(mods);
                    ctrl_linger = false;
                    return false;
                }
            }
            return true;
        }
        if (keycode == KC_BSPC) {
            if (ctrl_linger) {
                const uint8_t mods = get_mods();
                register_mods(MOD_BIT(KC_LCTL));
                tap_code(KC_BSPC);
                set_mods(mods);
                ctrl_linger = false;
                return false;
            }
            return true;
        }
        ctrl_linger = false;
        return true;
}

bool VOLD_active = false;
bool VOLU_active = false;
deferred_token VOLD_token = INVALID_DEFERRED_TOKEN;
deferred_token VOLU_token = INVALID_DEFERRED_TOKEN;

#define interval 15

uint32_t VOLD_callback(uint32_t trigger_time, void* cb_arg) {
    if (!VOLD_active) {
        register_code16(KC_VOLD);
        VOLD_active = true;
    } else {
        unregister_code16(KC_VOLD);
        VOLD_active = false;
    }
    return interval;
}
uint32_t VOLU_callback(uint32_t trigger_time, void* cb_arg) {
    if (!VOLU_active) {
        register_code16(KC_VOLU);
        VOLU_active = true;
    } else {
        unregister_code16(KC_VOLU);
        VOLU_active = false;
    }
    return interval * 1.5;
}

void VOLD_start(void) {
    if (VOLD_token == INVALID_DEFERRED_TOKEN) {
        uint32_t delay = VOLD_callback(0, NULL);
        VOLD_token = defer_exec(delay, VOLD_callback, NULL);
    }
}
void VOLU_start(void) {
    if (VOLU_token == INVALID_DEFERRED_TOKEN) {
        uint32_t delay = VOLU_callback(0, NULL);
        VOLU_token = defer_exec(delay, VOLU_callback, NULL);
    }
}

void VOLD_stop(void) {
    if (VOLD_token != INVALID_DEFERRED_TOKEN) {
        cancel_deferred_exec(VOLD_token);
        VOLD_token = INVALID_DEFERRED_TOKEN;
        if (VOLD_active) {
            unregister_code16(KC_VOLD);
            VOLD_active = false;
        }
    }
}
void VOLU_stop(void) {
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
            } else {
                VOLD_start();
            }
        } else {
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
            } else {
                VOLU_start();
            }
        } else {
            VOLU_stop();
            unregister_code16(KC_VOLU);
        }
        return false;
    }
    return true;
}



//==============================================================================
// Clock
//==============================================================================

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
            } else if (time_setting == 2) {
                if (min == 60) {
                    min = 0;
                } else {
                    min++;
                }
            } else if (time_setting == 3) {
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
            } else if (time_setting == 2) {
                if (min == 0) {
                    min = 59;
                } else {
                    min--;
                }
            } else if (time_setting == 3) {
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
                } else {
                    time_setting--;
                }
            } else {
                if (time_setting == 3) {
                    time_setting = 0;
                } else {
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
    } else if (time_setting == 2) {
        oled_set_cursor(shift+3,line-1);
        oled_write_char(148,false);
        oled_write_char(149,false);
        oled_set_cursor(shift+3,line+1);
        oled_write_char(180,false);
        oled_write_char(181,false);
    } else if (time_setting == 3) {
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
    if (!process_key_tracking(keycode, record)) { return false; }
    if (!process_magic(keycode, record)) { return false; }
    if (!process_cs_layer_tap(keycode, record)) { return false; }
    if (!process_lingering_mods(keycode, record)) { return false; }
    if (!process_select_word(keycode, record, SELECT)) { return false; }
    if (!process_vol_repeat(keycode, record)) { return false; }
    if (!process_clock(keycode, record)) { return false; }

    switch (keycode) {

        // =====================================================================
        // Layer-taps
        // =====================================================================

        case CS_LT3:
            if (record->event.pressed) {
                left_active = true;
            } else {
                left_active = false;
            }
            return true;
        case CS_RT3:
            if (record->event.pressed) {
                right_active = true;
            } else {
                right_active = false;
            }
            return true;


        // =====================================================================
        // Misc control
        // =====================================================================
            

        case MUTE:
            if (record->event.pressed) {
                register_code(KC_MUTE);
                muted = !muted;
            } else {
                unregister_code(KC_MUTE);
            }
            break;

        case MUTE_L:
            if (record->event.pressed && right_active) {
                register_code(KC_MUTE);
                muted = !muted;
            } else {
                unregister_code(KC_MUTE);
            }
            break;

        case MUTE_R:
            if (record->event.pressed && left_active) {
                register_code(KC_MUTE);
                muted = !muted;
            } else {
                unregister_code(KC_MUTE);
            }
            break;

        case MENU:
            if (record->event.pressed) {
                if (menu == 0) {
                    menu = 1;
                } else if (menu == 1) {
                    menu = 0;
                }
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
                if (IS_LAYER_ON(_QWERTY)) {  // QWERTY -> BASE
                    layer_off(_QWERTY);
                    layer_on(_BASE);
                } else if (IS_LAYER_ON(_BASE)) {  // BASE -> QWERTY
                    layer_off(_BASE);
                    layer_on(_QWERTY);
                } else {  // BASIC -> QWERTY
                    layer_off(_BASIC);
                    layer_on(_QWERTY);
                }
            }
            break;
        case BASIC:
            if (record->event.pressed) {
                if (IS_LAYER_ON(_QWERTY)) { // QWERTY -> BASIC
                    layer_off(_QWERTY);
                    layer_on(_BASIC);
                } else if (IS_LAYER_ON(_BASE)) { // BASE -> BASIC
                    layer_off(_BASE);
                    layer_on(_BASIC);
                } else { // BASIC -> BASE
                    layer_off(_BASIC);
                    layer_on(_BASE);
                }
            }
            break;

        case CS_BOOT:
            if (!record->tap.count && record->event.pressed) {
                reset_keyboard();
            }
            if (record->tap.count && record->event.pressed) {
                soft_reset_keyboard();
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
        case CS_QUOT:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code(KC_QUOT);
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
                update_last_key(KC_DOT);
            }
            break;
        case CS_COMM:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code(KC_COMM);
                set_mods(mods);
                update_last_key(KC_COMM);
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
                } else {
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
                } else {
                    const uint8_t mods = get_mods();
                    del_mods(MOD_MASK_SHIFT);
                    tap_code16(KC_QUES);
                    set_mods(mods);
                }
            }
            break;

        case APO_QUO:
            if (record->event.pressed) {
                if (shifted()) {
                    const uint8_t mods = get_mods();
                    del_mods(MOD_MASK_SHIFT);
                    tap_code16(KC_AT);
                    set_mods(mods);
                } else {
                    const uint8_t mods = get_mods();
                    del_mods(MOD_MASK_SHIFT);
                    tap_code16(KC_QUOT);
                    set_mods(mods);
                }
            }
            break;

        case MINS_AT:
            if (record->event.pressed) {
                if (shifted()) {
                    const uint8_t mods = get_mods();
                    del_mods(MOD_MASK_SHIFT);
                    tap_code16(KC_DQUO);
                    set_mods(mods);
                } else {
                    const uint8_t mods = get_mods();
                    del_mods(MOD_MASK_SHIFT);
                    tap_code(KC_MINS);
                    set_mods(mods);
                }
            }
            break;

        case NEWSENT:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                SEND_STRING(". ");
                set_mods(mods);
                add_oneshot_mods(MOD_BIT(KC_LSFT));
                update_last_key(KC_SPC);
            }
            break;

        // =====================================================================
        // Mod-taps
        // =====================================================================

        // Edit layer
        case MT_RBRC:
            if (!record->tap.count && record->event.pressed) {
                register_mods(MOD_BIT(KC_RCTL));
            } else {
                unregister_mods(MOD_BIT(KC_RCTL));
            }
            if (record->tap.count && record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code16(KC_RBRC);
                set_mods(mods);
            }
            return false;

        case MT_RPRN:
            if (!record->tap.count && record->event.pressed) {
                register_mods(MOD_BIT(KC_RSFT));
            } else {
                unregister_mods(MOD_BIT(KC_RSFT));
            }
            if (record->tap.count && record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code16(KC_RPRN);
                set_mods(mods);
            }
            return false;

        case MT_LPRN:
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

        case MT_UNDS:
            if (!record->tap.count && record->event.pressed) {
                register_mods(MOD_BIT(KC_RGUI));
            } else {
                unregister_mods(MOD_BIT(KC_RGUI));
            }
            if (record->tap.count && record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code16(KC_UNDS);
                set_mods(mods);
            }
            return false;



        // Data layer
        case MT_COMM:
            if (!record->tap.count && record->event.pressed) {
                register_mods(MOD_BIT(KC_LCTL));
            } else {
                unregister_mods(MOD_BIT(KC_LCTL));
            }
            if (record->tap.count && record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code(KC_COMM);
                set_mods(mods);
            }
            return false;

        case MT_EQL:
            if (!record->tap.count && record->event.pressed) {
                register_mods(MOD_BIT(KC_LSFT));
            } else {
                unregister_mods(MOD_BIT(KC_LSFT));
            }
            if (record->tap.count && record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code(KC_EQL);
                set_mods(mods);
            }
            return false;

        case MT_MINS:
            if (!record->tap.count && record->event.pressed) {
                register_mods(MOD_BIT(KC_LALT));
            } else {
                unregister_mods(MOD_BIT(KC_LALT));
            }
            if (record->tap.count && record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code(KC_MINS);
                set_mods(mods);
            }
            return false;

        case MT_PLUS:
            if (!record->tap.count && record->event.pressed) {
                register_mods(MOD_BIT(KC_LGUI));
            } else {
                unregister_mods(MOD_BIT(KC_LGUI));
            }
            if (record->tap.count && record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code16(KC_PLUS);
                set_mods(mods);
            }
            return false;

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
        case CM_BSPC_1:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_CSAG);
                add_mods(MOD_MASK_CTRL);
                tap_code(KC_BSPC);
                set_mods(mods);
            }
            break;
        case CM_BSPC_2:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_CSAG);
                tap_code(KC_END);
                add_mods(MOD_MASK_CTRL);
                tap_code(KC_DEL);
                del_mods(MOD_MASK_CTRL);
                tap_code(KC_SPC);
                set_mods(mods);
            }
            break;
        case CM_BSPC_3:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_CSAG);
                tap_code(KC_END);
                tap_code(KC_ENT);
                set_mods(mods);
            }
            break;
    }
    return true;
}

//==============================================================================
// OLED
//==============================================================================

//------------
// WPM
//------------

bool wpm_keycode_user(uint16_t keycode) {
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX) || (keycode >= QK_MODS && keycode <= QK_MODS_MAX)) {
        keycode = keycode & 0xFF;
    } else if (keycode > 0xFF) {
        keycode = 0;
    }
    
    switch (keycode) {
        case KC_A ... KC_0:
        case KC_TAB ... KC_NUBS:
        case COM_DOT ... CS_LPRN:
        case MAGIC:
        case REP:
        case NEWSENT:
            return true;
    }

    return false;
}


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

bool minor = true;
bool major = false;
uint8_t frame_count = 15;
uint16_t render_timer;
uint16_t anim_timer = 0;
bool show_text = true;

#include "frames.c"

uint8_t clean_frame = 0;

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
    if (IS_LAYER_ON(_NUMPAD)) {
        oled_write_P(PSTR(" Numpad\n"), false);
    } else if (IS_LAYER_ON(_TOUHOU)) {
        oled_write_P(PSTR(" Touhou\n"), false);
    } else if (IS_LAYER_ON(_STENO)) {
        oled_write_P(PSTR(" Steno.\n"), false);
    } else if (IS_LAYER_ON(_QWERTY)) {
        oled_write_P(PSTR(" QWERTY\n"), false);
    } else if (IS_LAYER_ON(_BASE)) {
        oled_write_P(PSTR(" Base\n"), false);
    } else {
        oled_write_P(PSTR(" Basic\n"), false);
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
    // if (IS_LAYER_ON(_MOUSE) || IS_LAYER_ON(_MOUSE_BTN)) {
    if (IS_LAYER_ON(_MOUSE)) {
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



bool oneshot_shift_on = false;
void oneshot_mods_changed_user(uint8_t mods) {
    if (mods & MOD_MASK_SHIFT) {
        oneshot_shift_on = true;
    } else {
        oneshot_shift_on = false;
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
    } else if (led_usb_state.caps_lock && led_usb_state.scroll_lock) {
        oled_write_char(207,false);
    } else if (!led_usb_state.caps_lock && led_usb_state.scroll_lock) {
        oled_write_char(208,false);
    } else {
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
    } else if (led_usb_state.scroll_lock && led_usb_state.num_lock) {
        oled_write_char(212,false);
        oled_write_char(213,false);
    } else if (!led_usb_state.scroll_lock && led_usb_state.num_lock) {
        oled_write_char(199,false);
        oled_write_char(214,false);
    } else {
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
    if ((get_mods() & MOD_MASK_SHIFT) || oneshot_shift_on) {
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
        default:
            oled_write_raw_P(menu_layout_base, frame_size);
            break;
        case _BASIC:
        case _QWERTY:
            oled_write_raw_P(menu_layout_qwerty, frame_size);
            break;
        case _STENO:
            oled_write_raw_P(menu_layout_steno, frame_size);
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
        case _UTILITY:
            oled_write_raw_P(menu_layout_utility, frame_size);
            break;
        case _TOUHOU:
            oled_write_raw_P(menu_layout_touhou, frame_size);
            break;
        case _NUMPAD:
            oled_write_raw_P(menu_layout_numpad, frame_size);
            break;
    }
}

void render_status(void) {
    if (menu == 0) {
        oled_set_cursor(0,3);
        oled_write_ln_P(PSTR("Layer:"), false); // 1
        render_layer(); // 7
    } else if (menu == 1) {
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
        } else {
            render_status();
        }
    } else {
        if (static_display || sync_data.static_display_sync) {
            /* intentionally blank */;
            // oled_write_raw_P(static_left, frame_size);
        } else {
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
    if (IS_LAYER_ON_STATE(state, _BASIC) || IS_LAYER_ON_STATE(state, _QWERTY)) {
        rgb_matrix_set_speed_noeeprom(48);
        rgb_matrix_mode_noeeprom(RGB_MATRIX_RAINBOW_PINWHEELS);
        rgb_matrix_sethsv_noeeprom(255,225,255);
    } else if (IS_LAYER_ON_STATE(state, _BASE)) {
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
    } else { // slave side
        if (sync_data.static_display_sync) { 
            oled_write_raw_P(static_left, frame_size);
        } else {
            // render_draw();
        }
        if (sync_data.oled_timeout_sync) { 
            oled_off();
        } else {
            oled_on();
        }
    }
}
