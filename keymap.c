#include QMK_KEYBOARD_H
#include "print.h"
#include "version.h"

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
    REP = SAFE_RANGE,
    MAGIC,
    NEWSENT,
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
    
    SELUP,
    SELDOWN,

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

    // Custom Symbols
    COM_DOT,
    QUE_EXL,
    APO_QUO,
    CS_CONJ,
    CS_DISJ,

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

    // Bracket macros
    CS_NORM,
    CS_CBRS,
    CS_PRNS,
    CS_BRCS,

    // Home block mods
    CS_RBRC,
    CS_RPRN,
    CS_LPRN,

    // Combos
    CM_MOUSE,
    DELWORD,


    // Edit overlay keys
    WORDCBR,
    WORDPRN,
    WORDBRC,

    WRAPBRC,
    
    SPC_DN,
    JOIN,
    SPC_UP,
    EO_HOME,
    EO_END,
    EO_ENT,

    CY_NUM,
    CY_BOOL,
    CY_MISC,
    CY_BRC,
    CY_COMP,
};

// Home row mods
#define LG_A LGUI_T(KC_A)
#define LA_S LALT_T(KC_S)
#define LC_D LCTL_T(KC_D)
#define LS_F LSFT_T(KC_F)

#define RS_J    RSFT_T(KC_J)
#define RC_K    RCTL_T(KC_K)
#define RA_L    LALT_T(KC_L)
#define RS_SCLN RGUI_T(KC_SCLN)

// Alt layout home row mods
#define LG_N LGUI_T(KC_N)
#define LA_R LALT_T(KC_R)
#define LC_T LCTL_T(KC_T)
#define LS_S LSFT_T(KC_S)

#define RS_H RSFT_T(KC_H)
#define RC_E RCTL_T(KC_E)
#define RA_I LALT_T(KC_I)
#define RG_A RGUI_T(KC_A)

// Symbol home row mods
#define RS_RPRN LT(0,CS_RPRN)
#define RC_LPRN LT(0,CS_LPRN)
#define RA_UNDS LT(0,CS_UNDS)
#define RG_TILD LT(0,CS_TILD)

#define RS_1 RSFT_T(KC_1)
#define RC_2 RCTL_T(KC_2)
#define RA_3 LALT_T(KC_3)
#define RG_UNDS LGUI_T(KC_UNDS)

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
#define CS_AL3 LT(_EDIT,CS_SCLN)
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
#define TAB     LCTL(KC_T)
#define WINDOW  LCTL(KC_N)
#define REFRESH LCTL(KC_R)
#define MERGE   LCTL(KC_E)
#define BOLD    LCTL(KC_B)
#define GROUP   LCTL(KC_G)
#define LEVEL   LCTL(KC_L)
#define DUPL    LCTL(KC_J)

// Other
#define NXT_TAB LCTL(KC_PGDN)
#define PRV_TAB LCTL(KC_PGUP)
#define OSMLSFT OSM(MOD_LSFT)

