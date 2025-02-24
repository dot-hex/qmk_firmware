/*
Copyright 2021 Shiftux <shiftux@gmail.com>

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
#include "redox_media.h"

bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) {
        return false;
    }
=======
#include "quantum.h"

bool encoder_update_kb(uint8_t index, bool clockwise) {
<<<<<<<< HEAD:keyboards/redox_media/redox_media.c
    if (!encoder_update_user(index, clockwise)) {
        return false;
    }
========
    if (!encoder_update_user(index, clockwise)) return false;
>>>>>>>> upstream/master:keyboards/ck60i/ck60i.c
>>>>>>> upstream/master
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code(KC_WH_D);
        } else {
            tap_code(KC_WH_U);
        }
    }
    return true;
}
