/* Copyright 2021 csandven
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

<<<<<<< HEAD
#include "bison.h"
=======
<<<<<<<< HEAD:keyboards/ungodly/nines/nines.c
bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) return false;
    if (index == 0) { /* Left encoder */
========
#include "quantum.h"
>>>>>>> upstream/master

bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) { return false; }
    if (index == 0) {
<<<<<<< HEAD
=======
>>>>>>>> upstream/master:keyboards/keyprez/bison/bison.c
>>>>>>> upstream/master
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        if (clockwise) {
<<<<<<< HEAD
            tap_code(KC_PGDOWN);
=======
            tap_code(KC_PGDN);
>>>>>>> upstream/master
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}
