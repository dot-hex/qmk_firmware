# custom bootloader
BOARD = ST_STM32F072B_DISCOVERY
MCU_LDSCRIPT = STM32F072_0x2000_bootloader

# Bootloader selection
BOOTLOADER = custom

DFU_ARGS = -d 0483:df11 -a 0 -s 0x08002000:leave
DFU_SUFFIX_ARGS = -v 0483 -p DF11
<<<<<<< HEAD

BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no	# Mouse keys
EXTRAKEY_ENABLE = no	# Audio control and System control
CONSOLE_ENABLE = no	# Console for debug
COMMAND_ENABLE = no    # Commands for debug and configuration
NKRO_ENABLE = no            # Enable N-Key Rollover
# BACKLIGHT_ENABLE = yes # This is broken on 072 for some reason
RGBLIGHT_ENABLE = no
=======
>>>>>>> upstream/master
