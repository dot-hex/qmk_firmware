<<<<<<< HEAD:keyboards/splitkb/kyria/keymaps/lw/config.h
/* Copyright 2022 Lucas Waelti (@LucasWaelti)
=======
/* Copyright 2021 bdtc123
 * Copyright 2021 sigprof
 * Copyright 2021 peepeetee
>>>>>>> upstream/master:keyboards/kprepublic/bm60hsrgb_iso/rev2/config.h
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

<<<<<<< HEAD:keyboards/splitkb/kyria/keymaps/lw/config.h
// Lets you roll mod-tap keys
#define IGNORE_MOD_TAP_INTERRUPT

// If you are using an Elite C rev3 on the slave side, uncomment the lines below:
// #define SPLIT_USB_DETECT
// #define NO_USB_STARTUP_CHECK

#define UNICODE_SELECTED_MODES UC_LNX, UC_WINC // support for Linux and Windows unicode 
=======
#define IS31FL3733_I2C_ADDRESS_1 IS31FL3733_I2C_ADDRESS_GND_GND
#define IS31FL3733_LED_COUNT 64

// Underglow LEDs are WS2812, but someone might want to use RGBLIGHT for them;
// don't use those LEDs in RGB Matrix in that case.
#ifdef RGBLIGHT_ENABLE
#    define WS2812_LED_COUNT 0
#else
#    define WS2812_LED_COUNT 6
#endif

#define RGB_MATRIX_LED_COUNT (IS31FL3733_LED_COUNT + WS2812_LED_COUNT)
>>>>>>> upstream/master:keyboards/kprepublic/bm60hsrgb_iso/rev2/config.h
