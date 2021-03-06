# Makefile-include
#
# Settings for Raspbian Wheezy compile in qemu-debootstrap environment
# Hans-J. Barthen, DL5DI 2013-01-21
# Rename this file to settings.mk before you compile the source for the Raspbian platform
#
	export DATADIR := "/usr/local/etc"
	export BINDIR  := "$(DESTDIR)/usr/bin"
	export CC      := $(shell wx-config --cxx)
	export LDFLAGS := -g
	export CFLAGS  := -g -O2 -march=armv6 -mfpu=vfp -mfloat-abi=hard -Wall -Wno-non-virtual-dtor -Wno-strict-aliasing -Wno-psabi -DDATA_DIR='$(DATADIR)' -DBIN_DIR='$(BINDIR)' -D_FILE_OFFSET_BITS=64 -D_LARGE_FILES -D__WXGTK__ -pthread $(shell wx-config --cxxflags)
	export LIBS    := -lportaudio $(shell wx-config --libs adv,core)
