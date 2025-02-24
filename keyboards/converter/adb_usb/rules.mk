CUSTOM_MATRIX = yes

<<<<<<< HEAD
# Bootloader selection
BOOTLOADER = caterina

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE  = no   # Mouse keys
CONSOLE_ENABLE   = no   # Console for debug
COMMAND_ENABLE   = no   # Commands for debug and configuration
NKRO_ENABLE = no            # Enable N-Key Rollover
EXTRAKEY_ENABLE  = yes
USB_HID_ENABLE   = yes
BACKLIGHT_ENABLE = no
CUSTOM_MATRIX    = yes

SRC = matrix.c adb.c led.c

# ADB_MOUSE_ENABLE
# OPT_DEFS += -DADB_MOUSE_ENABLE -DMOUSE_ENABLE
=======
SRC += matrix.c adb.c led.c

# OPT_DEFS += -DADB_MOUSE_ENABLE -DMOUSE_ENABLE

DEFAULT_FOLDER = converter/adb_usb/rev1
>>>>>>> upstream/master
