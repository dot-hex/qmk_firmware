PLATFORM_COMMON_DIR = $(PLATFORM_PATH)/$(PLATFORM_KEY)

<<<<<<< HEAD
TMK_COMMON_SRC +=	\
	$(PLATFORM_PATH)/suspend.c \
=======
SRC +=	\
	$(PLATFORM_PATH)/suspend.c \
	$(PLATFORM_PATH)/synchronization_util.c \
	$(PLATFORM_PATH)/timer.c \
	$(PLATFORM_COMMON_DIR)/hardware_id.c \
>>>>>>> upstream/master
	$(PLATFORM_COMMON_DIR)/platform.c \
	$(PLATFORM_COMMON_DIR)/suspend.c \
	$(PLATFORM_COMMON_DIR)/timer.c \
	$(PLATFORM_COMMON_DIR)/bootloaders/$(BOOTLOADER_TYPE).c

# Search Path
VPATH += $(PLATFORM_PATH)
VPATH += $(PLATFORM_PATH)/$(PLATFORM_KEY)
VPATH += $(PLATFORM_PATH)/$(PLATFORM_KEY)/$(DRIVER_DIR)
