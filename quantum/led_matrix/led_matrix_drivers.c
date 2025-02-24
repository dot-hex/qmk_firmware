/* Copyright 2018 James Laird-Wah
 * Copyright 2019 Clueboard
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
#include "led_matrix.h"
=======
#include "led_matrix_drivers.h"
>>>>>>> upstream/master

/* Each driver needs to define a struct:
 *
 *    const led_matrix_driver_t led_matrix_driver;
 *
 * All members must be provided. Keyboard custom drivers must define this
 * in their own files.
 */

<<<<<<< HEAD
#if defined(IS31FL3731) || defined(IS31FL3733) || defined(IS31FLCOMMON)
#    include "i2c_master.h"

static void init(void) {
    i2c_init();

#    if defined(IS31FL3731)
    IS31FL3731_init(LED_DRIVER_ADDR_1);
#        if defined(LED_DRIVER_ADDR_2)
    IS31FL3731_init(LED_DRIVER_ADDR_2);
#            if defined(LED_DRIVER_ADDR_3)
    IS31FL3731_init(LED_DRIVER_ADDR_3);
#                if defined(LED_DRIVER_ADDR_4)
    IS31FL3731_init(LED_DRIVER_ADDR_4);
#                endif
#            endif
#        endif

#    elif defined(IS31FL3733)
#        if !defined(LED_DRIVER_SYNC_1)
#            define LED_DRIVER_SYNC_1 0
#        endif
    IS31FL3733_init(LED_DRIVER_ADDR_1, LED_DRIVER_SYNC_1);
#        if defined(LED_DRIVER_ADDR_2)
#            if !defined(LED_DRIVER_SYNC_2)
#                define LED_DRIVER_SYNC_2 0
#            endif
    IS31FL3733_init(LED_DRIVER_ADDR_2, LED_DRIVER_SYNC_2);
#            if defined(LED_DRIVER_ADDR_3)
#                if !defined(LED_DRIVER_SYNC_3)
#                    define LED_DRIVER_SYNC_3 0
#                endif
    IS31FL3733_init(LED_DRIVER_ADDR_3, LED_DRIVER_SYNC_3);
#                if defined(LED_DRIVER_ADDR_4)
#                    if !defined(LED_DRIVER_SYNC_4)
#                        define LED_DRIVER_SYNC_4 0
#                    endif
    IS31FL3733_init(LED_DRIVER_ADDR_4, LED_DRIVER_SYNC_4);
#                endif
#            endif
#        endif

#    elif defined(IS31FLCOMMON)
    IS31FL_common_init(DRIVER_ADDR_1, ISSI_SSR_1);
#        if defined(LED_DRIVER_ADDR_2)
    IS31FL_common_init(DRIVER_ADDR_2, ISSI_SSR_2);
#            if defined(LED_DRIVER_ADDR_3)
    IS31FL_common_init(DRIVER_ADDR_3, ISSI_SSR_3);
#                if defined(LED_DRIVER_ADDR_4)
    IS31FL_common_init(DRIVER_ADDR_4, ISSI_SSR_4);
#                endif
#            endif
#        endif
#    endif

    for (int index = 0; index < DRIVER_LED_TOTAL; index++) {
#    if defined(IS31FL3731)
        IS31FL3731_set_led_control_register(index, true);
#    elif defined(IS31FL3733)
        IS31FL3733_set_led_control_register(index, true);
#    elif defined(IS31FLCOMMON)
        IS31FL_simple_set_scaling_buffer(index, true);
#    endif
    }

// This actually updates the LED drivers
#    if defined(IS31FL3731)
    IS31FL3731_update_led_control_registers(LED_DRIVER_ADDR_1, 0);
#        if defined(LED_DRIVER_ADDR_2)
    IS31FL3731_update_led_control_registers(LED_DRIVER_ADDR_2, 1);
#            if defined(LED_DRIVER_ADDR_3)
    IS31FL3731_update_led_control_registers(LED_DRIVER_ADDR_3, 2);
#                if defined(LED_DRIVER_ADDR_4)
    IS31FL3731_update_led_control_registers(LED_DRIVER_ADDR_4, 3);
#                endif
#            endif
#        endif

#    elif defined(IS31FL3733)
    IS31FL3733_update_led_control_registers(LED_DRIVER_ADDR_1, 0);
#        if defined(LED_DRIVER_ADDR_2)
    IS31FL3733_update_led_control_registers(LED_DRIVER_ADDR_2, 1);
#            if defined(LED_DRIVER_ADDR_3)
    IS31FL3733_update_led_control_registers(LED_DRIVER_ADDR_3, 2);
#                if defined(LED_DRIVER_ADDR_4)
    IS31FL3733_update_led_control_registers(LED_DRIVER_ADDR_4, 3);
#                endif
#            endif
#        endif

#    elif defined(IS31FLCOMMON)
#        ifdef ISSI_MANUAL_SCALING
    IS31FL_set_manual_scaling_buffer();
#        endif
    IS31FL_common_update_scaling_register(DRIVER_ADDR_1, 0);
#        if defined(LED_DRIVER_ADDR_2)
    IS31FL_common_update_scaling_register(DRIVER_ADDR_2, 1);
#            if defined(LED_DRIVER_ADDR_3)
    IS31FL_common_update_scaling_register(DRIVER_ADDR_3, 2);
#                if defined(LED_DRIVER_ADDR_4)
    IS31FL_common_update_scaling_register(DRIVER_ADDR_4, 3);
#                endif
#            endif
#        endif
#    endif
}

