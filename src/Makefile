test:
	nasm -f aout -o start.o start.asm
	gcc -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I./include -c -o kernel.o kernel.c 
	gcc -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I./include -c -o scrn.o scrn.c
	ld -T linker.ld -o kernel.bin start.o