; Sorry future me
; you're on your own
GLOBAL pointer 
global pointer
extern GDT ; easy
GLOBAL loadGDT:
    lgdt [gdt_pointer]
    
    ; load all the segment registers here
    ; you can't directly mov to them so you need to do like
    ; mov ax, <selector>
    ; mov ds, ax
    ; mov es, ax
    ; ...
    
    ; you cannot directly set cs, you instead need to do a far jump
    ; so do like jmp <selector>:<label>
    ; for instance

    jmp 0x08:part2
part2:
    cli
    ret