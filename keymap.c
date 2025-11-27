#include QMK_KEYBOARD_H
#include "print.h"
#include "version.h"
#include "raw_hid.h"

// #include "ps2_mouse.h"
// #include "ps2.h"

enum corne_layers {
    _QWERTY,
    _BASIC,
    _BASE,
    _CONTROL,
    _STENO,
    _DATA,
    _PROGRAM,
    _SYMBOL,
    _TRACKBALL,
    _CONTROL_OVERLAY,
    _EDIT,
    _EDIT_OVERLAY,
    _DATA_OVERLAY,
    _NUMPAD,
    _TOUHOU,
    _MOUSE,
    // _MOUSE_BTN,
    _UTILITY,
};

enum custom_keycodes {
    REP = QK_USER,
    MAGIC,
    NEWSENT,
    PCTLEFT,
    PCTRGHT,

    CS_CASE,
    ALTTAB,
    BASIC,
    BASE,
    MENU,

    CS_END,
    CS_HOME,
    SELLEFT,
    SELECT,
    SELRGHT,
    NAVTABS,
    COMMENT,

    MUTE,
    MUTE_L,
    MUTE_R,
    CS_VOLD,
    CS_VOLU,

    CS_RGBN,
    CS_RGBT,

    CLOCKUP,
    CLOCKDN,
    CLOCKNX,

    OLEDSAV,
    OLEDTOG,

    DB_INFO,

    CAPSWRD,

    COM_EXL,
    DOT_QUE,
    APO_QUO,
    CS_CONJ,
    CS_DISJ,

    // Custom Symbols Basic
    CS_SYMBOLS_START,

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
    CS_AT,
    CS_DQUO,
    CS_POUN,
    CS_BSLS,
    CS_QUES,

    CS_LCBR,
    CS_RCBR,
    CS_LPRN,
    CS_RPRN,

    // 
    CS_HASH,
    CS_SLSH,
    CS_EQL,
    CS_QUOT,
    CS_MINS,
    CS_DOT,
    CS_COMM,
    CS_SCLN,

    CS_LBRC,
    CS_RBRC,

    CS_SYMBOLS_END,

    // Edit overlay keys
    WRAPCBR,
    WRAPPRN,
    WRAPBRC,

    SPC_DN,
    JOIN,
    SPC_UP,

    EO_HOME,
    EO_END,
    EO_ENT,

    // Cycling macros
    CY_MISC,
    CY_BRC,
    CY_COMP,
    CY_WRAP,
    CY_ENUM,

    // Trackball
    TB_LOFF,
    TB_TVOL,
    TB_TOGG,
    SCROLL,

};

#define TB_M LT(0, KC_M)
#define TB_D LT(0, KC_D)

// Home row mods
#define LG_N LGUI_T(KC_N)
#define LA_R LALT_T(KC_R)
#define LC_T LCTL_T(KC_T)
#define LS_S LSFT_T(KC_S)

#define RS_H RSFT_T(KC_H)
#define RC_E RCTL_T(KC_E)
#define RA_I LALT_T(KC_I)
#define RG_A RGUI_T(KC_A)

// Symbol home row mods
#define RS_RPRN RSFT_T(KC_RPRN)
#define RC_LPRN RCTL_T(KC_LPRN)
#define RA_TILD LALT_T(KC_TILD)
#define RG_UNDS LGUI_T(KC_UNDS)

#define RS_1 RSFT_T(KC_1)
#define RC_2 RCTL_T(KC_2)
#define RA_3 LALT_T(KC_3)
#define RG_0 LGUI_T(KC_0)

// Data home row mods
#define LG_EXLM LGUI_T(KC_EXLM)
#define LA_COLN LALT_T(KC_COLN)
#define LC_DOT  LCTL_T(KC_DOT)
#define LS_COMM LSFT_T(KC_COMM)

// Edit overlay home row mods
#define RS_DELL RSFT_T(KC_BSPC)
#define RC_DELW RCTL_T(KC_BSPC)
#define RA_DELR LALT_T(KC_DEL)
#define RG_DEL  RGUI_T(KC_DEL)

// Layer keys
#define CS_LT3 LT(_UTILITY,KC_ENT)
#define CS_LT2 LT(_EDIT,MAGIC)
#define CS_LT1 LT(_DATA,KC_SPC)

#define CS_RT1 LT(_SYMBOL,KC_BSPC)
#define CS_RT2 LT(_PROGRAM,REP)
#define CS_RT3 LT(_UTILITY,KC_SLSH)

#define CS_AL1 LT(_PROGRAM,KC_0)
#define CS_AL2 LT(_EDIT,CS_BSLS)
#define CS_AL3 LT(_EDIT,KC_NUBS)
#define CS_AL4 LT(_EDIT_OVERLAY,KC_0)

// Custom tap-hold keys
#define CS_BOOT LT(0,KC_ESC)
#define TABLSFT LSFT_T(KC_TAB)
#define TABRSFT RSFT_T(KC_TAB)

// Control keys
#define CS_LCTL LM(_CONTROL, MOD_LCTL)

#define UNDO    LCTL(KC_Z)
#define REDO    LCTL(KC_Y)
#define CUT     LCTL(KC_X)
#define COPY    LCTL(KC_C)
#define PASTE   LCTL(KC_V)
#define FIND    LCTL(KC_F)
#define SAVE    LCTL(KC_S)
#define ALL     LCTL(KC_A)
#define CLOSE   LCTL(KC_W)
#define NEWTAB  LCTL(KC_T)
#define WINDOW  LCTL(KC_N)
#define REFRESH LCTL(KC_R)
#define MERGE   LCTL(KC_E)
#define BOLD    LCTL(KC_B)
#define GROUP   LCTL(KC_G)
#define LEVEL   LCTL(KC_L)
#define DUPL    LCTL(KC_J)

// Other
#define OSMLSFT OSM(MOD_LSFT)

static inline uint16_t cs_map(uint16_t keycode) {
    switch (keycode) { 
        case CS_COLN:
            return KC_COLN;
        case CS_UNDS:
            return KC_UNDS;
        case CS_PIPE:
            return LSFT(KC_NUBS);
        case CS_LT:
            return KC_LT;
        case CS_GT:
            return KC_GT;
        case CS_PERC:
            return KC_PERC;
        case CS_ASTR:
            return KC_ASTR;
        case CS_DLR:
            return KC_DLR;
        case CS_AMPR:
            return KC_AMPR;
        case CS_CIRC:
            return KC_CIRC;
        case CS_EXLM:
            return KC_EXLM;
        case CS_TILD:
            return LSFT(KC_NUHS);
        case CS_PLUS:
            return KC_PLUS;
        case CS_DQUO:
            return KC_AT;
        case CS_POUN:
            return KC_HASH;
        case CS_BSLS:
            return KC_NUBS;
        case CS_QUES:
            return KC_QUES;
        case CS_LCBR:
            return KC_LCBR;
        case CS_RCBR:
            return KC_RCBR;
        case CS_HASH:
            return KC_NUHS;
        case CS_SLSH:
            return KC_SLSH;
        case CS_EQL:
            return KC_EQL;
        case CS_QUOT:
            return KC_QUOT;
        case CS_MINS:
            return KC_MINS;
        case CS_DOT:
            return KC_DOT;
        case CS_COMM:
            return KC_COMM;
        case CS_SCLN:
            return KC_SCLN;
        case CS_LBRC:
            return KC_LBRC;
        case CS_RBRC:
            return KC_RBRC;
        case CS_RPRN:
            return KC_RPRN;
        case CS_LPRN:
            return KC_LPRN;

        case RC_LPRN:
            return CS_LPRN;
        case LA_COLN:
            return CS_COLN;
        case RG_UNDS:
            return CS_UNDS;
        case LG_EXLM:
            return CS_EXLM;
        case RA_TILD:
            return CS_TILD;
        case LC_DOT:
            return CS_DOT;
        case LS_COMM:
            return CS_COMM;
        case RS_RPRN:
            return CS_RPRN;

        case RS_1:
            return KC_1;
        case RC_2:
            return KC_2;
        case RA_3:
            return KC_3;
        case RG_0:
            return KC_0;
        default:
            return keycode;
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT( //0
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
           KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, CS_HASH,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, TABRSFT,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_QUOT, COM_EXL, DOT_QUE, CS_CASE,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                               CS_LT3,  CS_LT2,  KC_SPC,     CS_RT1,  CS_RT2,  CS_RT3
    ),

    [_BASIC] = LAYOUT( //1
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
           KC_ESC,    KC_Z,    KC_L,    KC_D,    KC_C,    KC_B,                         KC_J,    KC_F,    KC_O,    KC_U, KC_SCLN, CS_HASH,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          KC_LSFT,    KC_N,    KC_R,    KC_T,    KC_S,    KC_G,                         KC_Y,    KC_H,    KC_E,    KC_I,    KC_A, TABRSFT,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          KC_LCTL,    KC_Q,    KC_X,    KC_M,    KC_W,    KC_V,                         KC_K,    KC_P, PCTLEFT, PCTRGHT, DOT_QUE, CS_CASE,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                               CS_LT3,  CS_LT2,  KC_SPC,     CS_RT1,  CS_RT2,  CS_RT3
                                          //`--------------------------'  `--------------------------'
    ),

    [_BASE] = LAYOUT( //2
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
           KC_ESC,    KC_Z,    KC_L,    TB_D,    KC_C,    KC_B,                         KC_J,    KC_F,    KC_O,    KC_U, KC_SCLN, CS_HASH,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          TABLSFT,    LG_N,    LA_R,    LC_T,    LS_S,    KC_G,                         KC_Y,    RS_H,    RC_E,    RA_I,    RG_A, TABRSFT,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          CS_LCTL,    KC_Q,    KC_X,    TB_M,    KC_W,    KC_V,                         KC_K,    KC_P, PCTLEFT, PCTRGHT, DOT_QUE, CS_CASE,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                               CS_LT3,  CS_LT2,  CS_LT1,     CS_RT1,  CS_RT2,  CS_RT3
                                          //`--------------------------'  `--------------------------'
    ),

    [_CONTROL] = LAYOUT( //3
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
          _______,   LEVEL,   MERGE,   CLOSE, REFRESH,  NEWTAB,                      _______, _______, _______, _______, _______, _______,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          _______,    DUPL,     ALL,    SAVE,    FIND,  WINDOW,                      _______, _______, _______, _______, _______, _______,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          _______,    REDO,    UNDO,     CUT,    COPY,   PASTE,                      _______, _______, _______, _______, _______, _______,
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
                                              _______,   STN_A,   STN_O,      STN_E,   STN_U, _______
                                          //`--------------------------'  `--------------------------'
    ),

    [_DATA] = LAYOUT( //5
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
          _______, CS_PERC, CS_MINS, CS_PLUS,  CS_DLR, CS_AMPR,                      CY_MISC,    KC_7,    KC_8,    KC_9,  CS_EQL,  KC_DEL,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          OSMLSFT, LG_EXLM, LA_COLN,  LC_DOT, LS_COMM, CS_PIPE,                       CY_BRC,    RS_1,    RC_2,    RA_3, RG_UNDS, TABRSFT,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          CS_LCTL, CS_CIRC, CS_SLSH, CS_ASTR, CS_HASH, CS_TILD,                      CY_COMP,    KC_4,    KC_5,    KC_6, CS_QUES,  KC_ENT,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              _______, _______, _______,    _______,  CS_AL1, KC_SLSH
                                          //`--------------------------'  `--------------------------'
    ),

    [_SYMBOL] = LAYOUT( //6
      //,-----------------------------------------------------.                    ,---------------------------------------------------.
           KC_GRV,  CS_DLR, CS_EXLM, CS_DQUO, CS_AMPR, CS_HASH,                      CY_MISC, CS_RCBR, CS_LCBR, CS_CIRC, KC_SCLN,  KC_DEL,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          OSMLSFT, CS_PIPE,   CS_LT, CS_MINS,   CS_GT,  CS_EQL,                      CY_ENUM, RS_RPRN, RC_LPRN, RA_TILD, RG_UNDS, TABRSFT,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          CS_LCTL, CS_CIRC, CS_COLN,  CS_DOT, CS_COMM, CS_TILD,                      CY_COMP, CS_RBRC, CS_LBRC, CS_EXLM, CS_QUES,  KC_ENT,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              CS_SLSH,  CS_AL2, _______,    _______, _______, _______
                                          //`--------------------------'  `--------------------------'
    ),

    [_PROGRAM] = LAYOUT( //7
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
           KC_GRV, CS_PERC, CS_MINS, CS_PLUS,  CS_DLR, CS_CONJ,                      CY_MISC, CS_RCBR, CS_LCBR, CS_CIRC, KC_SCLN,  KC_DEL,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          OSMLSFT, CS_EXLM,   CS_LT,   CS_GT,  CS_EQL, CS_DISJ,                      CY_ENUM, RS_RPRN, RC_LPRN, RA_TILD, RG_UNDS, TABRSFT,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          CS_LCTL, CS_CIRC, CS_SLSH, CS_ASTR, CS_HASH, CS_TILD,                      CY_COMP, CS_RBRC, CS_LBRC, CS_EXLM, CS_QUES,  KC_ENT,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              CS_SLSH,  CS_AL3, _______,    _______, _______, _______
                                          //`--------------------------'  `--------------------------'
    ),

    [_TRACKBALL] = LAYOUT( //8
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
          _______, NAVTABS, MS_BTN4,  SCROLL, MS_BTN5, QK_LLCK,                      _______, _______, _______, _______, _______, _______,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          _______, _______, MS_BTN3, MS_BTN2, MS_BTN1,  KC_DEL,                      _______, _______, _______, _______, _______, _______,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          CS_LCTL, TB_LOFF, _______,  SCROLL, _______,  KC_ENT,                      _______, _______, _______, _______, _______, _______,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              _______, _______,  SCROLL,    MS_ACL2, MS_ACL0, MS_ACL1
                                          //`--------------------------'  `--------------------------'
    ),

    [_CONTROL_OVERLAY] = LAYOUT( //9
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
          _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          _______,    REDO,    UNDO,     CUT,    COPY,   PASTE,                      _______, _______, _______, _______, _______, _______,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              _______, _______, _______,    _______, _______, _______
                                          //`--------------------------'  `--------------------------'
    ),

    [_EDIT] = LAYOUT( //10
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
          _______, NAVTABS, CS_HOME,   KC_UP,  CS_END, QK_LLCK,                      CY_MISC, CS_RCBR, CS_LCBR, CS_CIRC, KC_SCLN,  KC_DEL,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          _______, COMMENT, KC_LEFT, KC_DOWN, KC_RGHT,  KC_DEL,                      CY_ENUM, RS_RPRN, RC_LPRN, RA_TILD, RG_UNDS, TABRSFT,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          _______, CY_WRAP, SELLEFT,  SELECT, SELRGHT,  EO_ENT,                      CY_COMP, CS_RBRC, CS_LBRC, CS_EXLM, CS_QUES,  KC_ENT,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              _______, _______, _______,    _______,  CS_AL4,  KC_SPC
                                          //`--------------------------'  `--------------------------'
    ),

    [_EDIT_OVERLAY] = LAYOUT( //11
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
          _______, KC_PGUP, EO_HOME,   KC_UP,  EO_END, KC_CAPS,                       KC_ESC,  SPC_UP,    JOIN,  SPC_DN, WRAPCBR, _______,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          _______, COMMENT, KC_LEFT, KC_DOWN, KC_RGHT,  KC_DEL,                      KC_BSPC, RS_DELL, RC_DELW, RA_DELR, WRAPPRN, _______,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          _______, KC_PGDN, SELLEFT,  SELECT, SELRGHT,  EO_ENT,                       KC_SPC,   PASTE,     CUT,    COPY, WRAPBRC, _______,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              _______, _______, _______,    _______, _______, _______
                                          //`--------------------------'  `--------------------------'
    ),

    [_DATA_OVERLAY] = LAYOUT( //12
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
          _______, _______, _______, _______, _______, KC_CAPS,                      CY_MISC,    KC_7,    KC_8,    KC_9,  CS_EQL,  KC_DEL,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          _______, _______, _______, _______, _______, _______,                       CY_BRC,    RS_1,    RC_2,    RA_3,    RG_0, TABRSFT,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          _______, _______, _______, _______, _______, _______,                      CY_COMP,    KC_4,    KC_5,    KC_6, CS_TILD,  KC_ENT,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              _______, _______, _______,    _______, _______, KC_SLSH
                                          //`--------------------------'  `--------------------------'
    ),

    [_NUMPAD] = LAYOUT( //13
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
          _______, _______, _______, _______, _______, _______,                       KC_NUM,   KC_P7,   KC_P8,   KC_P9, KC_CIRC,  KC_DEL,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          _______, _______, _______, _______, _______, _______,                      KC_PLUS,   KC_P4,   KC_P5,   KC_P6, KC_ASTR, TABRSFT,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          _______, _______, _______, _______, _______, _______,                      KC_MINS,   KC_P1,   KC_P2,   KC_P3, KC_UNDS,  KC_ENT,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              _______, _______, _______,    _______,   KC_P0, _______
                                          //`--------------------------'  `--------------------------'
    ),

    [_TOUHOU] = LAYOUT( //14
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

    [_MOUSE] = LAYOUT( //15
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
          _______, NAVTABS, MS_BTN4,   MS_UP, MS_BTN5, QK_LLCK,                      _______, _______, _______, _______, _______, _______,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          _______, COMMENT, MS_LEFT, MS_DOWN, MS_RGHT,  KC_DEL,                      _______, _______, _______, _______, _______, _______,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          KC_LCTL, MS_WHLL, MS_WHLU, MS_WHLD, MS_WHLR,  KC_ENT,                      _______, _______, _______, _______, _______, _______,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              MS_BTN3, MS_BTN2, MS_BTN1,    MS_ACL2, MS_ACL0, MS_ACL1
                                          //`--------------------------'  `--------------------------'
    ),

    [_UTILITY] = LAYOUT( //16
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
           ALTTAB, CLOCKUP, KC_PAUS, CS_VOLU,  KC_INS, OLEDSAV,                      CS_RGBN,   KC_F7,   KC_F8,   KC_F9,  KC_F10, CS_BOOT,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          _______, CLOCKDN, KC_MPRV, CS_VOLD, KC_MNXT,   BASIC,                         BASE,   KC_F1,   KC_F2,   KC_F3,  KC_F11, DB_TOGG,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          TB_TOGG, CLOCKNX, OLEDTOG,    MUTE, KC_PSCR,    MENU,                      CS_RGBT,   KC_F4,   KC_F5,   KC_F6,  KC_F12, KC_SCRL,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              KC_MSTP,  MUTE_L, KC_MPLY,    KC_MPLY,  MUTE_R, KC_MSTP
                                          //`--------------------------'  `--------------------------'
    ),
};



//==============================================================================
// Data Sync
//==============================================================================

#include "transactions.h"

typedef struct _master_to_slave_t {
    struct {
        bool static_display :1;
        bool timeout :1;
        bool active :1;
    } oled;
    struct {
        bool capturing :1;
        bool active :1;
    } case_lock;
} master_to_slave_t;

master_to_slave_t sync_data;

void user_config_sync_handler(uint8_t initiator2target_buffer_size, const void* initiator2target_buffer,
                      uint8_t target2initiator_buffer_size, void* target2initiator_buffer) {
    if (initiator2target_buffer_size == sizeof(master_to_slave_t)) {
        memcpy(&sync_data, initiator2target_buffer, initiator2target_buffer_size);
    }
}



//==============================================================================
// Variables
//==============================================================================

typedef struct {
    bool LT3_active :1;
    bool RT3_active :1;
    bool alt_tab_active :1;
    bool capsword_active :1;
} misc_key_flags_t;

static misc_key_flags_t misc_key_state = {
    .LT3_active = false,
    .RT3_active = false,
    .alt_tab_active = false,
    .capsword_active = false
};

typedef struct {
    uint8_t menu;
    bool static_display :1;
    bool timeout :1;
    bool active :1;
    bool muted :1;
} oled_flags_t;

static oled_flags_t oled_state = {
    .menu = 0,
    .static_display = false,
    .timeout = false,
    .active = true,
    .muted = false
};

static void update_sync(void);

static inline bool is_last_key(uint16_t);
static inline uint16_t get_last_key(void);
static inline uint16_t get_last_key_2(void);

static void rollback_last_key(void);
static void update_last_key(uint16_t);
static void update_last_keys(uint16_t, uint8_t);

static void rollback_wrapping_macro(void) {
    const uint8_t mods = get_mods();
    del_mods(MOD_MASK_CSAG);
    tap_code(KC_BSPC);
    tap_code16(LCTL(KC_LEFT));
    tap_code(KC_BSPC);
    tap_code16(LCTL(KC_RGHT));
    set_mods(mods);
    rollback_last_key();
}

static void cs_send_char(char c) {
    const uint8_t mods = get_mods();
    del_mods(MOD_MASK_CSAG);
    send_char(c);
    set_mods(mods);
    send_keyboard_report();
}

static void cs_send_char_punct(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        send_char(c);
    } else {
        const uint8_t mods = get_mods();
        del_mods(MOD_MASK_CSAG);
        send_char(c);
        set_mods(mods);
        send_keyboard_report();
    }
}

static void cs_send_string(const char *str) {
    while (*str) {
        cs_send_char(*str++);
    }
}

static void cs_send_string_leading(const char *str) {
    if (!*str) {
        return;
    }
    const uint8_t mods = get_mods();
    del_mods(MOD_MASK_CTRL);
    send_char(*str++);
    set_mods(mods);
    while (*str) {
        cs_send_char(*str++);
    }
}

static void cs_send_string_punct(const char *str) {
    while (*str) {
        cs_send_char_punct(*str++);
    }
}

static inline bool is_alpha(uint16_t keycode) {
    return keycode >= KC_A && keycode <= KC_Z;
}

static inline bool is_num(uint16_t keycode) {
    return keycode >= KC_1 && keycode <= KC_0;
}

static inline bool is_cs_symbol(uint16_t keycode) {
    return keycode >= CS_SYMBOLS_START && keycode <= CS_SYMBOLS_END;
}

static inline bool is_base_hrm(uint16_t keycode) { 
    switch(keycode) {
        case LG_N:
        case LA_R:
        case LC_T:
        case LS_S:
        case RS_H:
        case RC_E:
        case RA_I:
        case RG_A:

        case TB_D:
        case TB_M:
            return true;

        default:
            return false;
    }
}

static inline bool is_symbol_hrm(uint16_t keycode) {
    switch (keycode) {
        case RS_RPRN:
        case RC_LPRN:
        case RA_TILD:
        case RG_UNDS:

        case RS_1:
        case RC_2:
        case RA_3:
        case RG_0:

        case LG_EXLM:
        case LA_COLN:
        case LC_DOT:
        case LS_COMM:
            return true;

        default:
            return false;
    }
}

static inline bool is_hrm(uint16_t keycode) {
    switch (keycode) {
        case LG_N:
        case LA_R:
        case LC_T:
        case LS_S:
        case RS_H:
        case RC_E:
        case RA_I:
        case RG_A:

        case TB_D:
        case TB_M:

        case RS_RPRN:
        case RC_LPRN:
        case RA_TILD:
        case RG_UNDS:

        case RS_1:
        case RG_0:

        case LG_EXLM:
        case LA_COLN:
        case LC_DOT:
        case LS_COMM:

        case RS_DELL:
        case RC_DELW:
        case RA_DELR:
        case RG_DEL:
            return true;
        default:
            return false;
    }
}

static inline bool is_magic(uint16_t keycode) {
    return (keycode == CS_LT2 || keycode == CS_RT2);
}

static inline bool is_magic_punct(uint16_t keycode) {
    return keycode == PCTLEFT || keycode == PCTRGHT;
}

static inline bool is_layer_tap(uint16_t keycode) {
    return (keycode == CS_AL1 || keycode == CS_AL2 || keycode == CS_AL3 || keycode == CS_AL4);
}

static inline bool is_spc(uint16_t keycode) {
    return (keycode == CS_LT1 || keycode == KC_SPC);
}

static inline bool is_wrapping_macro(uint16_t keycode) {
    return ((keycode >= WRAPCBR && keycode <= WRAPBRC) || keycode == CY_WRAP);
}

static inline bool is_cycling_macro(uint16_t keycode) {
    return (keycode >= CY_MISC && keycode <= CY_ENUM);
}

static inline bool is_select_macro(uint16_t keycode) {
    return (keycode == SELLEFT || keycode == SELECT || keycode == SELRGHT);
}

static inline bool is_arrow(uint16_t keycode) {
    return (keycode == KC_UP || keycode == KC_DOWN || keycode == KC_LEFT || keycode == KC_RGHT);
}

static inline void cs_tap_code16_del_mods(uint16_t keycode, uint8_t mod_mask) {
    const uint8_t mods = get_mods();
    del_mods(mod_mask);
    if (is_cs_symbol(keycode)) {
        keycode = cs_map(keycode);
    }
    tap_code16(keycode);
    set_mods(mods);
}
static inline void cs_tap_code16(uint16_t keycode) {
    const uint8_t mods = get_mods();
    del_mods(MOD_MASK_SHIFT);
    if (is_cs_symbol(keycode)) {
        keycode = cs_map(keycode);
    }
    tap_code16(keycode);
    set_mods(mods);
}
static inline void cs_tap_code(uint16_t keycode) {
    const uint8_t mods = get_mods();
    del_mods(MOD_MASK_SHIFT);
    if (is_cs_symbol(keycode)) {
        keycode = cs_map(keycode);
    }
    tap_code16(keycode);
    set_mods(mods);
}
static inline void cs_register_code16(uint16_t keycode) {
    const uint8_t mods = get_mods();
    del_mods(MOD_MASK_SHIFT);
    if (is_cs_symbol(keycode)) {
        keycode = cs_map(keycode);
    }
    register_code16(keycode);
    set_mods(mods);
}
static inline void cs_unregister_code16(uint16_t keycode) {
    const uint8_t mods = get_mods();
    del_mods(MOD_MASK_SHIFT);
    if (is_cs_symbol(keycode)) {
        keycode = cs_map(keycode);
    }
    unregister_code16(keycode);
    set_mods(mods);
}

static inline bool ctrl_on(void) {
    return (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTL));
}

