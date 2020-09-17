.DEFAULT_GOAL := bad

bad:
	$(error "Please run make from the repo root.")

clean:
	rm -rf isodir
	rm -f *.o *.iso *.bin

asm: gdt.asm idt.asm isr.asm memset.asm
	nasm -f elf gdt.asm -o $(BUILD_DIR)/gdt.o
	nasm -f elf idt.asm -o $(BUILD_DIR)/idt.o
	nasm -f elf memset.asm -o $(BUILD_DIR)/memset.o
	nasm -f elf isr.asm -o $(BUILD_DIR)/isr.o

build: asm
	$(GCC) \
		-o $(BUILD_DIR)/novavita.bin \
		-z -T linker.ld \
		-nostdlib \
		-ffreestanding -O2 -Wall -Wextra -Wreturn-value \
		$(BUILD_DIR)/gdt.o \
		$(BUILD_DIR)/idt.o \
		$(BUILD_DIR)/memset.o \
		$(BUILD_DIR)/isr.o \
		gdt.cpp \
		io.cpp \
		terminal.cpp \
		kernel.cpp \
		boot.s

iso: build
	mkdir -p $(BUILD_DIR)/isodir/boot/grub
	cp grub.cfg $(BUILD_DIR)/isodir/boot/grub/grub.cfg
	cp $(BUILD_DIR)/novavita.bin $(BUILD_DIR)/isodir/boot/novavita.bin
	$(MKRESCUE) -o $(BUILD_DIR)/novavita.iso $(BUILD_DIR)/isodir

all: iso
