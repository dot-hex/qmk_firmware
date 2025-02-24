/*
<<<<<<< HEAD:keyboards/bpiphany/ghost_squid/ghost_squid.c
Copyright 2016 Daniel Svensson <dsvensson@gmail.com>
=======
Copyright 2021 ojthetiny
>>>>>>> upstream/master:keyboards/fruitykeeb/fruitbar/fruitbar.c

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "ghost_squid.h"

<<<<<<< HEAD:keyboards/bpiphany/ghost_squid/ghost_squid.c
void keyboard_pre_init_kb(void) {
    setPinOutput(D0);
    writePinLow(D0);
    fn_led_off();
    
    keyboard_pre_init_user();
}
=======
#ifdef OLED_ENABLE
bool oled_task_kb(void) {
    if (!oled_task_user()) {
        return false;
    }

    // Layer Status
    oled_write_P(PSTR("Layer:"), false);
    oled_write_ln(get_u8_str(get_highest_layer(layer_state), ' '), false);

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

    return true;
}
#endif
>>>>>>> upstream/master:keyboards/fruitykeeb/fruitbar/fruitbar.c