#define EO_LEFT LCTL(KC_LEFT)
#define EO_RGHT LCTL(KC_RGHT)
#define EO_UP   LCTL(KC_UP)
#define EO_DOWN LCTL(KC_DOWN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASIC] = LAYOUT( //0
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
           KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, CS_HASH,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, TABRSFT,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_QUOT, COM_DOT, QUE_EXL, CS_CASE,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                               CS_LT3,  CS_LT2,  KC_SPC,     CS_RT1,  CS_RT2,  CS_RT3
                                          //`--------------------------'  `--------------------------'
    ),

    [_QWERTY] = LAYOUT( //1
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
           KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, CS_HASH,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          TABLSFT,    LG_A,    LA_S,    LC_D,    LS_F,    KC_G,                         KC_H,    RS_J,    RC_K,    RA_L, RS_SCLN, TABRSFT,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          CS_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_QUOT, COM_DOT, QUE_EXL, CS_CASE,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                               CS_LT3,  CS_LT2,  CS_LT1,     CS_RT1,  CS_RT2,  CS_RT3
                                          //`--------------------------'  `--------------------------'
    ),

    [_BASE] = LAYOUT( //2
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
           KC_ESC,    KC_Z,    KC_L,    KC_D,    KC_C,    KC_B,                         KC_J,    KC_F,    KC_O,    KC_U, KC_SCLN, CS_HASH,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          TABLSFT,    LG_N,    LA_R,    LC_T,    LS_S,    KC_G,                         KC_Y,    RS_H,    RC_E,    RA_I,    RG_A, TABRSFT,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          CS_LCTL,    KC_Q,    KC_X,    KC_M,    KC_W,    KC_V,                         KC_K,    KC_P, KC_QUOT, COM_DOT, QUE_EXL, CS_CASE,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                               CS_LT3,  CS_LT2,  CS_LT1,     CS_RT1,  CS_RT2,  CS_RT3
                                          //`--------------------------'  `--------------------------'
    ),

    [_CONTROL] = LAYOUT( //3
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
          _______,   LEVEL,   MERGE,   CLOSE, REFRESH,     TAB,                      _______, _______, _______, _______, _______, _______,
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
                                               STN_FN,   STN_A,   STN_O,      STN_E,   STN_U, STN_PWR
                                          //`--------------------------'  `--------------------------'
    ),

    [_DATA] = LAYOUT( //5
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
          _______, CS_PERC, CS_MINS, CS_PLUS,  CS_DLR, CS_AMPR,                      CY_MISC,    KC_7,    KC_8,    KC_9,  CS_EQL,  KC_DEL,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          OSMLSFT, LG_EXLM, LA_COLN,  LC_DOT, LS_COMM, CS_PIPE,                       CY_BRC,    RS_1,    RC_2,    RA_3, RG_UNDS, TABRSFT,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          CS_LCTL, CS_CIRC, CS_SLSH, CS_ASTR, CS_HASH, CS_TILD,                      CY_COMP,    KC_4,    KC_5,    KC_6, CS_TILD,  KC_ENT,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              _______, _______, _______,    _______,  CS_AL1, KC_SLSH
                                          //`--------------------------'  `--------------------------'
    ),

    [_SYMBOL] = LAYOUT( //6
      //,-----------------------------------------------------.                    ,---------------------------------------------------.
           KC_GRV,  CS_DLR, CS_EXLM, CS_DQUO, CS_AMPR, CS_HASH,                       CS_EQL, KC_RCBR, KC_LCBR, CS_CIRC, CS_SCLN,  KC_DEL,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          OSMLSFT, CS_PIPE,   CS_LT, CS_MINS,   CS_GT,  CS_EQL,                        CS_LT, RS_RPRN, RC_LPRN, RA_UNDS, RG_TILD, TABRSFT,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          CS_LCTL, CS_CIRC, CS_COLN,  CS_DOT, CS_COMM, CS_TILD,                        CS_GT, KC_RBRC, KC_LBRC, CS_EXLM, CS_QUES,  KC_ENT,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              CS_SLSH,  CS_AL2, _______,    _______, _______, _______
                                          //`--------------------------'  `--------------------------'
    ),

    [_PROGRAM] = LAYOUT( //7
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
           KC_GRV, CS_PERC, CS_MINS, CS_PLUS,  CS_DLR, CS_CONJ,                       CS_EQL, KC_RCBR, KC_LCBR, CS_CIRC, CS_SCLN,  KC_DEL,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          OSMLSFT, CS_EXLM,   CS_LT,   CS_GT,  CS_EQL, CS_DISJ,                        CS_LT, RS_RPRN, RC_LPRN, RA_UNDS, RG_TILD, TABRSFT,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          CS_LCTL, CS_CIRC, CS_SLSH, CS_ASTR, CS_HASH, CS_TILD,                        CS_GT, KC_RBRC, KC_LBRC, CS_EXLM, CS_QUES,  KC_ENT,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              CS_SLSH,  CS_AL3, _______,    _______, _______, _______
                                          //`--------------------------'  `--------------------------'
    ),

    [_CONTROL_OVERLAY] = LAYOUT( //8
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

    [_EDIT] = LAYOUT( //9
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
          _______, KC_PGUP, CS_HOME,   KC_UP,  CS_END, QK_LLCK,                       CS_EQL, KC_RCBR, KC_LCBR, CS_CIRC, KC_SCLN,  KC_DEL,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          _______, DELWORD, KC_LEFT, KC_DOWN, KC_RGHT,  KC_DEL,                        CS_LT, RS_RPRN, RC_LPRN, RA_UNDS, RG_TILD, TABRSFT,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          _______, KC_PGDN, SELLEFT,  SELECT, SELRGHT,  EO_ENT,                        CS_GT, KC_RBRC, KC_LBRC, CS_EXLM, CS_QUES,  KC_ENT,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              _______, _______, _______,    _______,  CS_AL4,  KC_SPC
                                          //`--------------------------'  `--------------------------'
    ),

    [_EDIT_OVERLAY] = LAYOUT( //10
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
          _______, NXT_TAB, EO_HOME,   EO_UP,  EO_END, KC_CAPS,                      WORDCBR,  SPC_UP,    JOIN,  SPC_DN,  KC_ESC, _______,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          _______, DELWORD, EO_LEFT, EO_DOWN, EO_RGHT,  KC_DEL,                      WORDPRN, RS_DELL, RC_DELW, RA_DELR,  RG_DEL, _______,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          _______,    REDO,    UNDO,     CUT,    COPY,   PASTE,                      WORDBRC,   SELUP,  SELECT, SELDOWN,    UNDO, _______,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              _______, _______, _______,    _______, _______, _______
                                          //`--------------------------'  `--------------------------'
    ),

    [_DATA_OVERLAY] = LAYOUT( //11
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
          _______, KC_PGUP, CS_HOME,   KC_UP,  CS_END, KC_CAPS,                      CY_MISC,    KC_7,    KC_8,    KC_9,  CS_EQL,  KC_DEL,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          _______, DELWORD, KC_LEFT, KC_DOWN, KC_RGHT,  KC_DEL,                       CY_BRC,    RS_1,    RC_2,    RA_3, RG_UNDS, TABRSFT,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          _______, KC_PGDN, SELLEFT,  SELECT, SELRGHT,  EO_ENT,                      CY_COMP,    KC_4,    KC_5,    KC_6, CS_TILD,  KC_ENT,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              _______, _______, _______,    _______, _______, KC_SLSH
                                          //`--------------------------'  `--------------------------'
    ),

    [_NUMPAD] = LAYOUT( //12
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

    [_MOUSE] = LAYOUT( //14
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
          _______, NXT_TAB, MS_BTN4,   MS_UP, MS_BTN5, QK_LLCK,                      _______, _______, _______, _______, _______, _______,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          _______, PRV_TAB, MS_LEFT, MS_DOWN, MS_RGHT,  KC_DEL,                      _______, _______, _______, _______, _______, _______,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          KC_LCTL, MS_WHLL, MS_WHLU, MS_WHLD, MS_WHLR,  KC_ENT,                      _______, _______, _______, _______, _______, _______,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              MS_BTN3, MS_BTN2, MS_BTN1,    MS_ACL2, MS_ACL0, MS_ACL1
                                          //`--------------------------'  `--------------------------'
    ),

    [_UTILITY] = LAYOUT( //15
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
           ALTTAB, CLOCKUP, KC_PAUS, CS_VOLU,  KC_INS, OLEDSAV,                      CS_RGBN,   KC_F7,   KC_F8,   KC_F9,  KC_F10, CS_BOOT,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          _______, CLOCKDN, KC_MPRV, CS_VOLD, KC_MNXT,    BASE,                        BASIC,   KC_F1,   KC_F2,   KC_F3,  KC_F11, DB_TOGG,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          _______, CLOCKNX, OLEDTOG,    MUTE, KC_PSCR,    MENU,                      CS_RGBT,   KC_F4,   KC_F5,   KC_F6,  KC_F12, KC_SCRL,
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
    // bool boot_sync :1;
    bool static_display_sync :1;
    bool oled_timeout_sync :1;
    bool oled_disable_sync :1;
    bool case_lock_capture_sync :1;
    bool case_lock_active_sync :1;
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

static bool alt_tab_active = false;
static bool oled_timeout = false;
static bool oled_disable = false;

uint16_t boot_timer;
bool boot = false;
deferred_token boot_animation_token = INVALID_DEFERRED_TOKEN;

uint8_t set_rgb_mode = 5;

bool ctrl_linger = false;

bool left_eager_shift_on = false;
bool right_eager_shift_on = false;

bool case_lock_active = false;
bool case_lock_capture = false;
uint16_t case_lock_separator = KC_UNDS;
int16_t separator_distance = 0;

void update_sync(void) {
    if (is_keyboard_master()) {
        master_to_slave_t m2s = {
            .static_display_sync = static_display,
            .oled_timeout_sync = oled_timeout,
            .oled_disable_sync = oled_disable,
            .case_lock_capture_sync = case_lock_capture,
            .case_lock_active_sync = case_lock_active,
        };
        transaction_rpc_send(USER_SYNC_A, sizeof(master_to_slave_t), &m2s);
    }
}


void case_lock_capture_on(void) {
    case_lock_capture = true;
    update_sync();
}

void case_lock_capture_off(void) {
    case_lock_capture = false;
    update_sync();
}

void case_lock_on(void) {
    case_lock_active = true;
    update_sync();
    dprintf("case lock on!\n");
}

void case_lock_off(void) {
    case_lock_active = false;
    case_lock_capture = false;
    update_sync();
    case_lock_separator = KC_NO;
    dprintf("case lock off!\n");
}

bool ctrl_on(void) {
    return (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTL));
}

bool shifted(void) {
    return (get_mods() & MOD_BIT(KC_LSFT)
         || get_mods() & MOD_BIT(KC_RSFT)
         || get_oneshot_mods() & MOD_BIT(KC_LSFT)
         || get_oneshot_mods() & MOD_BIT(KC_RSFT)
         );
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
        case LG_A:
        case LA_S:
        case LC_D:
        case LS_F:
        case RS_J:
        case RC_K:
        case RA_L:
        case RS_SCLN:

        case LG_N:
        case LA_R:
        case LC_T:
        case LS_S:
        case RS_H:
        case RC_E:
        case RA_I:
        case RG_A:

        case RS_RPRN:
        case RC_LPRN:
        case RA_UNDS:
        case RG_TILD:

        case RS_1:
        case RC_2:
        case RA_3:
        case RG_UNDS:

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

bool last_key_dynamic = false;
bool magic_override = false;
uint8_t char_count = 1;
uint16_t last_key = KC_NO;
uint16_t last_key_2 = KC_NO;
uint16_t last_key_3 = KC_NO;

void rollback_last_key(void) {
    char_count = 1;

    last_key = last_key_2;
    last_key_2 = last_key_3;
    last_key_3 = KC_NO;
    // dprintf("rolled back!\n");
    // dprintf("last_key:   %d\n", last_key);
    // dprintf("last_key_2: %d\n", last_key_2);
    // dprintf("last_key_3: %d\n", last_key_3);
    // dprintf("char_count: %d\n", char_count);
}

void update_last_key(uint16_t new_keycode) {
    last_key_3 = last_key_2;
    last_key_2 = last_key;
    last_key = new_keycode;

    char_count = 1;

    // dprintf("updated keys!\n");
    // dprintf("last_key:   %d\n", last_key);
    // dprintf("last_key_2: %d\n", last_key_2);
    // dprintf("last_key_3: %d\n", last_key_3);
    // dprintf("char_count: %d\n", char_count);
}

void update_last_keys(uint16_t new_keycode, uint8_t new_count) {
    last_key_3 = last_key_2;
    last_key_2 = last_key;
    last_key = new_keycode;

    char_count = new_count;
    // dprintf("updated multiple keys!\n");
    // dprintf("last_key:   %d\n", last_key);
    // dprintf("last_key_2: %d\n", last_key_2);
    // dprintf("last_key_3: %d\n", last_key_3);
    // dprintf("char_count: %d\n", char_count);
}

bool is_magic(uint16_t keycode) {
    return ((keycode == CS_LT2) || (keycode == CS_RT2));
}

bool is_layer_tap(uint16_t keycode) {
    return (keycode == CS_AL1 || keycode == CS_AL2 || keycode == CS_AL3 || keycode == CS_AL4);
}

bool is_bspc(uint16_t keycode) {
    return (keycode == CS_RT1 || keycode == KC_BSPC);
}

bool is_spc(uint16_t keycode) {
    return (keycode == CS_LT1 || keycode == KC_SPC);
}

bool is_bracket_macro(uint16_t keycode) {
    return (keycode >= CS_NORM && keycode <= CS_BRCS);
}

bool is_bracket_wrap_macro(uint16_t keycode) {
    return (keycode >= WORDCBR && keycode <= WORDBRC);
}

bool is_cycling_macro(uint16_t keycode) {
    return (keycode >= CY_NUM && keycode <= CY_COMP);
}

bool is_select_macro(uint16_t keycode) {
    return (keycode == SELLEFT || keycode == SELECT || keycode == SELRGHT);
}

bool is_arrow_key(uint16_t keycode) {
    return (keycode == KC_UP || keycode == KC_DOWN || keycode == KC_LEFT || keycode == KC_RGHT);
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

void homerow_mod(uint8_t mods, keyrecord_t* record) {
    if (!record->tap.count && record->event.pressed) {
        register_mods(mods);
    } else if (!record->tap.count && !record->event.pressed) {
        unregister_mods(mods);
    }
}

bool process_homerow_mod_tap(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        // LGUI
        case LG_N:
        case LG_A:
        case LG_EXLM:
            homerow_mod(MOD_BIT(KC_LGUI), record);
            break;
        // LALT
        case LA_S:
        case LA_R:
        case LA_COLN:
            homerow_mod(MOD_BIT(KC_LALT), record);
            break;
        // LCTL
        case LC_D:
        case LC_T:
        case LC_DOT:
            homerow_mod(MOD_BIT(KC_LCTL), record);
            break;
        // LSFT
        case LS_F:
        case LS_S:
        case LS_COMM:
            homerow_mod(MOD_BIT(KC_LSFT), record);
            break;



        // RSFT
        case RS_J:
        case RS_H:
        case RS_RPRN:
        case RS_1:
        case RS_DELL:
            homerow_mod(MOD_BIT(KC_RSFT), record);
            break;
        // RCTL
        case RC_K:
        case RC_E:
        case RC_LPRN:
        case RC_2:
        case RC_DELW:
            homerow_mod(MOD_BIT(KC_RCTL), record);
            break;
        // RALT
        case RA_L:
        case RA_I:
        case RA_UNDS:
        case RA_3:
        case RA_DELR:
            homerow_mod(MOD_BIT(KC_LALT), record);
            break;
        // RGUI
        case RS_SCLN:
        case RG_A:
        case RG_TILD:
        case RG_UNDS:
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
        case COM_DOT:
        case QUE_EXL:
            return true;
    }
    return false;
}

uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t* record, 
                           uint16_t prev_keycode) {
    if (get_tap_keycode(prev_keycode) == KC_BSPC) {
        return false;
    }

    if (is_flow_tap_key(keycode) && is_flow_tap_key(prev_keycode)) {
        switch (keycode) {
            // Shift mod-taps
            case LS_F:
            case RS_J:
            case LS_S:
            case RS_H:
                return 50;
                
            // Ctrl mod-taps
            case LC_D:
            case RC_K:
            case LC_T:
            case RC_E:
                return 75;

            default:
                return FLOW_TAP_TERM;
        }
    }
    return 0;  // Disable Flow Tap.
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // enable key repeating on numerical home row mod keys
        case RS_1:
        case RC_2:
        case RA_3:
        // case RG_0:
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

    // disable key repeating on other home row mod keys
    if (is_hrm(keycode)) {
        return 0;
    }

    return TAPPING_TERM;
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

        case TABLSFT:
        case TABRSFT:
            return 125;

        // Shift mod-taps
        case LS_F:
        case RS_J:
        case LS_S:
        case RS_H:
            return 125;

        // Ctrl mod-taps
        case LC_D:
        case RC_K:
        case LC_T:
        case RC_E:
            return 150;

        // Alt mod-taps
        case LA_S:
        case RA_L:
        case LA_R:
        case RA_I:
            return 200;

        // GUI mod-taps
        case LG_A:
        case RS_SCLN:
        case LG_N:
        case RG_A:
            return 250;

        case OSMLSFT:
            return 300;

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
        // case CS_AL2:
        // case CS_AL3:
        // case CS_AL4:
        
        case TABLSFT:
        case TABRSFT:
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
            if (chordal_hold_handedness(other_record->event.key) == 'R' && (other_record->event.key.col == 1 || other_record->event.key.col == 2)) {
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

bool process_cs_layer_tap(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case CS_LT1:
            if (!record->tap.count && record->event.pressed) {
                layer_on(_DATA);
                update_tri_layer(_DATA, _PROGRAM, _EDIT);
            } else {
                layer_off(_DATA);
                update_tri_layer(_DATA, _PROGRAM, _EDIT);
            }
            if (record->tap.count && record->event.pressed) {
                tap_code(KC_SPC);
            }
            return false;
        case CS_RT1:
            if (!record->tap.count && record->event.pressed) {
                layer_on(_SYMBOL);
                update_tri_layer(_EDIT, _SYMBOL, _DATA_OVERLAY);
            } else {
                layer_off(_SYMBOL);
                update_tri_layer(_EDIT, _SYMBOL, _DATA_OVERLAY);
            }
            if (record->tap.count && record->event.pressed) {
                tap_code(KC_BSPC);
            }
            return false;
        case CS_AL1:
            if (!record->tap.count && record->event.pressed) {
                layer_on(_PROGRAM);
                update_tri_layer(_DATA, _PROGRAM, _EDIT);
            } else {
                layer_off(_PROGRAM);
                update_tri_layer(_DATA, _PROGRAM, _EDIT);
            }
            if (record->tap.count && record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code(KC_0);
                set_mods(mods);
            }
            return false;
        case CS_AL2:
            if (!record->tap.count && record->event.pressed) {
                layer_on(_EDIT);
                update_tri_layer(_EDIT, _SYMBOL, _DATA_OVERLAY);
            } else {
                layer_off(_EDIT);
                update_tri_layer(_EDIT, _SYMBOL, _DATA_OVERLAY);
            }
            if (record->tap.count && record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code16(KC_NUBS);
                set_mods(mods);
            }
            return false;
        case CS_AL3:
            if (!record->tap.count && record->event.pressed) {
                layer_on(_EDIT);
                update_tri_layer(_PROGRAM, _EDIT, _EDIT_OVERLAY);
            } else {
                layer_off(_EDIT);
                update_tri_layer(_PROGRAM, _EDIT, _EDIT_OVERLAY);
            }
            if (record->tap.count && record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code16(KC_NUBS);
                set_mods(mods);
            }
            return false;
        case CS_AL4:
            if (!record->tap.count && record->event.pressed) {
                layer_on(_PROGRAM);
                update_tri_layer(_PROGRAM, _EDIT, _EDIT_OVERLAY);
            } else {
                layer_off(_PROGRAM);
                update_tri_layer(_PROGRAM, _EDIT, _EDIT_OVERLAY);
            }
            if (record->tap.count && record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code(KC_0);
                set_mods(mods);
            }
            return true; // continue to arrow retrigger processing
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

    L_EXPONENT,
    L_COMMA,
    L_DOT,
    L_UNDERSCORE,
    L_ASTERISK,
    L_PLUS,
    L_EQUALS,
    L_MINUS,
    L_NEW,
    COLON,
    AMPERSAND,

    R_EXPONENT,
    R_COMMA,
    R_DOT,
    R_UNDERSCORE,
    R_ASTERISK,
    R_PLUS,
    R_EQUALS,
    R_MINUS,
    R_NEW,
    EXCLAMATION,
    SEMICOLON,

    SPC_F1,
    SPC_F2,
    SPC_F3,
    SPC_F4,
    SPC_F5,

    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM touhou[]         = {KC_P, CS_HASH, KC_ESC, COMBO_END};
const uint16_t PROGMEM steno[]          = {KC_P, CS_HASH, KC_SCLN, TABRSFT, COMBO_END};
const uint16_t PROGMEM numpad[]         = {KC_O, KC_P, CS_HASH, COMBO_END};
const uint16_t PROGMEM mouse[]          = {KC_SCLN, QUE_EXL, COMBO_END};
const uint16_t PROGMEM mouse2[]         = {KC_A, KC_Z, COMBO_END};

const uint16_t PROGMEM l_exponent[]     = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM l_comma[]        = {KC_D, KC_V, COMBO_END};
const uint16_t PROGMEM l_dot[]          = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM l_underscore[]   = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM l_asterisk[]     = {KC_F, KC_B, COMBO_END};
const uint16_t PROGMEM l_equals[]       = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM l_plus[]         = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM l_minus[]        = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM l_new[]          = {KC_X, KC_C, COMBO_END};
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
const uint16_t PROGMEM r_new[]          = {KC_QUOT, COM_DOT, COMBO_END};
const uint16_t PROGMEM semicolon[]      = {KC_J, KC_I, COMBO_END};
const uint16_t PROGMEM exclamation[]    = {KC_I, KC_L, COMBO_END};

const uint16_t PROGMEM spc_f1[]         = {KC_SPC, KC_Q, COMBO_END};
const uint16_t PROGMEM spc_f2[]         = {KC_SPC, KC_W, COMBO_END};
const uint16_t PROGMEM spc_f3[]         = {KC_SPC, KC_E, COMBO_END};
const uint16_t PROGMEM spc_f4[]         = {KC_SPC, KC_R, COMBO_END};
const uint16_t PROGMEM spc_f5[]         = {KC_SPC, KC_T, COMBO_END};


combo_t key_combos[] = {
    [TOUHOU]        = COMBO_ACTION(touhou),
    [STENO]         = COMBO_ACTION(steno),
    [NUMPAD]        = COMBO_ACTION(numpad),

    [MOUSE]         = COMBO(mouse,          CM_MOUSE),
    [MOUSE2]        = COMBO(mouse2,         CM_MOUSE),

    [L_EXPONENT]    = COMBO(l_exponent,     CS_CIRC),
    [L_COMMA]       = COMBO(l_comma,        CS_COMM),
    [L_DOT]         = COMBO(l_dot,          CS_DOT),
    [L_UNDERSCORE]  = COMBO(l_underscore,   CS_UNDS),
    [L_ASTERISK]    = COMBO(l_asterisk,     CS_ASTR),
    [L_EQUALS]      = COMBO(l_equals,       CS_EQL),
    [L_PLUS]        = COMBO(l_plus,         CS_PLUS),
    [L_MINUS]       = COMBO(l_minus,        CS_MINS),
    
    [AMPERSAND]     = COMBO(ampersand,      CS_AMPR),
    [COLON]         = COMBO(colon,          CS_COLN),
    
    [R_EXPONENT]    = COMBO(r_exponent,     CS_CIRC),
    [R_COMMA]       = COMBO(r_comma,        CS_COMM),
    [R_DOT]         = COMBO(r_dot,          CS_DOT),
    [R_UNDERSCORE]  = COMBO(r_underscore,   CS_UNDS),
    [R_ASTERISK]    = COMBO(r_asterisk,     CS_ASTR),
    [R_EQUALS]      = COMBO(r_equals,       CS_EQL),
    [R_PLUS]        = COMBO(r_plus,         CS_PLUS),
    [R_MINUS]       = COMBO(r_minus,        CS_MINS),

    [SEMICOLON]     = COMBO(semicolon,      CS_SCLN),
    [EXCLAMATION]   = COMBO(exclamation,    CS_EXLM),

    [L_NEW]         = COMBO(r_new,          NEWSENT),
    [R_NEW]         = COMBO(l_new,          NEWSENT),

    [SPC_F1]        = COMBO(spc_f1,         KC_F1),
    [SPC_F2]        = COMBO(spc_f2,         KC_F2),
    [SPC_F3]        = COMBO(spc_f3,         KC_F3),
    [SPC_F4]        = COMBO(spc_f4,         KC_F4),
    [SPC_F5]        = COMBO(spc_f5,         KC_F5),
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
        case STENO:
            if (pressed) {
                if (IS_LAYER_ON(_STENO)) {
                    layer_off(_STENO);
                } else {
                    layer_on(_STENO);
                    unregister_mods(MOD_BIT(KC_LSFT));
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
    }
}

// 50ms default
uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    switch (index) {
        case L_NEW:
        case R_NEW:

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
        case L_NEW:
            if (layer_state_is(_EDIT)) { 
                return false;
            }

        // Disable combos on some layers
        default:
            if (!(layer_state_is(_BASIC)
               || layer_state_is(_TOUHOU)
               || layer_state_is(_MOUSE)
               || layer_state_is(_STENO))) {
                return true;
            }
    }
    return false;
}



//==============================================================================
// Case Lock
//==============================================================================

void send_separator(void) {
    switch (case_lock_separator) {
        case KC_LSFT:
            set_oneshot_mods(MOD_BIT(KC_LSFT));
            break;
        case KC_RSFT:
            tap_code(KC_SPC);
            set_oneshot_mods(MOD_BIT(KC_LSFT));
        default:
            tap_code16(case_lock_separator);
            break;
    }
}

uint16_t separator_map(uint16_t keycode) {
    switch (keycode) {
        case CS_LT1:
            return KC_SPC;

        case CS_UNDS:
            return KC_UNDS;

        case CS_MINS:
            return KC_MINS;

        case CS_DOT: 
            return KC_DOT;

        case CS_SLSH:
        case CS_RT3:
            return KC_SLSH;

        case KC_Q:
        case KC_Z:
            return KC_NUBS;

        case TABLSFT:
            return KC_LSFT;

        case TABRSFT:
            return KC_RSFT;

        case RS_SCLN:
            return KC_SCLN;

        default:
            return keycode;
    }
}

bool process_case_capture(uint16_t keycode) {

    keycode = separator_map(keycode);

    switch (keycode) {
        default:
            case_lock_separator = KC_UNDS;
            case_lock_capture_off();
            case_lock_on();
            return true;

        case KC_SPC:
            case_lock_separator = KC_UNDS;
            case_lock_capture_off();
            case_lock_on();
            tap_code16(KC_UNDS);
            return false;

        case KC_RSFT:
            unregister_mods(MOD_BIT(KC_RSFT));
            set_oneshot_mods(MOD_BIT(KC_RSFT));
            
        case KC_LSFT:
            unregister_mods(MOD_BIT(KC_LSFT));

        case KC_UNDS:
        case KC_MINS:
        case KC_DOT:
        case KC_SLSH:
        case KC_NUBS:
            case_lock_separator = keycode;
            case_lock_capture_off();
            case_lock_on();
            return false;
    }
}

bool process_case_lock(uint16_t keycode, keyrecord_t* record) {

    keycode = separator_map(keycode);

    if (record->event.pressed) {
        if (keycode == CS_CASE) {;
            if (case_lock_capture) {
                tap_code(KC_CAPS);
                case_lock_off();
            } else {
                case_lock_capture_on();
            }
            return true;
        }

        if (case_lock_capture) {
            dprintf("capture start\n");
            return process_case_capture(keycode);
        }

        if (!case_lock_active) {
            return true;
        }

        // Track distance for rollbacks
        if (is_hrm(keycode)) {
            if (record->tap.count) {
                separator_distance += 1;
                // dprintf("separator distance = %d\n", separator_distance);
                return true;
            }
        }
        switch (keycode) {
            case KC_A ... KC_Z:
            case KC_1 ... KC_0:
            case KC_SCLN:
                separator_distance += 1;
                // dprintf("separator distance = %d\n", separator_distance);
                return true;

            case KC_UNDS:
            case KC_MINS:
            case KC_DOT:
            case KC_SLSH:
            case KC_NUBS:
                if (case_lock_separator == keycode) {
                    separator_distance = 0;
                } else {
                    separator_distance += 1;
                    // dprintf("separator distance = %d\n", separator_distance);
                }
                return true;
                
            case CS_LT2:
            case CS_RT2:
                if (record->tap.count) {
                    separator_distance += 1;
                    // dprintf("separator distance = %d\n", separator_distance);
                }
                return true;
        }

        if (keycode == KC_SPC) {
            if (record->tap.count) {
                if (case_lock_active) {
                    if (is_spc(last_key)) {
                        if (case_lock_separator == KC_LSFT) {
                            clear_oneshot_mods();
                            case_lock_off();
                            return true;
                        }
                        if (case_lock_separator == KC_RSFT) {
                            clear_oneshot_mods();
                            case_lock_off();
                            return false;
                        }
                        const uint8_t mods = get_mods();
                        del_mods(MOD_MASK_CSAG);
                        tap_code16(KC_BSPC);
                        set_mods(mods);
                        case_lock_off();
                        return true;
                    } else {
                        send_separator();
                        separator_distance = 0;
                        update_last_key(KC_SPC);
                        return false;
                    }
                }
            }
            return true;
        }

        if (keycode == CS_RT1) {
            if (record->tap.count) {
                if (ctrl_on() && separator_distance > 0) {
                    const uint8_t mods = get_mods();
                    del_mods(MOD_MASK_CSAG);
                    for (int i = 0; i < separator_distance; i++) {
                        tap_code(KC_BSPC);
                    }
                    set_mods(mods);
                    // dprintf("rolled back case!");
                    separator_distance = 0;
                    if (case_lock_separator == KC_LSFT || case_lock_separator == KC_RSFT) {
                        set_oneshot_mods(MOD_BIT(KC_LSFT));
                    }
                    return false;
                } else {
                    if (separator_distance > 0) {
                        separator_distance -= 1;
                    }
                    return true;
                }
            }
        }

        // Ignore modifier keys
        if (keycode == KC_LSFT || keycode == KC_RSFT || keycode == CS_LCTL || keycode == KC_LCTL) {
            return true;
        }
        // Ignore Data layer
        if (keycode == CS_LT1 && !record->tap.count) {
            return true;
        }
        // Disable Case Lock on Symbol, Program, and Edit layers
        if ((keycode == CS_RT1 || is_magic(keycode)) && !record->tap.count) {
            case_lock_off();
            return true;
        }

        // Disable case lock on other keys
        case_lock_off();
    }
    return true;
}



//==============================================================================
// Edit Control Keys
//==============================================================================

bool arrow_up = false;
bool arrow_down = false;
bool arrow_left = false;
bool arrow_right = false;

bool process_arrow_retrigger(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case KC_UP:
        case EO_UP:
            if (record->event.pressed) {
                arrow_up = true;
            } else {
                arrow_up = false;
            }
            return true;

        case KC_DOWN:
        case EO_DOWN:
            if (record->event.pressed) {
                arrow_down = true;
            } else {
                arrow_down = false;
            }
            return true;

        case KC_LEFT:
        case EO_LEFT:
            if (record->event.pressed) {
                arrow_left = true;
            } else {
                arrow_left = false;
            }
            return true;

        case KC_RGHT:
        case EO_RGHT:
            if (record->event.pressed) {
                arrow_right = true;
            } else {
                arrow_right = false;
            }
            return true;

        case CS_AL4:
            if (!record->tap.count && record->event.pressed) {
                if (arrow_up) { 
                    unregister_code(KC_UP);
                    register_code16(LCTL(KC_UP));
                }
                if (arrow_down) {
                    unregister_code(KC_DOWN);
                    register_code16(LCTL(KC_DOWN));
                }
                if (arrow_left) {
                    unregister_code(KC_LEFT);
                    register_code16(LCTL(KC_LEFT));
                }
                if (arrow_right) {
                    unregister_code(KC_RGHT);
                    register_code16(LCTL(KC_RGHT));
                }
            } else if (!record->tap.count && !record->event.pressed) {
                if (arrow_up) { 
                    unregister_code16(LCTL(KC_UP));
                    register_code(KC_UP);
                }
                if (arrow_down) {
                    unregister_code16(LCTL(KC_DOWN));
                    register_code(KC_DOWN);
                }
                if (arrow_left) {
                    unregister_code16(LCTL(KC_LEFT));
                    register_code(KC_LEFT);
                }
                if (arrow_right) {
                    unregister_code16(LCTL(KC_RGHT));
                    register_code(KC_RGHT);
                }
                return false;
            }

        default:
            return true;
    }
}


bool edit_clip = false;
bool select_line = false;

bool process_edit_macros(uint16_t keycode, keyrecord_t* record) {
    if (IS_LAYER_OFF(_EDIT_OVERLAY)) {
        select_line = false;
    }
    switch (keycode) {
        case DELWORD:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_CSAG);
                tap_code(KC_RGHT);
                add_mods(MOD_MASK_CTRL);
                tap_code(KC_LEFT);
                tap_code(KC_DEL);
                set_mods(mods);
            }
            break;

        case SELLEFT:
            if (record->event.pressed) {
                register_code16(LSFT(LCTL(KC_LEFT)));
                update_last_key(SELLEFT);
            } else {
                unregister_code16(LSFT(LCTL(KC_LEFT)));
            }
            break;

        case SELECT:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                if (is_select_macro(last_key)) {
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
            break;

        case SELRGHT:
            if (record->event.pressed) {
                register_code16(LSFT(LCTL(KC_RGHT)));
                update_last_key(SELRGHT);
            } else {
                unregister_code16(LSFT(LCTL(KC_RGHT)));
            }
            break;

        case EO_ENT:
            if (record->event.pressed) {
                register_code(KC_ENT);
            } else {
                unregister_code(KC_ENT);
            }
            break;

        case SELUP:
            if (!select_line) {
                if (record->event.pressed) {
                    const uint8_t mods = get_mods();
                    del_mods(MOD_MASK_CSAG);
                    select_line = true;
                    tap_code(KC_END);
                    add_mods(MOD_MASK_SHIFT);
                    tap_code(KC_HOME);
                    set_mods(mods);
                }
            } else {
                if (record->event.pressed) {
                    register_code16(LSFT(KC_UP));
                } else {
                    unregister_code16(LSFT(KC_UP));
                }
            }
            break;

        case SELDOWN:
            if (!select_line) {
                if (record->event.pressed) {
                    const uint8_t mods = get_mods();
                    del_mods(MOD_MASK_CSAG);
                    select_line = true;
                    tap_code(KC_HOME);
                    add_mods(MOD_MASK_SHIFT);
                    tap_code(KC_END);
                    set_mods(mods);
                }
            } else {
                if (record->event.pressed) {
                    register_code16(LSFT(KC_DOWN));
                } else {
                    unregister_code16(LSFT(KC_DOWN));
                }
            }
            break;
    }
    return true;
}

bool process_edit_controls(uint16_t keycode, keyrecord_t* record) {
    if (IS_LAYER_OFF(_EDIT)) {
        edit_clip = false;
    }
    if (get_highest_layer(layer_state) != _EDIT
     && get_highest_layer(layer_state) != _EDIT_OVERLAY 
     && get_highest_layer(layer_state) != _DATA_OVERLAY) {
        return true;
    }
    switch (keycode) {
        case DELWORD:
            if (record->event.pressed) {
                if (ctrl_on()) {
                    register_code16(LCTL(KC_Y));
                    return false;
                } else {
                    return true;
                }
            } else {
                unregister_code16(LCTL(KC_Y));
                return true;
            }
        case SELLEFT:
            if (record->event.pressed) {
                if (ctrl_on()) {
                    register_code16(LCTL(KC_Z));
                    return false;
                } else {
                    return true;
                }
            } else {
                unregister_code16(LCTL(KC_Z));
                return true;
            }
        case SELECT:
            if (record->event.pressed) {
                if (ctrl_on()) {
                    register_code16(LCTL(KC_X));
                    return false;
                } else {
                    return true;
                }
            } else {
                unregister_code16(LCTL(KC_X));
                return true;
            }
        case SELRGHT:
            if (record->event.pressed) {
                if (ctrl_on() || last_key == SELECT) {
                    register_code16(LCTL(KC_C));
                    edit_clip = true;
                    return false;
                } else {
                    return true;
                }
            } else {
                unregister_code16(LCTL(KC_C));
                return true;
            }
        case EO_ENT:
            if (record->event.pressed) {
                if (ctrl_on() || edit_clip) {
                    register_code16(LCTL(KC_V));
                    edit_clip = false;
                    return false;
                } else {
                    return true;
                }
            } else {
                unregister_code16(LCTL(KC_V));
                return true;
            }
    }
    return true;
}



//==============================================================================
// Cycling Macros
//==============================================================================

void rollback_bracket_wrap_macro(void) {
    const uint8_t mods = get_mods();
    del_mods(MOD_MASK_CSAG);
    tap_code(KC_BSPC);
    tap_code16(LCTL(KC_LEFT));
    tap_code(KC_BSPC);
    tap_code16(LCTL(KC_RGHT));
    set_mods(mods);
    rollback_last_key();
}

bool process_cycling_macros(uint16_t keycode, keyrecord_t* record) {
    static int bool_macro_state = 0;
    static int misc_macro_state = 0;
    static int bracket_macro_state = 0;
    static int comp_macro_state = 0;
    static int wrap_macro_state = 0;

    if (keycode != CY_BOOL) {
        bool_macro_state = 0;
    }
    if (keycode != CY_MISC) {
        misc_macro_state = 0;
    }
    if (keycode != CY_BRC) {
        bracket_macro_state = 0;
    }
    if (keycode != CY_COMP) {
        comp_macro_state = 0;
    }
    if (keycode != WRAPBRC) {
        wrap_macro_state = 0;
    }

    switch (keycode) {
        case CY_BOOL:
            if (record->event.pressed) {
                switch (bool_macro_state) {
                    case 0: {
                        const uint8_t mods = get_mods();
                        SEND_STRING("true");
                        set_mods(mods);

                        update_last_keys(KC_E,4);
                        bool_macro_state = 1;
                        break;
                    }
                    case 1: {
                        const uint8_t mods = get_mods();
                        tap_code(KC_BSPC);
                        tap_code(KC_BSPC);
                        tap_code(KC_BSPC);
                        tap_code(KC_BSPC);
                        SEND_STRING("false");
                        set_mods(mods);

                        rollback_last_key();
                        update_last_keys(KC_E,5);
                        bool_macro_state = 2;
                        break;
                    }
                    case 2: {
                        const uint8_t mods = get_mods();
                        tap_code(KC_BSPC);
                        tap_code(KC_BSPC);
                        tap_code(KC_BSPC);
                        tap_code(KC_BSPC);
                        tap_code(KC_BSPC);
                        SEND_STRING("true");
                        set_mods(mods);

                        rollback_last_key();
                        update_last_keys(KC_E,4);
                        bool_macro_state = 1;
                        break;
                    }
                }
            }
            break;

        case CY_MISC:
            if (record->event.pressed) {
                switch (misc_macro_state) {
                    case 0: {
                        const uint8_t mods = get_mods();
                        tap_code16(KC_DQUO); // CS_AT
                        set_mods(mods);

                        update_last_key(KC_DQUO);
                        misc_macro_state = 1;
                        break;
                    }
                    case 1: {
                        const uint8_t mods = get_mods();
                        tap_code(KC_BSPC);
                        tap_code16(KC_HASH); // CS_POUN
                        set_mods(mods);

                        update_last_key(KC_HASH);
                        misc_macro_state = 2;
                        break;
                    }
                    case 2: {
                        const uint8_t mods = get_mods();
                        tap_code(KC_BSPC);
                        tap_code16(KC_DQUO); // CS_AT
                        set_mods(mods);

                        update_last_key(KC_DQUO);
                        misc_macro_state = 1;
                        break;
                    }
                }
            }
            break;

        case CY_BRC:
            if (record->event.pressed) {
                switch (bracket_macro_state) {
                    case 0: {
                        const uint8_t mods = get_mods();
                        del_mods(MOD_MASK_CSAG);
                        tap_code16(KC_LPRN);
                        tap_code16(KC_RPRN);
                        tap_code(KC_LEFT);
                        set_mods(mods);

                        update_last_keys(CY_BRC,2);
                        bracket_macro_state = 1;
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

                        bracket_macro_state = 2;
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

                        bracket_macro_state = 3;
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

                        bracket_macro_state = 1;
                        break;
                    }
                }
            }
            break;

        case CY_COMP: 
            if (record->event.pressed) {
                switch (comp_macro_state) {
                    case 0: {
                        const uint8_t mods = get_mods();
                        del_mods(MOD_MASK_CSAG);
                        tap_code16(KC_GT);
                        set_mods(mods);

                        update_last_key(KC_GT);
                        comp_macro_state = 1;
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
                        comp_macro_state = 2;
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
                        comp_macro_state = 3;
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
                        comp_macro_state = 1;
                        break;
                    }
                }
            }
            break;



        case WRAPBRC:
            if (record->event.pressed) {
                switch (wrap_macro_state) {
                    case 0: {
                        const uint8_t mods = get_mods();
                        del_mods(MOD_MASK_CSAG);
                        tap_code(KC_RGHT);
                        tap_code16(LCTL(KC_LEFT));
                        tap_code16(KC_LPRN);
                        tap_code16(LCTL(KC_RGHT));
                        tap_code16(KC_RPRN);
                        set_mods(mods);
                        wrap_macro_state = 1;
                        break;
                    }
                    case 1: {
                        rollback_bracket_wrap_macro();
                        const uint8_t mods = get_mods();
                        del_mods(MOD_MASK_CSAG);
                        tap_code(KC_RGHT);
                        tap_code16(LCTL(KC_LEFT));
                        tap_code16(KC_LCBR);
                        tap_code16(LCTL(KC_RGHT));
                        tap_code16(KC_RCBR);
                        set_mods(mods);
                        wrap_macro_state = 2;
                        break;
                    }
                    case 2: {
                        rollback_bracket_wrap_macro();
                        const uint8_t mods = get_mods();
                        del_mods(MOD_MASK_CSAG);
                        tap_code(KC_RGHT);
                        tap_code16(LCTL(KC_LEFT));
                        tap_code(KC_LBRC);
                        tap_code16(LCTL(KC_RGHT));
                        tap_code(KC_RBRC);
                        set_mods(mods);
                        wrap_macro_state = 3;
                        break;
                    }
                    case 3: {
                        rollback_bracket_wrap_macro();
                        const uint8_t mods = get_mods();
                        del_mods(MOD_MASK_CSAG);
                        tap_code(KC_RGHT);
                        tap_code16(LCTL(KC_LEFT));
                        tap_code16(KC_LPRN);
                        tap_code16(LCTL(KC_RGHT));
                        tap_code16(KC_RPRN);
                        set_mods(mods);
                        wrap_macro_state = 1;
                        break;
                    }
                }
            }
            break;
    }
    return true;
}



//==============================================================================
// Repeat and Magic keys
//==============================================================================

bool process_rollback(void) {
    if (ctrl_on()) {
        rollback_last_key();
        return true;
    }

    if (is_bracket_wrap_macro(last_key) && (char_count == 2)) {
        rollback_bracket_wrap_macro();
        return false;
    }

    if (is_bracket_macro(last_key) && (char_count == 2)) {
        tap_code(KC_RGHT);
    }

    if (last_key == CY_BRC  && (char_count == 2)) {
        tap_code(KC_RGHT);
    }

    for (int i = 1; i < char_count; i++) {
        tap_code(KC_BSPC);
    }
    rollback_last_key();

    return true;
}

bool process_key_tracking(uint16_t keycode, keyrecord_t* record) {
    // Reset repeat space override if any non-magic key is pressed
    if (!is_magic(keycode)) {
        magic_override = false;
    }

    // Ignore tracking if layer tap key is held
    if (is_layer_tap(keycode)) {
        if (!record->tap.count && record->event.pressed) {
            return true;
        }
    }

    // Ignore tracking if ctrl is on (apart from data overlay layer) and reset rollback counter
    if (ctrl_on() && IS_LAYER_OFF(_DATA_OVERLAY)) {
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

    // Track mod-taps
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
    if (keycode == NEWSENT) {
        if (record->event.pressed) {
            update_last_keys(KC_SPC, 2);
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
    
    // Handle tap action of Tab-Shift keys
    if (keycode == TABLSFT || keycode == TABRSFT) {
        if (record->tap.count && record->event.pressed) {
            update_last_key(KC_SPC);
        }
        return true;
    }

    // Track punctuation
    if (keycode == KC_COMM || keycode == CS_COMM) {
        if (record->event.pressed) {
            update_last_key(KC_COMM);
        }
        return true;
    }
    if (keycode == KC_DOT || keycode == CS_DOT) {
        if (record->event.pressed) {
            update_last_key(KC_DOT);
        }
        return true;
    }
    if (keycode == KC_QUOT || keycode == CS_QUOT) {
        if (record->event.pressed) {
            update_last_key(KC_QUOT);
        }
        return true;
    }

    // Track various macros
    if (is_bracket_macro(keycode) || is_bracket_wrap_macro(keycode)) {
        if (record->event.pressed) {
            update_last_keys(keycode, 2);
        }
        return true;
    }
    if (keycode == CS_CONJ || keycode == CS_DISJ) {
        if (record->event.pressed) {
            if (ctrl_on() && shifted()) {
                update_last_keys(KC_NO, 4);
            } else if (ctrl_on()) {
                update_last_keys(KC_NO, 3);
            } else if (shifted()) {
                update_last_keys(KC_NO, 2);
            } else {
                update_last_key(KC_NO);
            }
        }
        return true;
    }
    // Tracking handled in macro for reactive events
    if (is_select_macro(keycode)) {
        return true;
    }
    if (is_cycling_macro(keycode)) {
        return true;
    }

    // Handle deletes
    if (keycode == CS_RT1) {
        if (record->tap.count && record->event.pressed) {
            return process_rollback();
        }
        return true;
    }
    if (keycode == KC_BSPC) {
        if (record->event.pressed) {
            return process_rollback();
        }
        return true;
    }

    // Do nothing:
    if (is_magic(keycode)) {
        return true;
    }
    if (keycode == KC_LSFT || keycode == OSMLSFT || keycode == KC_LCTL || keycode == CS_LCTL) {
        return true;
    }

    // Reset rollback counter and recorded key on any other keypress
    if (record->event.pressed) {
        update_last_key(KC_NO);
    }
    return true;
}

void send_the(void) {
    if (shifted()) {
        const uint8_t mods = get_mods();
        del_mods(MOD_MASK_CSAG);
        add_mods(MOD_MASK_SHIFT);
        tap_code(KC_T);
        del_mods(MOD_MASK_SHIFT);
        tap_code(KC_H);
        tap_code(KC_E);
        set_mods(mods);
    } else {
        SEND_STRING("the");
    }
    update_last_keys(KC_E,3);
}

void send_nt(void) {
    if (shifted()) {
        const uint8_t mods = get_mods();
        del_mods(MOD_MASK_CSAG);
        tap_code(KC_QUOT);
        add_mods(MOD_MASK_SHIFT);
        tap_code(KC_T);
        tap_code(KC_SPC);
        set_mods(mods);
    } else {
        SEND_STRING("'t ");
    }
    update_last_keys(KC_SPC,3);
}

void start_sentence(void) {
    tap_code(KC_SPC);
    set_oneshot_mods(MOD_BIT(KC_LSFT));
    update_last_key(KC_SPC);
}

bool process_magic(uint16_t keycode, keyrecord_t* record) {
    if (keycode == CS_LT2) {
        if (!record->tap.count && record->event.pressed) {
            layer_lock_off(_EDIT);
            layer_on(_EDIT);
            update_tri_layer(_EDIT, _SYMBOL, _DATA_OVERLAY);
            update_tri_layer(_PROGRAM, _EDIT, _EDIT_OVERLAY);
        } else if (!is_layer_locked(_EDIT)) {
            layer_off(_EDIT);
            update_tri_layer(_EDIT, _SYMBOL, _DATA_OVERLAY);
            update_tri_layer(_PROGRAM, _EDIT, _EDIT_OVERLAY);
        }

        if (record->tap.count && record->event.pressed) {
            if (is_layer_locked(_EDIT)) {
                layer_lock_off(_EDIT);
                return false;
            }
            const uint8_t mods = get_mods();
            del_mods(MOD_MASK_CTRL);
            last_key_dynamic = true;
            if (IS_LAYER_ON(_QWERTY) || IS_LAYER_ON(_BASIC)) {
                tap_code(last_key);
                update_last_key(last_key);
                set_mods(mods);
                return false;
            }

            magic_override = true;

            switch (last_key) {
                // Left hand keys
                case KC_Z: tap_code(KC_N); update_last_key(KC_N); break;
                case KC_L: tap_code(KC_R); update_last_key(KC_R); break;
                case KC_D: tap_code(KC_T); update_last_key(KC_T); break;
                case KC_C: tap_code(KC_S); update_last_key(KC_S); break;
                case KC_B: SEND_STRING(/*b*/"ecause "); update_last_keys(KC_SPC, 7); magic_override = false; break;

                case KC_N: send_nt(); magic_override = false; break;
                case KC_R: tap_code(KC_L); update_last_key(KC_L); break;
                case KC_T: SEND_STRING(/*t*/"ment"); update_last_keys(KC_N, 4); break;
                case KC_S: tap_code(KC_C); update_last_key(KC_C); break;
                case KC_G: tap_code(KC_S); update_last_key(KC_S); break;

                case KC_Q: tap_code(KC_U); update_last_key(KC_U); break;
                case KC_X: tap_code(KC_C); update_last_key(KC_C) ;break;
                case KC_M: SEND_STRING(/*m*/"ent"); update_last_keys(KC_T, 3); break;
                case KC_W: tap_code(KC_S); update_last_key(KC_S); break;
                case KC_V: tap_code(KC_S); update_last_key(KC_S); break;

                // Right hand overrides
                case KC_J: SEND_STRING(/*j*/"ect"); update_last_keys(KC_T, 3); break;
                case KC_O: tap_code(KC_E); update_last_key(KC_E); break;
                case KC_U: tap_code(KC_I); update_last_key(KC_I); break;
                case KC_Y: tap_code(KC_P); update_last_key(KC_P); break;
                case KC_H: SEND_STRING(/*h*/"ere"); update_last_keys(KC_E, 3); break;
                case KC_E: tap_code(KC_O); update_last_key(KC_O); break;
                case KC_I: SEND_STRING(/*i*/"on"); update_last_keys(KC_N, 2); break;
                case KC_A: SEND_STRING(/*a*/"nd "); update_last_keys(KC_SPC, 3); magic_override = false; break;

                case KC_NO:
                case KC_SPC: set_oneshot_mods(MOD_BIT(KC_LSFT)); magic_override = false; break;
                case KC_COMM: SEND_STRING(" and "); update_last_keys(KC_SPC, 4); magic_override = false; break;
                case KC_DOT: start_sentence(); magic_override = false; break;
                case KC_QUOT: SEND_STRING("ve "); update_last_keys(KC_SPC, 3); magic_override = false; break;

                default: tap_code(last_key); update_last_key(last_key); magic_override = false; break;
            }
            set_mods(mods);
        }
        return false;
    }

    if (keycode == CS_RT2) {
        if (!record->tap.count && record->event.pressed) {
            layer_on(_PROGRAM);
            update_tri_layer(_PROGRAM, _EDIT, _EDIT_OVERLAY);
            update_tri_layer(_DATA, _PROGRAM, _EDIT);
        } else {
            layer_off(_PROGRAM);
            if (IS_LAYER_OFF(_EDIT_OVERLAY)) {
                update_tri_layer(_DATA, _PROGRAM, _EDIT);
            }
            update_tri_layer(_PROGRAM, _EDIT, _EDIT_OVERLAY);
            layer_off(_DATA_OVERLAY);
        }

        if (record->tap.count && record->event.pressed) {
            const uint8_t mods = get_mods();
            del_mods(MOD_MASK_CTRL);
            if (magic_override) {
            last_key_dynamic = true;
                tap_code(KC_SPC);
                update_last_key(KC_SPC);
                magic_override = false;
                set_mods(mods);
                return false;
            }

            if (IS_LAYER_ON(_QWERTY) || IS_LAYER_ON(_BASIC)) {
                tap_code(last_key);
                update_last_key(last_key);
                set_mods(mods);
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
                case KC_A: SEND_STRING("nd "); update_last_keys(KC_SPC, 3); break;

                case KC_K: tap_code(KC_Y); update_last_key(KC_Y); break;
                case KC_P: tap_code(KC_H); update_last_key(KC_H); break;

                // Left hand overrides
                case KC_X: SEND_STRING(/*x*/"es"); update_last_keys(KC_S, 2); break;
                case KC_V: SEND_STRING(/*v*/"er"); update_last_keys(KC_R, 2); break;
                case KC_W: SEND_STRING(/*w*/"ith"); update_last_keys(KC_H, 3); break;

                case KC_NO:
                case KC_SPC: send_the(); break;
                case KC_COMM: SEND_STRING(" but "); update_last_keys(KC_SPC, 4); break;
                case KC_DOT: SEND_STRING("com"); update_last_keys(KC_NO, 3); break;
                case KC_QUOT: SEND_STRING("re "); update_last_keys(KC_SPC, 3); break;

                default: tap_code(last_key); update_last_key(last_key); break;
            }
            set_mods(mods);
        }
        return false;
    }

    last_key_dynamic = false;
    return true;
}



bool process_pre_key_tracking(uint16_t keycode, keyrecord_t* record) {
    if (last_key == KC_SPC && last_key_dynamic) {
        switch (keycode) {
            case KC_DOT:
            case CS_DOT:
            case KC_COMM:
            case CS_COMM:
            case COM_DOT:

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
            clear_oneshot_mods();
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



bool process_boot_anim(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case CS_LT3:
        case CS_LT2:
        case CS_LT1:
        case CS_RT1:
        case CS_RT2:
        case CS_RT3:
            if (!record->tap.count && record->event.pressed) {
                cancel_deferred_exec(boot_animation_token);
            }
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
    char time_str[9];

    time_str[8] = '\0';
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
// Events
//==============================================================================

bool pre_process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case TABLSFT:
            if (record->event.pressed && !(get_mods() & MOD_BIT(KC_LSFT))) {
                register_mods(MOD_BIT(KC_LSFT));
                left_eager_shift_on = true;
            }
            break;
        case TABRSFT:
            if (record->event.pressed && !(get_mods() & MOD_BIT(KC_RSFT))) {
                register_mods(MOD_BIT(KC_RSFT));
                right_eager_shift_on = true;
            }
            break;
    }
    return true;
}



bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_case_lock(keycode, record)) { return false; }
    if (!process_cycling_macros(keycode, record)) { return false; }
    if (!process_pre_key_tracking(keycode, record)) { return false; }
    // Reactive features go before key tracking
    if (!process_key_tracking(keycode, record)) { return false; }
    if (!process_lingering_mods(keycode, record)) { return false; }
    if (!process_magic(keycode, record)) { return false; }
    if (!process_homerow_mod_tap(keycode, record)) { return false; }
    if (!process_cs_layer_tap(keycode, record)) { return false; }
    if (!process_arrow_retrigger(keycode, record)) { return false; }
    if (!process_edit_controls(keycode, record)) { return false; }
    if (!process_edit_macros(keycode, record)) { return false; }
    if (!process_vol_repeat(keycode, record)) { return false; }
    if (!process_clock(keycode, record)) { return false; }
    if (!process_boot_anim(keycode, record)) { return false; }

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
        // Macros
        // =====================================================================

        case NEWSENT:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                clear_oneshot_mods();
                del_mods(MOD_MASK_SHIFT);
                SEND_STRING(". ");
                set_mods(mods);
                add_oneshot_mods(MOD_BIT(KC_LSFT));
            }
            break;

        case CS_NORM:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_CS);
                tap_code16(LSFT(KC_NUBS));
                tap_code16(LSFT(KC_NUBS));
                tap_code(KC_LEFT);
                set_mods(mods);
            }
            break;

        case CS_CBRS:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_CS);
                tap_code16(KC_LCBR);
                tap_code16(KC_RCBR);
                tap_code(KC_LEFT);
                set_mods(mods);
            }
            break;

        case CS_PRNS:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_CS);
                tap_code16(KC_LPRN);
                tap_code16(KC_RPRN);
                tap_code(KC_LEFT);
                set_mods(mods);
            }
            break;

        case CS_BRCS:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_CS);
                tap_code(KC_LBRC);
                tap_code(KC_RBRC);
                tap_code(KC_LEFT);
                set_mods(mods);
            }
            break;

        // Edit overlay keys
        case WORDCBR:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_CSAG);
                tap_code(KC_RGHT);
                tap_code16(LCTL(KC_LEFT));
                tap_code16(KC_LCBR);
                tap_code16(LCTL(KC_RGHT));
                tap_code16(KC_RCBR);
                set_mods(mods);
            }
            break;

        case WORDPRN:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_CSAG);
                tap_code(KC_RGHT);
                tap_code16(LCTL(KC_LEFT));
                tap_code16(KC_LPRN);
                tap_code16(LCTL(KC_RGHT));
                tap_code16(KC_RPRN);
                set_mods(mods);
            }
            break;

        case WORDBRC:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_CSAG);
                tap_code(KC_RGHT);
                tap_code16(LCTL(KC_LEFT));
                tap_code(KC_LBRC);
                tap_code16(LCTL(KC_RGHT));
                tap_code(KC_RBRC);
                set_mods(mods);
            }
            break;

        case SPC_UP:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_CSAG);
                tap_code(KC_HOME);
                tap_code(KC_ENT);
                tap_code(KC_UP);
                set_mods(mods);
            }
            break;
        case JOIN:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_CSAG);
                tap_code(KC_END);
                add_mods(MOD_MASK_CTRL);
                tap_code(KC_DEL);
                del_mods(MOD_MASK_CTRL);
                set_mods(mods);
                if (shifted()) {
                    /*intentionally blank*/ ;
                } else {
                    tap_code(KC_SPC);
                }
            }
            break;
        case SPC_DN:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_CSAG);
                tap_code(KC_END);
                tap_code(KC_ENT);
                set_mods(mods);
            }
            break;

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

        case CS_RGBN:
            if (record->event.pressed) {
                if (shifted()) {
                    if (set_rgb_mode < 7) {
                        set_rgb_mode += 1;
                    } else {
                        set_rgb_mode = 3;
                    }
                } else {
                    if (set_rgb_mode > 3) {
                        set_rgb_mode -= 1;
                    } else {
                        set_rgb_mode = 7;
                    }
                }
                dprintf("rgb_mode: %d\n", set_rgb_mode);
                rgb_matrix_mode_noeeprom(set_rgb_mode);
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
                update_sync();
                if (!static_display) {
                    oled_clear();
                }
            }
            break;
        case OLEDTOG:
            if (record->event.pressed) {
                oled_disable = !oled_disable;
                update_sync();
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
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_CTRL);
                tap_code16(LSFT(KC_END));
                set_mods(mods);
            }
            break;
        case EO_HOME:
            if (record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_CTRL);
                tap_code16(LSFT(KC_HOME));
                set_mods(mods);
            }
            break;

        case TABLSFT:
            if (!record->tap.count && !record->event.pressed) {
                unregister_mods(MOD_BIT(KC_LSFT));
            }
            if (record->tap.count && record->event.pressed) {
                if (left_eager_shift_on) {
                    unregister_mods(MOD_BIT(KC_LSFT));
                }
                if (IS_LAYER_OFF(_CONTROL_OVERLAY)) {
                    tap_code(KC_TAB);
                }
            }
            left_eager_shift_on = false;
            return false;
        case TABRSFT:
            if (!record->tap.count && !record->event.pressed) {
                unregister_mods(MOD_BIT(KC_RSFT));
            }
            if (record->tap.count && record->event.pressed) {
                if (right_eager_shift_on) {
                    unregister_mods(MOD_BIT(KC_RSFT));
                }
                tap_code(KC_TAB);
            }
            right_eager_shift_on = false;
            return false;

        // =====================================================================
        // Custom shifts
        // =====================================================================

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
                    tap_code16(KC_AMPR);
                }
                set_mods(mods);
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
                    tap_code16(LSFT(KC_NUBS));
                }
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
                tap_code16(LSFT(KC_NUHS));
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

        // =====================================================================
        // Home row mods
        // =====================================================================

        // Edit layer
        case RG_TILD:
            if (record->tap.count && record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code16(LSFT(KC_NUHS));
                set_mods(mods);
            }
            return false;

        case RA_UNDS:
            if (record->tap.count && record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code16(KC_UNDS);
                set_mods(mods);
            }
            return false;

        case RC_LPRN:
            if (record->tap.count && record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code16(KC_LPRN);
                set_mods(mods);
            }
            return false;

        case RS_RPRN:
            if (record->tap.count && record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code16(KC_RPRN);
                set_mods(mods);
            }
            return false;



        // Data layer
        case LG_EXLM:
            if (record->tap.count && record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code16(KC_EXLM);
                set_mods(mods);
            }
            return false;
        case LA_COLN:
            if (record->tap.count && record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code16(KC_COLN);
                set_mods(mods);
            }
            return false;
        case LC_DOT:
            if (record->tap.count && record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code(KC_DOT);
                set_mods(mods);
            }
            return false;
        case LS_COMM:
            if (record->tap.count && record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code(KC_COMM);
                set_mods(mods);
            }
            return false;

            
        case RG_UNDS:
            if (record->tap.count && record->event.pressed) {
                const uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code16(KC_UNDS);
                set_mods(mods);
            }
            return false;



        // Edit overlay
        case RS_DELL:
            if (record->tap.count && record->event.pressed) {
                const uint8_t mods = get_mods();
                if (shifted()) {
                    del_mods(MOD_MASK_CSAG);
                    tap_code16(LSFT(KC_HOME));
                    tap_code16(KC_BSPC);
                } else {
                    del_mods(MOD_MASK_CSAG);
                    tap_code16(LCTL(KC_BSPC));
                }
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
                if (shifted()) {
                    del_mods(MOD_MASK_CSAG);
                    tap_code16(LSFT(KC_END));
                    tap_code(KC_BSPC);
                } else {
                    del_mods(MOD_MASK_CSAG);
                    tap_code16(LCTL(KC_DEL));
                }
                set_mods(mods);
            }
            return false;

        // =====================================================================
        // Combos
        // =====================================================================

        case CM_MOUSE:
            if (record->event.pressed) {
                layer_lock_off(_MOUSE);
                layer_on(_MOUSE);
            } else if (!is_layer_locked(_MOUSE)) {
                layer_off(_MOUSE);
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
    char render_str[4];

    render_str[3] = '\0';
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
    if (sync_data.oled_timeout_sync || sync_data.oled_disable_sync) {
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
    if (IS_LAYER_ON(_MOUSE)) {
        oled_write_P(PSTR(" Mouse\n"), false);
    } else if (IS_LAYER_ON(_TOUHOU)) {
        oled_write_P(PSTR(" Touhou\n"), false);
    } else if (IS_LAYER_ON(_NUMPAD)) {
        oled_write_P(PSTR(" Numpad\n"), false);
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
    if ((get_mods() & MOD_MASK_SHIFT) || oneshot_shift_on) {
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

#define overlay_mask ~((1 << _CONTROL_OVERLAY) | (1 << _NUMPAD) | (1 << _MOUSE))
#define base_layer_mask ~((1 << _BASE) | (1 << _QWERTY) | (1 << _BASIC))

void render_layout(void) {
    if (IS_LAYER_ON(_BASE)) {
        oled_set_cursor(0,3);
        oled_write_raw_P(menu_layout_base_left, layout_left_size);
        oled_set_cursor(0,6);
        oled_write_raw_P(menu_layout_base_right, layout_right_size);
    } else if (IS_LAYER_ON(_BASIC) || IS_LAYER_ON(_QWERTY)) {
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
            oled_write_raw_P(menu_layout_data_right, layout_right_size);
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

void render_right_thumb(const char* progmem_data) {
    oled_set_cursor(8,6);
    oled_write_raw_P(&progmem_data[0], 16);
    oled_set_cursor(8,7);
    oled_write_raw_P(&progmem_data[16], 16);
    oled_set_cursor(8,8);
    oled_write_raw_P(&progmem_data[32], 16);
    oled_set_cursor(8,9);
    oled_write_raw_P(&progmem_data[48], 16);
}

void render_overlays(void) {
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
        oled_write_raw_P(menu_layout_data_overlay, 18);
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

void render_status(void) {
    if (menu == 0) {
        oled_set_cursor(0,3);
        oled_write_ln_P(PSTR("Layer:"), false); // 1
        render_layer(); // 7
    } else if (menu == 1) {
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
    if (oled_disable) {
        oled_clear();
        return false;
    }
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
        } else {
            render_draw();
        }
    }
    return false;
}



//==============================================================================
// RGB
//==============================================================================

// Wrapper around rgb_matrix_set_color to correct for split detection with MASTER_RIGHT defined
void rgb_matrix_set_color_split(uint8_t index, uint8_t r, uint8_t g, uint8_t b) {
    if ((!is_keyboard_master() && index < 27) || (is_keyboard_master() && index >= 27)) {
        rgb_matrix_set_color(index, r, g, b);
    }
}



bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // if (boot || sync_data.boot_sync) {
    //     return false;
    // }

    if (case_lock_capture || sync_data.case_lock_capture_sync) {
        for (uint8_t index = 6; index < 27; index++) {
            RGB green = hsv_to_rgb((HSV){ 85, 255, 100 });
            rgb_matrix_set_color_split(index, green.r, green.g, green.b);
            rgb_matrix_set_color_split(index+27, green.r, green.g, green.b);
        }
    } else if (case_lock_active || sync_data.case_lock_active_sync) {
        for (uint8_t index = 6; index < 27; index++) {
            RGB red = hsv_to_rgb((HSV){ 255, 255, 100 });
            rgb_matrix_set_color_split(index, red.r, red.g, red.b);
            rgb_matrix_set_color_split(index+27, red.r, red.g, red.b);
        }
    }

    int arrows[4] = { 17, 19, 16, 11 };
    int underglow[12] = { 0, 1, 2, 3, 4, 5, 27, 28, 29, 30, 31, 32 };

    HSV arrow_hsv = (HSV){ 169, 255, 255 };
    RGB arrow_rgb = hsv_to_rgb(arrow_hsv);

    HSV underglow_hsv = (HSV){ 0, 0, 0 };
    RGB underglow_rgb = hsv_to_rgb(underglow_hsv);

    switch (get_highest_layer(layer_state|default_layer_state)) {
        case _PROGRAM:
            underglow_hsv = (HSV){ 85, 255, 255 };
            underglow_rgb = hsv_to_rgb(underglow_hsv);
            for (uint8_t i = 0; i < 12; i++) {
                rgb_matrix_set_color_split(underglow[i], underglow_rgb.r, underglow_rgb.g, underglow_rgb.b);
            }
            break;
        case _DATA:
            underglow_hsv = (HSV){ 127, 255, 255 };
            underglow_rgb = hsv_to_rgb(underglow_hsv);
            for (uint8_t i = 0; i < 12; i++) {
                rgb_matrix_set_color_split(underglow[i], underglow_rgb.r, underglow_rgb.g, underglow_rgb.b);
            }
            break;
        case _EDIT:
            underglow_hsv = (HSV){ 0, 255, 255 };
            underglow_rgb = hsv_to_rgb(underglow_hsv);
            for (uint8_t i = 0; i < 12; i++) {
                rgb_matrix_set_color_split(underglow[i], underglow_rgb.r, underglow_rgb.g, underglow_rgb.b);
            }
            break;
        case _SYMBOL:
            underglow_hsv = (HSV){ 169, 255, 255 };
            underglow_rgb = hsv_to_rgb(underglow_hsv);
            for (uint8_t i = 0; i < 12; i++) {
                rgb_matrix_set_color_split(underglow[i], underglow_rgb.r, underglow_rgb.g, underglow_rgb.b);
            }
            break;
        case _MOUSE:
            underglow_hsv = (HSV){ 222, 255, 255 };
            underglow_rgb = hsv_to_rgb(underglow_hsv);
            for (uint8_t i = 0; i < 12; i++) {
                rgb_matrix_set_color_split(underglow[i], underglow_rgb.r, underglow_rgb.g, underglow_rgb.b);
            }
            break;
        case _NUMPAD:
            underglow_hsv = (HSV){ 43, 255, 255 };
            underglow_rgb = hsv_to_rgb(underglow_hsv);
            for (uint8_t i = 0; i < 12; i++) {
                rgb_matrix_set_color_split(underglow[i], underglow_rgb.r, underglow_rgb.g, underglow_rgb.b);
            }
            break;
        case _UTILITY:
            underglow_hsv = (HSV){ 201, 255, 255 };
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
        case _BASIC:
        default:
            break;
    }
    return false;
}
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


layer_state_t layer_state_set_user(layer_state_t state) {
    if (boot) {
        return state;
    }

    if (IS_LAYER_ON_STATE(state, _BASIC) || IS_LAYER_ON_STATE(state, _TOUHOU)) {
        rgb_matrix_sethsv_noeeprom(127,255,255);
        rgb_matrix_mode_noeeprom(RGB_MATRIX_RIVERFLOW);
    } else if (IS_LAYER_ON_STATE(state, _QWERTY)) {
        rgb_matrix_sethsv_noeeprom(255,255,255);
        rgb_matrix_mode_noeeprom(RGB_MATRIX_RIVERFLOW);
    } else if (IS_LAYER_ON_STATE(state, _BASE)) {
        rgb_matrix_sethsv_noeeprom(255,255,255);
        rgb_matrix_mode_noeeprom(set_rgb_mode);
    }
    return state;
}



// =============================================================================
//  Boot/Shutdown
// =============================================================================

uint32_t boot_animation_fade(uint32_t trigger_time, void* cb_arg) {
    static int fade = 0;
    rgb_matrix_sethsv_noeeprom(255, 255, fade);
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE);
    if (fade < 64) {
        fade += 2;
        return 50;
    } else if (fade < 127) {
        fade += 2;
        return 100;
    } else if (fade < 255) {
        fade += 1;
        return 100;
    }
    return 0;
}

void keyboard_post_init_user(void) {
    boot_timer = timer_read();
    boot = true;
    layer_move(_BASE);

    // Debug options
    debug_enable = true;
    // debug_matrix = true;
    // debug_keyboard = true;
    // debug_mouse = true;

    // Boot animation
    rgb_matrix_set_speed_noeeprom(64);
    rgb_matrix_sethsv_noeeprom(255,255,255);
    rgb_matrix_mode_noeeprom(RGB_MATRIX_BAND_VAL);

    boot_animation_token = defer_exec(5200, boot_animation_fade, NULL);

    // Clock
    defer_exec(clock_callback(0,NULL), clock_callback, NULL);

    // OLED sync
    transaction_register_rpc(USER_SYNC_A, user_config_sync_handler);
}

void oled_render_boot(bool bootloader) {
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
            RGB underglow_rgb  = hsv_to_rgb((HSV){ 255, 255, 255 });
            rgb_matrix_set_color_split(underglow[i], underglow_rgb.r, underglow_rgb.g, underglow_rgb.b);
        }
    }
    rgb_matrix_update_pwm_buffers();
    return false;
}



// =============================================================================
// Timers
// =============================================================================

#define IDLE_TIMEOUT 1000 * 60 * 5

void housekeeping_task_user(void) {
    // Exit boot animation
    if (timer_elapsed(boot_timer) > 5000) {
        boot = false;
    }

    // Layer timeout
    if (last_input_activity_elapsed() > IDLE_TIMEOUT) {
        layer_off(_NUMPAD);
        layer_off(_TOUHOU);
    }

    if (last_input_activity_elapsed() > 200 && last_key == SELECT) {
        // Reset Select control override
        last_key = KC_NO;
    }
    if (last_input_activity_elapsed() > 500) {
        // Reset key tracking
        char_count = 1;
    }
    if (last_input_activity_elapsed() > 1000) {
        // Reset magic keys
        last_key = KC_NO;
        last_key_2 = KC_NO;
        last_key_3 = KC_NO;

        // Reset Case Lock capture
        if (!case_lock_active) {
            case_lock_capture_off();
        }
    }
    if (last_input_activity_elapsed() > 2000) {
        // Reset Case Lock
        if (case_lock_active) {
            case_lock_off();
        }
    }

    if (last_input_activity_elapsed() > 3000) {
        // OLED timeout
        time_setting = 0;
        oled_timeout = true;
        static uint32_t last_sync = 0;
        if (timer_elapsed32(last_sync) > 500) {
            update_sync();
            last_sync = timer_read32();
        }
    } else {
        oled_timeout = false;
    }


    // Alt tab key
    if (alt_tab_active) {
        if (IS_LAYER_OFF(_UTILITY)) {
            unregister_code(KC_LALT);
            alt_tab_active = false;
        }
    }

    // =========================================================================
    // Data Sync
    // =========================================================================

    if (is_keyboard_master()) {
        static uint32_t last_sync = 0;
        if (timer_elapsed32(last_sync) > 500) { // Interact with slave every 500ms
            master_to_slave_t m2s = {
                .static_display_sync = static_display,
                .oled_timeout_sync = oled_timeout,
                .oled_disable_sync = oled_disable,
                .case_lock_capture_sync = case_lock_capture,
                .case_lock_active_sync = case_lock_active,
            };
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
        if (sync_data.oled_timeout_sync || sync_data.oled_disable_sync) { 
            oled_off();
        } else {
            oled_on();
        }
    }
}