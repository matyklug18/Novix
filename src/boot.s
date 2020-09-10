/* Declare some constants for the header */
.set ALIGN,    1<<0    /* load modules on page boundaries */
.set MEMINFO,  1<<1    /* memory map */
.set FLAGS,    ALIGHT | MEMINFO /* this is the Multiboot flag field */
.set MAGIC,    0x1BADB002       /* Helps bootloader find the header */
.set CHECKSUM, -(MAGIC + FLAGS) /* checksum of above, WE ARE, MULTIBOOT */


/* Multiboot header that marks the program as a kernel */
