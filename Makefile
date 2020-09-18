.DEFAULT_GOAL := all

MKRESCUE = grub-mkrescue

ifeq (, $(shell which grub-mkrescue 2>/dev/null))
	ifeq (, $(shell which grub2-mkrescue 2>/dev/null))
		$(error "No grub-mkrescue or grub2-mkrescue in $(PATH)")
	else
		MKRESCUE = grub2-mkrescue
	endif
endif

ROOT_DIR := $(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))
BUILD_DIR := $(ROOT_DIR)/_build
GCC := clang --target=i686-pc-none-elf -march=i686

export MKRESCUE
export GCC
export BUILD_DIR

all: clean
	mkdir -p $(BUILD_DIR)
	$(MAKE) -C src all

qemu: all
	qemu-system-i386 $(BUILD_DIR)/novavita.iso -m 1G

clean:
	rm _build/ -rv
