/* Copyright 2021 QMK
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
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

#include <ch.h>
#include <hal.h>

#include "_wait.h"

#ifdef WAIT_US_TIMER
void wait_us(uint16_t duration) {
<<<<<<< HEAD
    static const GPTConfig gpt_cfg = {1000000, NULL, 0, 0}; /* 1MHz timer, no callback */
=======
    static const GPTConfig gpt_cfg = {.frequency = 1000000}; /* 1MHz timer, no callback */
>>>>>>> upstream/master

    if (duration == 0) {
        duration = 1;
    }

    /*
     * Only use this timer on the main thread;
     * other threads need to use their own timer.
     */
<<<<<<< HEAD
    if (chThdGetSelfX() == &ch.mainthread && duration < (1ULL << (sizeof(gptcnt_t) * 8))) {
=======
    if (chThdGetSelfX() == &(currcore->mainthread) && duration < (1ULL << (sizeof(gptcnt_t) * 8))) {
>>>>>>> upstream/master
        gptStart(&WAIT_US_TIMER, &gpt_cfg);
        gptPolledDelay(&WAIT_US_TIMER, duration);
    } else {
        chThdSleepMicroseconds(duration);
    }
}
#endif
