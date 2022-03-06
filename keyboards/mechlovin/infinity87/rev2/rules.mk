# MCU name
<<<<<<< HEAD
MCU = atmega32a

# Processor frequency
F_CPU = 16000000

# Bootloader selection
BOOTLOADER = bootloadHID
=======
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = atmel-dfu
>>>>>>> 8e9d45d2708d71cf89bed704e8e0e1bf5671804f

# Build Options
#   change yes to no to disable
#
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
<<<<<<< HEAD
NKRO_ENABLE = no
BACKLIGHT_ENABLE = yes
=======
NKRO_ENABLE = yes           # Enable N-Key Rollover
BACKLIGHT_ENABLE = yes
RGBLIGHT_ENABLE = yes
>>>>>>> 8e9d45d2708d71cf89bed704e8e0e1bf5671804f
CUSTOM_MATRIX = lite

SRC += matrix.c
