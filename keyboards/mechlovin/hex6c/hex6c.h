/* Copyright 2021 Mechlovin' Studio
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

<<<<<<< HEAD
#define LAYOUT_ALL( \
=======
#define LAYOUT_all( \
>>>>>>> 8e9d45d2708d71cf89bed704e8e0e1bf5671804f
    K00, K01, K02, K03,  K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E, K0F, K0G, K0H,       K0I, K0J, K0K, \
    K10, K11, K12, K13,  K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, K1E, K1F, K1G, K1H, K2H,  K1I, K1J, K1K, \
    K20, K21, K22, K23,  K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D, K2E, K2F, K2G, K3G,       K2I, K2J, K2K, \
    K30, K31, K32, K33,  K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, K3E, K3F, K3H,                           \
    K40, K41, K42, K43,  K44, K45, K46, K47, K48, K49, K4A, K4B, K4C, K4D, K4E, K4F, K4G, K4H,            K4J,      \
    K50, K51, K52, K53,  K54, K55,  K56,               K5A,           K5E, K5F, K5G, K5H,            K5I, K5J, K5K  \
) { \
    { K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K0A,   K0B,   K0C,   K0D,   K0E,   K0F,   K0G,   K0H,   K0I,   K0J,   K0K   }, \
    { K10,   K11,   K12,   K13,   K14,   K15,   K16,   K17,   K18,   K19,   K1A,   K1B,   K1C,   K1D,   K1E,   K1F,   K1G,   K1H,   K1I,   K1J,   K1K   }, \
    { K20,   K21,   K22,   K23,   K24,   K25,   K26,   K27,   K28,   K29,   K2A,   K2B,   K2C,   K2D,   K2E,   K2F,   K2G,   K2H,   K2I,   K2J,   K2K   }, \
    { K30,   K31,   K32,   K33,   K34,   K35,   K36,   K37,   K38,   K39,   K3A,   K3B,   K3C,   K3D,   K3E,   K3F,   K3G,   K3H,   KC_NO, KC_NO, KC_NO }, \
    { K40,   K41,   K42,   K43,   K44,   K45,   K46,   K47,   K48,   K49,   K4A,   K4B,   K4C,   K4D,   K4E,   K4F,   K4G,   K4H,   KC_NO, K4J,   KC_NO }, \
    { K50,   K51,   K52,   K53,   K54,   K55,   K56,   KC_NO, KC_NO, KC_NO, K5A,   KC_NO, KC_NO, KC_NO, K5E,   K5F,   K5G,   K5H,   K5I,   K5J,   K5K   }, \
}
