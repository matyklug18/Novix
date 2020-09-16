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
ASSEMBLER := $(ROOT_DIR)/i686-elf-cross/bin/i686-elf-as
GCC := $(ROOT_DIR)/i686-elf-cross/bin/i686-elf-gcc

export MKRESCUE
export ASSEMBLER
export GCC
export BUILD_DIR

all:
	$(MAKE) -C src all
