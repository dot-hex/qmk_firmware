/* Copyright 2021 yushakobo
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
/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT( \
	k00, k01, k02, k03, \
	k10, k11, k12, k13, k14, k15, k16, \
	k20, k21, k22, k23, k24, k25, k26, \
	               k33, k34, k35, k36, \
	k40, k41, k42, k43, k44, k45, k46, \
	k50, k51, k52, k53, k54, k55, k56  \
	) \
    {\
	{ k01, k02, k13, k14, k15, k16 }, \
	{ k11, k12, k23, k24, k25, k26 }, \
	{ k21, k22, k33, k34, k35, k36 }, \
	{ k41, k42, k43, k44, k45, k46 }, \
	{ k51, k52, k53, k54, k55, k56 }, \
	{ k00, k03, k10, k20, k40, k50 } \
   	}
=======
<<<<<<<< HEAD:keyboards/yushakobo/navpad/10/rev1/rev1.h
#include "navpad_prefs.h"
========
#define LAYOUT_alice_split_bs( \
    K1E, K00, K01, K02, K03, K04, K05, K06,         K07,K08,K09, K0A, K0B, K0C, K0D, K0E,\
    K2E, K10, K11, K12, K13, K14, K15,              K16,K17,K18, K19, K1A, K1B, K1C, K1D,\
    K3E, K20, K21, K22, K23, K24, K25,              K26,K27,K28, K29, K2A, K2B, K2D,\
         K30,      K32, K33, K34, K35, K36,         K37,K38,K39, K3A, K3B, K3D, K3C, K4D,\
         K40,      K42,      K44,      K46,             K48,     K4A,               K4E \
) { \
    { K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K0A,   K0B,   K0C,   K0D,   K0E   }, \
    { K10,   K11,   K12,   K13,   K14,   K15,   K16,   K17,   K18,   K19,   K1A,   K1B,   K1C,   K1D,   K1E   }, \
    { K20,   K21,   K22,   K23,   K24,   K25,   K26,   K27,   K28,   K29,   K2A,   K2B,   KC_NO, K2D,   K2E   }, \
    { K30,   KC_NO, K32,   K33,   K34,   K35,   K36,   K37,   K38,   K39,   K3A,   K3B,   K3C,   K3D,   K3E   }, \
    { K40,   KC_NO, K42,   KC_NO, K44,   KC_NO, K46,   KC_NO, K48,   KC_NO, K4A,   KC_NO, KC_NO, K4D,   K4E   }, \
}

#define LAYOUT_alice( \
    K1E, K00, K01, K02, K03, K04, K05, K06,         K07,K08,K09, K0A, K0B, K0C, K0D, \
    K2E, K10, K11, K12, K13, K14, K15,              K16,K17,K18, K19, K1A, K1B, K1C, K1D,\
    K3E, K20, K21, K22, K23, K24, K25,              K26,K27,K28, K29, K2A, K2B, K2D,\
         K30,      K32, K33, K34, K35, K36,         K37,K38,K39, K3A, K3B, K3D, K3C, K4D,\
         K40,      K42,      K44,      K46,             K48,     K4A,               K4E \
) { \
    { K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K0A,   K0B,   K0C,   K0D,   KC_NO }, \
    { K10,   K11,   K12,   K13,   K14,   K15,   K16,   K17,   K18,   K19,   K1A,   K1B,   K1C,   K1D,   K1E   }, \
    { K20,   K21,   K22,   K23,   K24,   K25,   K26,   K27,   K28,   K29,   K2A,   K2B,   KC_NO, K2D,   K2E   }, \
    { K30,   KC_NO, K32,   K33,   K34,   K35,   K36,   K37,   K38,   K39,   K3A,   K3B,   K3C,   K3D,   K3E   }, \
    { K40,   KC_NO, K42,   KC_NO, K44,   KC_NO, K46,   KC_NO, K48,   KC_NO, K4A,   KC_NO, KC_NO, K4D,   K4E   }, \
}

#define LAYOUT_alice_split_bs_full_rshift( \
    K1E, K00, K01, K02, K03, K04, K05, K06,         K07, K08, K09, K0A, K0B, K0C, K0D, K0E, \
    K2E, K10, K11, K12, K13, K14, K15,              K16, K17, K18, K19, K1A, K1B, K1C, K1D, \
    K3E, K20, K21, K22, K23, K24, K25,              K26, K27, K28, K29, K2A, K2B, K2D,      \
         K30,      K32, K33, K34, K35, K36,         K37, K38, K39, K3A, K3B, K3D, K3C,      \
         K40,      K42,      K44,      K46,              K48,      K4A,                K4E  \
) { \
    { K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K0A,   K0B,   K0C,   K0D,   K0E   }, \
    { K10,   K11,   K12,   K13,   K14,   K15,   K16,   K17,   K18,   K19,   K1A,   K1B,   K1C,   K1D,   K1E   }, \
    { K20,   K21,   K22,   K23,   K24,   K25,   K26,   K27,   K28,   K29,   K2A,   K2B,   KC_NO, K2D,   K2E   }, \
    { K30,   KC_NO, K32,   K33,   K34,   K35,   K36,   K37,   K38,   K39,   K3A,   K3B,   K3C,   K3D,   K3E   }, \
    { K40,   KC_NO, K42,   KC_NO, K44,   KC_NO, K46,   KC_NO, K48,   KC_NO, K4A,   KC_NO, KC_NO, KC_NO, K4E   }, \
}

#define LAYOUT_alice_full_rshift( \
    K1E, K00, K01, K02, K03, K04, K05, K06,         K07, K08, K09, K0A, K0B, K0C, K0D,      \
    K2E, K10, K11, K12, K13, K14, K15,              K16, K17, K18, K19, K1A, K1B, K1C, K1D, \
    K3E, K20, K21, K22, K23, K24, K25,              K26, K27, K28, K29, K2A, K2B, K2D,      \
         K30,      K32, K33, K34, K35, K36,         K37, K38, K39, K3A, K3B, K3D, K3C,      \
         K40,      K42,      K44,      K46,              K48,      K4A,                K4E  \
) { \
    { K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K0A,   K0B,   K0C,   K0D,   KC_NO }, \
    { K10,   K11,   K12,   K13,   K14,   K15,   K16,   K17,   K18,   K19,   K1A,   K1B,   K1C,   K1D,   K1E   }, \
    { K20,   K21,   K22,   K23,   K24,   K25,   K26,   K27,   K28,   K29,   K2A,   K2B,   KC_NO, K2D,   K2E   }, \
    { K30,   KC_NO, K32,   K33,   K34,   K35,   K36,   K37,   K38,   K39,   K3A,   K3B,   K3C,   K3D,   K3E   }, \
    { K40,   KC_NO, K42,   KC_NO, K44,   KC_NO, K46,   KC_NO, K48,   KC_NO, K4A,   KC_NO, KC_NO, KC_NO, K4E   }, \
}

#define LAYOUT_all LAYOUT_alice_split_bs
>>>>>>>> upstream/master:keyboards/mechlovin/adelais/rgb_led/rev1/rev1.h
>>>>>>> upstream/master
