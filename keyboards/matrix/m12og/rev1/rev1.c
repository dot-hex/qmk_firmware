/* Copyright 2021 kb-elmo<mail@elmo.space>
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
#include "rev1.h"

void board_init(void) {
    writePinLow(A8);
=======
#include "quantum.h"

void board_init(void) {
<<<<<<<< HEAD:keyboards/matrix/m12og/rev1/rev1.c
    gpio_write_pin_low(A8);
>>>>>>> upstream/master
}

void bootloader_jump(void) {
    // This board doesn't use the standard DFU bootloader, and no information is available regarding how to enter bootloader mode. All we can do here is reset.
    NVIC_SystemReset();
}

void keyboard_post_init_kb(void) {
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(5, 255, 255);
    rgblight_mode_noeeprom(37);
<<<<<<< HEAD
=======

    keyboard_post_init_user();
========
    // B9 is configured as I2C1_SDA_PIN in the board file; that function must be
    // disabled before using B7 as I2C1_SDA.
    setPinInputHigh(B9);
>>>>>>>> upstream/master:keyboards/handwired/onekey/blackpill_f401/blackpill_f401.c
>>>>>>> upstream/master
}
