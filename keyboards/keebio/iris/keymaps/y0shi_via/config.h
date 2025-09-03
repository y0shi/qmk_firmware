// Copyright 2023 Danny Nguyen (danny@keeb.io)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// Enable split layer state synchronization for RGB indicators
// #define SPLIT_MODS_ENABLE
// #define RGB_MATRIX_ENABLE
#define EE_HANDS

#define SPLIT_LAYER_STATE_ENABLE

#define RGB_MATRIX_LIMIT_VAL 128
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR

// Disable RGB matrix split synchronization to prevent conflicts
#define RGB_MATRIX_DISABLE_SHARED_KEYCODES