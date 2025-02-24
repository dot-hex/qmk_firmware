/*
Copyright 2021 Danny Nguyen <danny@keeb.io>
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
#include "rev5.h"

=======
#include "quantum.h"

<<<<<<<< HEAD:keyboards/keebio/iris/rev5/rev5.c
#ifdef ENCODER_ENABLE
>>>>>>> upstream/master
bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) { return false; }
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return false;
<<<<<<< HEAD
}
=======
========
#include "evolv.h"

#ifndef MEDIA_KEY_DELAY
#     define MEDIA_KEY_DELAY 100
#endif

bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) return false;
    tap_code_delay(clockwise ? KC_VOLU : KC_VOLD, MEDIA_KEY_DELAY);
    return true;
>>>>>>>> upstream/master:keyboards/evolv/evolv.c
}
#endif
>>>>>>> upstream/master
