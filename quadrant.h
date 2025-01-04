#include QMK_KEYBOARD_H

#define MIN_SCALE 0.01
#define MOVE_FACTOR (2.0 / 3.0)
#define RESCALE_FACTOR (1.0 / 3.0)
#define QUADRANT_SCALE_LOCAL 0.125
#define ANIMATION_SLEEP 5
#define ANIMATION_STEP 75

enum quadrant_keycodes {
    MSQ_RST = MS_ACL0,
    MSQ_LOC = MS_ACL1,
    MSQ_DNC = MS_ACL2,

    MSQ_U = MS_UP,
    MSQ_L = MS_LEFT,
    MSQ_C = MS_BTN8,
    MSQ_R = MS_RGHT,
    MSQ_D = MS_DOWN,
};

typedef enum {
    x,
    y,
    centre,
} axis_t;

void quadrant_cursor_init(void);
bool process_quadrant(uint16_t keycode, keyrecord_t *record);