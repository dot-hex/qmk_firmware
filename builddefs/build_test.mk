ifndef VERBOSE
.SILENT:
endif

.DEFAULT_GOAL := all

<<<<<<< HEAD
include paths.mk
include $(BUILDDEFS_PATH)/message.mk

TARGET=test/$(TEST)
=======
OPT = g

include paths.mk
include $(BUILDDEFS_PATH)/message.mk

TARGET=test/$(TEST_OUTPUT)
>>>>>>> upstream/master

GTEST_OUTPUT = $(BUILD_DIR)/gtest

TEST_OBJ = $(BUILD_DIR)/test_obj

<<<<<<< HEAD
OUTPUTS := $(TEST_OBJ)/$(TEST) $(GTEST_OUTPUT)
=======
OUTPUTS := $(TEST_OBJ)/$(TEST_OUTPUT) $(GTEST_OUTPUT)
>>>>>>> upstream/master

GTEST_INC := \
	$(LIB_PATH)/googletest/googletest/include \
	$(LIB_PATH)/googletest/googlemock/include

GTEST_INTERNAL_INC := \
	$(LIB_PATH)/googletest/googletest \
	$(LIB_PATH)/googletest/googlemock

$(GTEST_OUTPUT)_SRC := \
	googletest/src/gtest-all.cc\
	googlemock/src/gmock-all.cc

$(GTEST_OUTPUT)_DEFS :=
$(GTEST_OUTPUT)_INC := $(GTEST_INC) $(GTEST_INTERNAL_INC)

LDFLAGS += -lstdc++ -lpthread -shared-libgcc
CREATE_MAP := no

VPATH += \
	$(LIB_PATH)/googletest \
	$(LIB_PATH)/googlemock \
<<<<<<< HEAD
	$(LIB_PATH)/printf

all: elf

VPATH += $(COMMON_VPATH)
=======
	$(COMMON_VPATH) \
	$(TEST_PATH)

all: elf

>>>>>>> upstream/master
PLATFORM:=TEST
PLATFORM_KEY:=test
BOOTLOADER_TYPE:=none

<<<<<<< HEAD
ifeq ($(strip $(DEBUG)), 1)
=======
DEBUG ?= 0
ifneq ($(strip $(DEBUG)), 0)
>>>>>>> upstream/master
CONSOLE_ENABLE = yes
endif

ifneq ($(filter $(FULL_TESTS),$(TEST)),)
include tests/test_common/build.mk
include $(TEST_PATH)/test.mk
endif

include $(BUILDDEFS_PATH)/common_features.mk
include $(BUILDDEFS_PATH)/generic_features.mk
include $(PLATFORM_PATH)/common.mk
include $(TMK_PATH)/protocol.mk
include $(QUANTUM_PATH)/debounce/tests/rules.mk
include $(QUANTUM_PATH)/encoder/tests/rules.mk
<<<<<<< HEAD
include $(QUANTUM_PATH)/sequencer/tests/rules.mk
=======
include $(QUANTUM_PATH)/os_detection/tests/rules.mk
include $(QUANTUM_PATH)/sequencer/tests/rules.mk
include $(QUANTUM_PATH)/wear_leveling/tests/rules.mk
include $(QUANTUM_PATH)/logging/print.mk
>>>>>>> upstream/master
include $(PLATFORM_PATH)/test/rules.mk
ifneq ($(filter $(FULL_TESTS),$(TEST)),)
include $(BUILDDEFS_PATH)/build_full_test.mk
endif

<<<<<<< HEAD
$(TEST)_SRC += \
	tests/test_common/main.c \
	$(LIB_PATH)/printf/printf.c \
	$(QUANTUM_PATH)/logging/print.c

$(TEST_OBJ)/$(TEST)_SRC := $($(TEST)_SRC)
$(TEST_OBJ)/$(TEST)_INC := $($(TEST)_INC) $(VPATH) $(GTEST_INC)
$(TEST_OBJ)/$(TEST)_DEFS := $($(TEST)_DEFS)
$(TEST_OBJ)/$(TEST)_CONFIG := $($(TEST)_CONFIG)
=======
$(TEST_OUTPUT)_SRC += \
	tests/test_common/main.cpp \
	$(QUANTUM_PATH)/logging/print.c

ifneq ($(strip $(INTROSPECTION_KEYMAP_C)),)
$(TEST_OUTPUT)_DEFS += -DINTROSPECTION_KEYMAP_C=\"$(strip $(INTROSPECTION_KEYMAP_C))\"
endif

$(TEST_OBJ)/$(TEST_OUTPUT)_SRC := $($(TEST_OUTPUT)_SRC)
$(TEST_OBJ)/$(TEST_OUTPUT)_INC := $($(TEST_OUTPUT)_INC) $(VPATH) $(GTEST_INC)
$(TEST_OBJ)/$(TEST_OUTPUT)_DEFS := $($(TEST_OUTPUT)_DEFS)
$(TEST_OBJ)/$(TEST_OUTPUT)_CONFIG := $($(TEST_OUTPUT)_CONFIG)
>>>>>>> upstream/master

include $(PLATFORM_PATH)/$(PLATFORM_KEY)/platform.mk
include $(BUILDDEFS_PATH)/common_rules.mk


$(shell mkdir -p $(BUILD_DIR)/test 2>/dev/null)
$(shell mkdir -p $(TEST_OBJ) 2>/dev/null)