static inline bool shifted(void) {
    return (get_mods() & MOD_BIT(KC_LSFT)
         || get_mods() & MOD_BIT(KC_RSFT)
         || get_oneshot_mods() & MOD_BIT(KC_LSFT)
         || get_oneshot_mods() & MOD_BIT(KC_RSFT)
         );
}

typedef struct {
    uint8_t mode;
    bool active :1;
} rgb_flags_t;

static rgb_flags_t rgb_state = {
    .mode = 0,
    .active = true
};

static void set_rgb_mode(void) {
    // dprintf("rgb_mode: %d\n", rgb_state.mode);
    if (rgb_state.mode == 0) {
        rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_reactive_smooth);
    } else {
        // Skip 0/1 for off/solid background animations
        rgb_matrix_mode_noeeprom(rgb_state.mode + 1);
    }
}

static void rgb_matrix_set_color_split(uint8_t index, uint8_t r, uint8_t g, uint8_t b) {
    if ((!is_keyboard_master() && index < 27) || (is_keyboard_master() && index >= 27)) {
        rgb_matrix_set_color(index, r, g, b);
    }
}

typedef enum {
    set_none,
    set_hour,
    set_min,
    set_sec,
} time_setting_t;

typedef struct {
    time_setting_t setting;
    uint8_t hrs;
    uint8_t min;
    uint8_t sec;
} clock_state_t;

static clock_state_t clock_state = {
    .setting = set_none,
    .hrs     = 0,
    .min     = 0,
    .sec     = 0
};

#define HOST_CLOCK_TIMEOUT 2000

static uint32_t last_host_clock_update = 0;
static bool host_clock_active = false;



//==============================================================================
// Raw HID
//==============================================================================

/** 

Send:
S - toggle scroll
V - toggle volume
T - toggle on/off

Receive:
A - layer on
B - layer off

*/

static bool auto_layer_on = true;

#define LAYER_LINGER_TIME 500

static uint32_t mouse_layer_off_callback(uint32_t trigger_time, void *cb_arg) {
    layer_off(_TRACKBALL);
    return 0;
}

static deferred_token trackball_token = INVALID_DEFERRED_TOKEN;

#define RAW_LENGTH 32

void raw_hid_receive(uint8_t *data, uint8_t length) {
    uint8_t response[length];
    memset(response, 0, length);
    dprintf("Keyboard  - Received HID data: %c\n", data[0]);
    
    switch (data[0]) {
        case 'A':
            cancel_deferred_exec(trackball_token);
            layer_on(_TRACKBALL);
            break;
        case 'B':
            trackball_token = defer_exec(LAYER_LINGER_TIME, mouse_layer_off_callback, NULL);
            break;
        case 'T':
            clock_state.hrs = data[1];
            clock_state.min = data[2];
            clock_state.sec = data[3];

            last_host_clock_update = timer_read();
            host_clock_active = true;
            break;
        default:
            dprintf("Unknown HID command: %c\n", data[0]);
            break;
    }
}

static void tap_hold_scroll_key(uint16_t keycode, keyrecord_t* record, uint16_t output_keycode) {
    if (!auto_layer_on || record->tap.count) {
        if (record->event.pressed) {
            register_code(output_keycode);
        } else {
            unregister_code(output_keycode);
        }
        return;
    }

    uint8_t msg[RAW_LENGTH];
    memset(msg, 0, RAW_LENGTH);
    msg[0] = 'S';
    raw_hid_send(msg, RAW_LENGTH);
}

static bool process_trackball_keys(uint16_t keycode, keyrecord_t* record) {
    uint8_t msg[RAW_LENGTH];
    memset(msg, 0, RAW_LENGTH);

    switch (keycode) {
        case TB_TOGG:
            if (record->event.pressed) {
                msg[0] = 'T';
                raw_hid_send(msg, RAW_LENGTH);
            }
            return false;

        case TB_TVOL:
            msg[0] = 'V';
            raw_hid_send(msg, RAW_LENGTH);
            return false;

        case CS_LT3:
        case CS_RT3:
            if (!record->tap.count) {
                msg[0] = 'V';
                raw_hid_send(msg, RAW_LENGTH);
            }
            return true;

        case TB_LOFF:
            if (record->event.pressed) {
                layer_off(_TRACKBALL);
            }
            return false;

        case SCROLL:
            msg[0] = record->event.pressed ? 'S' : 's';
            raw_hid_send(msg, RAW_LENGTH);
            return false;

        case TB_D:
            tap_hold_scroll_key(keycode, record, KC_D);
            return false;

        case TB_M:
            tap_hold_scroll_key(keycode, record, KC_M);
            return false;

        case MS_BTN1:
        case MS_BTN2:
        case MS_BTN3:
        case MS_BTN4:
        case MS_BTN5:
            extend_deferred_exec(trackball_token, LAYER_LINGER_TIME);
            return true;

        default:
            layer_off(_TRACKBALL);
            return true;
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
// Home row mods
//==============================================================================

static void homerow_mod(uint8_t mods, keyrecord_t* record) {
    if (!record->tap.count && record->event.pressed) {
        register_mods(mods);
    } else if (!record->tap.count && !record->event.pressed) {
        unregister_mods(mods);
    }
}

static bool process_homerow_mod_tap(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        // LGUI
        case LG_N:
        case LG_EXLM:
            homerow_mod(MOD_BIT(KC_LGUI), record);
            break;
        // LALT
        case LA_R:
        case LA_COLN:
            homerow_mod(MOD_BIT(KC_LALT), record);
            break;
        // LCTL
        case LC_T:
        case LC_DOT:
            homerow_mod(MOD_BIT(KC_LCTL), record);
            break;
        // LSFT
        case LS_S:
        case LS_COMM:
            homerow_mod(MOD_BIT(KC_LSFT), record);
            break;

        // RSFT
        case RS_H:
        case RS_RPRN:
        case RS_1:
        case RS_DELL:
            homerow_mod(MOD_BIT(KC_RSFT), record);
            break;
        // RCTL
        case RC_E:
        case RC_LPRN:
        case RC_2:
        case RC_DELW:
            homerow_mod(MOD_BIT(KC_RCTL), record);
            break;
        // RALT
        case RA_I:
        case RA_TILD:
        case RA_3:
        case RA_DELR:
            homerow_mod(MOD_BIT(KC_LALT), record);
            break;
        // RGUI
        case RG_A:
        case RG_UNDS:
        case RG_0:
        case RG_DEL:
            homerow_mod(MOD_BIT(KC_RGUI), record);
            break;
    }
    return true;
}



//==============================================================================
// Tap/hold
//==============================================================================

bool is_flow_tap_key(uint16_t keycode) {
    switch (get_tap_keycode(keycode)) {
        case KC_A ... KC_Z:
        case KC_DOT:
        case KC_COMM:
        case KC_SCLN:
        case KC_QUOT:
        case COM_EXL:
        case DOT_QUE:
            return true;
    }
    return false;
}

uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t* record, 
                           uint16_t prev_keycode) {
    if (get_tap_keycode(prev_keycode) == KC_BSPC) {
        return 0;
    }

    if (keycode == CS_LT2 || IS_LAYER_ON(_EDIT)) {
        return 0;
    }

    if (is_flow_tap_key(keycode) && is_flow_tap_key(prev_keycode)) {
        switch (keycode) {
            // Shift mod-taps
            case LS_S:
            case RS_H:
                return 25;

            // Ctrl mod-taps
            case LC_T:
            case RC_E:
                return 75;

            // Alt mod-taps
            case LA_R:
            case RA_I:
                return 100;

            // GUI mod-taps
            case LG_N:
            case RG_A:
                return 50;

            default:
                return FLOW_TAP_TERM;
        }
    }

    return 0;
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Enable key repeating on numerical home row mod keys
        case RS_1:
        case RC_2:
        case RA_3:
        case RG_0:
            return TAPPING_TERM;

        case CS_LT3:
        case CS_LT2:
        case CS_LT1:

        case CS_RT1:
        case CS_RT2:
        case CS_RT3:

        case CS_AL1:
        case CS_AL2:
        case CS_AL3:
        case CS_AL4:

        case TABLSFT:
        case TABRSFT:
            return 0;
    }

    // Disable key repeating on other home row mod keys
    if (is_hrm(keycode)) {
        return 0;
    }

    return TAPPING_TERM;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CS_LT2:
        case CS_RT2:
            return 200;

        case CS_LT3:
        case CS_LT1:

        case CS_RT1:
        case CS_RT3:
            return 150;

        case TABLSFT:
        case TABRSFT:
            return 125;

        case OSMLSFT:
            return 300;

        default:
            break;
    }

    uint8_t mod = mod_config(QK_MOD_TAP_GET_MODS(keycode));

    if (mod & MOD_LSFT || mod & MOD_RSFT) {
        return 150;
    }
    if (mod & MOD_LCTL || mod & MOD_RCTL) {
        return 200;
    }
    if (mod & MOD_LALT || mod & MOD_RALT) {
        return 225;
    }
    if (mod & MOD_LGUI || mod & MOD_RGUI) {
        return 250;
    }

    return TAPPING_TERM;
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
        // case CS_AL2:
        // case CS_AL3:
        // case CS_AL4:

        case TABLSFT:
        case TABRSFT:
            return true;

        default:
            return false;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    if (!is_base_hrm(keycode)) {
        return true;
    }

    uint8_t mod = mod_config(QK_MOD_TAP_GET_MODS(keycode));

    if (mod & MOD_LALT || mod & MOD_RALT ) {
        return false;
    }
    if (mod & MOD_LGUI || mod & MOD_RGUI ) {
        return false;
    }

    return true;
}

bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
                      uint16_t other_keycode, keyrecord_t* other_record) {
    if (is_hrm(tap_hold_keycode)) {
        return get_chordal_hold_default(tap_hold_record, other_record);
    }

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
        case CS_AL4:

        case CS_BOOT:
        case TABLSFT:
        case TABRSFT:
            return true;

        case CS_LT2:
            if (chordal_hold_handedness(other_record->event.key) == 'R' &&
                (other_record->event.key.col == 0 ||
                 other_record->event.key.col == 1 ||
                 other_record->event.key.col == 2)) {
                return false;
            
            }
            if (chordal_hold_handedness(other_record->event.key) == 'L' &&
                (other_record->event.key.col == 5)) {
                return true;
            }
            if (chordal_hold_handedness(other_record->event.key) == 'L' &&
                (other_record->event.key.col == 1)) {
                return false;
            }
            if (chordal_hold_handedness(other_record->event.key) == 'L' &&
                (other_record->event.key.row == 2)) {
                return false;
            }
            return true;

        case CS_AL1:
        case CS_RT2:
            return get_chordal_hold_default(tap_hold_record, other_record);

        default:
            return false;
    }
}

