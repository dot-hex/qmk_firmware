<<<<<<< HEAD
# MCU name
MCU = STM32F103

# Bootloader selection
BOOTLOADER = stm32duino

SRC = matrix.c

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes   # Mouse keys
EXTRAKEY_ENABLE = yes   # Audio control and System control
CONSOLE_ENABLE = yes    # Console for debug
COMMAND_ENABLE = yes    # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover
BACKLIGHT_ENABLE = no
RGBLIGHT_ENABLE = no
SLEEP_LED_ENABLE = yes
=======
>>>>>>> upstream/master
CUSTOM_MATRIX = yes
SRC = matrix.c
