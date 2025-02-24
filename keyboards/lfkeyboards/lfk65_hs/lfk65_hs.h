#pragma once

#include "quantum.h"
<<<<<<< HEAD
#include "matrix.h"
#include <avr/sfr_defs.h>
#include <stdint.h>

void reset_keyboard_kb(void);

// readability
#define ___ KC_NO

/* All Keymap - contains every possible switch
* ,-------------------------------------------------------------------------------.
* | 00 | 01 | 02 | 03 | 04 | 05 | 06 | 07 | 08 | 09 | 0A | 0B | 0C | 0D | 0E | 0F |
* |-------------------------------------------------------------------------------|
* | 10  | 11 |12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 1A | 1B | 1C |    1E   | 1F |
* |-------------------------------------------------------------------------------|
* | 20   | 21 | 22 | 23 | 24 | 25 | 26 | 27 | 28 | 29 | 2A | 2B | 2C  | 2E   | 2F |
* |-------------------------------------------------------------------------------|
* | 30  |31 | 32 | 33 | 34 | 35 | 36 | 37 | 38 | 39 | 3A | 3B |    3C   | 3E | 3F |
* |-------------------------------------------------------------------------------|
* | 40  |  41  | 42  |              46              | 4A | 4B | 4C | 4D | 2D | 3D |
* `-------------------------------------------------------------------------------'
*/
// The first section contains all of the arguements
// The second converts the arguments into a two-dimensional array
#define LAYOUT_all( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0A, k0B, k0C, k0D, k0E, k0F, \
    k10,   k11, k12, k13, k14, k15, k16, k17, k18, k19, k1A, k1B, k1C,    k1E, k1F, \
    k20,    k21, k22, k23, k24, k25, k26, k27, k28, k29, k2A, k2B, k2C,   k2E, k2F, \
    k30, k31, k32, k33,  k34, k35, k36, k37, k38, k39, k3A, k3B,     k3C, k3E, k3F, \
    k40, k41, k42,              k46,                  k4A, k4B, k4C, k4D, k2D, k3D \
) { \
    { k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0A, k0B, k0C, k0D, k0E, k0F }, \
    { k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1A, k1B, k1C, ___, k1E, k1F }, \
    { k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2A, k2B, k2C, k2D, k2E, k2F }, \
    { k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3A, k3B, k3C, k3D, k3E, k3F }, \
    { k40, k41, k42, ___, ___, ___, k46, ___, ___, ___, k4A, k4B, k4C, k4D, ___, ___ } \
}

/* ANSI Keymap
* ,-------------------------------------------------------------------------------.
* | 00 | 01 | 02 | 03 | 04 | 05 | 06 | 07 | 08 | 09 | 0A | 0B | 0C |   0E    | 0F |
* |-------------------------------------------------------------------------------|
* | 10   | 11 |12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 1A | 1B | 1C |   1E   | 1F |
* |-------------------------------------------------------------------------------|
* | 20    | 21 |22 | 23 | 24 | 25 | 26 | 27 | 28 | 29 | 2A | 2B |      2E    | 2F |
* |-------------------------------------------------------------------------------|
* | 30      | 32 |33 | 34 | 35 | 36 | 37 | 38 | 39 | 3A | 3B |    3C    | 3E | 3F |
* |-------------------------------------------------------------------------------|
* | 40  |  41  | 42  |              46              | 4A | 4B | 4C | 4D | 2D | 3D |
* `-------------------------------------------------------------------------------'
*/
#define LAYOUT_ansi( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0A, k0B, k0C,         k0E, k0F, \
    k10,   k11, k12, k13, k14, k15, k16, k17, k18, k19, k1A, k1B, k1C,       k1E, k1F, \
    k20,    k21, k22, k23, k24, k25, k26, k27, k28, k29, k2A, k2B,           k2E, k2F, \
    k30,     k32, k33,  k34, k35, k36, k37, k38, k39, k3A, k3B,         k3C, k3E, k3F, \
    k40, k41, k42,              k46,                     k4A, k4B, k4C, k4D, k2D, k3D \
) { \
    { k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0A, k0B, k0C, ___, k0E, k0F }, \
    { k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1A, k1B, k1C, ___, k1E, k1F }, \
    { k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2A, k2B, ___, k2D, k2E, k2F }, \
    { k30, ___, k32, k33, k34, k35, k36, k37, k38, k39, k3A, k3B, k3C, k3D, k3E, k3F }, \
    { k40, k41, k42, ___, ___, ___, k46, ___, ___, ___, k4A, k4B, k4C, k4D, ___, ___ } \
}
=======

void reset_keyboard_kb(void);
>>>>>>> upstream/master