#    if defined(IS31FL3731)
static void flush(void) {
    IS31FL3731_update_pwm_buffers(LED_DRIVER_ADDR_1, 0);
#        if defined(LED_DRIVER_ADDR_2)
    IS31FL3731_update_pwm_buffers(LED_DRIVER_ADDR_2, 1);
#            if defined(LED_DRIVER_ADDR_3)
    IS31FL3731_update_pwm_buffers(LED_DRIVER_ADDR_3, 2);
#                if defined(LED_DRIVER_ADDR_4)
    IS31FL3731_update_pwm_buffers(LED_DRIVER_ADDR_4, 3);
#                endif
#            endif
#        endif
}

const led_matrix_driver_t led_matrix_driver = {
    .init          = init,
    .flush         = flush,
    .set_value     = IS31FL3731_set_value,
    .set_value_all = IS31FL3731_set_value_all,
};

#    elif defined(IS31FL3733)
static void flush(void) {
    IS31FL3733_update_pwm_buffers(LED_DRIVER_ADDR_1, 0);
#        if defined(LED_DRIVER_ADDR_2)
    IS31FL3733_update_pwm_buffers(LED_DRIVER_ADDR_2, 1);
#            if defined(LED_DRIVER_ADDR_3)
    IS31FL3733_update_pwm_buffers(LED_DRIVER_ADDR_3, 2);
#                if defined(LED_DRIVER_ADDR_4)
    IS31FL3733_update_pwm_buffers(LED_DRIVER_ADDR_4, 3);
#                endif
#            endif
#        endif
}

const led_matrix_driver_t led_matrix_driver = {
    .init = init,
    .flush = flush,
    .set_value = IS31FL3733_set_value,
    .set_value_all = IS31FL3733_set_value_all,
};

#    elif defined(IS31FLCOMMON)
static void flush(void) {
    IS31FL_common_update_pwm_register(DRIVER_ADDR_1, 0);
#        if defined(LED_DRIVER_ADDR_2)
    IS31FL_common_update_pwm_register(DRIVER_ADDR_2, 1);
#            if defined(LED_DRIVER_ADDR_3)
    IS31FL_common_update_pwm_register(DRIVER_ADDR_3, 2);
#                if defined(LED_DRIVER_ADDR_4)
    IS31FL_common_update_pwm_register(DRIVER_ADDR_4, 3);
#                endif
#            endif
#        endif
}

const led_matrix_driver_t led_matrix_driver = {
    .init = init,
    .flush = flush,
    .set_value = IS31FL_simple_set_brightness,
    .set_value_all = IS31FL_simple_set_brigntness_all,
};
#    endif
=======
#if defined(LED_MATRIX_IS31FL3218)
const led_matrix_driver_t led_matrix_driver = {
    .init          = is31fl3218_init,
    .flush         = is31fl3218_update_pwm_buffers,
    .set_value     = is31fl3218_set_value,
    .set_value_all = is31fl3218_set_value_all,
};

