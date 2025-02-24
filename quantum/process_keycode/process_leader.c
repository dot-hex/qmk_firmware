/* Copyright 2016 Jack Humbert
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

#include "process_leader.h"
#include "leader.h"
#include "quantum_keycodes.h"

bool process_leader(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
<<<<<<< HEAD
        if (leading) {
#    ifndef LEADER_NO_TIMEOUT
            if (timer_elapsed(leader_time) < LEADER_TIMEOUT)
#    endif // LEADER_NO_TIMEOUT
            {
#    ifndef LEADER_KEY_STRICT_KEY_PROCESSING
                if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
                    keycode = keycode & 0xFF;
                }
#    endif // LEADER_KEY_STRICT_KEY_PROCESSING
                if (leader_sequence_size < (sizeof(leader_sequence) / sizeof(leader_sequence[0]))) {
                    leader_sequence[leader_sequence_size] = keycode;
                    leader_sequence_size++;
                } else {
                    leading = false;
                    leader_end();
                }
#    ifdef LEADER_PER_KEY_TIMING
                leader_time = timer_read();
#    endif
                return false;
=======
        if (leader_sequence_active() && !leader_sequence_timed_out()) {
#ifndef LEADER_KEY_STRICT_KEY_PROCESSING
            if (IS_QK_MOD_TAP(keycode)) {
                keycode = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
            } else if (IS_QK_LAYER_TAP(keycode)) {
                keycode = QK_LAYER_TAP_GET_TAP_KEYCODE(keycode);
>>>>>>> upstream/master
            }
#endif

            if (!leader_sequence_add(keycode)) {
                leader_end();

                return true;
            }

#ifdef LEADER_PER_KEY_TIMING
            leader_reset_timer();
#endif

            return false;
        } else if (keycode == QK_LEADER) {
            leader_start();
        }
    }

    return true;
}
