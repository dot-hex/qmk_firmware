<<<<<<< HEAD
# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = atmel-dfu

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no        # Console for debug
COMMAND_ENABLE = no        # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
AUDIO_ENABLE = no           # Audio output
=======
>>>>>>> upstream/master
CIE1931_CURVE = yes
I2C_DRIVER_REQUIRED = yes

# project specific files
SRC =	keyboards/wilba_tech/wt_main.c \
		keyboards/wilba_tech/wt_rgb_backlight.c \
		quantum/color.c \
<<<<<<< HEAD
		drivers/led/issi/is31fl3731.c \
		i2c_master.c
=======
		drivers/led/issi/is31fl3731.c
>>>>>>> upstream/master
