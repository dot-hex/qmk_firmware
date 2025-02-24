// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

<<<<<<< HEAD
#include "keymap.h"

// List of keycodes for the steno keyboard. To prevent
// errors, this must be <= 42 total entries in order to
// support the GeminiPR protocol.
enum steno_keycodes {
    STN__MIN = QK_STENO,
    STN_FN   = STN__MIN,
    STN_NUM,
    STN_N1 = STN_NUM,
    STN_N2,
    STN_N3,
    STN_N4,
    STN_N5,
    STN_N6,
    STN_SL,
    STN_S1 = STN_SL,
    STN_S2,
    STN_TL,
    STN_KL,
    STN_PL,
    STN_WL,
    STN_HL,
    STN_RL,
    STN_A,
    STN_O,
    STN_STR,
    STN_ST1 = STN_STR,
    STN_ST2,
    STN_RES1,
    STN_RE1 = STN_RES1,
    STN_RES2,
    STN_RE2 = STN_RES2,
    STN_PWR,
    STN_ST3,
    STN_ST4,
    STN_E,
    STN_U,
    STN_FR,
    STN_RR,
    STN_PR,
    STN_BR,
    STN_LR,
    STN_GR,
    STN_TR,
    STN_SR,
    STN_DR,
    STN_N7,
    STN_N8,
    STN_N9,
    STN_NA,
    STN_NB,
    STN_NC,
    STN_ZR,
    STN__MAX = STN_ZR, // must be less than QK_STENO_BOLT
};

#ifdef STENO_COMBINEDMAP
enum steno_combined_keycodes {
    STN_S3 = QK_STENO_COMB,
    STN_TKL,
    STN_PWL,
    STN_HRL,
    STN_FRR,
    STN_PBR,
    STN_LGR,
    STN_TSR,
    STN_DZR,
    STN_AO,
    STN_EU,
    STN_COMB_MAX = STN_EU,
};
#endif
=======
#pragma message("keymap_steno.h include is no longer required")
>>>>>>> upstream/master