#elif defined(LED_MATRIX_IS31FL3236)
const led_matrix_driver_t led_matrix_driver = {
    .init          = is31fl3236_init_drivers,
    .flush         = is31fl3236_flush,
    .set_value     = is31fl3236_set_value,
    .set_value_all = is31fl3236_set_value_all,
};

#elif defined(LED_MATRIX_IS31FL3729)
const led_matrix_driver_t led_matrix_driver = {
    .init          = is31fl3729_init_drivers,
    .flush         = is31fl3729_flush,
    .set_value     = is31fl3729_set_value,
    .set_value_all = is31fl3729_set_value_all,
};

#elif defined(LED_MATRIX_IS31FL3731)
const led_matrix_driver_t led_matrix_driver = {
    .init          = is31fl3731_init_drivers,
    .flush         = is31fl3731_flush,
    .set_value     = is31fl3731_set_value,
    .set_value_all = is31fl3731_set_value_all,
};

#elif defined(LED_MATRIX_IS31FL3733)
const led_matrix_driver_t led_matrix_driver = {
    .init          = is31fl3733_init_drivers,
    .flush         = is31fl3733_flush,
    .set_value     = is31fl3733_set_value,
    .set_value_all = is31fl3733_set_value_all,
};

#elif defined(LED_MATRIX_IS31FL3736)
const led_matrix_driver_t led_matrix_driver = {
    .init          = is31fl3736_init_drivers,
    .flush         = is31fl3736_flush,
    .set_value     = is31fl3736_set_value,
    .set_value_all = is31fl3736_set_value_all,
};

#elif defined(LED_MATRIX_IS31FL3737)
const led_matrix_driver_t led_matrix_driver = {
    .init          = is31fl3737_init_drivers,
    .flush         = is31fl3737_flush,
    .set_value     = is31fl3737_set_value,
    .set_value_all = is31fl3737_set_value_all,
};

#elif defined(LED_MATRIX_IS31FL3741)
const led_matrix_driver_t led_matrix_driver = {
    .init          = is31fl3741_init_drivers,
    .flush         = is31fl3741_flush,
    .set_value     = is31fl3741_set_value,
    .set_value_all = is31fl3741_set_value_all,
};

#elif defined(LED_MATRIX_IS31FL3742A)
const led_matrix_driver_t led_matrix_driver = {
    .init          = is31fl3742a_init_drivers,
    .flush         = is31fl3742a_flush,
    .set_value     = is31fl3742a_set_value,
    .set_value_all = is31fl3742a_set_value_all,
};

#elif defined(LED_MATRIX_IS31FL3743A)
const led_matrix_driver_t led_matrix_driver = {
    .init          = is31fl3743a_init_drivers,
    .flush         = is31fl3743a_flush,
    .set_value     = is31fl3743a_set_value,
    .set_value_all = is31fl3743a_set_value_all,
};

#elif defined(LED_MATRIX_IS31FL3745)
const led_matrix_driver_t led_matrix_driver = {
    .init          = is31fl3745_init_drivers,
    .flush         = is31fl3745_flush,
    .set_value     = is31fl3745_set_value,
    .set_value_all = is31fl3745_set_value_all,
};

#elif defined(LED_MATRIX_IS31FL3746A)
const led_matrix_driver_t led_matrix_driver = {
    .init          = is31fl3746a_init_drivers,
    .flush         = is31fl3746a_flush,
    .set_value     = is31fl3746a_set_value,
    .set_value_all = is31fl3746a_set_value_all,
};

#elif defined(LED_MATRIX_SNLED27351)
const led_matrix_driver_t led_matrix_driver = {
    .init          = snled27351_init_drivers,
    .flush         = snled27351_flush,
    .set_value     = snled27351_set_value,
    .set_value_all = snled27351_set_value_all,
};

>>>>>>> upstream/master
#endif
