/* Copyright 2021 Danny Nguyen <danny@keeb.io>

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

<<<<<<< HEAD
#include "foldkb.h"
=======
#include "quantum.h"
>>>>>>> upstream/master

void eeconfig_init_kb(void) {
#ifdef BACKLIGHT_ENABLE
    backlight_enable();
    backlight_level(3);
#endif
    eeconfig_update_kb(0);
    eeconfig_init_user();
}

bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) { return false; }
    if (index == 0) {
        if (clockwise) {
<<<<<<< HEAD
=======
<<<<<<<< HEAD:keyboards/keebio/foldkb/rev1/rev1.c
>>>>>>> upstream/master
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
<<<<<<< HEAD
=======
========
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
>>>>>>>> upstream/master:keyboards/keebio/sinc/rev2/rev2.c
>>>>>>> upstream/master
        }
    }
    return false;
}
