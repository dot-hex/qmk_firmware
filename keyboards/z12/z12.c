<<<<<<< HEAD:keyboards/z12/z12.c
/* Copyright 2020 Sergi Meseguer <zigotica@gmail.com>
=======
/* Copyright 2018-2021 Harrison Chan (@Xelus)
>>>>>>> upstream/master:platforms/chibios/boards/GENERIC_STM32_L433XC/configs/config.h
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

<<<<<<< HEAD:keyboards/z12/z12.c
#include "z12.h"

#ifdef ENCODER_ENABLE
bool encoder_update_kb(uint8_t index, bool clockwise) {
    return encoder_update_user(index, clockwise);
}
=======
/* Address for jumping to bootloader on STM32 chips. */
/* It is chip dependent, the correct number can be looked up by checking against ST's application note AN2606.
 */

#ifndef EARLY_INIT_PERFORM_BOOTLOADER_JUMP
#    define EARLY_INIT_PERFORM_BOOTLOADER_JUMP TRUE
>>>>>>> upstream/master:platforms/chibios/boards/GENERIC_STM32_L433XC/configs/config.h
#endif
