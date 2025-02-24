/* Copyright 2020 Vladislav Kucheriavykh
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
#include "quantum.h"
#include "process_dynamic_tapping_term.h"
=======
#include "process_dynamic_tapping_term.h"
#include "quantum.h"
#include "keycodes.h"
#include "send_string.h"
>>>>>>> upstream/master

#ifndef DYNAMIC_TAPPING_TERM_INCREMENT
#    define DYNAMIC_TAPPING_TERM_INCREMENT 5
#endif

static void tapping_term_report(void) {
<<<<<<< HEAD
=======
#ifdef SEND_STRING_ENABLE
>>>>>>> upstream/master
    const char *tapping_term_str = get_u16_str(g_tapping_term, ' ');
    // Skip padding spaces
    while (*tapping_term_str == ' ') {
        tapping_term_str++;
    }
    send_string(tapping_term_str);
<<<<<<< HEAD
=======
#endif
>>>>>>> upstream/master
}

bool process_dynamic_tapping_term(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
<<<<<<< HEAD
            case DT_PRNT:
                tapping_term_report();
                return false;

            case DT_UP:
                g_tapping_term += DYNAMIC_TAPPING_TERM_INCREMENT;
                return false;

            case DT_DOWN:
=======
            case QK_DYNAMIC_TAPPING_TERM_PRINT:
                tapping_term_report();
                return false;

            case QK_DYNAMIC_TAPPING_TERM_UP:
                g_tapping_term += DYNAMIC_TAPPING_TERM_INCREMENT;
                return false;

            case QK_DYNAMIC_TAPPING_TERM_DOWN:
>>>>>>> upstream/master
                g_tapping_term -= DYNAMIC_TAPPING_TERM_INCREMENT;
                return false;
        }
    }
    return true;
}
