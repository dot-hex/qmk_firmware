# MCU name
MCU = atmega32a

# Processor frequency
F_CPU = 16000000

# Bootloader selection
<<<<<<< HEAD
BOOTLOADER = bootloadHID
=======
BOOTLOADER = usbasploader
>>>>>>> 8e9d45d2708d71cf89bed704e8e0e1bf5671804f

# Build Options
#   change yes to no to disable
#
<<<<<<< HEAD
BOOTMAGIC_ENABLE = lite     # Virtual DIP switch configuration
=======
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
>>>>>>> 8e9d45d2708d71cf89bed704e8e0e1bf5671804f
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
<<<<<<< HEAD
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = no            # USB Nkey Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
BLUETOOTH_ENABLE = no       # Enable Bluetooth
=======
NKRO_ENABLE = no            # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
>>>>>>> 8e9d45d2708d71cf89bed704e8e0e1bf5671804f
AUDIO_ENABLE = no           # Audio output
