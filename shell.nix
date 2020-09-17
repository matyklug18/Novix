{
  pkgs ? import <nixpkgs> {
    crossSystem = {
      config = "i686-elf";
    };
  }
}:

pkgs.mkShell {
  nativeBuildInputs = with pkgs.buildPackages.buildPackages; [ mtools xorriso nasm binutils pkgs.buildPackages.clang grub2 qemu ];
}