static void tap_hold_tri_layer(keyrecord_t* record, uint8_t hold_layer,
                               uint8_t tri_layer2, uint8_t tri_layer3) {
    if (!record->tap.count && record->event.pressed) {
        layer_on(hold_layer);
        update_tri_layer(hold_layer, tri_layer2, tri_layer3);
    } else {
        layer_off(hold_layer);
        update_tri_layer(hold_layer, tri_layer2, tri_layer3);
    }
}


static bool process_cs_layer_tap(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case CS_LT3:
            if (record->event.pressed) {
                misc_key_state.LT3_active = true;
                if (record->tap.count) {
                    tap_code(KC_ENT);
                } else {
                    layer_on(_UTILITY);
                }
            } else {
                misc_key_state.LT3_active = false;
                layer_off(_UTILITY);
            }
            return false;
        case CS_RT3:
            if (record->event.pressed) {
                misc_key_state.RT3_active = true;
                if (record->tap.count) {
                    tap_code(KC_SLSH);
                } else {
                    layer_on(_UTILITY);
                }
            } else {
                misc_key_state.RT3_active = false;
                layer_off(_UTILITY);
            }
            return false;

        case CS_LT1:
            tap_hold_tri_layer(record, _DATA, _PROGRAM, _EDIT);
            if (record->tap.count && record->event.pressed) {
                tap_code(KC_SPC);
            }
            return false;
        case CS_RT1:
            tap_hold_tri_layer(record, _SYMBOL, _EDIT, _DATA_OVERLAY);
            if (record->tap.count && record->event.pressed) {
                tap_code(KC_BSPC);
            }
            return false;
        case CS_AL1:
            tap_hold_tri_layer(record, _PROGRAM, _DATA, _EDIT);
            if (record->tap.count && record->event.pressed) {
                cs_tap_code(KC_0);
            }
            return false;
        case CS_AL2:
            tap_hold_tri_layer(record, _EDIT, _SYMBOL, _DATA_OVERLAY);
            if (record->tap.count && record->event.pressed) {
                cs_tap_code16(KC_NUBS);
            }
            return false;
        case CS_AL3:
            tap_hold_tri_layer(record, _EDIT, _PROGRAM, _EDIT_OVERLAY);
            if (record->tap.count && record->event.pressed) {
                cs_tap_code16(KC_NUBS);
            }
            return false;
        case CS_AL4:
            tap_hold_tri_layer(record, _PROGRAM, _EDIT, _EDIT_OVERLAY);
            if (record->tap.count && record->event.pressed) {
                cs_tap_code(KC_0);
            }
            return false;
        case CS_LCTL:
            if (record->event.pressed) {
                layer_on(_CONTROL);
                layer_on(_CONTROL_OVERLAY);
            } else {
                layer_off(_CONTROL);
                layer_off(_CONTROL_OVERLAY);
            }
            return true;
        default:
            return true;
    }
}



//==============================================================================
// Combos
//==============================================================================

enum combo_events {
    TOUHOU,
    STENO,
    NUMPAD,

    MOUSE,
    MOUSE2,

    BACKSPACE,
    TRANSPOSE,
    CAPSWORD,

    L_EXPONENT,
    L_COMMA,
    L_DOT,
    L_UNDERSCORE,
    L_ASTERISK,
    L_PLUS,
    L_EQUALS,
    L_MINUS,
    L_NEWSENT,
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
    R_NEWSENT,
    SEMICOLON,
    AMPERSAND,

    SPC_F1,
    SPC_F2,
    SPC_F3,
    SPC_F4,
    SPC_F5,

    SPC_1,
    SPC_2,
    SPC_3,
    SPC_4,
    SPC_5,
    SPC_6,
    SPC_7,
    SPC_8,
    SPC_9,
    SPC_0,

    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM touhou[]       = {    KC_P, CS_HASH,  KC_ESC,          COMBO_END};
const uint16_t PROGMEM steno[]        = {    KC_P, CS_HASH, KC_SCLN, TABRSFT, COMBO_END};
const uint16_t PROGMEM numpad[]       = {    KC_O,    KC_P, CS_HASH,          COMBO_END};
const uint16_t PROGMEM mouse[]        = { KC_SCLN, DOT_QUE,                   COMBO_END};
const uint16_t PROGMEM mouse2[]       = {    KC_A,    KC_Z,                   COMBO_END};
const uint16_t PROGMEM backspace[]    = {  CS_RT1,  CS_RT2,                   COMBO_END};
const uint16_t PROGMEM capsword[]     = { KC_LSFT, TABRSFT,                   COMBO_END};
const uint16_t PROGMEM transpose[]    = {  KC_SPC,  CS_LT2,                   COMBO_END};

const uint16_t PROGMEM l_exponent[]   = {    KC_W,    KC_E,                   COMBO_END};
const uint16_t PROGMEM l_comma[]      = {    KC_D,    KC_V,                   COMBO_END};
const uint16_t PROGMEM l_dot[]        = {    KC_S,    KC_D,                   COMBO_END};
const uint16_t PROGMEM l_underscore[] = {    KC_C,    KC_V,                   COMBO_END};
const uint16_t PROGMEM l_asterisk[]   = {    KC_F,    KC_B,                   COMBO_END};
const uint16_t PROGMEM l_equals[]     = {    KC_E,    KC_R,                   COMBO_END};
const uint16_t PROGMEM l_plus[]       = {    KC_F,    KC_G,                   COMBO_END};
const uint16_t PROGMEM l_minus[]      = {    KC_D,    KC_F,                   COMBO_END};
const uint16_t PROGMEM l_newsent[]    = {    KC_X,    KC_D,                   COMBO_END};
const uint16_t PROGMEM exclamation[]  = {    KC_S,    KC_E,                   COMBO_END};
const uint16_t PROGMEM colon[]        = {    KC_E,    KC_F,                   COMBO_END};

const uint16_t PROGMEM r_exponent[]   = {    KC_I,    KC_O,                   COMBO_END};
const uint16_t PROGMEM r_comma[]      = {    KC_M,    KC_K,                   COMBO_END};
const uint16_t PROGMEM r_dot[]        = {    KC_K,    KC_L,                   COMBO_END};
const uint16_t PROGMEM r_underscore[] = {    KC_M, KC_QUOT,                   COMBO_END};
const uint16_t PROGMEM r_asterisk[]   = {    KC_N,    KC_J,                   COMBO_END};
const uint16_t PROGMEM r_equals[]     = {    KC_U,    KC_I,                   COMBO_END};
const uint16_t PROGMEM r_plus[]       = {    KC_H,    KC_J,                   COMBO_END};
const uint16_t PROGMEM r_minus[]      = {    KC_J,    KC_K,                   COMBO_END};
const uint16_t PROGMEM r_newsent[]    = {    KC_K, COM_EXL,                   COMBO_END};
const uint16_t PROGMEM semicolon[]    = {    KC_J,    KC_I,                   COMBO_END};
const uint16_t PROGMEM ampersand[]    = {    KC_I,    KC_L,                   COMBO_END};

const uint16_t PROGMEM spc_f1[]       = {  KC_SPC,    KC_Q,                   COMBO_END};
const uint16_t PROGMEM spc_f2[]       = {  KC_SPC,    KC_W,                   COMBO_END};
const uint16_t PROGMEM spc_f3[]       = {  KC_SPC,    KC_E,                   COMBO_END};
const uint16_t PROGMEM spc_f4[]       = {  KC_SPC,    KC_R,                   COMBO_END};
const uint16_t PROGMEM spc_f5[]       = {  KC_SPC,    KC_T,                   COMBO_END};

const uint16_t PROGMEM spc_1[]        = {  KC_SPC,    KC_A,                   COMBO_END};
const uint16_t PROGMEM spc_2[]        = {  KC_SPC,    KC_S,                   COMBO_END};
const uint16_t PROGMEM spc_3[]        = {  KC_SPC,    KC_D,                   COMBO_END};
const uint16_t PROGMEM spc_4[]        = {  KC_SPC,    KC_F,                   COMBO_END};
const uint16_t PROGMEM spc_5[]        = {  KC_SPC,    KC_G,                   COMBO_END};
const uint16_t PROGMEM spc_6[]        = {  KC_SPC,    KC_Z,                   COMBO_END};
const uint16_t PROGMEM spc_7[]        = {  KC_SPC,    KC_X,                   COMBO_END};
const uint16_t PROGMEM spc_8[]        = {  KC_SPC,    KC_C,                   COMBO_END};
const uint16_t PROGMEM spc_9[]        = {  KC_SPC,    KC_V,                   COMBO_END};
const uint16_t PROGMEM spc_0[]        = {  KC_SPC,    KC_B,                   COMBO_END};

combo_t key_combos[] = {
    [TOUHOU]        = COMBO_ACTION(touhou),
    [STENO]         = COMBO_ACTION(steno),
    [NUMPAD]        = COMBO_ACTION(numpad),

    [MOUSE]         = COMBO_ACTION(mouse),
    [MOUSE2]        = COMBO_ACTION(mouse2),

    [BACKSPACE]     = COMBO_ACTION(backspace),
    [TRANSPOSE]     = COMBO_ACTION(transpose),
    [CAPSWORD]      = COMBO(capsword,     CAPSWRD),

    [L_EXPONENT]    = COMBO(l_exponent,   CS_CIRC),
    [L_COMMA]       = COMBO(l_comma,      CS_COMM),
    [L_DOT]         = COMBO(l_dot,        CS_DOT),
    [L_UNDERSCORE]  = COMBO(l_underscore, CS_UNDS),
    [L_ASTERISK]    = COMBO(l_asterisk,   CS_ASTR),
    [L_EQUALS]      = COMBO(l_equals,     CS_EQL),
    [L_PLUS]        = COMBO(l_plus,       CS_PLUS),
    [L_MINUS]       = COMBO(l_minus,      CS_MINS),
    [L_NEWSENT]     = COMBO(r_newsent,    NEWSENT),
    [EXCLAMATION]   = COMBO(exclamation,  CS_EXLM),
    [COLON]         = COMBO(colon,        CS_COLN),

    [R_EXPONENT]    = COMBO(r_exponent,   CS_CIRC),
    [R_COMMA]       = COMBO(r_comma,      CS_COMM),
    [R_DOT]         = COMBO(r_dot,        CS_DOT),
    [R_UNDERSCORE]  = COMBO(r_underscore, CS_UNDS),
    [R_ASTERISK]    = COMBO(r_asterisk,   CS_ASTR),
    [R_EQUALS]      = COMBO(r_equals,     CS_EQL),
    [R_PLUS]        = COMBO(r_plus,       CS_PLUS),
    [R_MINUS]       = COMBO(r_minus,      CS_MINS),
    [R_NEWSENT]     = COMBO(l_newsent,    NEWSENT),
    [SEMICOLON]     = COMBO(semicolon,    CS_SCLN),
    [AMPERSAND]     = COMBO(ampersand,    CS_AMPR),

    [SPC_F1]        = COMBO(spc_f1,       KC_F1),
    [SPC_F2]        = COMBO(spc_f2,       KC_F2),
    [SPC_F3]        = COMBO(spc_f3,       KC_F3),
    [SPC_F4]        = COMBO(spc_f4,       KC_F4),
    [SPC_F5]        = COMBO(spc_f5,       KC_F5),

    [SPC_1]         = COMBO(spc_1,       KC_1),
    [SPC_2]         = COMBO(spc_2,       KC_2),
    [SPC_3]         = COMBO(spc_3,       KC_3),
    [SPC_4]         = COMBO(spc_4,       KC_4),
    [SPC_5]         = COMBO(spc_5,       KC_5),
    [SPC_6]         = COMBO(spc_6,       KC_6),
    [SPC_7]         = COMBO(spc_7,       KC_7),
    [SPC_8]         = COMBO(spc_8,       KC_8),
    [SPC_9]         = COMBO(spc_9,       KC_9),
    [SPC_0]         = COMBO(spc_0,       KC_0),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
        case TOUHOU:
            if (pressed) {
                oled_state.menu = 1;
                if (IS_LAYER_ON(_TOUHOU)) {
                    layer_off(_TOUHOU);
                } else {
                    layer_on(_TOUHOU);
                }
            }
            break;
        case STENO:
            if (pressed) {
                layer_invert(_STENO);
                unregister_mods(MOD_BIT(KC_RSFT));
            }
            break;
        case NUMPAD:
            if (pressed) {
                layer_invert(_NUMPAD);
            }
            break;
        case MOUSE:
        case MOUSE2:
            if (pressed) {
                layer_lock_off(_MOUSE);
                layer_on(_MOUSE);
            } else if (!is_layer_locked(_MOUSE)) {
                layer_off(_MOUSE);
            }
            break;
        case BACKSPACE:
            if (pressed) {
                register_code16(LCTL(KC_BSPC));
            } else {
                unregister_code16(LCTL(KC_BSPC));
            }
            break;
        case TRANSPOSE:
            if (pressed && get_last_key() != KC_NO && get_last_key_2() != KC_NO) {
                const uint16_t key1 = get_last_key();
                const uint16_t key2 = get_last_key_2();
                cs_tap_code(KC_BSPC);
                cs_tap_code(KC_BSPC);
                cs_tap_code16(key1);
                cs_tap_code16(key2);
                update_last_key(key1);
                update_last_key(key2);
            }
            break;
    }
}

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    uint16_t combo_term = 0;
    switch (index) {
        case CAPSWORD:
            combo_term = 30;
            break;

        case L_UNDERSCORE:
        case R_UNDERSCORE:
            combo_term = 50;
            break;
            
        case L_NEWSENT:
        case R_NEWSENT:
        case L_COMMA:
        case R_COMMA:
            combo_term = 25;
            break;

        case L_EXPONENT:
        case R_EXPONENT:
        case L_MINUS:
        case R_MINUS:
            combo_term = 15;
            break;

        case BACKSPACE:
        case TRANSPOSE:
        case MOUSE:
        case MOUSE2:
            combo_term = 75;
            break;

        default:
            combo_term = 20;
            break;
    }

    if (IS_LAYER_ON(_EDIT) || IS_LAYER_ON(_PROGRAM) || IS_LAYER_ON(_SYMBOL)) {
        combo_term /= 5;
    }

    return combo_term;
}

bool get_combo_must_tap(uint16_t index, combo_t *combo) {
    switch (index) {
        case BACKSPACE:
        case MOUSE:
        case MOUSE2:
            return false;
        default:
            return true;
    }
}

bool combo_should_trigger(uint16_t combo_index, combo_t *combo,
                          uint16_t keycode, keyrecord_t *record) {
    switch (combo_index) {
        // Layer switching combos always trigger
        case TOUHOU:
        case MOUSE:
        case MOUSE2:
        case STENO:
        case NUMPAD:
            return true;

        // Disable only left hand combos on Edit layer
        case L_EXPONENT:
        case L_COMMA:
        case L_DOT:
        case L_UNDERSCORE:
        case L_ASTERISK:
        case L_EQUALS:
        case L_PLUS:
        case L_MINUS:
        case AMPERSAND:
        case COLON:
        case L_NEWSENT:
            if (IS_LAYER_ON(_EDIT)) { 
                return false;
            }

        default:
            if (IS_LAYER_OFF(_QWERTY)
             && IS_LAYER_OFF(_BASIC)
             && IS_LAYER_OFF(_TOUHOU)
             && IS_LAYER_OFF(_MOUSE)
             && IS_LAYER_OFF(_STENO)
             && IS_LAYER_OFF(_UTILITY)) {
                return true;
            }
            return false;
    }
}

bool process_mouse_lock(uint16_t keycode, keyrecord_t* record) {
    if (!record->event.pressed) {
        return true;
    }
    if ((IS_QK_MOD_TAP(keycode) || IS_QK_LAYER_TAP(keycode)) && !record->tap.count) {
        return true;
    }
    if (record->event.pressed &&
        is_layer_locked(_MOUSE) &&
        record->event.key.row >= 4 &&
        record->event.key.row <= 6) {
        layer_off(_MOUSE);
    }
    return true;
}



//==============================================================================
// Case Lock
//==============================================================================

typedef enum {
    SEP_DEF,
    SEP_SYM,
    SEP_SPC,
    SEP_LSFT,
    SEP_RSFT
} sep_kind_t;

typedef struct {
    uint16_t keycode;
    sep_kind_t kind;
    uint16_t output;
} sep_rule_t;

typedef struct {
    bool active :1;
    bool capturing :1;
    const sep_rule_t *rule;
    int16_t distance;
} case_lock_flags_t;

static case_lock_flags_t case_lock_state = {
    .active = false,
    .capturing = false,
    .rule = NULL,
    .distance = 0
};

static const sep_rule_t separator_rules[] = {
    { KC_NO,   SEP_DEF,  KC_UNDS },

    { CS_UNDS, SEP_SYM,  KC_UNDS },
    { KC_UNDS, SEP_SYM,  KC_UNDS },

    { CS_MINS, SEP_SYM,  KC_MINS },
    { KC_MINS, SEP_SYM,  KC_MINS },

    { CS_DOT,  SEP_SYM,  KC_DOT  },
    { KC_DOT,  SEP_SYM,  KC_DOT  },

    { CS_RT3,  SEP_SYM,  KC_SLSH },
    { KC_SLSH, SEP_SYM,  KC_SLSH },

    { CS_LT2,  SEP_SYM,  KC_NUBS },
    { KC_NUBS, SEP_SYM,  KC_NUBS },

    { CS_LT1,  SEP_SPC,  KC_UNDS },
    { KC_SPC,  SEP_SPC,  KC_UNDS },

    { TABLSFT, SEP_LSFT, KC_NO   },
    { KC_LSFT, SEP_LSFT, KC_NO   },

    { TABRSFT, SEP_RSFT, KC_SPC  },
    { KC_RSFT, SEP_RSFT, KC_SPC  },
};

static inline void case_lock_capture_on(void) {
    case_lock_state.capturing = true;
    update_sync();
}

static inline void case_lock_capture_off(void) {
    case_lock_state.capturing = false;
    update_sync();
}

static inline void case_lock_on(void) {
    case_lock_state.active = true;
    case_lock_state.distance = 0;
    update_sync();
}

