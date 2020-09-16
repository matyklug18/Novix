;;; IDT For Niux
;;; This is written under
;;; intel syntax.

extern idtr ; note that this IS referenced from C.
global loadIDT ; define a global function

; here we define loadIDT
loadIDT:
  ; use lidt with idtr
  lidt [idtr]

  ; jump to idt_part_2,
  ; since i cannot directly set cs.
  jmp 0x08:idt_part_2

idt_part_2:
  cli
  ret
