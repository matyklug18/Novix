clean:
		rm -rf isodir
		rm *.o *.iso *.bin


build:
	../i686-elf-cross/bin/i686-elf-as boot.s -o boot.o
	../i686-elf-cross/bin/i686-elf-gcc -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	../i686-elf-cross/bin/i686-elf-gcc -c gdt.c -o gdt_2.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	../i686-elf-cross/bin/i686-elf-gcc -c idt.c -o idt_2.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	nasm -f elf gdt.asm
	nasm -f elf idt.asm
	../i686-elf-cross/bin/i686-elf-gcc -T linker.ld -o novix.bin -ffreestanding -O2 -nostdlib boot.o gdt.o gdt_2.o idt.o idt_2.o kernel.o -lgcc

iso:
	mkdir -p isodir/boot/grub
	cp grub.cfg isodir/boot/grub/grub.cfg
	cp novix.bin isodir/boot/novix.bin
	grub-mkrescue -o novix.iso isodir
