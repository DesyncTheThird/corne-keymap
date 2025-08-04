RGB_MATRIX_EFFECT(reactive_smooth)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#    ifdef RGB_MATRIX_KEYREACTIVE_ENABLED

static hsv_t reactive_smooth_math(hsv_t hsv, uint16_t offset) {
    hsv.h = scale16by8(g_rgb_timer, qadd8(rgb_matrix_config.speed, 8) >> 4);
    uint8_t tri = 127 - abs8((int8_t)offset - 128);
    hsv.h += scale8(tri << 1, 64);
    return hsv;
}

bool reactive_smooth(effect_params_t* params) {
    return effect_runner_reactive(params, &reactive_smooth_math);
}

#    endif
#endif
