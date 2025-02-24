CUSTOM_MATRIX = yes

<<<<<<< HEAD
# Bootloader selection
BOOTLOADER = caterina

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
#MOUSEKEY_ENABLE  = yes  # Mouse keys
EXTRAKEY_ENABLE  = yes  # Audio control and System control
#CONSOLE_ENABLE   = yes  # Console for debug
#COMMAND_ENABLE   = yes  # Commands for debug and configuration
NKRO_ENABLE = no            # Enable N-Key Rollover
#BACKLIGHT_ENABLE = yes
USB_HID_ENABLE   = yes
CUSTOM_MATRIX    = yes

SRC = custom_matrix.cpp
=======
SRC += custom_matrix.cpp
>>>>>>> upstream/master

DEFAULT_FOLDER = converter/usb_usb/hasu
