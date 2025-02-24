<<<<<<< HEAD
# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = atmel-dfu

=======
>>>>>>> upstream/master
# Build Options
#   change yes to no to disable
#
CUSTOM_MATRIX 		= yes
<<<<<<< HEAD
EXTRAKEY_ENABLE		= yes
CONSOLE_ENABLE  	= yes
COMMAND_ENABLE		= yes
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite

DEBOUNCE_TYPE = sym_eager_pr
SRC += matrix.c
QUANTUM_LIB_SRC += i2c_master.c
=======

SRC += matrix.c
I2C_DRIVER_REQUIRED = yes
>>>>>>> upstream/master
