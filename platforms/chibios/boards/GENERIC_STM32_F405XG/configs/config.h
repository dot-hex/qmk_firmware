<<<<<<< HEAD
/* Copyright 2021 Andrei Purdea
=======
<<<<<<< HEAD:platforms/chibios/boards/GENERIC_STM32_L412XB/configs/config.h
/* Copyright 2018-2021 Harrison Chan (@Xelus)
=======
/* Copyright 2021 Andrei Purdea
>>>>>>> upstream/master:platforms/chibios/boards/GENERIC_STM32_F405XG/configs/config.h
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

/* Address for jumping to bootloader on STM32 chips. */
/* It is chip dependent, the correct number can be looked up by checking against ST's application note AN2606.
 */

<<<<<<< HEAD
#ifndef EARLY_INIT_PERFORM_BOOTLOADER_JUMP
#    define EARLY_INIT_PERFORM_BOOTLOADER_JUMP TRUE
#endif
=======
<<<<<<< HEAD:platforms/chibios/boards/GENERIC_STM32_L412XB/configs/config.h
#define PAL_STM32_OSPEED_HIGHEST PAL_STM32_OSPEED_HIGH

#ifndef EARLY_INIT_PERFORM_BOOTLOADER_JUMP
#    define EARLY_INIT_PERFORM_BOOTLOADER_JUMP TRUE
#endif
=======
#ifndef EARLY_INIT_PERFORM_BOOTLOADER_JUMP
#    define EARLY_INIT_PERFORM_BOOTLOADER_JUMP TRUE
#endif

#ifdef WEAR_LEVELING_EMBEDDED_FLASH
#    ifndef WEAR_LEVELING_EFL_FIRST_SECTOR
#        ifdef BOOTLOADER_TINYUF2
#            define WEAR_LEVELING_EFL_FIRST_SECTOR 3
#        else
#            define WEAR_LEVELING_EFL_FIRST_SECTOR 1
#        endif
#    endif
#endif
>>>>>>> upstream/master:platforms/chibios/boards/GENERIC_STM32_F405XG/configs/config.h
>>>>>>> upstream/master
