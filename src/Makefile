.DEFAULT_GOAL := all

clean:
	rm -rf isodir
	rm -f *.o *.iso *.bin

kernel: kernel.c
	$(GCC) -c kernel.c -o $(BUILD_DIR)/kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

gdt: gdt.c
	$(GCC) -c gdt.c -o $(BUILD_DIR)/gdt_2.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

boot: boot.s
	$(ASSEMBLER) boot.s -o $(BUILD_DIR)/boot.o

idt: idt.c
	$(GCC) -c idt.c -o $(BUILD_DIR)/idt_2.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

asm: gdt.asm idt.asm
	nasm -f elf gdt.asm -o $(BUILD_DIR)/gdt.o
	nasm -f elf idt.asm -o $(BUILD_DIR)/idt.o

build: kernel gdt boot idt asm
	mkdir -p $(BUILD_DIR)
	$(GCC) \
		-o $(BUILD_DIR)/novix.bin \
		-T linker.ld \
		-ffreestanding -O2 -nostdlib \
		-lgcc \
		$(BUILD_DIR)/boot.o \
		$(BUILD_DIR)/gdt.o \
		$(BUILD_DIR)/gdt_2.o \
		$(BUILD_DIR)/idt.o \
		$(BUILD_DIR)/idt_2.o \
		$(BUILD_DIR)/kernel.o

iso: build
	mkdir -p $(BUILD_DIR)/isodir/boot/grub
	cp grub.cfg $(BUILD_DIR)/isodir/boot/grub/grub.cfg
	cp novix.bin $(BUILD_DIR)/isodir/boot/novix.bin
	$(MKRESCUE) -o $(BUILD_DIR)/novix.iso $(BUILD_DIR)/isodir

all: iso
