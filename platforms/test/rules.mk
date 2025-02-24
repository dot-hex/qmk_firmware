<<<<<<< HEAD
eeprom_stm32_DEFS  := -DEEPROM_TEST_HARNESS -DFLASH_STM32_MOCKED -DNO_PRINT -DFEE_FLASH_BASE=FlashBuf
eeprom_stm32_tiny_DEFS := $(eeprom_stm32_DEFS) \
=======
eeprom_legacy_emulated_flash_DEFS  := -DEEPROM_TEST_HARNESS -DLEGACY_FLASH_OPS_MOCKED -DNO_PRINT -DFEE_FLASH_BASE=FlashBuf
eeprom_legacy_emulated_flash_tiny_DEFS := $(eeprom_legacy_emulated_flash_DEFS) \
>>>>>>> upstream/master
	-DFEE_MCU_FLASH_SIZE=1 \
	-DMOCK_FLASH_SIZE=1024 \
	-DFEE_PAGE_SIZE=512 \
	-DFEE_PAGE_COUNT=1
<<<<<<< HEAD
eeprom_stm32_large_DEFS := $(eeprom_stm32_DEFS) \
=======
eeprom_legacy_emulated_flash_large_DEFS := $(eeprom_legacy_emulated_flash_DEFS) \
>>>>>>> upstream/master
	-DFEE_MCU_FLASH_SIZE=64 \
	-DMOCK_FLASH_SIZE=65536 \
	-DFEE_PAGE_SIZE=2048 \
	-DFEE_PAGE_COUNT=16

<<<<<<< HEAD
eeprom_stm32_INC := \
	$(PLATFORM_PATH)/chibios/
eeprom_stm32_tiny_INC := $(eeprom_stm32_INC)
eeprom_stm32_large_INC := $(eeprom_stm32_INC)

eeprom_stm32_SRC := \
	$(TOP_DIR)/drivers/eeprom/eeprom_driver.c \
	$(PLATFORM_PATH)/$(PLATFORM_KEY)/eeprom_stm32_tests.cpp \
	$(PLATFORM_PATH)/$(PLATFORM_KEY)/flash_stm32_mock.c \
	$(PLATFORM_PATH)/chibios/eeprom_stm32.c
eeprom_stm32_tiny_SRC := $(eeprom_stm32_SRC)
eeprom_stm32_large_SRC := $(eeprom_stm32_SRC)
=======
eeprom_legacy_emulated_flash_INC := \
	$(PLATFORM_PATH)/chibios/drivers/eeprom/ \
	$(PLATFORM_PATH)/chibios/drivers/flash/
eeprom_legacy_emulated_flash_tiny_INC := $(eeprom_legacy_emulated_flash_INC)
eeprom_legacy_emulated_flash_large_INC := $(eeprom_legacy_emulated_flash_INC)

eeprom_legacy_emulated_flash_SRC := \
	$(TOP_DIR)/drivers/eeprom/eeprom_driver.c \
	$(PLATFORM_PATH)/$(PLATFORM_KEY)/eeprom_legacy_emulated_flash_tests.cpp \
	$(PLATFORM_PATH)/$(PLATFORM_KEY)/legacy_flash_ops_mock.c \
	$(PLATFORM_PATH)/chibios/drivers/eeprom/eeprom_legacy_emulated_flash.c
eeprom_legacy_emulated_flash_tiny_SRC := $(eeprom_legacy_emulated_flash_SRC)
eeprom_legacy_emulated_flash_large_SRC := $(eeprom_legacy_emulated_flash_SRC)
>>>>>>> upstream/master
