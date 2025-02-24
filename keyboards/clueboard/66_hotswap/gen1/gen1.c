/* Copyright 2017 Clueboard <info@clueboard.co>
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
#include "quantum.h"

#ifdef LED_MATRIX_ENABLE
<<<<<<< HEAD
const is31_led PROGMEM g_is31_leds[DRIVER_LED_TOTAL] = {
=======
const is31fl3731_led_t PROGMEM g_is31fl3731_leds[IS31FL3731_LED_COUNT] = {
>>>>>>> upstream/master
/* Refer to IS31 manual for these locations
 *    driver
 *    |  LED address
 *    |  | */
    { 0, C1_1  }, // k00 QK_GESC
    { 0, C1_2  }, // k01 KC_1
    { 0, C1_3  }, // k02 KC_2
    { 0, C1_4  }, // k03 KC_3
    { 0, C1_5  }, // k04 KC_4
    { 0, C1_6  }, // k05 KC_5
    { 0, C1_7  }, // k06 KC_6
    { 0, C1_8  }, // k07 KC_7
    { 0, C1_9  }, // k50 KC_8
    { 0, C1_10 }, // k51 KC_9
    { 0, C1_11 }, // k52 KC_0
    { 0, C1_12 }, // k53 KC_MINS
    { 0, C1_13 }, // k54 KC_EQL
    { 0, C1_14 }, // k55 KC_BSPC
    { 0, C1_15 }, // k57 KC_PGUP
    { 0, C2_1  }, // k10 KC_TAB
    { 0, C2_2  }, // k11 KC_Q
    { 0, C2_3  }, // k12 KC_W
    { 0, C2_4  }, // k13 KC_E
    { 0, C2_5  }, // k14 KC_R
    { 0, C2_6  }, // k15 KC_T
    { 0, C2_7  }, // k16 KC_Y
    { 0, C2_8  }, // k17 KC_U
    { 0, C2_9  }, // k60 KC_I
    { 0, C2_10 }, // k61 KC_O
    { 0, C2_11 }, // k62 KC_P
    { 0, C2_12 }, // k63 KC_LBRC
    { 0, C2_13 }, // k64 KC_RBRC
    { 0, C2_14 }, // k65 KC_BSLS
    { 0, C2_15 }, // k67 KC_PGDN
    { 0, C3_1  }, // k20 KC_CAPS
    { 0, C3_2  }, // k21 KC_A
    { 0, C3_3  }, // k22 KC_S
    { 0, C3_4  }, // k23 KC_D
    { 0, C3_5  }, // k24 KC_F
    { 0, C3_6  }, // k25 KC_G
    { 0, C3_7  }, // k26 KC_H
    { 0, C3_8  }, // k27 KC_J
    { 0, C3_9  }, // k70 KC_K
    { 0, C3_10 }, // k71 KC_L
    { 0, C3_11 }, // k72 KC_SCLN
    { 0, C3_12 }, // k73 KC_QUOT
    { 0, C3_14 }, // k75 KC_ENT
    { 0, C4_1  }, // k30 KC_LSFT
    { 0, C4_3  }, // k32 KC_Z
    { 0, C4_4  }, // k33 KC_X
    { 0, C4_5  }, // k34 KC_C
    { 0, C4_6  }, // k35 KC_V
    { 0, C4_7  }, // k36 KC_B
    { 0, C4_8  }, // k37 KC_N
    { 0, C4_9  }, // k80 KC_M
    { 0, C4_10 }, // k81 KC_COMM
    { 0, C4_11 }, // k82 KC_DOT
    { 0, C4_12 }, // k83 KC_SLSH
    { 0, C4_13 }, // k85 KC_RSFT
    { 0, C4_14 }, // k86 KC_UP
    { 0, C5_1  }, // k40 KC_LCTL
    { 0, C5_2  }, // k41 KC_LGUI
    { 0, C5_3  }, // k42 KC_LALT
    { 0, C5_4  }, // Unassociated between LALT and SPACE_2.75
    { 0, C5_5  }, // k45 KC_SPC SPACE_2.75
    { 0, C5_6  }, // k45 KC_SPC SPACE_6.75
    { 0, C5_7  }, // k46 KC_SPC SPACE_2.25
    { 0, C5_8  }, // Unassociated between SPACE_2.25 and SPACE_1.25
    { 0, C5_9  }, // k90 KC_RGUI
    { 0, C5_10 }, // k92 KC_RALT
    { 0, C5_11 }, // k93 MO(_FL)
    { 0, C5_12 }, // k94 KC_RCTL
    { 0, C5_13 }, // k95 KC_LEFT
    { 0, C5_14 }, // k96 KC_DOWN
    { 0, C5_15 }  // k97 KC_RGHT
};
#endif
