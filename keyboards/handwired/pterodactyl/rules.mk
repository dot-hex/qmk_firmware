# Processor frequency
F_CPU = 8000000

<<<<<<< HEAD
# Bootloader selection
BOOTLOADER = caterina

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no        # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = yes        # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output
UNICODE_ENABLE = yes
=======
>>>>>>> upstream/master
CUSTOM_MATRIX = yes
BLUETOOTH_ENABLE = yes
BLUETOOTH_DRIVER = BluefruitLE

SRC += matrix.c
I2C_DRIVER_REQUIRED = yes
