<<<<<<< HEAD
MCU = atmega32u4

BOOTLOADER = atmel-dfu

CUSTOM_MATRIX    = yes
MOUSEKEY_ENABLE  = yes  # Mouse keys
COMBO_ENABLE     = yes
EXTRAKEY_ENABLE  = yes
CONSOLE_ENABLE   = no
NKRO_ENABLE = yes           # Enable N-Key Rollover
COMMAND_ENABLE   = yes
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite

LAYOUTS = split_3x5_3

DEBOUNCE_TYPE = sym_eager_pr
SRC += matrix.c
QUANTUM_LIB_SRC += i2c_master.c
=======
# Build Options
#   change yes to no to disable
#
CUSTOM_MATRIX = yes

SRC += matrix.c
I2C_DRIVER_REQUIRED = yes
>>>>>>> upstream/master
