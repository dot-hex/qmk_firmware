# BINEPAD BN009

![BINEPAD BN009](https://imgur.com/fu0iXD0h.jpg)

A 9% macropad.

<<<<<<< HEAD
* Keyboard Maintainer: [BINEPAD]
* Hardware Supported: BN009 PCB (ATmega32U4)
* Hardware Availability: [Interest Check](https://www.binepad.com/bn009)

**Physical reset button**: There's a small hole at the bottom of macropad. Use the reset pin provided in box and push it hard through the hole, so that it press the reset button on  pcb.

Make example for this keyboard (after setting up your build environment):

    make binepad/bn009:default

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
=======
* Keyboard Maintainer: [binepad](https://github.com/binepad)
* Hardware Supported:
    * BN009 R1 *(ft. ATmega32U4)*
    * BN009 R2 *(ft. STM32F103)*
* Hardware Availability: [binepad.com](https://www.binepad.com/bn009)

Make example for this keyboard (after setting up your build environment):

    make binepad/bn009/r1:default

..or..

    make binepad/bn009/r2:default

Flashing example for this keyboard:

    make binepad/bn009/r1:default:flash

..or..

    make binepad/bn009/r2:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information.
Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key) and plug in the keyboard
* **Physical reset button**: Briefly press the button under the small hole on the back of the macropad
* **Keycode in layout**: Press the key mapped to `QK_BOOT` or `RESET` if it is available
>>>>>>> upstream/master
