# MCU name
MCU = STM32F303
<<<<<<< HEAD

BOARD = QMK_PROTON_C

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = lite     # Virtual DIP switch configuration
=======
BOARD = QMK_PROTON_C

# Bootloader selection
BOOTLOADER = stm32-dfu

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
>>>>>>> 8e9d45d2708d71cf89bed704e8e0e1bf5671804f
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = yes        # Console for debug
COMMAND_ENABLE = yes        # Commands for debug and configuration
<<<<<<< HEAD
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = yes           # USB Nkey Rollover
BLUETOOTH_ENABLE = no       # Enable Bluetooth
=======
NKRO_ENABLE = yes           # Enable N-Key Rollover
>>>>>>> 8e9d45d2708d71cf89bed704e8e0e1bf5671804f
AUDIO_ENABLE = no           # Audio output
ENCODER_ENABLE = yes
