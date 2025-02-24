/*  Copyright (C) 2019 Elia Ritterbusch
 +
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
/* Library made by: g4lvanix
 * GitHub repository: https://github.com/g4lvanix/I2C-master-lib
 */

#pragma once

#include <stdint.h>

// ### DEPRECATED - DO NOT USE ###
#define i2c_writeReg(devaddr, regaddr, data, length, timeout) i2c_write_register(devaddr, regaddr, data, length, timeout)
#define i2c_writeReg16(devaddr, regaddr, data, length, timeout) i2c_write_register16(devaddr, regaddr, data, length, timeout)
#define i2c_readReg(devaddr, regaddr, data, length, timeout) i2c_read_register(devaddr, regaddr, data, length, timeout)
#define i2c_readReg16(devaddr, regaddr, data, length, timeout) i2c_read_register16(devaddr, regaddr, data, length, timeout)
// ###############################

#define I2C_READ 0x01
#define I2C_WRITE 0x00

typedef int16_t i2c_status_t;

#define I2C_STATUS_SUCCESS (0)
#define I2C_STATUS_ERROR (-1)
#define I2C_STATUS_TIMEOUT (-2)

#define I2C_TIMEOUT_IMMEDIATE (0)
#define I2C_TIMEOUT_INFINITE (0xFFFF)

void         i2c_init(void);
i2c_status_t i2c_transmit(uint8_t address, const uint8_t* data, uint16_t length, uint16_t timeout);
i2c_status_t i2c_transmit_P(uint8_t address, const uint8_t* data, uint16_t length, uint16_t timeout);
i2c_status_t i2c_receive(uint8_t address, uint8_t* data, uint16_t length, uint16_t timeout);
<<<<<<< HEAD:platforms/avr/drivers/i2c_master.h
i2c_status_t i2c_writeReg(uint8_t devaddr, uint8_t regaddr, const uint8_t* data, uint16_t length, uint16_t timeout);
i2c_status_t i2c_writeReg16(uint8_t devaddr, uint16_t regaddr, const uint8_t* data, uint16_t length, uint16_t timeout);
i2c_status_t i2c_readReg(uint8_t devaddr, uint8_t regaddr, uint8_t* data, uint16_t length, uint16_t timeout);
i2c_status_t i2c_readReg16(uint8_t devaddr, uint16_t regaddr, uint8_t* data, uint16_t length, uint16_t timeout);
void         i2c_stop(void);
=======
i2c_status_t i2c_write_register(uint8_t devaddr, uint8_t regaddr, const uint8_t* data, uint16_t length, uint16_t timeout);
i2c_status_t i2c_write_register16(uint8_t devaddr, uint16_t regaddr, const uint8_t* data, uint16_t length, uint16_t timeout);
i2c_status_t i2c_read_register(uint8_t devaddr, uint8_t regaddr, uint8_t* data, uint16_t length, uint16_t timeout);
i2c_status_t i2c_read_register16(uint8_t devaddr, uint16_t regaddr, uint8_t* data, uint16_t length, uint16_t timeout);
i2c_status_t i2c_ping_address(uint8_t address, uint16_t timeout);
>>>>>>> upstream/master:drivers/avr/i2c_master.h
