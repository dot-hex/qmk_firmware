/*
<<<<<<< HEAD:keyboards/cozykeys/bloomer/bloomer.h
Copyright 2021 Paul Ewing
=======
Copyright 2019 Cole Markham
>>>>>>> upstream/master:keyboards/woodkeys/scarletbandana/config.h

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
#pragma once

<<<<<<< HEAD:keyboards/cozykeys/bloomer/bloomer.h
#if defined(KEYBOARD_cozykeys_bloomer_v2)
    #include "v2.h"
#elif defined(KEYBOARD_cozykeys_bloomer_v3)
    #include "v3.h"
=======
#ifdef AUDIO_ENABLE
#define AUDIO_PIN C6
#define STARTUP_SONG SONG(PREONIC_SOUND)
// Disable music mode to keep the firmware size down
#define NO_MUSIC_MODE
>>>>>>> upstream/master:keyboards/woodkeys/scarletbandana/config.h
#endif
