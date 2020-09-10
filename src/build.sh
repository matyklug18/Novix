#!/bin/bash


# cleaning up after builing
rm -rf isodir/
rm niux.iso
rm boot.o
rm kernel.o
rm myos.bin
rm *.o

# build process
nasm -f aout -o start.o start.asm
gcc -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I./include -c -o kernel.o kernel.c -I./include -c -o scrn.o scrn.c
ld -T link.ld -o kernel.bin start.o

# then we test it
# qemu-system-i386 -cdrom niux.iso