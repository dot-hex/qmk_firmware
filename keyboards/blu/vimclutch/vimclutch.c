/*
Copyright 2023 Brandon Lu

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
<<<<<<< HEAD:keyboards/woodkeys/bigseries/1key/1key.h

#pragma once

#include "quantum.h"

#define LAYOUT( \
    k00 \
) { \
    { k00 } \
}
=======
#include "quantum.h"

void keyboard_pre_init_kb(void)
{
	gpio_set_pin_output(F4);
	gpio_set_pin_output(F5);

	keyboard_pre_init_user();
};
>>>>>>> upstream/master:keyboards/blu/vimclutch/vimclutch.c
