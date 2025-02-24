<<<<<<< HEAD:keyboards/mechlovin/infinity87/rev1/rev1.c
/* Copyright 2020 Team Mechlovin'
=======
/* Copyright 2023 Yiancar-Designs
>>>>>>> upstream/master:keyboards/geonworks/ee_at/ee_at.c
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
<<<<<<< HEAD:keyboards/mechlovin/infinity87/rev1/rev1.c

#include "rev1.h"
<<<<<<< HEAD

void matrix_init_kb(void) {
    matrix_init_user();
    led_init_ports();
}

void led_init_ports(void) {
    setPinOutput(A3);
    writePinLow(A3);
    setPinOutput(A4);
    writePinLow(A4);
}

bool led_update_kb(led_t led_state) {
    if(led_update_user(led_state)) {
        writePin(A4, !led_state.caps_lock);
        writePin(A8, !led_state.scroll_lock);
    }

    return true;
}
=======
>>>>>>> 8e9d45d2708d71cf89bed704e8e0e1bf5671804f
=======
#include "quantum.h"

void led_init_ports(void) {
    // Set our LED pins as open drain outputs
    gpio_set_pin_output_open_drain(LED_CAPS_LOCK_PIN);
    gpio_set_pin_output_open_drain(LED_NUM_LOCK_PIN);
    gpio_set_pin_output_open_drain(LED_SCROLL_LOCK_PIN);
    gpio_set_pin_output_open_drain(LED_KANA_PIN);
    gpio_set_pin_output_open_drain(A14);
}

layer_state_t layer_state_set_kb(layer_state_t state) {
    gpio_write_pin(A14, !layer_state_cmp(state, 1));
    return layer_state_set_user(state);
}
>>>>>>> upstream/master:keyboards/geonworks/ee_at/ee_at.c