static inline void case_lock_off(void) {
    clear_oneshot_mods();
    case_lock_state.active = false;
    case_lock_state.capturing = false;
    update_sync();
    case_lock_state.rule = NULL;
}

static const sep_rule_t* get_separator_rule(uint16_t keycode) {
    for (size_t i = 0; i < ARRAY_SIZE(separator_rules); i++) {
        if (separator_rules[i].keycode == keycode) {
            return &separator_rules[i];
        }
    }
    return NULL;
}

static void send_separator(void){
    switch (case_lock_state.rule->kind) {
        case SEP_SPC:
        case SEP_DEF:
        case SEP_SYM:
            tap_code16(case_lock_state.rule->output);
            break;
        case SEP_LSFT:
            set_oneshot_mods(MOD_BIT(KC_LSFT));
            break;
        case SEP_RSFT:
            tap_code(KC_SPC);
            set_oneshot_mods(MOD_BIT(KC_LSFT));
            break;
    }
    case_lock_state.distance = 0;
}

static bool process_case_capture(uint16_t keycode) {
    case_lock_state.rule = get_separator_rule(keycode);
    if (!case_lock_state.rule) {
        // Default to { KC_NO, SEP_DEF, KC_UNDS }
        case_lock_state.rule = &separator_rules[0];
    }

    case_lock_capture_off();
    case_lock_on();

    // Immediate behaviours
    switch (case_lock_state.rule->kind) {
        case SEP_DEF:
            case_lock_state.distance++;
            return true;

        case SEP_SYM:
            return false;

        case SEP_SPC:
            tap_code16(case_lock_state.rule->output);
            return false;

        case SEP_LSFT:
            unregister_mods(MOD_BIT(KC_LSFT));
            return false;

        case SEP_RSFT:
            unregister_mods(MOD_BIT(KC_RSFT));
            set_oneshot_mods(MOD_BIT(KC_RSFT));
            return false;
    }
    return true;
}

static bool process_case_lock(uint16_t keycode, keyrecord_t* record) {
    if (!record->event.pressed) {
        return true;
    }

    if (keycode == CS_CASE) {
        if (!case_lock_state.capturing) {
            case_lock_capture_on();
        } else {
            tap_code(KC_CAPS);
            case_lock_capture_off();
        }
        return true;
    }

    if (keycode == KC_ESC) {
        case_lock_off();
        case_lock_capture_off();
        return true;
    }

    if (case_lock_state.capturing) {
        return process_case_capture(keycode);
    }

    if (!case_lock_state.active) {
        return true;
    }

    if (keycode == KC_SPC || (keycode == CS_LT1 && record->tap.count)) {
        if (is_spc(get_last_key())) {
            switch (case_lock_state.rule->kind) {
                case SEP_LSFT:
                    case_lock_off();
                    return true;

                case SEP_RSFT:
                    case_lock_off();
                    return false;

                case SEP_DEF:
                case SEP_SYM:
                case SEP_SPC:
                    cs_tap_code16_del_mods(KC_BSPC, MOD_MASK_CSAG);
                    tap_code(KC_SPC);
                    case_lock_off();
                    return false;
            }
        } else {
            send_separator();
            case_lock_state.distance = 0;
            dprintf("separator distance = %d\n", case_lock_state.distance);
            update_last_key(KC_SPC);
            return false;
        }
    }

    if (keycode == KC_BSPC || (keycode == CS_RT1 && record->tap.count)) {
        if (ctrl_on() && case_lock_state.distance > 0) {
            const uint8_t mods = get_mods();
            del_mods(MOD_MASK_CSAG);
            for (int i = 0; i < case_lock_state.distance; i++) {
                tap_code(KC_BSPC);
            }
            set_mods(mods);
            case_lock_state.distance = 0;
            if (case_lock_state.rule->kind == SEP_LSFT || case_lock_state.rule->kind == SEP_RSFT) {
                set_oneshot_mods(MOD_BIT(KC_LSFT));
            }
            return false;
        } else {
            if (case_lock_state.distance > 0) {
                case_lock_state.distance--;
                dprintf("separator distance = %d\n", case_lock_state.distance);
            }
            return true;
        }
    }

    if (is_hrm(keycode) && record->tap.count) {
        case_lock_state.distance++;
        dprintf("separator distance = %d\n", case_lock_state.distance);
        return true;
    }

    switch (keycode) {
        case KC_A ... KC_Z:
        case KC_1 ... KC_0:
            case_lock_state.distance++;
            dprintf("separator distance = %d\n", case_lock_state.distance);
            return true;
    }

    if (is_magic(keycode) && record->tap.count) {
        // Handle variable-length outputs elsewhere
        return true;
    }

    const sep_rule_t* translate = get_separator_rule(keycode);
    if (translate) {
        if (translate->output == case_lock_state.rule->output) {
            case_lock_state.distance = 0;
            dprintf("separator distance = %d\n", case_lock_state.distance);
        } else {
            case_lock_state.distance++;
            dprintf("separator distance = %d\n", case_lock_state.distance);
        }
        return true;
    }

    if (keycode == KC_LSFT || keycode == KC_RSFT ||
        keycode == CS_LCTL || keycode == KC_LCTL) {
        return true;
    }
    if (keycode == CAPSWRD) {
        return true;
    }
    if (keycode == CS_LT1 && !record->tap.count) {
        return true;
    }
    if ((keycode == CS_RT1 || is_magic(keycode)) && !record->tap.count) {
        return true;
    }

    if ((keycode == TABLSFT || keycode == TABRSFT) && record->tap.count) {
        case_lock_off();
        return true;
    }

    case_lock_off();
    return true;
}



//==============================================================================
// Caps Word
//==============================================================================

static bool process_capsword(uint16_t keycode, keyrecord_t* record) {
    if (keycode == CAPSWRD) {
        if (record->event.pressed) {
            unregister_mods(MOD_MASK_SHIFT);
            misc_key_state.capsword_active = !misc_key_state.capsword_active;
        }
        return false;
    }

    if (is_hrm(keycode)) {
        keycode = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
    }

    if (misc_key_state.capsword_active) {
        switch (keycode) {
            // Add shift mod
            case CS_LT2:
            case CS_RT2:
                if (!record->tap.count) { break; }
            case KC_A ... KC_Z:
                if (record->event.pressed) {
                    add_mods(MOD_BIT(KC_LSFT));
                    break;
                }

            // Shift keys
            case TABLSFT:
            case TABRSFT:
            case OSMLSFT:
            case KC_LSFT:
                if (record->event.pressed) {
                    misc_key_state.capsword_active = false;
                } else {
                    del_mods(MOD_BIT(KC_LSFT));
                }
                break;

            // Ignore keys
            case KC_BSPC:
            case CS_RT1:
            case CS_CASE:
                break;

            // Exit capsword
            case CS_LT1:
            case KC_SPC:
                if (case_lock_state.active) {
                    break;
                }

            default:
                del_mods(MOD_BIT(KC_LSFT));
                misc_key_state.capsword_active = false;
                break;
        }
    }
    return true;
}



//==============================================================================
// Edit Control Keys
//==============================================================================

typedef enum {
    ARROW_NONE  = 0,
    ARROW_UP    = 1 << 0,
    ARROW_DOWN  = 1 << 1,
    ARROW_LEFT  = 1 << 2,
    ARROW_RIGHT = 1 << 3
} arrow_bit_t;

#define VERTICAL_MASK (ARROW_UP | ARROW_DOWN)

typedef struct {
    arrow_bit_t last_key;
    uint8_t held_keys;
    bool ctrl_active;
    uint32_t last_press;
} arrow_state_t;

static arrow_state_t arrow_state = {
    .last_key = ARROW_NONE,
    .held_keys = 0,
    .ctrl_active = false,
    .last_press = 0
};

static inline void set_arrow(arrow_bit_t arrow)    { arrow_state.held_keys |= arrow; }
static inline void clear_arrow(arrow_bit_t arrow)  { arrow_state.held_keys &= ~arrow; }
static inline bool check_arrow(arrow_bit_t arrow)  { return arrow_state.held_keys & arrow; }

static inline arrow_bit_t arrow_bit(uint16_t keycode) {
    switch (keycode) {
        case KC_UP:   return ARROW_UP;
        case KC_DOWN: return ARROW_DOWN;
        case KC_LEFT: return ARROW_LEFT;
        case KC_RGHT: return ARROW_RIGHT;
        default:      return ARROW_NONE;
    }
}

static uint16_t arrows[4] = {KC_UP, KC_DOWN, KC_LEFT, KC_RGHT};

uint16_t mod8_to_qk16(uint8_t mod_mask) {
    uint8_t left = mod_mask & 0x0f;
    uint8_t right = (mod_mask >> 4) & 0x0f;
    uint8_t mods = left | right;
    uint16_t qk_mod = ((uint16_t)mods) << 8;
    if (right) {
        qk_mod |= QK_RMODS_MIN;
    }
    return qk_mod;
}

static void arrow_update_mods(uint8_t add, uint8_t del) {
    uint8_t mods = 0x00;
    
    mods &= ~del;
    mods |= add;

    for (int i = 0; i < 4; i++ ) {
        if (arrow_state.held_keys & 1 << i) {
            unregister_code16(HYPR(arrows[i]));
            register_code16(mod8_to_qk16(mods) | arrows[i]);
        }
    }
}

static bool process_arrow_retrigger(uint16_t keycode, keyrecord_t* record) {
    if (is_arrow(keycode)) {
        arrow_bit_t arrow = arrow_bit(keycode);

        if (record->event.pressed) {
            set_arrow(arrow);

            if (arrow_state.ctrl_active) {
                uint32_t delay = timer_read() - arrow_state.last_press;

                if (arrow_state.last_key != arrow || delay > 150) {
                    register_code16(LCTL(keycode));
                    arrow_state.last_key = arrow;
                    return false;
                } else {
                    arrow_state.ctrl_active = false;
                }
            }

            arrow_state.ctrl_active = false;
            arrow_state.last_key = arrow;
        } else {
            clear_arrow(arrow);
            arrow_state.last_press = timer_read();
        }
        return true;
    }

    if (is_hrm(keycode) && QK_MOD_TAP_GET_MODS(keycode) & MOD_MASK_CS) {
        if (!record->tap.count){
            arrow_update_mods(0x00, 0x00);
            return true;
        }
    }

    if (keycode == CS_AL4) {
        if (record->tap.count) {
            return true;
        }

        if (record->event.pressed) {
            arrow_state.ctrl_active = true;
            arrow_update_mods(MOD_BIT_LCTRL, 0x00);
        } else if (arrow_state.ctrl_active) {
            arrow_state.ctrl_active = false;
            arrow_update_mods(0x00, MOD_BIT_LCTRL);
        }
        return true;
    }
    
    if (IS_LAYER_ON(_EDIT_OVERLAY)) {
        if (keycode == CS_LCTL) {
            if (record->event.pressed) {
                arrow_update_mods(MOD_BIT_LCTRL, 0x00);
                arrow_state.ctrl_active = true;
            }
            return true;
        }
    }

    arrow_state.ctrl_active = false;
    return true;
}

static bool process_edit_macros(uint16_t keycode, keyrecord_t* record) {
    static bool edit_clip = false;
    if (IS_LAYER_OFF(_EDIT)) {
        edit_clip = false;
    }

    switch (keycode) {
        case KC_PGDN:
            if (get_highest_layer(layer_state) != _EDIT_OVERLAY) {
                return true;
            }
            
            if (record->event.pressed) {
                if (ctrl_on() && IS_LAYER_ON(_EDIT)) {
                    register_code16(LCTL(KC_Y));
                    return false;
                }
            } else {
                unregister_code16(LCTL(KC_Y));
            }
            return true;

        case SELLEFT:
            if (record->event.pressed) {
                if (ctrl_on()) {
                    register_code16(LCTL(KC_Z));
                } else if (is_last_key(SELECT)) {
                    tap_code(KC_DEL);
                    edit_clip = true;
                    update_last_key(KC_DEL);
                } else {
                    register_code16(LSFT(LCTL(KC_LEFT)));
                    update_last_key(SELLEFT);
                }
            } else {
                unregister_code16(LCTL(KC_Z));
                unregister_code16(LSFT(LCTL(KC_LEFT)));
            }
            return false;

        case SELECT:
            if (record->event.pressed) {
                if (ctrl_on()) {
                    register_code16(LCTL(KC_X));
                } else {
                    const uint8_t mods = get_mods();
                    if (is_select_macro(get_last_key())) {
                        tap_code16(LCTL(KC_X));
                        edit_clip = true;
                    } else {
                        del_mods(MOD_MASK_CSAG);
                        tap_code(KC_RGHT);
                        tap_code16(LCTL(KC_LEFT));
                        tap_code16(LSFT(LCTL(KC_RGHT)));
                    }
                    set_mods(mods);
                    update_last_key(SELECT);
                }
            } else {
                unregister_code16(LCTL(KC_X));
            }
            return false;

        case SELRGHT:
            if (record->event.pressed) {
                if (ctrl_on() || is_last_key(SELECT)) {
                    register_code16(LCTL(KC_C));
                    edit_clip = true;
                } else {
                    register_code16(LSFT(LCTL(KC_RGHT)));
                    update_last_key(SELRGHT);
                }
            } else {
                unregister_code16(LCTL(KC_C));
                unregister_code16(LSFT(LCTL(KC_RGHT)));
            }
            return false;
            
        case WRAPCBR:
            if (record->event.pressed) {
                if (is_wrapping_macro(get_last_key())) {
                    rollback_wrapping_macro();
                }
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_CSAG);
                tap_code(KC_RGHT);
                tap_code16(LCTL(KC_LEFT));
                tap_code16(KC_LCBR);
                tap_code16(LCTL(KC_RGHT));
                tap_code16(KC_RCBR);
                set_mods(mods);
                update_last_key(keycode);
            }
            return false;
            
        case WRAPPRN:
            if (record->event.pressed) {
                if (is_wrapping_macro(get_last_key())) {
                    rollback_wrapping_macro();
                }
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_CSAG);
                tap_code(KC_RGHT);
                tap_code16(LCTL(KC_LEFT));
                tap_code16(KC_LPRN);
                tap_code16(LCTL(KC_RGHT));
                tap_code16(KC_RPRN);
                set_mods(mods);
                update_last_key(keycode);
            }
            return false;

        case WRAPBRC:
            if (record->event.pressed) {
                if (is_wrapping_macro(get_last_key())) {
                    rollback_wrapping_macro();
                }
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_CSAG);
                tap_code(KC_RGHT);
                tap_code16(LCTL(KC_LEFT));
                tap_code(KC_LBRC);
                tap_code16(LCTL(KC_RGHT));
                tap_code(KC_RBRC);
                set_mods(mods);
                update_last_key(keycode);
            }
            return false;

        case EO_ENT:
            if (record->event.pressed) {
                if (ctrl_on() || edit_clip || is_last_key(SELECT)) {
                    register_code16(LCTL(KC_V));
                    edit_clip = false;
                } else {
                    register_code(KC_ENT);
                }
            } else {
                unregister_code16(LCTL(KC_V));
                unregister_code(KC_ENT);
            }
            return false;
    }
    return true;
}



//==============================================================================
// Cycling Macros
//==============================================================================

typedef struct {
    uint misc :2;
    uint bracket :2;
    uint comp :2;
    uint wrap :2;
    uint num :4;
} cycling_macro_state_t;

static cycling_macro_state_t cycle_state = {
    .misc = 0,
    .bracket = 0,
    .comp = 0,
    .wrap = 0,
    .num = 0
};

