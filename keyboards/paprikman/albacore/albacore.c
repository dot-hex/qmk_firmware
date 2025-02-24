<<<<<<< HEAD
<<<<<<< HEAD:keyboards/paprikman/albacore/albacore.c
/* Copyright 2021 paprikman
=======
/* Copyright 2021 Andrew Fahmy
>>>>>>> upstream/master:keyboards/input_club/k_type/k_type-rgbdriver.c
=======
/* Copyright 2021 paprikman
>>>>>>> upstream/master
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
<<<<<<< HEAD:keyboards/paprikman/albacore/albacore.c
#include "albacore.h"
=======
#include "quantum.h"
>>>>>>> upstream/master

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = { {
  { 0, 1, 2, 3 },
  { 7, 6, 5, 4 }
}, {
  { 56, 16 }, { 112, 16 }, { 168, 16 }, { 224, 16 },
  { 56, 24 }, { 112, 24 }, { 168, 24 }, { 224, 24 }
}, {
    1, 1, 1, 1,
    1, 1, 1, 1
} };
<<<<<<< HEAD
=======
#ifdef RGB_MATRIX_ENABLE
#    include "rgb_matrix.h"
#    include "is31fl3733-dual.h"

const rgb_matrix_driver_t rgb_matrix_driver = {
    .init = is31fl3733_init_drivers,
    .flush = is31fl3733_flush,
    .set_color = is31fl3733_set_color,
    .set_color_all = is31fl3733_set_color_all,
};
>>>>>>> upstream/master:keyboards/input_club/k_type/k_type-rgbdriver.c
=======
>>>>>>> upstream/master
#endif
