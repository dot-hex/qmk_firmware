<<<<<<< HEAD:keyboards/acheron/elongate/elongate.c
/* Copyright 2021 Gondolindrim
=======
/* Copyright 2023 CMM.S Freather
>>>>>>> upstream/master:keyboards/ah/haven80/haven80.c
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
 */
 
#include "quantum.h"

<<<<<<< HEAD:keyboards/acheron/elongate/elongate.c
#include "elongate.h"
=======
bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    if (res) {
    if (led_state.caps_lock) {
        rgblight_sethsv_range(0, 0, 255, 0,20);
    } else {
        rgblight_sethsv_range(0, 0, 0, 0, 20);
    }
  }
    return res;
}
>>>>>>> upstream/master:keyboards/ah/haven80/haven80.c
