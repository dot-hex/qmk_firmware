# Processor frequency
F_CPU = 8000000

<<<<<<< HEAD
# Bootloader selection
BOOTLOADER = caterina

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = yes        # Console for debug
COMMAND_ENABLE = yes        # Commands for debug and configuration
NKRO_ENABLE = no            # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output
CUSTOM_MATRIX = yes
DEBUG_ENABLE = yes
BLUETOOTH_ENABLE = yes
BLUETOOTH_DRIVER = BluefruitLE

=======
CUSTOM_MATRIX = yes
>>>>>>> upstream/master
SRC += matrix.c mcp23017.c
