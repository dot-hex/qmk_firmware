// Copyright (c) 2018 Cirque Corp. Restrictions apply. See: www.cirque.com/sw-license
#include "cirque_pinnacle.h"
#include "spi_master.h"
<<<<<<< HEAD
#include "print.h"
#include "debug.h"
=======
>>>>>>> upstream/master

// Masks for Cirque Register Access Protocol (RAP)
#define WRITE_MASK 0x80
#define READ_MASK 0xA0
<<<<<<< HEAD
=======
#define FILLER_BYTE 0xFC
>>>>>>> upstream/master

extern bool touchpad_init;

/*  RAP Functions */
// Reads <count> Pinnacle registers starting at <address>
void RAP_ReadBytes(uint8_t address, uint8_t* data, uint8_t count) {
    uint8_t cmdByte = READ_MASK | address; // Form the READ command byte
    if (touchpad_init) {
        if (spi_start(CIRQUE_PINNACLE_SPI_CS_PIN, CIRQUE_PINNACLE_SPI_LSBFIRST, CIRQUE_PINNACLE_SPI_MODE, CIRQUE_PINNACLE_SPI_DIVISOR)) {
<<<<<<< HEAD
            spi_write(cmdByte);
            spi_read(); // filler
            spi_read(); // filler
            for (uint8_t i = 0; i < count; i++) {
                data[i] = spi_read(); // each sepsequent read gets another register's contents
            }
        } else {
#ifdef CONSOLE_ENABLE
            dprintf("error right touchpad\n");
#endif
=======
            spi_write(cmdByte);     // write command byte, receive filler
            spi_write(FILLER_BYTE); // write & receive filler
            spi_write(FILLER_BYTE); // write & receive filler
            for (uint8_t i = 0; i < count; i++) {
                data[i] = spi_write(FILLER_BYTE); // write filler, receive data on the third filler send
            }
        } else {
            pd_dprintf("error cirque_pinnacle spi_start read\n");
>>>>>>> upstream/master
            touchpad_init = false;
        }
        spi_stop();
    }
}

// Writes single-byte <data> to <address>
void RAP_Write(uint8_t address, uint8_t data) {
    uint8_t cmdByte = WRITE_MASK | address; // Form the WRITE command byte

    if (touchpad_init) {
        if (spi_start(CIRQUE_PINNACLE_SPI_CS_PIN, CIRQUE_PINNACLE_SPI_LSBFIRST, CIRQUE_PINNACLE_SPI_MODE, CIRQUE_PINNACLE_SPI_DIVISOR)) {
            spi_write(cmdByte);
            spi_write(data);
        } else {
<<<<<<< HEAD
#ifdef CONSOLE_ENABLE
            dprintf("error right touchpad\n");
#endif
=======
            pd_dprintf("error cirque_pinnacle spi_start write\n");
>>>>>>> upstream/master
            touchpad_init = false;
        }
        spi_stop();
    }
}
