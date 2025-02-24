# custom bootloader
MCU_LDSCRIPT = noah_boot
BOARD = ST_NUCLEO64_F411RE

<<<<<<< HEAD
# Bootloader selection
BOOTLOADER = custom

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes	    # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = no            # Enable N-Key Rollover
NO_USB_STARTUP_CHECK = yes	# Disable initialization only when usb is plugged in

RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = IS31FL3731

RGBLIGHT_ENABLE = yes
RGBLIGHT_CUSTOM_DRIVER = yes
=======
WS2812_DRIVER_REQUIRED = yes
>>>>>>> upstream/master

CUSTOM_MATRIX = yes
# project specific files
SRC += matrix.c
