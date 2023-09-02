.SILENT:

MAKEFLAGS += --no-print-directory

OVERLAY_DIR := $(patsubst %/,%,$(dir $(shell realpath "$(lastword $(MAKEFILE_LIST))")))
ifeq ($(OVERLAY_DIR),)
    OVERLAY_DIR := $(shell pwd)
endif

%:
	+$(MAKE) -C $(shell qmk config -ro user.qmk_home | cut -d= -f2) $(MAKECMDGOALS) QMK_USERSPACE=$(OVERLAY_DIR)