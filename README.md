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

# Building

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
