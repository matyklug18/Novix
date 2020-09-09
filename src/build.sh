#!/bin/bash


# cleaning up after builing
rm -rf isodir/
rm niux.iso
rm boot.o
rm kernel.o
rm myos.bin

# build process
../i686-elf-cross/bin/i686-elf-as boot.s -o boot.o
../i686-elf-cross/bin/i686-elf-gcc -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
../i686-elf-cross/bin/i686-elf-gcc -T linker.ld -o myos.bin -ffreestanding -O2 -nostdlib boot.o kernel.o -lgcc
mkdir -p isodir/boot/grub
cp myos.bin isodir/boot/myos.bin
cp grub.cfg isodir/boot/grub/grub.cfg
grub-mkrescue -o niux.iso isodir