static bool process_cycling_macros(uint16_t keycode, keyrecord_t* record) {
    if (keycode != CY_MISC) {
        cycle_state.misc = 0;
    }
    if (keycode != CY_BRC) {
        cycle_state.bracket = 0;
    }
    if (keycode != CY_COMP) {
        cycle_state.comp = 0;
    }
    if (keycode != CY_WRAP) {
        cycle_state.wrap = 0;
    }

    switch (keycode) {
        case CY_MISC:
            if (record->event.pressed) {
                switch (cycle_state.misc) {
                    case 0: {
                        const uint8_t mods = get_mods();
                        del_mods(MOD_MASK_CSAG);
                        tap_code16(KC_PERC);
                        set_mods(mods);

                        rollback_last_key();
                        update_last_key(KC_PERC);
                        cycle_state.misc = 1;
                        break;
                    }
                    case 1: {
                        const uint8_t mods = get_mods();
                        del_mods(MOD_MASK_CSAG);
                        tap_code(KC_BSPC);
                        tap_code16(KC_DQUO); // CS_AT
                        set_mods(mods);

                        rollback_last_key();
                        update_last_key(KC_HASH);
                        cycle_state.misc = 2;
                        break;
                    }
                    case 2: {
                        const uint8_t mods = get_mods();
                        del_mods(MOD_MASK_CSAG);
                        tap_code(KC_BSPC);
                        tap_code16(KC_HASH); // CS_POUN
                        set_mods(mods);

                        rollback_last_key();
                        update_last_key(KC_DQUO);
                        cycle_state.misc = 3;
                        break;
                    }
                    case 3: {
                        const uint8_t mods = get_mods();
                        del_mods(MOD_MASK_CSAG);
                        tap_code(KC_BSPC);
                        tap_code16(KC_PERC);
                        set_mods(mods);

                        rollback_last_key();
                        update_last_key(KC_PERC);
                        cycle_state.misc = 1;
                        break;
                    }
                }
            }
            break;

        case CY_BRC:
            if (record->event.pressed) {
                switch (cycle_state.bracket) {
                    case 0: {
                        const uint8_t mods = get_mods();
                        del_mods(MOD_MASK_CSAG);
                        tap_code16(KC_LPRN);
                        tap_code16(KC_RPRN);
                        tap_code(KC_LEFT);
                        set_mods(mods);

                        update_last_keys(CY_BRC,2);
                        cycle_state.bracket = 1;
                        break;
                    }
                    case 1: {
                        const uint8_t mods = get_mods();
                        del_mods(MOD_MASK_CSAG);
                        tap_code(KC_DEL);
                        tap_code(KC_BSPC);
                        tap_code16(KC_LCBR);
                        tap_code16(KC_RCBR);
                        tap_code(KC_LEFT);
                        set_mods(mods);

                        cycle_state.bracket = 2;
                        break;
                    }
                    case 2: {
                        const uint8_t mods = get_mods();
                        del_mods(MOD_MASK_CSAG);
                        tap_code(KC_DEL);
                        tap_code(KC_BSPC);
                        tap_code(KC_LBRC);
                        tap_code(KC_RBRC);
                        tap_code(KC_LEFT);
                        set_mods(mods);

                        cycle_state.bracket = 3;
                        break;
                    }
                    case 3: {
                        const uint8_t mods = get_mods();
                        del_mods(MOD_MASK_CSAG);
                        tap_code(KC_DEL);
                        tap_code(KC_BSPC);
                        tap_code16(KC_LPRN);
                        tap_code16(KC_RPRN);
                        tap_code(KC_LEFT);
                        set_mods(mods);

                        cycle_state.bracket = 1;
                        break;
                    }
                }
            }
            break;

        case CY_COMP: 
            if (record->event.pressed) {
                switch (cycle_state.comp) {
                    case 0: {
                        cs_tap_code16_del_mods(KC_GT, MOD_MASK_CSAG);

                        update_last_key(KC_GT);
                        cycle_state.comp = 1;
                        break;
                    }
                    case 1: {
                        const uint8_t mods = get_mods();
                        del_mods(MOD_MASK_CSAG);
                        tap_code(KC_BSPC);
                        tap_code16(KC_LT);
                        set_mods(mods);

                        rollback_last_key();
                        update_last_key(KC_LT);
                        cycle_state.comp = 2;
                        break;
                    }
                    case 2: {
                        const uint8_t mods = get_mods();
                        del_mods(MOD_MASK_CSAG);
                        tap_code(KC_BSPC);
                        tap_code(KC_EQL);
                        set_mods(mods);

                        rollback_last_key();
                        update_last_key(KC_EQL);
                        cycle_state.comp = 3;
                        break;
                    }
                    case 3: {
                        const uint8_t mods = get_mods();
                        del_mods(MOD_MASK_CSAG);
                        tap_code(KC_BSPC);
                        tap_code16(KC_GT);
                        set_mods(mods);

                        rollback_last_key();
                        update_last_key(KC_GT);
                        cycle_state.comp = 1;
                        break;
                    }
                }
            }
            break;

        case CY_WRAP:
            if (record->event.pressed) {
                if (ctrl_on() && IS_LAYER_ON(_EDIT)) {
                    register_code16(LCTL(KC_Y));
                    return false;
                }

                switch (cycle_state.wrap) {
                    case 0: {
                        const uint8_t mods = get_mods();
                        del_mods(MOD_MASK_CSAG);
                        tap_code(KC_RGHT);
                        tap_code16(LCTL(KC_LEFT));
                        tap_code16(KC_LPRN);
                        tap_code16(LCTL(KC_RGHT));
                        tap_code16(KC_RPRN);
                        set_mods(mods);
                        cycle_state.wrap = 1;
                        break;
                    }
                    case 1: {
                        rollback_wrapping_macro();
                        const uint8_t mods = get_mods();
                        del_mods(MOD_MASK_CSAG);
                        tap_code(KC_RGHT);
                        tap_code16(LCTL(KC_LEFT));
                        tap_code16(KC_LCBR);
                        tap_code16(LCTL(KC_RGHT));
                        tap_code16(KC_RCBR);
                        set_mods(mods);
                        cycle_state.wrap = 2;
                        break;
                    }
                    case 2: {
                        rollback_wrapping_macro();
                        const uint8_t mods = get_mods();
                        del_mods(MOD_MASK_CSAG);
                        tap_code(KC_RGHT);
                        tap_code16(LCTL(KC_LEFT));
                        tap_code(KC_LBRC);
                        tap_code16(LCTL(KC_RGHT));
                        tap_code(KC_RBRC);
                        set_mods(mods);
                        cycle_state.wrap = 3;
                        break;
                    }
                    case 3: {
                        rollback_wrapping_macro();
                        const uint8_t mods = get_mods();
                        del_mods(MOD_MASK_CSAG);
                        tap_code(KC_RGHT);
                        tap_code16(LCTL(KC_LEFT));
                        tap_code16(KC_LPRN);
                        tap_code16(LCTL(KC_RGHT));
                        tap_code16(KC_RPRN);
                        set_mods(mods);
                        cycle_state.wrap = 1;
                        break;
                    }
                }
            }
            break;

        case CY_ENUM:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                uint16_t num_key = cycle_state.num == 0 ? KC_0 : KC_1 + cycle_state.num - 1;
                if (shifted()) {
                    if (get_last_key() == num_key) {
                        del_mods(MOD_MASK_CS);
                        tap_code(KC_BSPC);
                        set_mods(mods);
                    }
                }
                if (ctrl_on()) {
                    cycle_state.num = (cycle_state.num + 9) % 10;
                } else {
                    cycle_state.num = (cycle_state.num + 1) % 10;
                }
                char num[2] = {'0' + cycle_state.num, '\0'};
                cs_send_string(num);
                num_key = cycle_state.num == 0 ? KC_0 : KC_1 + cycle_state.num - 1;
                update_last_key(num_key);
            }
            break;
    }
    return true;
}



//==============================================================================
// Repeat and Magic keys
//==============================================================================

typedef struct {
    uint8_t count;
    uint16_t last_key;
    uint16_t last_key_2;
    uint16_t last_key_3;
    bool dynamic :1;
} recent_key_state_t;

static recent_key_state_t recent_key_state = {
    .count       = 1,
    .last_key    = KC_NO,
    .last_key_2  = KC_NO,
    .last_key_3  = KC_NO,
    .dynamic     = false
};

static inline bool is_last_key(uint16_t keycode) {
    return keycode == recent_key_state.last_key;
}

static inline uint16_t get_last_key(void) {
    return recent_key_state.last_key;
}

static inline uint16_t get_last_key_2(void) {
    return recent_key_state.last_key_2;
}

static void rollback_last_key(void) {
    recent_key_state.count = 1;

    recent_key_state.last_key   = recent_key_state.last_key_2;
    recent_key_state.last_key_2 = recent_key_state.last_key_3;
    recent_key_state.last_key_3 = KC_NO;
}

static void update_last_key(uint16_t new_keycode) {
    recent_key_state.last_key_3 = recent_key_state.last_key_2;
    recent_key_state.last_key_2 = recent_key_state.last_key;
    recent_key_state.last_key   = new_keycode;

    recent_key_state.count = 1;
}

static void update_last_keys(uint16_t new_keycode, uint8_t new_count) {
    recent_key_state.last_key_3 = recent_key_state.last_key_2;
    recent_key_state.last_key_2 = recent_key_state.last_key;
    recent_key_state.last_key   = new_keycode;
    
    recent_key_state.count = new_count;
}

static bool process_rollback(void) {
    if (ctrl_on()) {
        recent_key_state.count = 1;

        recent_key_state.last_key   = KC_NO;
        recent_key_state.last_key_2 = KC_NO;
        recent_key_state.last_key_3 = KC_NO;
        return true;
    }

    if (is_wrapping_macro(get_last_key()) && recent_key_state.count == 2) {
        rollback_wrapping_macro();
        return false;
    }

    if (is_last_key(CY_BRC) && recent_key_state.count == 2) {
        tap_code(KC_RGHT);
    }

    for (int i = 1; i < recent_key_state.count; i++) {
        tap_code(KC_BSPC);
    }
    rollback_last_key();

    return true;
}

static bool process_key_tracking(uint16_t keycode, keyrecord_t* record) {
    if (!record->event.pressed) {
        return true;
    }

    if (is_layer_tap(keycode)) {
        if (!record->tap.count) {
            return true;
        }
    }

    if (ctrl_on()) {
        switch (keycode) {
            case UNDO:
            case KC_Z:
                update_last_key(UNDO);
                return true;
            case REDO:
            case KC_Y:
                update_last_key(REDO);
                return true;
            case CS_CONJ:
            case CS_DISJ:
                break;
            default:
                recent_key_state.count = 1;
        }
    }

    if (is_alpha(keycode) || is_num(keycode) || is_cs_symbol(keycode)) {
        update_last_key(keycode);
        return true;
    }
    if (is_symbol_hrm(keycode)) {
        if (record->tap.count) {
            update_last_key(cs_map(keycode));
        }
        return true;
    }
    if (is_hrm(keycode)) {
        if (record->tap.count) {
            update_last_key(QK_MOD_TAP_GET_TAP_KEYCODE(keycode));
        }
        return true;
    }

    if (keycode == CS_LT1) {
        if (record->tap.count) {
            update_last_key(KC_SPC);
        }
        return true;
    }
    if (keycode == KC_SPC) {
        update_last_key(KC_SPC);
        return true;
    }
    if (keycode == NEWSENT) {
        update_last_keys(KC_SPC, 2);
        return true;
    }

    if (keycode == KC_ENT) {
        update_last_key(KC_NO);
        return true;
    }

    if (keycode == TABLSFT || keycode == TABRSFT) {
        if (record->tap.count) {
            update_last_key(KC_SPC);
        }
        return true;
    }

    if (keycode == KC_COMM || keycode == CS_COMM || (keycode == COM_EXL && !shifted())) {
        update_last_key(KC_COMM);
        return true;
    }
    if (keycode == KC_DOT || keycode == CS_DOT || (keycode == DOT_QUE && !shifted())) {
        update_last_key(KC_DOT);
        return true;
    }
    if (keycode == KC_QUOT || keycode == CS_QUOT) {
        update_last_key(KC_QUOT);
        return true;
    }
    if (keycode == KC_GRV) {
        update_last_key(KC_GRV);
        return true;
    }

    if (keycode == CS_CONJ || keycode == CS_DISJ) {
        if (ctrl_on() && shifted()) {
            update_last_keys(KC_NO, 4);
        } else if (ctrl_on()) {
            update_last_keys(KC_NO, 3);
        } else if (shifted()) {
            update_last_keys(KC_NO, 2);
        } else {
            update_last_key(KC_NO);
        }
        return true;
    }

    // Tracking handled in macro for reactive events
    if (is_select_macro(keycode) || keycode == EO_ENT) {
        return true;
    }
    if (is_wrapping_macro(keycode)) {
        return true;
    }
    if (is_cycling_macro(keycode)) {
        return true;
    }

    if (keycode == CS_RT1) {
        if (record->tap.count) {
            return process_rollback();
        }
        return true;
    }
    if (keycode == KC_BSPC) {
        return process_rollback();
    }

    if (is_magic(keycode)) {
        return true;
    }

    if (keycode == KC_LSFT || keycode == OSMLSFT ||
        keycode == KC_LCTL || keycode == CS_LCTL ||
        keycode == TABLSFT || keycode == TABRSFT) {
        // Tap actions for tab-shift keys already handled earlier
        return true;
    }

    update_last_key(KC_NO);
    return true;
}

static inline void start_sentence(void) {
    tap_code(KC_SPC);
    set_oneshot_mods(MOD_BIT(KC_LSFT));
    update_last_key(KC_SPC);
}

static bool process_magic(uint16_t keycode, keyrecord_t* record) {
    if (keycode == CS_LT2) {
        if (!record->tap.count && record->event.pressed) {
            layer_lock_off(_EDIT);
            layer_on(_EDIT);
            update_tri_layer(_EDIT, _SYMBOL, _DATA_OVERLAY);
            update_tri_layer(_EDIT, _PROGRAM, _EDIT_OVERLAY);
        } else if (!is_layer_locked(_EDIT)) {
            layer_off(_EDIT);
            update_tri_layer(_EDIT, _SYMBOL, _DATA_OVERLAY);
            update_tri_layer(_EDIT, _PROGRAM, _EDIT_OVERLAY);
        }

        if (record->tap.count && record->event.pressed) {
            if (is_layer_locked(_EDIT)) {
                layer_lock_off(_EDIT);
                return false;
            }
            const uint8_t mods = get_mods();
            del_mods(MOD_MASK_CTRL);
            recent_key_state.dynamic = true;

            if (get_highest_layer(layer_state) == _QWERTY) {
                tap_code(get_last_key());
                update_last_key(get_last_key());
                set_mods(mods);
                return false;
            }
            
            const uint16_t last_key = cs_map(get_last_key());
            switch (last_key) {
                // Left hand keys
                case KC_Z: tap_code(KC_N); update_last_key(KC_N); break;
                case KC_L: tap_code(KC_R); update_last_key(KC_R); break;
                case KC_D: tap_code(KC_G); update_last_key(KC_G); break;
                case KC_C: tap_code(KC_S); update_last_key(KC_S); break;
                case KC_B: send_string(/*b*/"ecause "); update_last_keys(KC_SPC, 7); break;

                case KC_N: cs_send_string_punct("'t "); update_last_keys(KC_SPC,3); break;
                case KC_R: tap_code(KC_L); update_last_key(KC_L); break;
                case KC_T: send_string(/*t*/"ment"); update_last_keys(KC_T, 4); break;
                case KC_S: tap_code(KC_C); update_last_key(KC_C); break;
                case KC_G: tap_code(KC_S); update_last_key(KC_S); break;

                case KC_Q: tap_code(KC_U); update_last_key(KC_U); break;
                case KC_X: tap_code(KC_C); update_last_key(KC_C) ;break;
                case KC_M: send_string(/*m*/"ent"); update_last_keys(KC_T, 3); break;
                case KC_W: tap_code(KC_S); update_last_key(KC_S); break;
                case KC_V: tap_code(KC_S); update_last_key(KC_S); break;

                // Right hand overrides
                case KC_J: send_string(/*j*/"ect"); update_last_keys(KC_T, 3); break;
                case KC_O: tap_code(KC_E); update_last_key(KC_E); break;
                case KC_U: tap_code(KC_I); update_last_key(KC_I); break;
                case KC_Y: tap_code(KC_P); update_last_key(KC_P); break;
                case KC_H: send_string(/*h*/"ere"); update_last_keys(KC_E, 3); break;
                case KC_E: tap_code(KC_O); update_last_key(KC_O); break;
                case KC_I: send_string(/*i*/"on"); update_last_keys(KC_N, 2); break;
                case KC_A: send_string(/*a*/"nd "); update_last_keys(KC_SPC, 3); break;
                case KC_K: send_string(/*k*/"now"); update_last_keys(KC_SPC, 4); break;

                case KC_NO:
                case KC_SPC: set_oneshot_mods(MOD_BIT(KC_LSFT)); break;
                case KC_COMM: send_string(" and "); update_last_keys(KC_SPC, 4); break;
                case KC_DOT: start_sentence(); break;
                case KC_QUOT: send_string("ve "); update_last_keys(KC_SPC, 3); break;

                case UNDO:
                case REDO: tap_code16(LCTL(KC_Y)); update_last_key(REDO); break;

                default:
                    if (is_alpha(last_key)) {
                        tap_code(last_key);
                    } else {
                        cs_tap_code16(last_key);
                    }
                    update_last_key(get_last_key());
                    break;
            }
            set_mods(mods);

            if (is_last_key(KC_SPC)) {
                if (misc_key_state.capsword_active) {
                    del_mods(MOD_BIT(KC_LSFT));
                }
                misc_key_state.capsword_active = false;
            }

            if (case_lock_state.active) {
                case_lock_state.distance += recent_key_state.count;
                dprintf("separator distance = %d\n", case_lock_state.distance);
            }
        }
        return false;
    }

    if (keycode == CS_RT2) {
        if (!record->tap.count && record->event.pressed) {
            layer_on(_PROGRAM);
            update_tri_layer(_EDIT, _PROGRAM, _EDIT_OVERLAY);
            update_tri_layer(_DATA, _PROGRAM, _EDIT);
        } else {
            layer_off(_PROGRAM);
            if (IS_LAYER_OFF(_EDIT_OVERLAY)) {
                update_tri_layer(_DATA, _PROGRAM, _EDIT);
            }
            update_tri_layer(_EDIT, _PROGRAM, _EDIT_OVERLAY);
            layer_off(_DATA_OVERLAY);
        }

        if (record->tap.count && record->event.pressed) {
            const uint8_t mods = get_mods();
            del_mods(MOD_MASK_CTRL);
            recent_key_state.dynamic = true;

            if (get_highest_layer(layer_state) == _QWERTY) {
                tap_code(get_last_key());
                update_last_key(get_last_key());
                set_mods(mods);
                return false;
            }

            const uint16_t last_key = cs_map(get_last_key());
            switch (last_key) {
                // Right hand keys
                case KC_J: send_string(/*j*/"ust"); update_last_keys(KC_T, 3); break;
                case KC_F: tap_code(KC_Y); update_last_key(KC_Y); break;
                case KC_O: tap_code(KC_O); update_last_key(KC_O); break;
                case KC_U: tap_code(KC_I); update_last_key(KC_I); break;

                case KC_Y: tap_code(KC_P); update_last_key(KC_P); break;
                case KC_H: tap_code(KC_Y); update_last_key(KC_Y); break;
                case KC_E: tap_code(KC_E); update_last_key(KC_E); break;
                case KC_I: tap_code(KC_U); update_last_key(KC_U); break;
                case KC_A: send_string(/*a*/"ph"); update_last_keys(KC_H, 2); break;

                case KC_K: tap_code(KC_Y); update_last_key(KC_Y); break;
                case KC_P: tap_code(KC_H); update_last_key(KC_H); break;

                // Left hand overrides
                case KC_X: send_string(/*x*/"es"); update_last_keys(KC_S, 2); break;
                case KC_V: send_string(/*v*/"er"); update_last_keys(KC_R, 2); break;
                case KC_W: send_string(/*w*/"ith"); update_last_keys(KC_H, 3); break;

                case KC_NO:
                case KC_SPC: cs_send_string_leading("the"); update_last_keys(KC_E,3); break;
                case KC_COMM: send_string(" but "); update_last_keys(KC_SPC, 4); break;
                case KC_DOT: send_string("com"); update_last_keys(KC_NO, 3); break;
                case KC_QUOT: send_string("re "); update_last_keys(KC_SPC, 3); break;

                case UNDO:
                case REDO: tap_code16(LCTL(KC_Z)); update_last_key(UNDO); break;

                default:
                    if (is_alpha(last_key)) {
                        tap_code(last_key);
                    } else {
                        cs_tap_code16(last_key);
                    }
                    update_last_key(get_last_key());
                    break;
            }
            set_mods(mods);

            if (is_last_key(KC_SPC)) {
                if (misc_key_state.capsword_active) {
                    del_mods(MOD_BIT(KC_LSFT));
                }
                misc_key_state.capsword_active = false;
            }

            if (case_lock_state.active) {
                case_lock_state.distance += recent_key_state.count;
                dprintf("separator distance = %d\n", case_lock_state.distance);
            }
        }
        return false;
    }

    recent_key_state.dynamic = false;
    return true;
}

