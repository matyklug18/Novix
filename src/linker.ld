OUTPUT_FORMAT(elf32-i386)
ENTRY(entry_point)

SECTIONS {
    . = 0x100000;
    .multiboot : ALIGN(4K) {
        *(.multiboot)
    }
    .text : ALIGN(4K) {
        *(.text*)
    }
    .data : ALIGN(4K)  {
        *(.data)
    }
    .rodata : ALIGN(4K) {
        *(.rodata)
    }
    .bss : ALIGN(4K) {
        *(.bss)
    }
}