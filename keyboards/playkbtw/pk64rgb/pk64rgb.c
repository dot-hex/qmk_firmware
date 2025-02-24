/* Copyright 2021 Play Keyboard
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
#include "pk64rgb.h"

#ifdef RGB_MATRIX_ENABLE
const is31_led PROGMEM g_is31_leds[DRIVER_LED_TOTAL] = {
=======
#include "quantum.h"

#ifdef RGB_MATRIX_ENABLE
const is31fl3733_led_t PROGMEM g_is31fl3733_leds[IS31FL3733_LED_COUNT] = {
>>>>>>> upstream/master
 /* Refer to IS31 manual for these locations
 *   driver
 *   |  R location
 *   |  |      G location
 *   |  |      |      B location
 *   |  |      |      | */

<<<<<<< HEAD
   {0, A_1,   B_1,   C_1},
   {0, D_1,   E_1,   F_1},
   {0, G_1,   H_1,   I_1},
   {0, J_1,   K_1,   L_1},
   {0, A_6,   B_6,   C_6},
   {0, D_6,   E_6,   F_6},
   {0, G_6,   H_6,   I_6},
   {0, J_6,   K_6,   L_6},
   {0, A_11,  B_11,  C_11},
   {0, D_11,  E_11,  F_11},
   {0, G_11,  H_11,  I_11},
   {0, J_11,  K_11,  L_11},
   {0, A_16,  B_16,  C_16},
   {0, D_16,  E_16,  F_16},
      
   {0, A_2,   B_2,   C_2},
   {0, D_2,   E_2,   F_2},
   {0, G_2,   H_2,   I_2},
   {0, J_2,   K_2,   L_2},
   {0, A_7,   B_7,   C_7},
   {0, D_7,   E_7,   F_7},
   {0, G_7,   H_7,   I_7},
   {0, J_7,   K_7,   L_7},
   {0, A_12,  B_12,  C_12},
   {0, D_12,  E_12,  F_12},
   {0, G_12,  H_12,  I_12},
   {0, J_12,  K_12,  L_12},
   {0, G_16,  H_16,  I_16},
   {0, J_16,  K_16,  L_16},

   {0, A_3,   B_3,   C_3},
   {0, D_3,   E_3,   F_3},
   {0, G_3,   H_3,   I_3},
   {0, J_3,   K_3,   L_3},
   {0, A_8,   B_8,   C_8},
   {0, D_8,   E_8,   F_8},
   {0, G_8,   H_8,   I_8},
   {0, J_8,   K_8,   L_8},
   {0, A_13,  B_13,  C_13},
   {0, D_13,  E_13,  F_13},
   {0, G_13,  H_13,  I_13},
   {0, J_13,  K_13,  L_13},
   {0, A_15,  B_15,  C_15},

   {0, A_4,   B_4,   C_4},
   {0, D_4,   E_4,   F_4},
   {0, G_4,   H_4,   I_4},
   {0, J_4,   K_4,   L_4},
   {0, A_9,   B_9,   C_9},
   {0, D_9,   E_9,   F_9},
   {0, G_9,   H_9,   I_9},
   {0, J_9,   K_9,   L_9},
   {0, A_14,  B_14,  C_14},
   {0, D_14,  E_14,  F_14},
   {0, G_14,  H_14,  I_14},
   {0, J_14,  K_14,  L_14},
   {0, D_15,  E_15,  F_15},
   {0, G_15,  H_15,  I_15},

   {0, A_5,   B_5,   C_5},
   {0, D_5,   E_5,   F_5},
   {0, G_5,   H_5,   I_5},
   {0, J_5,   K_5,   L_5},
   {0, A_10,  B_10,  C_10},
   {0, D_10,  E_10,  F_10},
   {0, G_10,  H_10,  I_10},
   {0, J_10,  K_10,  L_10},
   {0, J_15,  K_15,  L_15}
};

