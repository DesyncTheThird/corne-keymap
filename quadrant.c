#include QMK_KEYBOARD_H
#include "quadrant.h"

typedef struct {
    float x, y;
    float scale_x;
    float scale_y;
} quadrant_cursor_t;
static quadrant_cursor_t quadrant_cursor;
static uint16_t quadrant_animation_start;
static axis_t prev_axis = centre;

void quadrant_cursor_init(void) {
    quadrant_cursor.x = 0.5;
    quadrant_cursor.y = 0.5;
    quadrant_cursor.scale_x = 0.5;
    quadrant_cursor.scale_y = 0.5;
    prev_axis = centre;

}

quadrant_cursor_t make_quadrant_cursor(float x, float y, float scale_x, float scale_y) {
    quadrant_cursor_t cursor;
    cursor.x = x;
    cursor.y = y;
    cursor.scale_x = scale_x;
    cursor.scale_y = scale_y;
    return cursor;
}

quadrant_cursor_t quadrant_cursor_direction(quadrant_cursor_t cursor, int8_t delta, axis_t axis) {
    float new_x;
    float new_y;
    float new_scale_x;
    float new_scale_y;

    // Center key
    if (axis == centre) {
        new_x = cursor.x;
        new_y = cursor.y;
        new_scale_x = cursor.scale_x * RESCALE_FACTOR;
        new_scale_y = cursor.scale_y * RESCALE_FACTOR;
    } else if (axis == x) {
        new_x = cursor.x + (float)(delta) * MOVE_FACTOR * cursor.scale_x;
        new_y = cursor.y;
        new_scale_x = cursor.scale_x * RESCALE_FACTOR;
        new_scale_y = cursor.scale_y;
    } else {
        new_x = cursor.x;
        new_y = cursor.y + (float)(delta) * MOVE_FACTOR * cursor.scale_y;
        new_scale_x = cursor.scale_x;
        new_scale_y = cursor.scale_y * RESCALE_FACTOR;
    }

    // If same axis is repeated, shrink both scales instead
    if (axis == prev_axis) {
        new_scale_x = cursor.scale_x * RESCALE_FACTOR;
        new_scale_y = cursor.scale_y * RESCALE_FACTOR;
    }
    prev_axis = axis;

    cursor = make_quadrant_cursor(
        new_x,
        new_y,
        new_scale_x,
        new_scale_y
    );

    if (cursor.x < 0) {
        cursor.x = 0;
    }
    if (cursor.x > 1) {
        cursor.x = 1;
    }
    if (cursor.y < 0) {
        cursor.y = 0;
    }
    if (cursor.y > 1) {
        cursor.y = 1;
    }
    if (cursor.scale_x < MIN_SCALE) {
        cursor.scale_x = MIN_SCALE;
    }
    if (cursor.scale_y < MIN_SCALE) {
        cursor.scale_y = MIN_SCALE;
    }
    return cursor;
}

uint32_t quadrant_animation(uint32_t trigger_time, void *cb_arg) {
    if (quadrant_animation_start == 0) {
        return 0;
    }
    uint8_t step = (timer_read() - quadrant_animation_start) / ANIMATION_STEP;
    int8_t delta;
    axis_t axis;
    switch (step) {
        case 0:
        case 4:
            delta = -1;
            axis = y;
            break;
        case 1:
            delta = 1;
            axis = x;
            break;
        case 2:
            delta = 1;
            axis = y;
            break;
        case 3:
            delta = -1;
            axis = x;
            break;
        default:
            delta = 0;
            axis = centre;
            quadrant_animation_start = 0;
            break;
    }
    quadrant_cursor_t animation_cursor = quadrant_cursor_direction(quadrant_cursor, delta, axis);
    digitizer_set_position(animation_cursor.x, animation_cursor.y);
    return ANIMATION_SLEEP;
}

bool process_quadrant(uint16_t keycode, keyrecord_t *record) {
    bool msq = true;
    if (record->event.pressed) {
        switch (keycode) {
            case MSQ_RST:
                quadrant_cursor_init();
                break;
            case MSQ_LOCAL:
                quadrant_cursor.scale_x = QUADRANT_SCALE_LOCAL;
                quadrant_cursor.scale_y = QUADRANT_SCALE_LOCAL;
                break;
            case MSQ_DNC:
                quadrant_animation_start = timer_read();
                defer_exec(1, &quadrant_animation, NULL);
                return true;

            case MSQ_U:
                quadrant_cursor = quadrant_cursor_direction(quadrant_cursor, -1, y);
                break;
            case MSQ_D:
                quadrant_cursor = quadrant_cursor_direction(quadrant_cursor, 1, y);
                break;
            case MSQ_L:
                quadrant_cursor = quadrant_cursor_direction(quadrant_cursor, -1, x);
                break;
            case MSQ_R:
                quadrant_cursor = quadrant_cursor_direction(quadrant_cursor, 1, x);
                break;
            case MSQ_C:
                quadrant_cursor = quadrant_cursor_direction(quadrant_cursor, 0, centre);
                break;
            default:
                msq = false;
                break;
        }
    } else {
        msq = false;
    }

    if (msq) {
        quadrant_animation_start = 0;
        digitizer_in_range_on();
        digitizer_set_position(quadrant_cursor.x, quadrant_cursor.y);
        return false;
    }
    return true;
}