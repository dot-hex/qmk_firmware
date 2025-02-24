/* Copyright 2021 Colin Lam (Ploopy Corporation)
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2019 Sunjun Kim
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

<<<<<<< HEAD:keyboards/ploopyco/trackball_mini/trackball_mini.h
#include "quantum.h"
#include "analog.h"
#include "opt_encoder.h"

// Sensor defs
#define OPT_ENC1 F0
#define OPT_ENC2 F4
#define OPT_ENC1_MUX 0
#define OPT_ENC2_MUX 4

void process_wheel(void);

#define LAYOUT(BL, BM, BR, BF, BB) \
    { {BL, BM, BR, BF, BB}, }

typedef union {
    uint32_t raw;
    struct {
        uint8_t dpi_config;
    };
} keyboard_config_t;

extern keyboard_config_t keyboard_config;

enum ploopy_keycodes {
#ifdef VIA_ENABLE
    DPI_CONFIG = USER00,
#else
    DPI_CONFIG = SAFE_RANGE,
#endif
    DRAG_SCROLL,
#ifdef VIA_ENABLE
    PLOOPY_SAFE_RANGE = SAFE_RANGE,
#else
    PLOOPY_SAFE_RANGE,
#endif
};

bool encoder_update_user(uint8_t index, bool clockwise);
bool encoder_update_kb(uint8_t index, bool clockwise);
=======
/* disable action features */
// #define NO_ACTION_LAYER
// #define NO_ACTION_TAPPING
// #define NO_ACTION_ONESHOT

// #define ROTATIONAL_TRANSFORM_ANGLE 0
#define POINTING_DEVICE_INVERT_Y

// If board has a debug LED, you can enable it by defining this
// #define DEBUG_LED_PIN F7

/* PMW3360 Settings */
#define POINTING_DEVICE_CS_PIN B0

#define ENCODER_BUTTON_COL 1
#define ENCODER_BUTTON_ROW 0

#define ENCODER_LOW_THRES_A 20
#define ENCODER_HIGH_THRES_A 75
#define ENCODER_LOW_THRES_B 20
#define ENCODER_HIGH_THRES_B 90
/* Custom encoder needs to specify just how many encoders we have */
#define NUM_ENCODERS 1

#define ENCODER_A_PINS { F4 }
#define ENCODER_B_PINS { F0 }
>>>>>>> upstream/master:keyboards/ploopyco/trackball_thumb/config.h
