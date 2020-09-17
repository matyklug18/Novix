/* Declare some constants for the header */
.set ALIGN,    1<<0    /* load modules on page boundaries */
.set MEMINFO,  1<<1    /* memory map */
.set FLAGS,    ALIGN | MEMINFO /* this is the Multiboot flag field */
.set MAGIC,    0x1BADB002       /* Helps bootloader find the header */
.set CHECKSUM, -(MAGIC + FLAGS) /* checksum of above, WE ARE, MULTIBOOT */


/* Multiboot header that marks the program as a kernel */
.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

/* bss section */
.section .bss
.align 16
stack_bottom:
    .skip 16384 # 16 kib
stack_top:

/* the linker script specifies _start as the entry 
point for the kernel */
.section .text
.global _start
.type _start, @function
_start:
    /* stack */
    mov $stack_top, %esp

    cli

    call loadGDT

    mov %cr0, %eax
    or 1, %al
    mov %eax, %cr0

    call loadIDT

    sti

    jmp $0x8,$protectedModeMain

protectedModeMain:
    /* here we call kernel_main */
    call kernel_main

    /* if the system has nothing else to do, put the pc
    into an infinite loop */
1:	hlt
    jmp 1b

/* set thie size of the _start symbol to the current location */
.size _start, . - _start
