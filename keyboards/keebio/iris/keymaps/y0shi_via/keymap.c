enum {
    _QWERTY = 0,
    _RAISE,
    _LOWER,
    _MEDIA
};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // Determine the current layer
    uint8_t layer = get_highest_layer(layer_state | default_layer_state);

    // Apply color based on the layer
    for (uint8_t i = led_min; i < led_max; i++) {
        switch (layer) {
            case _QWERTY:
                // Base layer: Purple underglow
                RGB_MATRIX_INDICATOR_SET_COLOR(i, 128, 0, 128); // RGB values for purple
                break;
            case _RAISE:
                // Raise layer: Red underglow
                RGB_MATRIX_INDICATOR_SET_COLOR(i, 255, 0, 0); // RGB values for red
                break;
            case _LOWER:
                // Lower layer: Green underglow
                RGB_MATRIX_INDICATOR_SET_COLOR(i, 0, 255, 0); // RGB values for green
                break;
            case _MEDIA:
                // media layer: Blue underglow
                RGB_MATRIX_INDICATOR_SET_COLOR(i, 0, 0, 255); // RGB values for blue
                break;
            default:
                // Default color for any other layers (or no specific layer active)
                RGB_MATRIX_INDICATOR_SET_COLOR(i, 0, 0, 0); // RGB values for off (or another default)
                break;
        }
    }

    return true;
}

