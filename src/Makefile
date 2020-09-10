test:
	nasm -f elf32 -o start.o start.asm
	gcc  -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I./include -c -o kernel.o kernel.c -m32
	gcc  -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I./include -c -o scrn.o scrn.c -m32
	gcc  -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I./include -c -o gdt.o gdt.c -m32
	gcc  -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I./include -c -o idt.o idt.c -m32
	ld -T linker.ld -o kernel.bin kernel.o start.o gdt.o idt.o -m elf_i386

clean_up:
	rm *.o
	rm *.bin
	rm *.iso
	rm -rf isodir

run:
	rm -rf isodir
	mkdir -p isodir/boot/grub
	cp kernel.bin isodir/boot/kernel.bin
	cp grub.cfg isodir/boot/grub/grub.cfg
	grub-mkrescue -o niux.iso isodir