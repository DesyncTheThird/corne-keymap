RGB_MATRIX_EFFECT(reactive_smooth)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#    ifdef RGB_MATRIX_KEYREACTIVE_ENABLED

static hsv_t reactive_smooth_math(hsv_t hsv, uint16_t offset) {
    hsv.h = scale16by8(g_rgb_timer, qadd8(rgb_matrix_config.speed, 8) >> 4);
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
