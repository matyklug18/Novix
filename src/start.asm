[BITS 32]
global start
start:
    mov esp, _sys_stack     ; This points the stack to our new stack area
    jmp stublet
MULTIBOOT_PAGE_ALIGN equ 1<<0
MULTIBOOT_MEMORY_INFO equ 1<<1
MULTIBOOT_MAGIC equ 0x1BADB002
MULTIBOOT_FLAGS equ MULTIBOOT_PAGE_ALIGN | MULTIBOOT_MEMORY_INFO
MULTIBOOT_CHECKSUM equ -(MULTIBOOT_MAGIC + MULTIBOOT_FLAGS)

align 4
mboot:
  dd MULTIBOOT_MAGIC
  dd MULTIBOOT_FLAGS
  dd MULTIBOOT_CHECKSUM
; This is an endless loop here.
stublet:
    extern main
    call main
    jmp $


global _gdt_flush     ; Allows the C code to link to this
extern _gp            ; Says that '_gp' is in another file
_gdt_flush:
    lgdt [_gp]        ; Load the GDT with our '_gp' which is a special pointer
    mov ax, 0x10      ; 0x10 is the offset in the GDT to our data segment
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    jmp 0x08:flush2   ; 0x08 is the offset to our code segment: Far jump!
flush2:
    ret               ; Returns back to the C code!


SECTION .bss
    resb 8192               ; This reserves 8KBytes of memory here
_sys_stack:
