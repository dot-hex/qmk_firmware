<<<<<<< HEAD:keyboards/3keyecosystem/2key2/2key2.h
/*
Copyright 2021 John Mueller
=======
/* Copyright 2022 ItsFiremanSam
>>>>>>> upstream/master:keyboards/0xcb/tutelpad/config.h

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

#define OLED_TIMEOUT 20000              // Turns off OLED after said amount of milliseconds
#define OLED_BRIGHTNESS 128
#define OLED_DISPLAY_128X64

<<<<<<< HEAD:keyboards/3keyecosystem/2key2/2key2.h
/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT( \
    k00, k01 \
) { \
    { k00, k01 }  \
}
=======
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
>>>>>>> upstream/master:keyboards/0xcb/tutelpad/config.h
