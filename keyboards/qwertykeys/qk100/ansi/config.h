/* 
Copyright 2023 Qwertykeys

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

#define RGBLIGHT_LAYERS_RETAIN_VAL      
#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_RAINBOW_SWIRL + 5

<<<<<<< HEAD:keyboards/clawsome/gamebuddy/v1_0/config.h
/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x17B9
#define DEVICE_VER      0x0001
#define MANUFACTURER    AlisGraveNil
#define PRODUCT         GameBuddy1_0
=======
/*== customize breathing effect ==*/
#define RGBLIGHT_BREATHE_TABLE_SIZE 128
#define RGBLIGHT_EFFECT_BREATHE_CENTER 1.0
#define RGBLIGHT_EFFECT_BREATHE_MAX    60
>>>>>>> upstream/master:keyboards/qwertykeys/qk100/ansi/config.h

/* RGB matrix */
#define I2C1_CLOCK_SPEED 400000  
#define I2C1_DUTY_CYCLE FAST_DUTY_CYCLE_2

#define IS31FL3741_I2C_ADDRESS_1 IS31FL3741_I2C_ADDRESS_GND

#define RGB_MATRIX_DISABLE_SHARED_KEYCODES
