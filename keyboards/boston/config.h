/* Copyright 2020 Pylon
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
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

<<<<<<< HEAD
/* USB Device descriptor parameter */
#define VENDOR_ID 0xAC12
#define PRODUCT_ID 0x4176
#define DEVICE_VER 0x0001
#define MANUFACTURER Pylon
#define PRODUCT Boston
/* key matrix size */
#define MATRIX_ROWS 7
#define MATRIX_COLS 19

#define MATRIX_COL_PINS \
    { B10, B11, B12, B13, B14, B15, A8, A9, A10, A15, B3, B4, B7, B8, B9, C14, C15, F0, A3 }
#define MATRIX_ROW_PINS \
    { B5, B6, A7, B0, B1, B2, A4 }
#define DIODE_DIRECTION COL2ROW

#define BACKLIGHT_PIN A6
=======
>>>>>>> upstream/master
#define BACKLIGHT_PWM_DRIVER PWMD3
#define BACKLIGHT_PWM_CHANNEL 1
#define BACKLIGHT_PAL_MODE 1

#define RGBLIGHT_LAYERS

//The 3D-printed version of Boston uses APA106 LEDs, which are reversed
#define WS2812_BYTE_ORDER WS2812_BYTE_ORDER_RGB

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
