RGB_MATRIX_EFFECT(plasma_flow)
RGB_MATRIX_EFFECT(boot_animation_effect)
RGB_MATRIX_EFFECT(reactive_smooth)


#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static bool plasma_flow(effect_params_t *params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    const int16_t center_x = 112;

    uint16_t step = scale16by8(g_rgb_timer, rgb_matrix_config.speed); 

    uint16_t cycle = (center_x + 80) * 2 + 100;
    uint16_t radius = step % cycle;

    for (uint8_t i = led_min; i < led_max; ++i) {
        RGB_MATRIX_TEST_LED_FLAGS();

        int16_t lx   = g_led_config.point[i].x;
        uint16_t dist = (uint16_t)abs((int16_t)lx - center_x);
        int16_t delta = (int16_t)radius - (int16_t)dist;

        hsv_t hsv = rgb_matrix_config.hsv;

        if (delta >= 0 && delta < 65) {
            if (delta < 10) {
                hsv.h = 120 + (30 * delta) / 10;
                hsv.s = 255;
                hsv.v = RGB_MATRIX_MAXIMUM_BRIGHTNESS;
            } else {
                hsv.h = 200 + (30 * (delta - 10)) / 30;
                hsv.s = 255;
                uint8_t trail_delta = delta - 10;
                if (trail_delta < 15) {
                    hsv.v = RGB_MATRIX_MAXIMUM_BRIGHTNESS - (trail_delta * (RGB_MATRIX_MAXIMUM_BRIGHTNESS / 2) / 15);
                } else {
                    hsv.v = (RGB_MATRIX_MAXIMUM_BRIGHTNESS / 2) - ((trail_delta - 15) * (RGB_MATRIX_MAXIMUM_BRIGHTNESS / 2) / 40);
                }
            }
        } else {
            hsv.v = 0;
        }

        rgb_t rgb = rgb_matrix_hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return rgb_matrix_check_finished_leds(led_max);
}



static bool boot_animation_effect(effect_params_t *params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    const int16_t center_x = 112;

    uint16_t step = scale16by8(g_rgb_timer, rgb_matrix_config.speed); 

    uint16_t cycle = (center_x + 80) * 2 + 500;
    uint16_t radius = step % cycle;
    
    bool second_sweep = radius >= (center_x + 80);
    if (second_sweep) {
        radius -= (center_x + 80);
    }

    for (uint8_t i = led_min; i < led_max; ++i) {
        RGB_MATRIX_TEST_LED_FLAGS();

        int16_t lx   = g_led_config.point[i].x;
        uint16_t dist = (uint16_t)abs((int16_t)lx - center_x);
        int16_t delta = (int16_t)radius - (int16_t)dist;

        hsv_t hsv = rgb_matrix_config.hsv;

        if (delta >= 0 && delta < 65) {
            if (delta < 10) {
                hsv.h = 120 + (30 * delta) / 10;
                hsv.s = 255;
                hsv.v = RGB_MATRIX_MAXIMUM_BRIGHTNESS;
            } else {
                hsv.h = 200 + (30 * (delta - 10)) / 30;
                hsv.s = 255;
                uint8_t trail_delta = delta - 10;
                if (trail_delta < 15) {
                    hsv.v = RGB_MATRIX_MAXIMUM_BRIGHTNESS - (trail_delta * (RGB_MATRIX_MAXIMUM_BRIGHTNESS / 2) / 15);
                } else {
                    hsv.v = (RGB_MATRIX_MAXIMUM_BRIGHTNESS / 2) - ((trail_delta - 15) * (RGB_MATRIX_MAXIMUM_BRIGHTNESS / 2) / 40);
                }
            }
        } else if (delta >= 65) {
            if (!second_sweep) {
                hsv.v = 0;
            } else {
                hsv.h = 200;
                hsv.s = 255;
                hsv.v = delta < 185 ? delta - 65 : 120;
            }
        } else {
            hsv.v = 0;
        }

        rgb_t rgb = rgb_matrix_hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return rgb_matrix_check_finished_leds(led_max);
}



#    ifdef RGB_MATRIX_KEYREACTIVE_ENABLED

static hsv_t reactive_smooth_math(hsv_t hsv, uint16_t offset) {
    hsv.h += scale16by8(g_rgb_timer, qadd8(rgb_matrix_config.speed, 8) >> 4);
    uint8_t shift = (uint8_t)offset;
    uint8_t tri = shift < 128 ? shift * 2 : (255 - shift) * 2;
    hsv.h += scale8(tri, 64);
    return hsv;
}

bool reactive_smooth(effect_params_t* params) {
    return effect_runner_reactive(params, &reactive_smooth_math);
}

#    endif

#endif