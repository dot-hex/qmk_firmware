CUSTOM_MATRIX = lite

<<<<<<< HEAD
# Bootloader selection
BOOTLOADER = atmel-dfu

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no        # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = yes       # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output
ENCODER_ENABLE = yes        # Use rotary encoder
LTO_ENABLE = yes            # Link-time optimization
CUSTOM_MATRIX = lite        # Lite custom matrix
=======
UART_DRIVER_REQUIRED = yes
>>>>>>> upstream/master

# Project specific files
SRC += matrix.c \
       common/bitc_led.c \
       big_led.c \
       common/remote_kb.c
<<<<<<< HEAD
QUANTUM_LIB_SRC += uart.c
=======
>>>>>>> upstream/master
