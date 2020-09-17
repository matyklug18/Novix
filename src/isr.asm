%macro ISRWithoutErrorCode 1
  global isr%1
  isr%1:
    cli
    push byte 0
    push byte %1
    jmp CommonISRStub
%endmacro

%macro ISRWithErrorCode 1
  global isr%1
  isr%1:
    cli
    push byte %1
    jmp CommonISRStub
%endmacro

ISRWithoutErrorCode 0
ISRWithoutErrorCode 1
ISRWithoutErrorCode 2
ISRWithoutErrorCode 3
ISRWithoutErrorCode 4
ISRWithoutErrorCode 5
ISRWithoutErrorCode 6
ISRWithErrorCode 7
ISRWithoutErrorCode 8
ISRWithErrorCode 9
ISRWithErrorCode 10
ISRWithErrorCode 11
ISRWithErrorCode 12
ISRWithErrorCode 13
ISRWithoutErrorCode 14
ISRWithoutErrorCode 15
ISRWithoutErrorCode 16
ISRWithoutErrorCode 17
ISRWithoutErrorCode 18
ISRWithoutErrorCode 19
ISRWithoutErrorCode 20
ISRWithoutErrorCode 21
ISRWithoutErrorCode 22
ISRWithoutErrorCode 23
ISRWithoutErrorCode 24
ISRWithoutErrorCode 25
ISRWithoutErrorCode 26
ISRWithoutErrorCode 27
ISRWithoutErrorCode 28
ISRWithoutErrorCode 29
ISRWithoutErrorCode 30
ISRWithoutErrorCode 31

EXTERN ISRHandler

CommonISRStub:
    pusha

    mov ax, ds
    push eax

    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    call ISRHandler

    pop eax
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    popa
    add esp, 8
    sti
    iret
