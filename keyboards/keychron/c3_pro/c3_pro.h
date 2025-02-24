/* Copyright 2024 @ Keychron (https://www.keychron.com)
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

#include "quantum.h"

<<<<<<< HEAD:quantum/process_keycode/process_printer.h
bool process_printer(uint16_t keycode, keyrecord_t *record);
=======
enum my_keycodes {
    KC_OS_SWITCH = QK_KB_11,
};

#define KC_OSSW KC_OS_SWITCH
>>>>>>> upstream/master:keyboards/keychron/c3_pro/c3_pro.h
