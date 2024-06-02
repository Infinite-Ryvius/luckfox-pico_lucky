
ifeq ($(SYSDRV_PARAM), )
    SYSDRV_PARAM:=../../../Makefile.param
    include $(SYSDRV_PARAM)
endif

export LC_ALL=C
SHELL:=/bin/bash
# arch=arm default use thumb-2 compile
ifeq ($(SYSDRV_ARCH_TYPE),arm)
PKG_USE_THUMB2 ?= YES
endif

CURRENT_DIR := $(shell pwd)

ifeq ($(shell pkg-config --version),)
$(info ***************************)
$(info Please Install pkg-config tool)
$(info sudo apt-get install pkg-config)
$(error ***************************)
endif

PKG_TARBALL_EUDEV := eudev-3.2.7.tar.gz
PKG_NAME_EUDEV := eudev-3.2.7
PKG_PATCHES_EUDEV := eudev-patches

PKG_TARBALL_KMOD := kmod-29.tar.xz
PKG_NAME_KMOD := kmod-29
PKG_PATCHES_KMOD := kmod-26-patches

PKG_TARBALL_UTIL_LINUX := util-linux-2.37.2.tar.xz
PKG_NAME_UTIL_LINUX := util-linux-2.37.2
PKG_PATCHES_UTIL_LINUX := util-linux-2.37.2-patches

PKG_BIN := out

PKG_CONF_OPTS += $(SYSDRV_OPTS) -Os -I$(CURRENT_DIR)/$(PKG_BIN)/include -L$(CURRENT_DIR)/$(PKG_BIN)/lib

ifeq ($(PKG_USE_THUMB2),YES)
PKG_CONF_OPTS += -mthumb -Wa,-mimplicit-it=thumb -mthumb-interwork
endif

all:
	@mkdir -p $(CURRENT_DIR)/$(PKG_BIN)/etc/init.d ;
	@cp -f S01own $(CURRENT_DIR)/$(PKG_BIN)/etc/init.d
	$(call MAROC_COPY_PKG_TO_SYSDRV_OUTPUT, $(SYSDRV_DIR_OUT_ROOTFS), $(CURRENT_DIR)/$(PKG_BIN))

clean: distclean

distclean:
	@rm -rf $(CURRENT_DIR)/$(PKG_BIN)
