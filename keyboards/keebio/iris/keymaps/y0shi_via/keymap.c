enum {
    _QWERTY = 0,
    _RAISE,
    _LOWER,
    _MEDIA
};

void set_layer_rgb(uint8_t layer) {
    if (!is_keyboard_master()) {
        return;
    }
    
    switch (layer) {
        case _QWERTY:
            // Base layer: Purple
            rgb_matrix_sethsv_noeeprom(213, 255, 128); // Purple in HSV
            break;
        case _RAISE:
            // Raise layer: Red
            rgb_matrix_sethsv_noeeprom(0, 255, 255); // Red in HSV
            break;
        case _LOWER:
            // Lower layer: Green
            rgb_matrix_sethsv_noeeprom(85, 255, 255); // Green in HSV
            break;
        case _MEDIA:
            // Media layer: Blue
            rgb_matrix_sethsv_noeeprom(170, 255, 255); // Blue in HSV
            break;
        default:
            // Default - turn off
            rgb_matrix_sethsv_noeeprom(0, 0, 0);
            break;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t layer = get_highest_layer(state | default_layer_state);
    set_layer_rgb(layer);
    return state;
}

void keyboard_post_init_user(void) {
    // Initialize RGB matrix to solid color mode and set initial layer color
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    set_layer_rgb(_QWERTY);
}

