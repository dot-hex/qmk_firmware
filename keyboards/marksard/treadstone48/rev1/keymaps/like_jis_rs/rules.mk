MOUSEKEY_ENABLE = yes       # Mouse keys

RGBLIGHT_ENABLE = yes        # Enable keyboard RGB underglow
OLED_ENABLE = yes
<<<<<<< HEAD:keyboards/marksard/treadstone48/rev1/keymaps/like_jis_rs/rules.mk
OLED_DRIVER = SSD1306
=======
>>>>>>> upstream/master:keyboards/treadstone48/rev1/keymaps/like_jis_rs/rules.mk
LTO_ENABLE = yes

# If you use connection the Rhymestone, please enable RS_EXTRA_LED
OPT_DEFS += -DRS_EXTRA_LED

# If you want to change the display of OLED, you need to change here
SRC +=  ./common/oled_helper.c \