static bool process_punctuation_space(uint16_t keycode, keyrecord_t* record) {
    if (is_last_key(KC_SPC) && recent_key_state.dynamic) {
        switch (keycode) {
            case KC_DOT:
            case CS_DOT:
            case KC_COMM:
            case CS_COMM:
            case COM_EXL:

            case KC_EXLM:
            case CS_EXLM:

            case KC_QUES:
            case CS_QUES:

            case KC_SCLN:
            case CS_SCLN:
                tap_code(KC_BSPC);
        }
    }
    return true;
}



//==============================================================================
// Magic punctuation
//==============================================================================

typedef enum {
    JUST,       // Match keycode
    IU_VOWEL,   // Match I, U
    EO_VOWEL,   // Match E, O
    ANY_VOWEL,  // Match A, E, I, O, U
    ANY_SPACE,  // Match space/tab
    ANY_LETTER, // Match any letter
    ANY_KEY,    // Match any key
    IMMEDIATE,  // Immediately emit output -- should only be used in `next` field
} keymatch_kind_t;

typedef enum {
    NONE,
    LEFT,
    RIGHT,
    EITHER,
} magic_key_t;

typedef struct {
    keymatch_kind_t kind;
    uint16_t keycode;
} keymatch_t;

typedef struct {
    bool consume_next;
    uint16_t keycode;
    uint8_t length;
} track_t;

typedef struct {
    magic_key_t key;
    keymatch_t prev;
    keymatch_t next;
    const char* output;
    track_t track;
} keymatch_rule_t;

static const keymatch_rule_t match_rules[] = {
    { EITHER, { JUST, KC_N    }, { JUST, KC_T    }, /*n*/"'t ",  { true, KC_SPC,  3 } },
    { EITHER, { JUST, KC_N    }, { JUST, KC_B    }, /*n*/".b.",  { true, KC_DOT,  3 } },
    { LEFT,   { JUST, KC_I    }, { JUST, KC_E    }, /*i*/".e.",  { true, KC_DOT,  3 } },
    { LEFT,   { JUST, KC_A    }, { JUST, KC_M    }, /*a*/".m.",  { true, KC_DOT,  3 } },
    { EITHER, { JUST, KC_P    }, { JUST, KC_M    }, /*p*/".m.",  { true, KC_DOT,  3 } },
    { RIGHT,  { ANY_SPACE     }, { IMMEDIATE     }, /*⎵*/"-",    { true, KC_MINS, 1 } },
    { RIGHT,  { JUST, KC_E    }, { JUST, KC_G    }, /*e*/".g.",  { true, KC_DOT,  3 } },
    { EITHER, { ANY_KEY       }, { JUST, KC_ENT  }, /*-*/";",    { false            } },
    { EITHER, { ANY_KEY       }, { JUST, CS_LT3  }, /*-*/";",    { false            } },
    { LEFT,   { JUST, KC_S    }, { ANY_SPACE     }, /*s*/"'",    { false            } },
    { EITHER, { ANY_LETTER    }, { ANY_SPACE     }, /*-*/",",    { false            } },
    { EITHER, { ANY_LETTER    }, { JUST, KC_D    }, /*-*/"'d ",  { true, KC_SPC,  3 } },
    { EITHER, { ANY_LETTER    }, { JUST, KC_L    }, /*-*/"'ll ", { true, KC_SPC,  4 } },
    { EITHER, { ANY_LETTER    }, { JUST, KC_V    }, /*-*/"'ve ", { true, KC_SPC,  4 } },
    { EITHER, { ANY_LETTER    }, { JUST, KC_M    }, /*-*/"'m ",  { true, KC_SPC,  3 } },
    { EITHER, { ANY_LETTER    }, { JUST, KC_S    }, /*-*/"'s ",  { true, KC_SPC,  3 } },
    { EITHER, { ANY_LETTER    }, { JUST, KC_R    }, /*-*/"'re ", { true, KC_SPC,  4 } },

    // Double taps and rolls
    { LEFT,   { JUST, PCTLEFT }, { IMMEDIATE     }, "''",   { true, KC_QUOT, 2 } }, // -> [-]'
    { LEFT,   { JUST, PCTRGHT }, { IMMEDIATE     }, "''",   { true, KC_QUOT, 2 } }, // -> [-]'
    { RIGHT,  { JUST, PCTLEFT }, { IMMEDIATE     }, ",",    { true, KC_COMM, 1 } }, // -> [-],
    { RIGHT,  { JUST, PCTRGHT }, { IMMEDIATE     }, ",",    { true, KC_COMM, 1 } }, // -> [-],
};

static bool pattern_match_key(keymatch_t keymatch, uint16_t keycode) {
    if (is_hrm(keycode)) {
        keycode = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
    }
    switch (keymatch.kind) {
        case JUST:       return keycode == keymatch.keycode;
        case IU_VOWEL:   return keycode == KC_I || keycode == KC_U;
        case EO_VOWEL:   return keycode == KC_E || keycode == KC_O;
        case ANY_VOWEL:  return keycode == KC_A || keycode == KC_E ||
                                keycode == KC_I || keycode == KC_O ||
                                keycode == KC_U;
        case ANY_SPACE:  return keycode == KC_SPC || keycode == KC_TAB ||
                                keycode == CS_LT1 || keycode == TABLSFT ||
                                keycode == TABRSFT;
        case ANY_LETTER: return is_alpha(keycode) || is_magic(keycode);
        case ANY_KEY:    return !is_magic_punct(keycode) && keycode != KC_NO;
        default:         return false;
    }
}

typedef struct {
    magic_key_t active;
    uint16_t last_key;
    uint16_t current;
    deferred_token token;
} magic_flag_t;

static magic_flag_t magic_state = {
    .active = NONE,
    .last_key = KC_NO,
    .current = KC_NO,
    .token = INVALID_DEFERRED_TOKEN
};

static inline void update_magic_punctuation_history(uint16_t keycode) {
    if (!is_magic_punct(keycode)) {
        magic_state.active = NONE;
    }
    magic_state.last_key = magic_state.current;
    magic_state.current = keycode;
}

static inline void reset_magic_punctuation_history(void) {
    magic_state.active = NONE;
    magic_state.last_key = KC_NO;
    magic_state.current = KC_NO;
}

static inline void resolve_magic_punctuation_fallback(void) {
    cancel_deferred_exec(magic_state.token);
    if (magic_state.active == LEFT) {
        cs_tap_code(KC_QUOT);
        update_last_key(KC_QUOT);
    } else if (magic_state.active == RIGHT) {
        cs_tap_code(KC_COMM);
        update_last_key(KC_COMM);
    }
}

uint32_t PCTLEFT_fallback(uint32_t trigger_time, void *cb_arg) {
    cs_tap_code(KC_QUOT);
    update_last_key(KC_QUOT);
    reset_magic_punctuation_history();
    return 0;
}

uint32_t PCTRGHT_fallback(uint32_t trigger_time, void *cb_arg) {
    cs_tap_code(KC_COMM);
    update_last_key(KC_COMM);
    reset_magic_punctuation_history();
    return 0;
}

static inline bool apply_magic_punctuation_rule(size_t i) {
    keymatch_rule_t const *rule = &match_rules[i];
    cs_send_string_punct(rule->output);
    reset_magic_punctuation_history();
    cancel_deferred_exec(magic_state.token);
    if (rule->track.consume_next) {
        update_last_keys(rule->track.keycode, rule->track.length);
    }
    dprintf("rule matched: %d\n", i);
    return !rule->track.consume_next;
}

static bool process_magic_punctuation(uint16_t keycode, keyrecord_t* record) {
    if (!record->event.pressed) {
        return true;
    }
    if ((IS_QK_MOD_TAP(keycode) || IS_QK_LAYER_TAP(keycode)) && !record->tap.count) {
        return true;
    }

    switch (keycode) {
        case PCTLEFT:
            if (shifted()) {
                cs_tap_code16(LSFT(KC_QUOT));
                return true;
            }
            magic_state.active = LEFT;
            cancel_deferred_exec(magic_state.token);
            magic_state.token = defer_exec(500, PCTLEFT_fallback, NULL);
            break;

        case PCTRGHT:
            if (shifted()) {
                cs_tap_code16(LSFT(KC_NUHS));
                return true;
            }
            magic_state.active = RIGHT;
            cancel_deferred_exec(magic_state.token);
            magic_state.token = defer_exec(500, PCTRGHT_fallback, NULL);
            break;

        default:
            break;
    }

    for (size_t i = 0; i < sizeof(match_rules)/sizeof(match_rules[0]); i++) {
        keymatch_rule_t const *rule = &match_rules[i];

        // Skip if key doesn't match
        if (magic_state.active == NONE || (rule->key != magic_state.active && rule->key != EITHER)) {
            continue;
        }

        const bool immediate = rule->next.kind == IMMEDIATE && is_magic_punct(keycode) &&
            pattern_match_key(rule->prev, magic_state.current);
        const bool sequential = pattern_match_key(rule->prev, magic_state.last_key) &&
            pattern_match_key(rule->next, keycode);

        if (immediate || sequential) {
            return apply_magic_punctuation_rule(i);
        }
    }

    if (!magic_state.token) {
        update_magic_punctuation_history(keycode);
        return true;
    }

    if (!is_magic_punct(keycode)) {
        cancel_deferred_exec(magic_state.token);
        resolve_magic_punctuation_fallback();
        reset_magic_punctuation_history();
        update_magic_punctuation_history(keycode);
        return true;
    }
    if (keycode == magic_state.current) {
        cancel_deferred_exec(magic_state.token);
        resolve_magic_punctuation_fallback();
        reset_magic_punctuation_history();
        return true;
    }

    update_magic_punctuation_history(keycode);
    return true;
}



//==============================================================================
// Deferred Executions
//==============================================================================

//------------------------------------------------------------------------------
// Lingering modifiers
//------------------------------------------------------------------------------

static bool ctrl_linger = false;

static uint32_t ctrl_linger_callback(uint32_t trigger_time, void *cb_arg) {
    ctrl_linger = false;
    return 0;
}

static bool process_lingering_mods(uint16_t keycode, keyrecord_t* record) {
    if (!record->event.pressed) {
        return true;
    }

    if (keycode == CS_LCTL) {
        ctrl_linger = true;
        defer_exec(500, ctrl_linger_callback, NULL);
        clear_oneshot_mods();
        return true;
    }

    if (keycode == CS_RT1) {
        if (record->tap.count) {
            if (ctrl_linger) {
                const uint8_t mods = get_mods();
                tap_code16(LCTL(KC_BSPC));
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

    // Reset on any other keypress
    ctrl_linger = false;
    return true;
}

//------------------------------------------------------------------------------
// Volume keys
//------------------------------------------------------------------------------

uint32_t vold_action(uint32_t trigger_time, void *cb_arg) {
    tap_code16(KC_VOLD);
    return 30;
}

uint32_t volu_action(uint32_t trigger_time, void *cb_arg) {
    tap_code16(KC_VOLU);
    return 50;
}

static bool process_vol_controls(uint16_t keycode, keyrecord_t* record) {
    static deferred_token vold_token = INVALID_DEFERRED_TOKEN;
    static deferred_token volu_token = INVALID_DEFERRED_TOKEN;

    switch (keycode) {
        case CS_VOLD:
            if (record->event.pressed) {
                if (!shifted()) {
                    vold_action(0,NULL);
                    vold_token = defer_exec(30,vold_action,NULL);
                } else {
                    tap_code16(KC_VOLD);
                }
            } else {
                cancel_deferred_exec(vold_token);
            }
            return false;

        case CS_VOLU:
            if (record->event.pressed) {
                if (!shifted()) {
                    volu_action(0,NULL);
                    volu_token = defer_exec(15,volu_action,NULL);
                } else {
                    tap_code16(KC_VOLU);
                }
            } else {
                cancel_deferred_exec(volu_token);
            }
            return false;

        default:
            return true;
    }
}

//------------------------------------------------------------------------------
// Clock
//------------------------------------------------------------------------------

static uint32_t clock_callback(uint32_t trigger_time, void* cb_arg) {
    if (!host_clock_active || timer_elapsed(last_host_clock_update) >= HOST_CLOCK_TIMEOUT) {
        clock_state.sec++;
        if (clock_state.sec >= 60) {
            clock_state.sec = 0;
            clock_state.min++;
        }
        if (clock_state.min >= 60) {
            clock_state.min = 0;
            clock_state.hrs++;
        }
        if (clock_state.hrs >= 24) {
            clock_state.hrs = 0;
        }

        host_clock_active = false;
    }

    return 1000;
}

static uint32_t clock_up_action(uint32_t trigger_time, void *cb_arg) {
    switch (clock_state.setting) {
        case set_hour:
            clock_state.hrs = (clock_state.hrs + 1) % 24;
            return 200;
        case set_min:
            clock_state.min = (clock_state.min + 1) % 60;
            return 150;
        case set_sec:
            clock_state.sec = (clock_state.sec + 1) % 60;
            return 150;

        default:
        case set_none:
            return 0;
    }
}

static uint32_t clock_dn_action(uint32_t trigger_time, void *cb_arg) {
    switch (clock_state.setting) {
        case set_hour:
            clock_state.hrs = clock_state.hrs == 0 ? 23 : clock_state.hrs - 1;
            return 200;
        case set_min:
            clock_state.min = clock_state.min == 0 ? 59 : clock_state.min - 1;
            return 150;
        case set_sec:
            clock_state.sec = clock_state.sec == 0 ? 59 : clock_state.sec - 1;
            return 150;

        default:
        case set_none:
            return 0;
    }
}

static deferred_token clock_up_token = INVALID_DEFERRED_TOKEN;
static deferred_token clock_dn_token = INVALID_DEFERRED_TOKEN;

static bool process_clock_controls(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case CLOCKNX:
            if (record->event.pressed) {
                if (!shifted()) {
                    clock_state.setting = (clock_state.setting + 1) % 4;
                } else {
                    clock_state.setting = clock_state.setting == 0 ? 3 : clock_state.setting - 1;
                }
            }
            return false;

        case CLOCKUP:
            if (record->event.pressed) {
                clock_up_action(0, NULL);
                clock_up_token = defer_exec(100, clock_up_action, NULL);
            } else {
                cancel_deferred_exec(clock_up_token);
                clock_up_token = INVALID_DEFERRED_TOKEN;
            }
            return false;

        case CLOCKDN:
            if (record->event.pressed) {
                clock_dn_action(0, NULL);
                clock_dn_token = defer_exec(100, clock_dn_action, NULL);
            } else {
                cancel_deferred_exec(clock_dn_token);
                clock_dn_token = INVALID_DEFERRED_TOKEN;
            }
            return false;

        default: 
            return true;
    }
}



//==============================================================================
// Eager mods
//==============================================================================

typedef struct {
    uint16_t keycode;
    uint8_t mods;
    bool active :1;
    int8_t row, col;
} eager_key_t;

static eager_key_t eager_keys[] = {
    { TABLSFT, MOD_BIT(KC_LSFT), false, -1, -1 },
    { TABRSFT, MOD_BIT(KC_RSFT), false, -1, -1 }
};

static eager_key_t* eager_keycode(uint16_t keycode) {
    for (size_t i = 0; i < ARRAY_SIZE(eager_keys); i++) {
        if (eager_keys[i].keycode == keycode) {
            return &eager_keys[i];
        }
    }
    return NULL;
}

static eager_key_t* eager_keypos(uint8_t row, uint8_t col) {
    for (size_t i = 0; i < ARRAY_SIZE(eager_keys); i++) {
        if (eager_keys[i].row == row && eager_keys[i].col == col) {
            return &eager_keys[i];
        }
    }
    return NULL;
}

bool pre_process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!record->event.pressed) {
        return true;
    }

    eager_key_t *ek = eager_keycode(keycode);

    if (ek && !(get_mods() & ek->mods)) {
        register_mods(ek->mods);
        ek->active = true;
        ek->row = record->event.key.row;
        ek->col = record->event.key.col;
    }
    return true;
}

bool process_eager_mods(uint16_t keycode, keyrecord_t* record) {
    eager_key_t *ek = eager_keycode(keycode);

    if (ek) {
        if (!record->tap.count && !record->event.pressed) {
            unregister_mods(ek->mods);
        }
        if (record->tap.count & record->event.pressed) {
            if (ek->active) {
                unregister_mods(ek->mods);
            }
            switch (ek->keycode) {
                case TABLSFT:
                    if (IS_LAYER_OFF(_CONTROL_OVERLAY)) {
                        tap_code(KC_TAB);
                    }
                    break;
                case TABRSFT:
                    tap_code(KC_TAB);
                    break;
            }
        }
        ek->active = false;
        return false;
    }

    if (!record->event.pressed) {
        ek = eager_keypos(record->event.key.row, record->event.key.col);
        if (ek && ek->active) {
            unregister_mods(ek->mods);
            ek->active = false;
        }
    }

    return true;
}



