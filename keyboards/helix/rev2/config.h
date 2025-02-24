/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
Copyright 2018 MakotoKurauchi

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
#define VENDOR_ID       0x3265
#define PRODUCT_ID      0x0000
#define DEVICE_VER      0x0001
#define MANUFACTURER    Yushakobo
#define PRODUCT         Helix Beta

#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 100

#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE

/* Use I2C or Serial */
#define USE_SERIAL
//#define USE_MATRIX_I2C

/* Soft Serial defines */
#define SOFT_SERIAL_PIN D2
#define SERIAL_USE_MULTI_TRANSACTION

/* Select hand configuration */
#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

// Helix keyboard OLED support
//      see ./local_features.mk: OLED_SELECT=local
#ifdef OLED_LOCAL_ENABLE
  #define SSD1306OLED
#endif
=======
#define QUICK_TAP_TERM 0
>>>>>>> upstream/master

#define OLED_UPDATE_INTERVAL 50

// Helix keyboard RGB LED support
//    see ./rules.mk: LED_BACK_ENABLE or LED_UNDERGLOW_ENABLE set yes
#ifdef RGBLED_BACK
  #define RGBLIGHT_LED_COUNT 32
#else
  #define RGBLIGHT_LED_COUNT 6
#endif

#ifndef IOS_DEVICE_ENABLE
  #if RGBLIGHT_LED_COUNT <= 6
    #define RGBLIGHT_LIMIT_VAL 255
  #else
    #define RGBLIGHT_LIMIT_VAL 120
  #endif
  #define RGBLIGHT_VAL_STEP 17
#else
  #if RGBLIGHT_LED_COUNT <= 6
    #define RGBLIGHT_LIMIT_VAL 90
  #else
    #define RGBLIGHT_LIMIT_VAL 35
  #endif
  #define RGBLIGHT_VAL_STEP 4
#endif

#if defined(RGBLIGHT_ENABLE) && !defined(IOS_DEVICE_ENABLE)
// USB_MAX_POWER_CONSUMPTION value for Helix keyboard
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

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
// #define NO_DEBUG

/* disable print */
// #define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
