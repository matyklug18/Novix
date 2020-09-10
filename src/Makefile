test:
	nasm -f elf32 -o start.o start.asm
	gcc  -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I./include -c -o kernel.o kernel.c -m32
	gcc  -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I./include -c -o scrn.o scrn.c -m32
	ld -T linker.ld -o Kernel.bin kernel.o start.o -m elf_i386