<<<<<<< HEAD
ifeq ($(strip $(ISSI_ENABLE)), yes)
    TMK_COMMON_DEFS += -DISSI_ENABLE
endif

ifeq ($(strip $(WATCHDOG_ENABLE)), yes)
    TMK_COMMON_DEFS += -DWATCHDOG_ENABLE
=======
ifeq ($(strip $(WATCHDOG_ENABLE)), yes)
    OPT_DEFS += -DWATCHDOG_ENABLE
>>>>>>> upstream/master
endif
