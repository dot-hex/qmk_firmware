<<<<<<< HEAD
<<<<<<< HEAD:quantum/digitizer.h
/* Copyright 2021
=======
/* Copyright 2020 Richard Sutherland <rich@brickbots.com>
>>>>>>> upstream/master:keyboards/molecule/adns.h
=======
/* Copyright 2021
>>>>>>> upstream/master
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
#pragma once

#include "quantum.h"

#include <stdint.h>

<<<<<<< HEAD:quantum/digitizer.h
enum digitizer_status { DZ_INITIALIZED = 1, DZ_UPDATED = 2 };

typedef struct {
    int8_t  tipswitch;
    int8_t  inrange;
    uint8_t id;
    float   x;
    float   y;
    uint8_t status : 2;
} digitizer_t;

extern digitizer_t digitizer;

digitizer_t digitizer_get_report(void);

void digitizer_set_report(digitizer_t newDigitizerReport);

void digitizer_task(void);

void host_digitizer_send(digitizer_t *digitizer);
=======
void adns_begin(void);

void adns_end(void);

void adns_write(uint8_t reg_addr, uint8_t data);

uint8_t adns_read(uint8_t reg_addr);


int16_t convertDeltaToInt(uint8_t high, uint8_t low);

struct _motion_delta {
    int16_t delta_x;
    int16_t delta_y;
    int8_t motion_ind;
};
typedef struct _motion_delta motion_delta_t;

motion_delta_t readSensor(void);
>>>>>>> upstream/master:keyboards/molecule/adns.h
=======

#pragma once

#include <stdbool.h>

/**
 * \file
 *
 * defgroup digitizer HID Digitizer
 * \{
 */

typedef struct {
    bool  in_range : 1;
    bool  tip : 1;
    bool  barrel : 1;
    float x;
    float y;
    bool  dirty;
} digitizer_t;

extern digitizer_t digitizer_state;

/**
 * \brief Send the digitizer report to the host if it is marked as dirty.
 */
void digitizer_flush(void);

/**
 * \brief Assert the "in range" indicator, and flush the report.
 */
void digitizer_in_range_on(void);

/**
 * \brief Deassert the "in range" indicator, and flush the report.
 */
void digitizer_in_range_off(void);

/**
 * \brief Assert the tip switch, and flush the report.
 */
void digitizer_tip_switch_on(void);

/**
 * \brief Deassert the tip switch, and flush the report.
 */
void digitizer_tip_switch_off(void);

/**
 * \brief Assert the barrel switch, and flush the report.
 */
void digitizer_barrel_switch_on(void);

/**
 * \brief Deassert the barrel switch, and flush the report.
 */
void digitizer_barrel_switch_off(void);

/**
 * \brief Set the absolute X and Y position of the digitizer contact, and flush the report.
 *
 * \param x The X value of the contact position, from 0 to 1.
 * \param y The Y value of the contact position, from 0 to 1.
 */
void digitizer_set_position(float x, float y);

void host_digitizer_send(digitizer_t *digitizer);

/** \} */
>>>>>>> upstream/master
