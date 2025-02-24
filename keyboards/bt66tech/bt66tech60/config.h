/*
Copyright 2020 bt66tech

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

<<<<<<< HEAD
/* USB Device descriptor parameter */
#define VENDOR_ID	0x4254
#define PRODUCT_ID	0x7070
#define DEVICE_VER      0x0001
#define MANUFACTURER bt66tech
#define PRODUCT bt66tech 60%

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 14

#define MATRIX_COL_PINS { B9, B8, B7, B6, B5, B4, B3, B11, A15, A10, A9, B14, B13, B12 }
#define MATRIX_ROW_PINS { B10, B1, B0, A7, A6 }
#define DIODE_DIRECTION COL2ROW

#define BACKLIGHT_PIN A8
=======
>>>>>>> upstream/master
#define BACKLIGHT_PWM_DRIVER PWMD1
#define BACKLIGHT_PWM_CHANNEL 1

#define WS2812_SPI_DRIVER SPID2
#define WS2812_SPI_MOSI_PAL_MODE 5
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
