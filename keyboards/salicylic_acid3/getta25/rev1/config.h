/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x3060
#define DEVICE_VER      0x0013
#define MANUFACTURER    Salicylic_Acid
#define PRODUCT         getta25

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 6

// wiring of each half
#define MATRIX_ROW_PINS { D4, C6, D7, E6, B2 }
#define MATRIX_COL_PINS { F4, F5, F6, F7, B1, B3 }

/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* ws2812 RGB LED */
#define RGB_DI_PIN D3

#define RGBLED_NUM 9    // Number of LEDs
#define RGBLIGHT_ANIMATIONS

=======
<<<<<<<< HEAD:keyboards/vitamins_included/config.h
/* Common USB Device descriptor parameters */
#define VENDOR_ID       0x1209
#define PRODUCT_ID      0xBEE5
#define MANUFACTURER    Duckle29
#define PRODUCT         Vitamins included

#include "config_common.h"
========
>>>>>>> upstream/master
#ifndef IOS_DEVICE_ENABLE
  #define RGBLIGHT_LIMIT_VAL 180
  #define RGBLIGHT_VAL_STEP 17
#else
  #define RGBLIGHT_LIMIT_VAL 50
  #define RGBLIGHT_VAL_STEP 4
#endif
<<<<<<< HEAD
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 17
=======
>>>>>>> upstream/master

#if defined(RGBLIGHT_ENABLE) && !defined(IOS_DEVICE_ENABLE)
// USB_MAX_POWER_CONSUMPTION value for naked48 keyboard
//  120  RGBoff, OLEDoff
//  120  OLED
//  330  RGB 6
//  300  RGB 32
//  310  OLED & RGB 32
  #define USB_MAX_POWER_CONSUMPTION 400
#else
  // fix iPhone and iPad power adapter issue
  // iOS device need lessthan 100
  #define USB_MAX_POWER_CONSUMPTION 100
#endif
<<<<<<< HEAD
=======
>>>>>>>> upstream/master:keyboards/salicylic_acid3/getta25/rev1/config.h
>>>>>>> upstream/master
