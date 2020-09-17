# Nova Vita

Nova Vita is a new operating system to bring a new life to computing.

# Requirements

Nova Vita requires the following things to be built:

- GNU Make
- Clang with cross compilation targets supported
- grub-mkrescue or grub2-mkrescue
- Xorriso
- NASM
- GNU Binutils

If you are on Arch Linux, you can use the novix-devel-meta AUR package to install these things.
# Building

### NixOS

Run the `nix-make.sh` script. 

### Make

Run `make` in the root folder of the directory. Artifacts will be located in
`_build`.

## Running the kernel

### On real hardware
```
sudo dd if=_build/novavita.iso of=[device] bs=4M
```

### With QEMU
```
make qemu
```
