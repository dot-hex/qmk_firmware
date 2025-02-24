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

#define CAPS_LOCK_LED_PIN B6
<<<<<<< HEAD

/* serial.c configuration for split keyboard */
#define SOFT_SERIAL_PIN D0

/* ws2812 RGB LED */
#define RGB_DI_PIN E6
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 16    // Number of LEDs
#define RGBLED_SPLIT { 8, 8 }
#define RGBLIGHT_LED_MAP { 1, 2, 3, 12, 13, 14, 15, 0, 7, 6, 5, 4, 11, 10, 9, 8 }

// Set 65% column (option 3) and Macro (option 4) on by default
#define VIA_EEPROM_LAYOUT_OPTIONS_DEFAULT 0x00DE
#define VIA_EEPROM_LAYOUT_OPTIONS_SIZE 2
=======
>>>>>>> upstream/master