led_config_t g_led_config = {{
    {  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13 },
    { 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27 },
    { 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40},
    { 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54 },
    { 55, 56, 57, 58, 59, 60, 61, 62, 63}
}, {
    {   0,  0 }, {  16,  0 }, {  32,  0 }, {  48,  0 }, {  64,  0 }, { 80,  0 }, { 96,  0 }, { 112,  0 }, { 128,  0 }, { 144,  0 }, { 160,  0 }, { 176,  0 }, { 192,  0 }, { 216,  0 },
    {   4, 16 }, {  18, 16 }, {  34, 16 }, {  50, 16 }, {  66, 16 }, { 82, 16 }, { 98, 16 }, { 114, 16 }, { 130, 16 }, { 146, 16 }, { 162, 16 }, { 178, 16 }, { 194,  16 }, { 220,  16 },
    {   6, 32 }, {  20, 32 }, {  36, 32 }, {  52, 32 }, {  68, 32 }, { 84, 32 }, { 100, 32 }, { 116, 32 }, { 132, 32 }, { 148, 32 }, { 164, 32 }, { 180, 32 }, { 212,  32 },
    {   9, 48 }, {  27, 48 }, {  43, 48 }, {  59, 48 }, {  75, 48 }, { 91, 48 }, { 107, 48 }, { 123, 48 }, { 139, 48 }, { 155, 48 }, { 171, 48 }, { 187, 48 }, { 203,  48 }, { 219,  48 },
    {   2, 64 }, {  16, 64 }, {  32, 64 }, {  64, 64 },  { 114, 64 }, { 130, 64 }, { 146, 64 }, { 204, 64 }, { 224, 64 }
}, {
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
    1, 1, 1,         4,              1, 1, 4, 4, 4,
}};
=======
   {0, SW1_CS1,   SW2_CS1,   SW3_CS1},
   {0, SW4_CS1,   SW5_CS1,   SW6_CS1},
   {0, SW7_CS1,   SW8_CS1,   SW9_CS1},
   {0, SW10_CS1,   SW11_CS1,   SW12_CS1},
   {0, SW1_CS6,   SW2_CS6,   SW3_CS6},
   {0, SW4_CS6,   SW5_CS6,   SW6_CS6},
   {0, SW7_CS6,   SW8_CS6,   SW9_CS6},
   {0, SW10_CS6,   SW11_CS6,   SW12_CS6},
   {0, SW1_CS11,  SW2_CS11,  SW3_CS11},
   {0, SW4_CS11,  SW5_CS11,  SW6_CS11},
   {0, SW7_CS11,  SW8_CS11,  SW9_CS11},
   {0, SW10_CS11,  SW11_CS11,  SW12_CS11},
   {0, SW1_CS16,  SW2_CS16,  SW3_CS16},
   {0, SW4_CS16,  SW5_CS16,  SW6_CS16},
      
   {0, SW1_CS2,   SW2_CS2,   SW3_CS2},
   {0, SW4_CS2,   SW5_CS2,   SW6_CS2},
   {0, SW7_CS2,   SW8_CS2,   SW9_CS2},
   {0, SW10_CS2,   SW11_CS2,   SW12_CS2},
   {0, SW1_CS7,   SW2_CS7,   SW3_CS7},
   {0, SW4_CS7,   SW5_CS7,   SW6_CS7},
   {0, SW7_CS7,   SW8_CS7,   SW9_CS7},
   {0, SW10_CS7,   SW11_CS7,   SW12_CS7},
   {0, SW1_CS12,  SW2_CS12,  SW3_CS12},
   {0, SW4_CS12,  SW5_CS12,  SW6_CS12},
   {0, SW7_CS12,  SW8_CS12,  SW9_CS12},
   {0, SW10_CS12,  SW11_CS12,  SW12_CS12},
   {0, SW7_CS16,  SW8_CS16,  SW9_CS16},
   {0, SW10_CS16,  SW11_CS16,  SW12_CS16},

   {0, SW1_CS3,   SW2_CS3,   SW3_CS3},
   {0, SW4_CS3,   SW5_CS3,   SW6_CS3},
   {0, SW7_CS3,   SW8_CS3,   SW9_CS3},
   {0, SW10_CS3,   SW11_CS3,   SW12_CS3},
   {0, SW1_CS8,   SW2_CS8,   SW3_CS8},
   {0, SW4_CS8,   SW5_CS8,   SW6_CS8},
   {0, SW7_CS8,   SW8_CS8,   SW9_CS8},
   {0, SW10_CS8,   SW11_CS8,   SW12_CS8},
   {0, SW1_CS13,  SW2_CS13,  SW3_CS13},
   {0, SW4_CS13,  SW5_CS13,  SW6_CS13},
   {0, SW7_CS13,  SW8_CS13,  SW9_CS13},
   {0, SW10_CS13,  SW11_CS13,  SW12_CS13},
   {0, SW1_CS15,  SW2_CS15,  SW3_CS15},

   {0, SW1_CS4,   SW2_CS4,   SW3_CS4},
   {0, SW4_CS4,   SW5_CS4,   SW6_CS4},
   {0, SW7_CS4,   SW8_CS4,   SW9_CS4},
   {0, SW10_CS4,   SW11_CS4,   SW12_CS4},
   {0, SW1_CS9,   SW2_CS9,   SW3_CS9},
   {0, SW4_CS9,   SW5_CS9,   SW6_CS9},
   {0, SW7_CS9,   SW8_CS9,   SW9_CS9},
   {0, SW10_CS9,   SW11_CS9,   SW12_CS9},
   {0, SW1_CS14,  SW2_CS14,  SW3_CS14},
   {0, SW4_CS14,  SW5_CS14,  SW6_CS14},
   {0, SW7_CS14,  SW8_CS14,  SW9_CS14},
   {0, SW10_CS14,  SW11_CS14,  SW12_CS14},
   {0, SW4_CS15,  SW5_CS15,  SW6_CS15},
   {0, SW7_CS15,  SW8_CS15,  SW9_CS15},

   {0, SW1_CS5,   SW2_CS5,   SW3_CS5},
   {0, SW4_CS5,   SW5_CS5,   SW6_CS5},
   {0, SW7_CS5,   SW8_CS5,   SW9_CS5},
   {0, SW10_CS5,   SW11_CS5,   SW12_CS5},
   {0, SW1_CS10,  SW2_CS10,  SW3_CS10},
   {0, SW4_CS10,  SW5_CS10,  SW6_CS10},
   {0, SW7_CS10,  SW8_CS10,  SW9_CS10},
   {0, SW10_CS10,  SW11_CS10,  SW12_CS10},
   {0, SW10_CS15,  SW11_CS15,  SW12_CS15}
};
>>>>>>> upstream/master
#endif