//==============================================================================
// Events
//==============================================================================

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_case_lock(keycode, record)) { return false; }
    if (!process_cycling_macros(keycode, record)) { return false; }
    if (!process_capsword(keycode, record)) { return false; }
    if (!process_punctuation_space(keycode, record)) { return false; }
    // Reactive features go before key tracking
    if (!process_key_tracking(keycode, record)) { return false; }
    if (!process_magic_punctuation(keycode, record)) { return false; }
    if (!process_lingering_mods(keycode, record)) { return false; }
    if (!process_eager_mods(keycode, record)) { return false; }
    if (!process_magic(keycode, record)) { return false; }
    if (!process_homerow_mod_tap(keycode, record)) { return false; }
    if (!process_arrow_retrigger(keycode, record)) { return false; }
    if (!process_cs_layer_tap(keycode, record)) { return false; }
    if (!process_edit_macros(keycode, record)) { return false; }
    if (!process_vol_controls(keycode, record)) { return false; }
    if (!process_clock_controls(keycode, record)) { return false; }
    if (!process_mouse_lock(keycode, record)) { return false; }
    if (!process_trackball_keys(keycode, record)) { return false; }

    switch (keycode) {

        case CS_SYMBOLS_START ... CS_SYMBOLS_END:
            if (record->event.pressed) {
                cs_register_code16(keycode);
            } else {
                cs_unregister_code16(keycode);
            }
            return true;

        // =====================================================================
        // Macros
        // =====================================================================

        case NAVTABS:
            if (record->event.pressed) {
                uint8_t mods = get_mods();
                uint16_t key = shifted() ? KC_PGUP : KC_PGDN;
                del_mods(MOD_MASK_SHIFT);
                if (ctrl_on()) {
                    add_mods(MOD_MASK_SHIFT);
                }
                tap_code16(LCTL(key));
                set_mods(mods);
                update_last_key(key);
            }
            break;

        case COMMENT:
            if (record->event.pressed) {
                cs_tap_code16(LCTL(KC_SLSH));
            }
            update_last_key(KC_NO);
            break;

        case NEWSENT:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                clear_oneshot_mods();
                del_mods(MOD_MASK_SHIFT);
                send_string(". ");
                set_mods(mods);
                add_oneshot_mods(MOD_BIT(KC_LSFT));
            }
            break;

        case SPC_UP:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                if (!shifted() && !ctrl_on()) {
                    del_mods(MOD_MASK_CSAG);
                    tap_code(KC_HOME);
                    tap_code(KC_ENT);
                    tap_code(KC_UP);
                    tap_code(KC_END);
                } else {
                    del_mods(MOD_MASK_CSAG);
                    tap_code16(LCTL(KC_BSPC));
                }
                set_mods(mods);

            }
            break;
        case JOIN:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                if (!shifted() && !ctrl_on()) {
                    del_mods(MOD_MASK_CSAG);
                    tap_code(KC_END);
                    tap_code16(LCTL(KC_DEL));
                    tap_code(KC_SPC);
                } else {
                    del_mods(MOD_MASK_CSAG);
                    tap_code(KC_END);
                    tap_code16(LCTL(KC_DEL));
                }
                set_mods(mods);
            }
            break;
        case SPC_DN:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                if (!shifted() && !ctrl_on()) {
                    del_mods(MOD_MASK_CSAG);
                    tap_code(KC_END);
                    tap_code(KC_ENT);
                } else {
                    del_mods(MOD_MASK_CSAG);
                    tap_code16(LCTL(KC_DEL));
                }
                set_mods(mods);
            }
            break;

        case CS_CONJ:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                if (ctrl_on() && shifted()) {
                    del_mods(MOD_MASK_CSAG);
                    tap_code(KC_SPC);
                    tap_code16(KC_AMPR);
                    tap_code16(KC_AMPR);
                    tap_code(KC_SPC);
                } else if (ctrl_on()) {
                    del_mods(MOD_MASK_CSAG);
                    tap_code(KC_SPC);
                    tap_code16(KC_AMPR);
                    tap_code(KC_SPC);
                    
                } else if (shifted()) {
                    del_mods(MOD_MASK_CSAG);
                    tap_code16(KC_AMPR);
                    tap_code16(KC_AMPR);
                } else {
                    del_mods(MOD_MASK_CSAG);
                    cs_register_code16(KC_AMPR);
                }
                set_mods(mods);
            } else {
                cs_unregister_code16(KC_AMPR);
            }
            break;

        case CS_DISJ:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                if (ctrl_on() && shifted()) {
                    del_mods(MOD_MASK_CSAG);
                    tap_code(KC_SPC);
                    tap_code16(LSFT(KC_NUBS));
                    tap_code16(LSFT(KC_NUBS));
                    tap_code(KC_SPC);
                } else if (ctrl_on()) {
                    del_mods(MOD_MASK_CSAG);
                    tap_code(KC_SPC);
                    tap_code16(LSFT(KC_NUBS));
                    tap_code(KC_SPC);
                    
                } else if (shifted()) {
                    del_mods(MOD_MASK_CSAG);
                    tap_code16(LSFT(KC_NUBS));
                    tap_code16(LSFT(KC_NUBS));
                } else {
                    del_mods(MOD_MASK_CSAG);
                    cs_register_code16(LSFT(KC_NUBS));
                }
                set_mods(mods);
            } else {
                cs_unregister_code16(LSFT(KC_NUBS));
            }
            break;

        // =====================================================================
        // Misc control
        // =====================================================================

        case MUTE:
            if (record->event.pressed) {
                register_code(KC_MUTE);
                oled_state.muted = !oled_state.muted;
            } else {
                unregister_code(KC_MUTE);
            }
            break;

        case MUTE_L:
            if (record->event.pressed && misc_key_state.RT3_active) {
                register_code(KC_MUTE);
                oled_state.muted = !oled_state.muted;
            } else {
                unregister_code(KC_MUTE);
            }
            break;

        case MUTE_R:
            if (record->event.pressed && misc_key_state.LT3_active) {
                register_code(KC_MUTE);
                oled_state.muted = !oled_state.muted;
            } else {
                unregister_code(KC_MUTE);
            }
            break;

        case MENU:
            if (record->event.pressed) {
                if (oled_state.menu == 0) {
                    oled_state.menu = 1;
                } else if (oled_state.menu == 1) {
                    oled_state.menu = 0;
                }
            }
            break;

        case CS_RGBN:
            if (record->event.pressed) {
                if (!shifted()) {
                    rgb_state.mode = rgb_state.mode == 0 ? 5 : rgb_state.mode -1;
                } else {
                    rgb_state.mode = (rgb_state.mode + 1) % 6;
                }
                set_rgb_mode();
            }
            break;

        case CS_RGBT:
            if (record->event.pressed) {
                rgb_matrix_toggle_noeeprom();
                rgb_state.active = !rgb_state.active;
            }
            break;

        case ALTTAB:
            if (!misc_key_state.alt_tab_active) {
                misc_key_state.alt_tab_active = true;
                register_code(KC_LALT);
            }
            // alt_tab_timer = timer_read();
            if (record->event.pressed) {
                tap_code16(KC_TAB);
            }
            break;

        case OLEDSAV:
            if (record->event.pressed) {
                oled_state.static_display = !oled_state.static_display;
                update_sync();
                if (!oled_state.static_display) {
                    oled_clear();
                } else {
                    clock_state.setting = set_none;
                }
            }
            break;
        case OLEDTOG:
            if (record->event.pressed) {
                oled_state.active = !oled_state.active;
                update_sync();
            }
            break;

        case BASIC:
            if (record->event.pressed) {
                if (IS_LAYER_ON(_BASIC)) {
                    layer_off(_BASIC);
                    layer_on(_BASE);
                } else if (IS_LAYER_ON(_BASE)) {
                    layer_off(_BASE);
                    layer_on(_BASIC);
                } else {
                    layer_off(_QWERTY);
                    layer_on(_BASIC);
                }
            }
            break;
        case BASE:
            if (record->event.pressed) {
                if (IS_LAYER_ON(_BASIC)) {
                    layer_off(_BASIC);
                    layer_on(_QWERTY);
                } else if (IS_LAYER_ON(_BASE)) {
                    layer_off(_BASE);
                    layer_on(_QWERTY);
                } else {
                    layer_off(_QWERTY);
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
            return false;

        case CS_END:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                if (ctrl_on()) {
                    del_mods(MOD_MASK_CTRL);
                    tap_code16(LSFT(KC_END));
                } else {
                    del_mods(MOD_MASK_CTRL);
                    tap_code(KC_END);
                }
                set_mods(mods);
            }
            break;
        case CS_HOME:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                if (ctrl_on()) {
                    del_mods(MOD_MASK_CTRL);
                    tap_code16(LSFT(KC_HOME));
                } else {
                    del_mods(MOD_MASK_CTRL);
                    tap_code(KC_HOME);
                }
                set_mods(mods);
            }
            break;

        case EO_END:
            if (record->event.pressed) {
                cs_tap_code16_del_mods(LSFT(KC_END), MOD_MASK_CTRL);
            }
            break;
        case EO_HOME:
            if (record->event.pressed) {
                cs_tap_code16_del_mods(LSFT(KC_HOME), MOD_MASK_CTRL);
            }
            break;

        // =====================================================================
        // Custom shifts
        // =====================================================================

        case COM_EXL:
            if (record->event.pressed) {
                if (!shifted()) {
                    cs_tap_code(KC_COMM);
                } else {
                    cs_tap_code16(KC_EXLM);
                }
            }
            break;

        case DOT_QUE:
            if (record->event.pressed) {
                if (!shifted()) {
                    cs_tap_code(KC_DOT);
                } else {
                    cs_tap_code16(KC_QUES);
                }
            }
            break;

        case APO_QUO:
            if (record->event.pressed) {
                if (!shifted()) {
                    cs_tap_code16(KC_QUOT);
                } else {
                    cs_tap_code16(KC_AT);
                }
            }
            break;

        // =====================================================================
        // Home row mods
        // =====================================================================

        // Edit layer
        case RG_UNDS:
            if (record->tap.count && record->event.pressed) {
                cs_tap_code16(KC_UNDS);
            }
            return false;
        case RA_TILD:
            if (record->tap.count && record->event.pressed) {
                cs_tap_code16(LSFT(KC_NUHS));
            }
            return false;
        case RC_LPRN:
            if (record->tap.count && record->event.pressed) {
                cs_tap_code16(KC_LPRN);
            }
            return false;
        case RS_RPRN:
            if (record->tap.count && record->event.pressed) {
                cs_tap_code16(KC_RPRN);
            }
            return false;



        // Data layer
        case LG_EXLM:
            if (record->tap.count && record->event.pressed) {
                cs_tap_code16(KC_EXLM);
            }
            return false;
        case LA_COLN:
            if (record->tap.count && record->event.pressed) {
                cs_tap_code16(KC_COLN);
            }
            return false;
        case LC_DOT:
            if (record->tap.count && record->event.pressed) {
                cs_tap_code(KC_DOT);
            }
            return false;
        case LS_COMM:
            if (record->tap.count && record->event.pressed) {
                cs_tap_code(KC_COMM);
            }
            return false;



        case RG_0:
            if (record->tap.count && record->event.pressed) {
                cs_tap_code16(KC_0);
            }
            return false;



        // Edit overlay
        case RS_DELL:
            if (record->tap.count && record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_CSAG);
                tap_code16(LSFT(KC_HOME));
                tap_code16(KC_BSPC);
                set_mods(mods);
            }
            return false;

        case RC_DELW:
            if (record->tap.count && record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_CSAG);
                tap_code(KC_RGHT);
                add_mods(MOD_MASK_CTRL);
                tap_code(KC_LEFT);
                tap_code(KC_DEL);
                set_mods(mods);
            }
            return false;

        case RA_DELR:
            if (record->tap.count && record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_CSAG);
                tap_code16(LSFT(KC_END));
                tap_code(KC_BSPC);
                set_mods(mods);
            }
            return false;
    }
    return true;
}



//==============================================================================
// OLED
//==============================================================================

//------------------------------------------------------------------------------
// Clock
//------------------------------------------------------------------------------

static void render_clock(uint8_t shift, uint8_t line) {
    char time_str[9];

    time_str[8] = '\0';
    time_str[7] = '0' + clock_state.sec % 10;
    time_str[6] = '0' + clock_state.sec / 10;
    time_str[5] = ':';
    time_str[4] = '0' + clock_state.min % 10;
    time_str[3] = '0' + clock_state.min / 10;
    time_str[2] = ':';
    time_str[1] = '0' + clock_state.hrs % 10;
    time_str[0] = '0' + clock_state.hrs / 10;

    if (clock_state.setting == set_hour) {
        oled_set_cursor(shift,line-1);
        oled_write_char(148,false);
        oled_write_char(149,false);
        oled_set_cursor(shift,line+1);
        oled_write_char(180,false);
        oled_write_char(181,false);
    } else if (clock_state.setting == set_min) {
        oled_set_cursor(shift+3,line-1);
        oled_write_char(148,false);
        oled_write_char(149,false);
        oled_set_cursor(shift+3,line+1);
        oled_write_char(180,false);
        oled_write_char(181,false);
    } else if (clock_state.setting == set_sec) {
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

//------------------------------------------------------------------------------
// WPM
//------------------------------------------------------------------------------

bool wpm_keycode_user(uint16_t keycode) {
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX)
     || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)
     || (keycode >= QK_MODS && keycode <= QK_MODS_MAX)) {
        keycode = keycode & 0xFF;
    } else if (keycode > 0xFF) {
        keycode = 0;
    }
    
    switch (keycode) {
        case KC_A ... KC_0:
        case KC_TAB ... KC_SLSH:
        case COM_EXL ... EO_ENT:
        case MAGIC:
        case REP:
        case NEWSENT:
            return true;
    }

    return false;
}


static void render_wpm(void) {
    uint8_t n = get_current_wpm();
    char render_str[4];

    render_str[3] = '\0';
    render_str[2] = '0' + n % 10;
    render_str[1] = '0' + (n /= 10) % 10;
    render_str[0] = '0' + n / 10;
    
    oled_write_P(PSTR("WPM: "), false);
    oled_write(render_str, false);
}

//------------------------------------------------------------------------------
// OLED animation
//------------------------------------------------------------------------------

static bool minor = true;
static bool major = false;
static uint8_t frame_count = 15;
static uint16_t render_timer;
static uint16_t anim_timer = 0;
static bool show_text = true;

#include "frames.inc"

static uint8_t clean_frame = 0;

static void render_stats(void) {
    oled_set_cursor(0,14);
    render_wpm();
    render_clock(0,15);
}

static void render_text_clean(void) {
    oled_write_raw_P(text_clean[clean_frame], frame_size);
}

static void render_text_major(void) {
    oled_write_raw_P(text_major[rand() % text_major_count], frame_size);
}

#define BIAS 2

static void render_text_minor(bool can_be_major) {
    clean_frame = rand() % 2;
    uint8_t frame = can_be_major ? rand() % (BIAS*text_minor_count + text_major_count) : rand() % text_minor_count;
    if (frame < BIAS*text_minor_count) {
        oled_write_raw_P(text_minor[frame % text_minor_count], frame_size);
        return;
    }

    render_text_major();
}

static void render_logo_clean(void) {
    oled_write_raw_P(logo_clean, frame_size);
    render_stats();
}

static void render_logo_major(void) {
    oled_write_raw_P(logo_major[rand() % logo_major_count], frame_size);
}

static void render_logo_minor(bool can_be_major) {
    uint8_t frame = can_be_major ? rand() % (logo_minor_count + logo_major_count) : rand() % logo_minor_count;
    if (frame < logo_minor_count) {
        oled_write_raw_P(logo_minor[frame], frame_size);

        return;
    }

    render_logo_major();
}

