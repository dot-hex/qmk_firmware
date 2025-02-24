/* Copyright 2021 DZTECH <moyi4681@live.cn>
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
#include "v3.h"

#ifdef RGB_MATRIX_ENABLE

const is31_led PROGMEM g_is31_leds[DRIVER_LED_TOTAL] = {
    {0, CS21_SW1, CS20_SW1, CS19_SW1},
    {0, CS21_SW2, CS20_SW2, CS19_SW2},
    {0, CS21_SW3, CS20_SW3, CS19_SW3},
    {0, CS21_SW4, CS20_SW4, CS19_SW4},
    {0, CS21_SW5, CS20_SW5, CS19_SW5},
    {0, CS21_SW6, CS20_SW6, CS19_SW6},
    {0, CS21_SW7, CS20_SW7, CS19_SW7},
    {0, CS21_SW8, CS20_SW8, CS19_SW8},
    {0, CS24_SW1, CS23_SW1, CS22_SW1},
    {0, CS24_SW2, CS23_SW2, CS22_SW2},
    {0, CS24_SW3, CS23_SW3, CS22_SW3},
    {0, CS24_SW4, CS23_SW4, CS22_SW4},
    {0, CS24_SW5, CS23_SW5, CS22_SW5},
    {0, CS24_SW6, CS23_SW6, CS22_SW6},
    {0, CS24_SW7, CS23_SW7, CS22_SW7},

    {0, CS15_SW1, CS14_SW1, CS13_SW1},
    {0, CS15_SW2, CS14_SW2, CS13_SW2},
    {0, CS15_SW3, CS14_SW3, CS13_SW3},
    {0, CS15_SW4, CS14_SW4, CS13_SW4},
    {0, CS15_SW5, CS14_SW5, CS13_SW5},
    {0, CS15_SW6, CS14_SW6, CS13_SW6},
    {0, CS15_SW7, CS14_SW7, CS13_SW7},
    {0, CS15_SW8, CS14_SW8, CS13_SW8},
    {0, CS30_SW1, CS29_SW1, CS28_SW1},
    {0, CS30_SW2, CS29_SW2, CS28_SW2},
    {0, CS30_SW3, CS29_SW3, CS28_SW3},
    {0, CS30_SW4, CS29_SW4, CS28_SW4},
    {0, CS30_SW5, CS29_SW5, CS28_SW5},
    {0, CS30_SW6, CS29_SW6, CS28_SW6},
    {0, CS30_SW7, CS29_SW7, CS28_SW7},

    {0, CS12_SW1, CS11_SW1, CS10_SW1},
    {0, CS12_SW2, CS11_SW2, CS10_SW2},
    {0, CS12_SW3, CS11_SW3, CS10_SW3},
    {0, CS12_SW4, CS11_SW4, CS10_SW4},
    {0, CS12_SW5, CS11_SW5, CS10_SW5},
    {0, CS12_SW6, CS11_SW6, CS10_SW6},
    {0, CS12_SW7, CS11_SW7, CS10_SW7},
    {0, CS12_SW8, CS11_SW8, CS10_SW8},
    {0, CS33_SW1, CS32_SW1, CS31_SW1},
    {0, CS33_SW2, CS32_SW2, CS31_SW2},
    {0, CS33_SW3, CS32_SW3, CS31_SW3},
    {0, CS33_SW4, CS32_SW4, CS31_SW4},
    {0, CS33_SW5, CS32_SW5, CS31_SW5},
    {0, CS33_SW7, CS32_SW7, CS31_SW7},

    {0, CS9_SW1, CS8_SW1, CS7_SW1},
    {0, CS9_SW2, CS8_SW2, CS7_SW2},
    {0, CS9_SW3, CS8_SW3, CS7_SW3},
    {0, CS9_SW4, CS8_SW4, CS7_SW4},
    {0, CS9_SW5, CS8_SW5, CS7_SW5},
    {0, CS9_SW6, CS8_SW6, CS7_SW6},
    {0, CS9_SW7, CS8_SW7, CS7_SW7},
    {0, CS9_SW8, CS8_SW8, CS7_SW8},
    {0, CS36_SW1, CS35_SW1, CS34_SW1},
    {0, CS36_SW2, CS35_SW2, CS34_SW2},
    {0, CS36_SW3, CS35_SW3, CS34_SW3},
    {0, CS36_SW4, CS35_SW4, CS34_SW4},
    {0, CS36_SW5, CS35_SW5, CS34_SW5},
    {0, CS36_SW7, CS35_SW7, CS34_SW7},

    {0, CS3_SW1, CS2_SW1, CS1_SW1},
    {0, CS3_SW2, CS2_SW2, CS1_SW2},
    {0, CS3_SW3, CS2_SW3, CS1_SW3},
    {0, CS3_SW6, CS2_SW6, CS1_SW6},
//    {0, CS39_SW1, CS38_SW1, CS37_SW1},
    {0, CS39_SW2, CS38_SW2, CS37_SW2},
    {0, CS39_SW3, CS38_SW3, CS37_SW3},
    {0, CS39_SW4, CS38_SW4, CS37_SW4},
    {0, CS39_SW5, CS38_SW5, CS37_SW5},
    {0, CS39_SW7, CS38_SW7, CS37_SW7}
=======
#include "quantum.h"

#ifdef RGB_MATRIX_ENABLE

const is31fl3741_led_t PROGMEM g_is31fl3741_leds[IS31FL3741_LED_COUNT] = {
    {0, SW1_CS21, SW1_CS20, SW1_CS19},
    {0, SW2_CS21, SW2_CS20, SW2_CS19},
    {0, SW3_CS21, SW3_CS20, SW3_CS19},
    {0, SW4_CS21, SW4_CS20, SW4_CS19},
    {0, SW5_CS21, SW5_CS20, SW5_CS19},
    {0, SW6_CS21, SW6_CS20, SW6_CS19},
    {0, SW7_CS21, SW7_CS20, SW7_CS19},
    {0, SW8_CS21, SW8_CS20, SW8_CS19},
    {0, SW1_CS24, SW1_CS23, SW1_CS22},
    {0, SW2_CS24, SW2_CS23, SW2_CS22},
    {0, SW3_CS24, SW3_CS23, SW3_CS22},
    {0, SW4_CS24, SW4_CS23, SW4_CS22},
    {0, SW5_CS24, SW5_CS23, SW5_CS22},
    {0, SW6_CS24, SW6_CS23, SW6_CS22},
    {0, SW7_CS24, SW7_CS23, SW7_CS22},

    {0, SW1_CS15, SW1_CS14, SW1_CS13},
    {0, SW2_CS15, SW2_CS14, SW2_CS13},
    {0, SW3_CS15, SW3_CS14, SW3_CS13},
    {0, SW4_CS15, SW4_CS14, SW4_CS13},
    {0, SW5_CS15, SW5_CS14, SW5_CS13},
    {0, SW6_CS15, SW6_CS14, SW6_CS13},
    {0, SW7_CS15, SW7_CS14, SW7_CS13},
    {0, SW8_CS15, SW8_CS14, SW8_CS13},
    {0, SW1_CS30, SW1_CS29, SW1_CS28},
    {0, SW2_CS30, SW2_CS29, SW2_CS28},
    {0, SW3_CS30, SW3_CS29, SW3_CS28},
    {0, SW4_CS30, SW4_CS29, SW4_CS28},
    {0, SW5_CS30, SW5_CS29, SW5_CS28},
    {0, SW6_CS30, SW6_CS29, SW6_CS28},
    {0, SW7_CS30, SW7_CS29, SW7_CS28},

    {0, SW1_CS12, SW1_CS11, SW1_CS10},
    {0, SW2_CS12, SW2_CS11, SW2_CS10},
    {0, SW3_CS12, SW3_CS11, SW3_CS10},
    {0, SW4_CS12, SW4_CS11, SW4_CS10},
    {0, SW5_CS12, SW5_CS11, SW5_CS10},
    {0, SW6_CS12, SW6_CS11, SW6_CS10},
    {0, SW7_CS12, SW7_CS11, SW7_CS10},
    {0, SW8_CS12, SW8_CS11, SW8_CS10},
    {0, SW1_CS33, SW1_CS32, SW1_CS31},
    {0, SW2_CS33, SW2_CS32, SW2_CS31},
    {0, SW3_CS33, SW3_CS32, SW3_CS31},
    {0, SW4_CS33, SW4_CS32, SW4_CS31},
    {0, SW5_CS33, SW5_CS32, SW5_CS31},
    {0, SW7_CS33, SW7_CS32, SW7_CS31},

    {0, SW1_CS9, SW1_CS8, SW1_CS7},
    {0, SW2_CS9, SW2_CS8, SW2_CS7},
    {0, SW3_CS9, SW3_CS8, SW3_CS7},
    {0, SW4_CS9, SW4_CS8, SW4_CS7},
    {0, SW5_CS9, SW5_CS8, SW5_CS7},
    {0, SW6_CS9, SW6_CS8, SW6_CS7},
    {0, SW7_CS9, SW7_CS8, SW7_CS7},
    {0, SW8_CS9, SW8_CS8, SW8_CS7},
    {0, SW1_CS36, SW1_CS35, SW1_CS34},
    {0, SW2_CS36, SW2_CS35, SW2_CS34},
    {0, SW3_CS36, SW3_CS35, SW3_CS34},
    {0, SW4_CS36, SW4_CS35, SW4_CS34},
    {0, SW5_CS36, SW5_CS35, SW5_CS34},
    {0, SW7_CS36, SW7_CS35, SW7_CS34},

    {0, SW1_CS3, SW1_CS2, SW1_CS1},
    {0, SW2_CS3, SW2_CS2, SW2_CS1},
    {0, SW3_CS3, SW3_CS2, SW3_CS1},
    {0, SW6_CS3, SW6_CS2, SW6_CS1},
//    {0, SW1_CS39, SW1_CS38, SW1_CS37},
    {0, SW2_CS39, SW2_CS38, SW2_CS37},
    {0, SW3_CS39, SW3_CS38, SW3_CS37},
    {0, SW4_CS39, SW4_CS38, SW4_CS37},
    {0, SW5_CS39, SW5_CS38, SW5_CS37},
    {0, SW7_CS39, SW7_CS38, SW7_CS37}
>>>>>>> upstream/master

};

#define __ NO_LED
#define CAPS_LOCK_LED_INDEX 30

led_config_t g_led_config = { {
    // Key Matrix to LED Index
    {  0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14 },
    {  15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29 },
    {  30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, __, 42, 43 },
    {  44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, __, 56, 57 },
    {  58, 59, 60, __, __, 61, __, __, 62, __, 63, 64, __, 65, 66 }
}, {
    // LED Index to Physical Position
    // based on: https://gist.github.com/vinorodrigues/07fd735683856b2a06c7c52b9b3878cb
    {0, 0},  {15, 0},  {30, 0},  {45, 0},  {60, 0},  {75, 0},  {90, 0},   {105, 0},  {119, 0},  {134, 0},  {149, 0},  {164, 0},  {179, 0},  {202, 0},  {224, 0},
    {4, 16}, {22, 16}, {37, 16}, {52, 16}, {67, 16}, {82, 16}, {97, 16},  {112, 16}, {127, 16}, {142, 16}, {157, 16}, {172, 16}, {187, 16}, {205, 16}, {224, 16},
    {6, 32}, {26, 32}, {41, 32}, {56, 32}, {71, 32}, {86, 32}, {101, 32}, {116, 32}, {131, 32}, {146, 32}, {161, 32}, {175, 32},            {200, 32}, {224, 32},
    {9, 48}, {34, 48}, {49, 48}, {63, 48}, {78, 48}, {93, 48}, {108, 48}, {123, 48}, {138, 48}, {153, 48}, {168, 48}, {189, 48},            {209, 48}, {224, 48},
    {2, 64}, {21, 64}, {39, 64},                     {95, 64},                       {151, 64},            {170, 64}, {194, 64},            {209, 64}, {224, 64}
}, {
    // LED Index to Flag
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
    9, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,    4, 1,  // caps lock is also an indicator so mask is `0x01 | 0x08`
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,    4, 1,
    1, 1, 1,       4,       1,    1, 1,    1, 1
} };

#endif

#if defined(RGB_MATRIX_ENABLE) && defined(CAPS_LOCK_LED_INDEX)

<<<<<<< HEAD
#ifdef RGB_MATRIX_MAXIMUM_BRIGHTNESS
    #define CAPS_LOCK_MAX_BRIGHTNESS RGB_MATRIX_MAXIMUM_BRIGHTNESS
#else
    #define CAPS_LOCK_MAX_BRIGHTNESS 0xFF
#endif

#ifdef RGB_MATRIX_VAL_STEP
    #define CAPS_LOCK_VAL_STEP RGB_MATRIX_VAL_STEP
#else
    #define CAPS_LOCK_VAL_STEP 8
#endif

__attribute__ ((weak))
void rgb_matrix_indicators_user(void) {
=======
#if !defined(CAPS_LOCK_MAX_BRIGHTNESS)
    #define CAPS_LOCK_MAX_BRIGHTNESS RGB_MATRIX_MAXIMUM_BRIGHTNESS
#endif

#if !defined(CAPS_LOCK_VAL_STEP)
    #define CAPS_LOCK_VAL_STEP RGB_MATRIX_VAL_STEP
#endif

bool rgb_matrix_indicators_kb(void) {
    if (!rgb_matrix_indicators_user()) {
        return false;
    }
>>>>>>> upstream/master
    if (host_keyboard_led_state().caps_lock) {
        uint8_t b = rgb_matrix_get_val();
        if (b < CAPS_LOCK_VAL_STEP) {
            b = CAPS_LOCK_VAL_STEP;
        } else if (b < (CAPS_LOCK_MAX_BRIGHTNESS - CAPS_LOCK_VAL_STEP)) {
            b += CAPS_LOCK_VAL_STEP;  // one step more than current brightness
        } else {
            b = CAPS_LOCK_MAX_BRIGHTNESS;
        }
        rgb_matrix_set_color(CAPS_LOCK_LED_INDEX, b, b, b);  // white, with the adjusted brightness
    }
<<<<<<< HEAD
=======
    return true;
>>>>>>> upstream/master
}

#endif
