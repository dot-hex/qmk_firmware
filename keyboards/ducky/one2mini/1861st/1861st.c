// Copyright 2022 Nick Brassel (@tzarc)
// SPDX-License-Identifier: GPL-2.0-or-later
<<<<<<< HEAD
#include "1861st.h"
=======
#include "quantum.h"
>>>>>>> upstream/master

void bootloader_jump(void) {
    // TODO: Work out how to jump to LDROM, for now just reset the board.
    NVIC_SystemReset();
}
