RGB_MATRIX_EFFECT(plasma_flow)
RGB_MATRIX_EFFECT(boot_animation_effect)
RGB_MATRIX_EFFECT(fade_out_effect)
RGB_MATRIX_EFFECT(fade_in_effect)
RGB_MATRIX_EFFECT(reactive_smooth)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static bool plasma_flow(effect_params_t *params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    const int16_t center_x = 112;

    const uint16_t period = 200;
    const uint16_t pause  = 200;
    const uint16_t total_cycle = period + pause;

    uint16_t step = scale16by8(g_rgb_timer, rgb_matrix_config.speed);
    uint16_t cycle_pos = step % total_cycle;
    uint16_t radius = cycle_pos * (center_x + 80) / period;

    for (uint8_t i = led_min; i < led_max; ++i) {
        RGB_MATRIX_TEST_LED_FLAGS();

        int16_t lx   = g_led_config.point[i].x;
        int16_t dist = abs(lx - center_x);
        int16_t delta = radius - dist;

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

    const uint16_t delay  = 250;
    const uint16_t period = 200;
    const uint16_t pause  = 200;
    const uint16_t hold   = 1000;
    const uint16_t total_cycle = delay + period + pause + period + hold;

    uint16_t step = scale16by8(g_rgb_timer, rgb_matrix_config.speed);
    uint16_t cycle_pos = step % total_cycle;

    bool first_wave  = cycle_pos >= delay
                    && cycle_pos <  delay + period;
    bool second_wave = cycle_pos >= delay + period + pause
                    && cycle_pos <  delay + period + pause + period + hold;

    uint16_t radius = 0;
    if (first_wave) {
        radius = (cycle_pos - delay) * (center_x + 80) / period;
    } else if (second_wave) {
        radius = (cycle_pos - delay - period - pause) * (center_x + 80) / period;
    }

    for (uint8_t i = led_min; i < led_max; ++i) {
        RGB_MATRIX_TEST_LED_FLAGS();

        int16_t lx   = g_led_config.point[i].x;
        int16_t dist = abs(lx - center_x);
        int16_t delta = radius - dist;

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
                    hsv.v = RGB_MATRIX_MAXIMUM_BRIGHTNESS - (trail_delta * RGB_MATRIX_MAXIMUM_BRIGHTNESS / 30);
                } else {
                    hsv.v = (RGB_MATRIX_MAXIMUM_BRIGHTNESS / 2) - ((trail_delta - 15) * RGB_MATRIX_MAXIMUM_BRIGHTNESS / 80);
                }
            }
        } else if (delta >= 65 && second_wave) {
            hsv.h = 200;
            hsv.s = 255;
            hsv.v = delta < 185 ? delta - 65 : 120;
        } else {
            hsv.v = 0;
        }

        rgb_t rgb = rgb_matrix_hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return rgb_matrix_check_finished_leds(led_max);
}

bool fade_out_active = false;
bool fade_in_active = false;
static uint16_t fade_start = 0;
static const int16_t duration = 5000;

static bool fade_out_effect(effect_params_t *params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    if (timer_elapsed(fade_start) > duration && !fade_out_active) {
        fade_start = timer_read();
        fade_out_active = true;
        fade_in_active = false;
    }

    int32_t elapsed = timer_elapsed(fade_start);

    if (elapsed > duration) {
        fade_out_active = false;
        rgb_matrix_disable_noeeprom();
        return rgb_matrix_check_finished_leds(led_max);
    }

    hsv_t hsv = rgb_matrix_config.hsv;
    hsv.v = RGB_MATRIX_MAXIMUM_BRIGHTNESS - elapsed * RGB_MATRIX_MAXIMUM_BRIGHTNESS / duration;
    hsv.h += scale16by8(g_rgb_timer, qadd8(rgb_matrix_config.speed, 8) >> 4);

    for (uint8_t i = led_min; i < led_max; ++i) {
        RGB_MATRIX_TEST_LED_FLAGS();

        rgb_t rgb = rgb_matrix_hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return rgb_matrix_check_finished_leds(led_max);
}

static bool fade_in_effect(effect_params_t *params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    if (timer_elapsed(fade_start) > duration && !fade_in_active) {
        fade_start = timer_read();
        fade_in_active = true;
        fade_out_active = false;
    }

    if (fade_out_active) {
        fade_start = timer_read() - (duration - timer_elapsed(fade_start)) / 2;
        fade_out_active = false;
    }

    int32_t elapsed = timer_elapsed(fade_start);

    if (elapsed > duration / 2) {
        fade_in_active = false;
        rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_reactive_smooth); 
        return rgb_matrix_check_finished_leds(led_max);
    }

    hsv_t hsv = rgb_matrix_config.hsv;
    hsv.v = 2 * elapsed * RGB_MATRIX_MAXIMUM_BRIGHTNESS / duration;
    hsv.h += scale16by8(g_rgb_timer, qadd8(rgb_matrix_config.speed, 8) >> 4);

    for (uint8_t i = led_min; i < led_max; ++i) {
        RGB_MATRIX_TEST_LED_FLAGS();
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