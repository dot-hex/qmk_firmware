# Krush60 solder

<<<<<<< HEAD
![Krush60](https://cdn.discordapp.com/attachments/898507964942536715/906171092916391956/252763374_2899749087003964_8763371038132517512_n.png)
=======
![Krush60](https://i.imgur.com/v8n2ED7h.jpeg)
>>>>>>> upstream/master

A 60% keyboard PCB made and sold by SawnsProjects with Nuxros in [Facebook](https://www.facebook.com/groups/vnmkmarket/posts/1412997345762674). 

* Keyboard Maintainer: [Mai The San](https://github.com/MaiTheSan)
* Hardware Supported: 60% keyboard case
* Hardware Availability: [Facebook](https://www.facebook.com/groups/vnmkmarket/posts/1412997345762674)

Make example for this keyboard (after setting up your build environment):

<<<<<<< HEAD
    make sawnsprojects/krush60/solder:default

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
=======
    make sawnsprojects/krush/krush60/solder:default

Flashing example for this keyboard:

    make sawnsprojects/krush/krush60/solder:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
>>>>>>> upstream/master
