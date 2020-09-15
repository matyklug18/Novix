#!/bin/bash


# first we clean up
rm -rf isodir
rm *.o *.iso *.bin

# then we can compile

# boot.s
../i686-elf-cross/bin/i686-elf-as boot.s -o boot.o

# kernel.c
../i686-elf-cross/bin/i686-elf-gcc -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

# gdt.c
../i686-elf-cross/bin/i686-elf-gcc -c gdt.c -o gdt_2.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

# gdt.asm
nasm -f elf gdt.asm

# linking it
../i686-elf-cross/bin/i686-elf-gcc -T linker.ld -o niux.bin -ffreestanding -O2 -nostdlib boot.o gdt.o gdt_2.o kernel.o -lgcc


# show that it was compiled
echo Compiled Niux Kernel...Now building iso

sleep 3

# kernel time
mkdir -p isodir/boot/grub
cp grub.cfg isodir/boot/grub/grub.cfg
cp niux.bin isodir/boot/niux.bin
grub-mkrescue -o niux.iso isodir