static void render_draw(void) {
    if (sync_data.oled.timeout || !sync_data.oled.active) {
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

//------------------------------------------------------------------------------
// OLED menu
//------------------------------------------------------------------------------

static inline void render_linebreak(void) {
    oled_write_P(PSTR("__________"), false);
}

static void render_mode(void) {
    if (IS_LAYER_ON(_TRACKBALL)) {
        oled_write_P(PSTR(" Trackball"), false);
    } else if (IS_LAYER_ON(_MOUSE)) {
        oled_write_P(PSTR(" Mouse\n"), false);
    } else if (IS_LAYER_ON(_TOUHOU)) {
        oled_write_P(PSTR(" Touhou\n"), false);
    } else if (IS_LAYER_ON(_NUMPAD)) {
        oled_write_P(PSTR(" Numpad\n"), false);
    } else if (IS_LAYER_ON(_STENO)) {
        oled_write_P(PSTR(" Steno.\n"), false);
    } else if (IS_LAYER_ON(_BASIC)) {
        oled_write_P(PSTR(" Basic\n"), false);
    } else if (IS_LAYER_ON(_BASE)) {
        oled_write_P(PSTR(" Base\n"), false);
    } else {
        oled_write_P(PSTR(" QWERTY\n"), false);
    }
}

static void render_layer(void) {
    if (IS_LAYER_ON(_DATA) || IS_LAYER_ON(_DATA_OVERLAY)) {
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



static bool oneshot_shift = false;
void oneshot_mods_changed_user(uint8_t mods) {
    if (mods & MOD_MASK_SHIFT) {
        oneshot_shift = true;
    } else {
        oneshot_shift = false;
    }
}

static void render_locking_key_state(led_t led_usb_state) {
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

static void render_modifier_state(uint8_t line) {
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
    if (get_mods() & MOD_MASK_CTRL) {
        oled_write_char(143,false);
        oled_write_char(144,false);
        oled_set_cursor(4,line+1);
        oled_write_char(175,false);
        oled_write_char(176,false);
    } else {
        oled_write_char(135,false);
        oled_write_char(136,false);
        oled_set_cursor(4,line+1);
        oled_write_char(167,false);
        oled_write_char(168,false);
    }
    oled_set_cursor(6,line);
    if ((get_mods() & MOD_MASK_SHIFT) || oneshot_shift) {
        oled_write_char(141,false);
        oled_write_char(142,false);
        oled_set_cursor(6,line+1);
        oled_write_char(173,false);
        oled_write_char(174,false);
    } else {
        oled_write_char(133,false);
        oled_write_char(134,false);
        oled_set_cursor(6,line+1);
        oled_write_char(165,false);
        oled_write_char(166,false);
    }
    oled_set_cursor(8,line);
    oled_write_char(145,false);
    oled_set_cursor(8,line+1);
    oled_write_char(177,false);
    oled_set_cursor(9,line);
    if (!oled_state.muted) {
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

#include "menu.inc"

#define overlay_mask ~((1 << _CONTROL_OVERLAY) | (1 << _NUMPAD) | (1 << _MOUSE))
#define base_layer_mask ~((1 << _BASE) | (1 << _BASIC) | (1 << _QWERTY))

static void render_layout(void) {
    if (IS_LAYER_ON(_BASE) || IS_LAYER_ON(_BASIC)) {
        oled_set_cursor(0,3);
        oled_write_raw_P(menu_layout_base_left, layout_left_size);
        oled_set_cursor(0,6);
        oled_write_raw_P(menu_layout_base_right, layout_right_size);
    } else {
        oled_set_cursor(0,3);
        oled_write_raw_P(menu_layout_qwerty_left, layout_left_size);
        oled_set_cursor(0,6);
        oled_write_raw_P(menu_layout_qwerty_right, layout_right_size);
    }

    switch (get_highest_layer(layer_state & overlay_mask)) {
        case _STENO:
            oled_set_cursor(0,3);
            oled_write_raw_P(menu_layout_steno_left, layout_left_size);
            oled_set_cursor(0,6);
            oled_write_raw_P(menu_layout_steno_right, layout_right_size);
            break;
        case _DATA:
            oled_set_cursor(0,3);
            oled_write_raw_P(menu_layout_data_left, layout_left_size);
            oled_set_cursor(0,6);
            oled_write_raw_P(menu_layout_data_right, layout_right_size);
            break;
        case _PROGRAM:
            oled_set_cursor(0,3);
            oled_write_raw_P(menu_layout_program_left, layout_left_size);
            oled_set_cursor(0,6);
            oled_write_raw_P(menu_layout_program_right, layout_right_size);
            break;
        case _SYMBOL:
            oled_set_cursor(0,3);
            oled_write_raw_P(menu_layout_symbol_left, layout_left_size);
            oled_set_cursor(0,6);
            oled_write_raw_P(menu_layout_symbol_right, layout_right_size);
            break;
        case _EDIT:
            oled_set_cursor(0,3);
            oled_write_raw_P(menu_layout_edit_left, layout_left_size);
            oled_set_cursor(0,6);
            oled_write_raw_P(menu_layout_edit_right, layout_right_size);
            break;
        case _EDIT_OVERLAY:
            oled_set_cursor(0,3);
            oled_write_raw_P(menu_layout_edit_overlay_left, layout_left_size);
            oled_set_cursor(0,6);
            oled_write_raw_P(menu_layout_edit_overlay_right, layout_right_size);
            break;
        case _DATA_OVERLAY:
            oled_set_cursor(0,3);
            oled_write_raw_P(menu_layout_edit_left, layout_left_size);
            oled_set_cursor(0,6);
            oled_write_raw_P(menu_layout_data_overlay_right, layout_right_size);
            break;
        case _UTILITY:
            oled_set_cursor(0,3);
            oled_write_raw_P(menu_layout_utility_left, layout_left_size);
            oled_set_cursor(0,6);
            oled_write_raw_P(menu_layout_utility_right, layout_right_size);
            break;
        case _TOUHOU:
            oled_set_cursor(0,3);
            oled_write_raw_P(menu_layout_touhou, 448);
            break;
    }
}

static void render_right_thumb(const char* progmem_data) {
    oled_set_cursor(8,6);
    oled_write_raw_P(&progmem_data[0], 16);
    oled_set_cursor(8,7);
    oled_write_raw_P(&progmem_data[16], 16);
    oled_set_cursor(8,8);
    oled_write_raw_P(&progmem_data[32], 16);
    oled_set_cursor(8,9);
    oled_write_raw_P(&progmem_data[48], 16);
}

static void render_overlays(void) {
    if (IS_LAYER_ON(_UTILITY) || IS_LAYER_ON(_TOUHOU)){
        return;
    }

    if (IS_LAYER_ON(_NUMPAD)) {
        oled_set_cursor(0,6);
        oled_write_raw_P(menu_layout_numpad, layout_right_size);
        return;
    }
    if (IS_LAYER_ON(_MOUSE)) {
        oled_set_cursor(0,3);
        oled_write_raw_P(menu_layout_mouse_left, layout_left_size);
        render_right_thumb(menu_layout_mouse_right);
        return;
    }

    if (get_highest_layer(layer_state & overlay_mask & base_layer_mask) < 3) {
        return;
    }
    if (IS_LAYER_ON(_DATA_OVERLAY)) {
        oled_set_cursor(5,3);
        oled_write_raw_P(menu_layout_data_overlay_left, 18);
        return;
    }
    if (IS_LAYER_ON(_CONTROL_OVERLAY)) {
        oled_set_cursor(1,5);
        oled_write_raw_P(menu_layout_control_overlay, 42);
        return;
    }
    if (ctrl_on() &&
       (get_highest_layer(layer_state) == _EDIT 
     || get_highest_layer(layer_state) == _EDIT_OVERLAY) ) {
        oled_set_cursor(1,5);
        oled_write_raw_P(menu_layout_control_overlay, 42);
        return;
    }
}

static void render_status(void) {
    if (oled_state.menu == 0) {
        oled_set_cursor(0,3);
        oled_write_ln_P(PSTR("Layer:"), false); // 1
        render_layer(); // 7
    } else if (oled_state.menu == 1) {
        render_layout();
        render_overlays();
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
    if (is_keyboard_master()) {
        if (!oled_state.active) {
            oled_clear();
            return false;
        }
        if (oled_state.timeout) {
            oled_off();
            return false;
        }
        if (oled_state.static_display) {
            oled_write_raw_P(static_right, frame_size);
        } else {
            render_status();
        }
    } else {
        if (!sync_data.oled.active) {
            oled_clear();
            return false;
        }
        if (sync_data.oled.timeout) {
            oled_off();
            return false;
        }
        if (sync_data.oled.static_display) {
            oled_write_raw_P(static_left, frame_size);
        } else {
            render_draw();
        }
    }
    return false;
}



// =============================================================================
//  Boot/Shutdown
// =============================================================================

bool boot = false;

void keyboard_post_init_user(void) {
    boot = true;
    layer_move(_BASE);

    // Debug options
    debug_enable = true;
    // debug_matrix = true;
    // debug_keyboard = true;
    // debug_mouse = true;

    update_sync();

    rgb_matrix_enable_noeeprom();
    rgb_matrix_sethsv_noeeprom(255,255,255);
    rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_boot_animation_effect);

    defer_exec(clock_callback(0,NULL), clock_callback, NULL);

    transaction_register_rpc(USER_SYNC_A, user_config_sync_handler);
}

static void oled_render_boot(bool bootloader) {
    oled_clear();
    if (bootloader) {
        oled_write_raw_P(bootloader_oled, frame_size);
    } else {
        oled_write_P(PSTR("Rebooting"), false);
    }
    oled_render_dirty(true);
}

bool shutdown_user(bool jump_to_bootloader) {
    oled_render_boot(jump_to_bootloader);
    if (jump_to_bootloader) {
        rgb_matrix_set_color_all(RGB_OFF);
        int underglow[12] = { 0, 1, 2, 3, 4, 5, 27, 28, 29, 30, 31, 32 };
        for (uint8_t i = 0; i < 12; i++) {
            rgb_t underglow_rgb  = hsv_to_rgb((hsv_t){ 255, 255, 255 });
            rgb_matrix_set_color_split(underglow[i], underglow_rgb.r, underglow_rgb.g, underglow_rgb.b);
        }
    }
    rgb_matrix_update_pwm_buffers();
    return false;
}



//==============================================================================
// RGB Matrix
//==============================================================================

//  ,-----------------------.           ,-----------------------.
//    24, 23, 18, 17, 10, 09,             36, 37, 44, 45, 50, 51,
//  |---+---+---+---+---+---|           |---+---+---+---+---+---|
//    25, 22, 19, 16, 11, 08,             35, 38, 43, 46, 49, 52,
//  |---+---+---+---+---+---|           |---+---+---+---+---+---|
//    26, 21, 20, 15, 12, 07,             34, 39, 42, 47, 48, 53,
//  |---+---+---+---+---+---+---|   |---+---+---+---+---+---+---|
//                    14, 13, 06,     33, 40, 41
//                  `-----------'   `-----------'
// Underglow:            00 - 05      27 - 32

// int column1[] = {  6,  7,  8,  9, 33, 34, 35, 36};
// int column2[] = { 13, 12, 11, 10, 40, 39, 38, 37};
// int column3[] = { 14, 15, 16, 17, 41, 42, 43, 44};
// int column4[] = {     20, 19, 18,     47, 46, 45};
// int column5[] = {     21, 22, 23,     48, 49, 50};
// int column6[] = {     26, 25, 24,     53, 52, 51};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (case_lock_state.capturing || sync_data.case_lock.capturing) {
        for (uint8_t index = 6; index < 27; index++) {
            rgb_t green = hsv_to_rgb((hsv_t){ 85, 255, 100 });
            rgb_matrix_set_color_split(index, green.r, green.g, green.b);
            rgb_matrix_set_color_split(index+27, green.r, green.g, green.b);
        }
    } else if (case_lock_state.active || sync_data.case_lock.active) {
        for (uint8_t index = 6; index < 27; index++) {
            rgb_t red = hsv_to_rgb((hsv_t){ 255, 255, 100 });
            rgb_matrix_set_color_split(index, red.r, red.g, red.b);
            rgb_matrix_set_color_split(index+27, red.r, red.g, red.b);
        }
    }

    int arrows[4] = { 17, 19, 16, 11 };
    int underglow[12] = { 0, 1, 2, 3, 4, 5, 27, 28, 29, 30, 31, 32 };

    hsv_t arrow_hsv = (hsv_t){ 169, 255, 255 };
    rgb_t arrow_rgb = hsv_to_rgb(arrow_hsv);

    hsv_t underglow_hsv = (hsv_t){ 0, 0, 0 };
    rgb_t underglow_rgb = hsv_to_rgb(underglow_hsv);

    switch (get_highest_layer(layer_state|default_layer_state)) {
        case _PROGRAM:
            underglow_hsv = (hsv_t){ 85, 255, 255 };
            underglow_rgb = hsv_to_rgb(underglow_hsv);
            for (uint8_t i = 0; i < 12; i++) {
                rgb_matrix_set_color_split(underglow[i], underglow_rgb.r, underglow_rgb.g, underglow_rgb.b);
            }
            break;
        case _DATA:
            underglow_hsv = (hsv_t){ 127, 255, 255 };
            underglow_rgb = hsv_to_rgb(underglow_hsv);
            for (uint8_t i = 0; i < 12; i++) {
                rgb_matrix_set_color_split(underglow[i], underglow_rgb.r, underglow_rgb.g, underglow_rgb.b);
            }
            break;
        case _EDIT:
            underglow_hsv = (hsv_t){ 0, 255, 255 };
            underglow_rgb = hsv_to_rgb(underglow_hsv);
            for (uint8_t i = 0; i < 12; i++) {
                rgb_matrix_set_color_split(underglow[i], underglow_rgb.r, underglow_rgb.g, underglow_rgb.b);
            }
            break;
        case _SYMBOL:
            underglow_hsv = (hsv_t){ 169, 255, 255 };
            underglow_rgb = hsv_to_rgb(underglow_hsv);
            for (uint8_t i = 0; i < 12; i++) {
                rgb_matrix_set_color_split(underglow[i], underglow_rgb.r, underglow_rgb.g, underglow_rgb.b);
            }
            break;
        case _MOUSE:
            underglow_hsv = (hsv_t){ 222, 255, 255 };
            underglow_rgb = hsv_to_rgb(underglow_hsv);
            for (uint8_t i = 0; i < 12; i++) {
                rgb_matrix_set_color_split(underglow[i], underglow_rgb.r, underglow_rgb.g, underglow_rgb.b);
            }
            break;
        case _NUMPAD:
            underglow_hsv = (hsv_t){ 43, 255, 255 };
            underglow_rgb = hsv_to_rgb(underglow_hsv);
            for (uint8_t i = 0; i < 12; i++) {
                rgb_matrix_set_color_split(underglow[i], underglow_rgb.r, underglow_rgb.g, underglow_rgb.b);
            }
            break;
        case _UTILITY:
            underglow_hsv = (hsv_t){ 201, 255, 255 };
            underglow_rgb = hsv_to_rgb(underglow_hsv);
            for (uint8_t i = 0; i < 12; i++) {
                rgb_matrix_set_color_split(underglow[i], underglow_rgb.r, underglow_rgb.g, underglow_rgb.b);
            }
            break;
        case _TOUHOU:
            for (uint8_t i = 0; i < 4; i++) {
                rgb_matrix_set_color_split(arrows[i], arrow_rgb.r, arrow_rgb.g, arrow_rgb.b);
            }
            break;
        case _QWERTY:
        default:
            break;
    }
    return false;
}

extern bool fade_out_active;
extern bool fade_in_active;

layer_state_t layer_state_set_user(layer_state_t state) {
    static layer_state_t previous_state = 0;
    
    const layer_state_t check_layers = 
        (1UL << _MOUSE) |
        (1UL << _QWERTY) |
        (1UL << _TOUHOU) |
        (1UL << _BASIC) |
        (1UL << _BASE);

    if ((previous_state & (1UL << _EDIT)) && !(state & (1UL << _EDIT))) {
        cycle_state.num = 0;
    }

    if (boot || fade_out_active || fade_in_active ||
        !((state ^ previous_state) & check_layers)) {
        previous_state = state;
        return state;
    }

    if (IS_LAYER_ON_STATE(state, _MOUSE)) {
        rgb_matrix_sethsv_noeeprom(209,255,192);
        rgb_matrix_mode_noeeprom(RGB_MATRIX_RIVERFLOW);
    } else if (IS_LAYER_ON_STATE(state, _BASIC) ||
               IS_LAYER_ON_STATE(state, _TOUHOU)) {
        rgb_matrix_sethsv_noeeprom(127,255,255);
        rgb_matrix_mode_noeeprom(RGB_MATRIX_RIVERFLOW);
    } else if (IS_LAYER_ON_STATE(state, _QWERTY)) {
        rgb_matrix_sethsv_noeeprom(255,255,255);
        rgb_matrix_mode_noeeprom(RGB_MATRIX_RIVERFLOW);
    } else {
        rgb_matrix_sethsv_noeeprom(110,255,255);
        set_rgb_mode();
    }

    previous_state = state;
    return state;
}



// =============================================================================
// Timers
// =============================================================================

typedef enum {
    EDGE_NONE,
    EDGE_RISE,
    EDGE_FALL
} edge_t;

typedef struct {
    uint32_t duration;
    bool active;
    edge_t edge;
} timeout_t;

enum {
    TIMEOUT_IDLE,
    TIMEOUT_SELECT,
    TIMEOUT_ARROW,
    TIMEOUT_TRACKING,
    TIMEOUT_MAGIC,
    TIMEOUT_CASE_CAPTURE,
    TIMEOUT_CASE_LOCK,
    TIMEOUT_OLED,
    TIMEOUT_CAPSWORD,

    TIMEOUT_COUNT
};

static timeout_t timeouts[TIMEOUT_COUNT] = {
    [TIMEOUT_IDLE]         = { .duration = 300000 },
    [TIMEOUT_SELECT]       = { .duration = 200 },
    [TIMEOUT_ARROW]        = { .duration = 1000 },
    [TIMEOUT_TRACKING]     = { .duration = 500 },
    [TIMEOUT_MAGIC]        = { .duration = 1000 },
    [TIMEOUT_CASE_CAPTURE] = { .duration = 1000 },
    [TIMEOUT_CASE_LOCK]    = { .duration = 2000 },
    [TIMEOUT_OLED]         = { .duration = 10000 },
    [TIMEOUT_CAPSWORD]     = { .duration = 5000 },
};

static void update_timeouts(void) {
    uint32_t elapsed = last_input_activity_elapsed();

    for (int i = 0; i < TIMEOUT_COUNT; i++) {
        bool new_active = (elapsed > timeouts[i].duration);
        if (new_active != timeouts[i].active) {
            timeouts[i].active = new_active;
            timeouts[i].edge = new_active ? EDGE_RISE : EDGE_FALL;
        } else {
            timeouts[i].edge = EDGE_NONE;
        }
    }
}



void housekeeping_task_user(void) {
    update_timeouts();

    switch (timeouts[TIMEOUT_IDLE].edge) {
        case EDGE_RISE:
            layer_off(_NUMPAD);
            layer_off(_TOUHOU);
            layer_off(_MOUSE);
            layer_off(_EDIT);

            rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_fade_out_effect);
            break;

        case EDGE_FALL:
            if (rgb_state.active) {
                rgb_matrix_enable_noeeprom();
                rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_fade_in_effect);
            }
            break;

        default:
            break;
    }

    if (timeouts[TIMEOUT_SELECT].active) {
        if (is_last_key(SELECT)) {
            recent_key_state.last_key = KC_NO;
        }
    }

    if (timeouts[TIMEOUT_ARROW].active) {
        if (!arrow_state.held_keys) {
            arrow_state.ctrl_active = false;
        }
    }

    if (timeouts[TIMEOUT_TRACKING].active) {
        recent_key_state.count = 1;
    }
    if (timeouts[TIMEOUT_MAGIC].active) {
        recent_key_state.last_key = KC_NO;
        recent_key_state.last_key_2 = KC_NO;
        recent_key_state.last_key_3 = KC_NO;
    }

    if (timeouts[TIMEOUT_CASE_CAPTURE].active) {
        if (!case_lock_state.active) {
            case_lock_capture_off();
        }
    }
    if (timeouts[TIMEOUT_CASE_LOCK].active) {
        if (case_lock_state.active) {
            case_lock_off();
        }
    }

    if (timeouts[TIMEOUT_CAPSWORD].active) {
        misc_key_state.capsword_active = false;
    }

    switch (timeouts[TIMEOUT_OLED].edge) {
        case EDGE_RISE:
            if (clock_state.setting != set_none && (clock_up_token || clock_dn_token)) {
                oled_state.timeout = false;
            } else {
                clock_state.setting = set_none;
                oled_state.timeout = true;
            }
            break;

        case EDGE_FALL:
            oled_state.timeout = false;
            update_sync();
            break;

        default:
            break;
    }

    if (misc_key_state.alt_tab_active) {
        if (IS_LAYER_OFF(_UTILITY)) {
            unregister_code(KC_LALT);
            misc_key_state.alt_tab_active = false;
        }
    }

    // =========================================================================
    // Data Sync
    // =========================================================================

    if (is_keyboard_master()) {
        static uint32_t last_sync = 0;
        if (timer_elapsed32(last_sync) > 500) {
            master_to_slave_t m2s = {
                .oled = {
                    .static_display = oled_state.static_display,
                    .timeout = oled_state.timeout,
                    .active = oled_state.active,
                },
                .case_lock = {
                    .capturing = case_lock_state.capturing,
                    .active = case_lock_state.active
                }
            };
            if (transaction_rpc_send(USER_SYNC_A, sizeof(master_to_slave_t), &m2s)) {
                last_sync = timer_read32();
            } else {
                dprint("Slave sync failed!\n");
            }
        }
    }
}

static void update_sync(void) {
    if (is_keyboard_master()) {
        master_to_slave_t m2s = {
            .oled = {
                .static_display = oled_state.static_display,
                .timeout = oled_state.timeout,
                .active = oled_state.active,
            },
            .case_lock = {
                .capturing = case_lock_state.capturing,
                .active = case_lock_state.active
            }
        };
        transaction_rpc_send(USER_SYNC_A, sizeof(master_to_slave_t), &m2s);
    }
}