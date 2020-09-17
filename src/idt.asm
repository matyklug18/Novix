EXTERN idtr

global loadIDT ; make global

%macro  cglobal 1

  global  _%1
  %define %1 _%1

%endmacro

%macro  cextern 1

  extern  _%1
  %define %1 _%1

%endmacro

global irq0
global irq1
global irq2
global irq3
global irq4
global irq5
global irq6
global irq7
global irq8
global irq9
global irq10
global irq11
global irq12
global irq13
global irq14
global irq15

global load_idt

EXTERN irq0_handler
EXTERN irq1_handler
EXTERN irq2_handler
EXTERN irq3_handler
EXTERN irq4_handler
EXTERN irq5_handler
EXTERN irq6_handler
EXTERN irq7_handler
EXTERN irq8_handler
EXTERN irq9_handler
EXTERN irq10_handler
EXTERN irq11_handler
EXTERN irq12_handler
EXTERN irq13_handler
EXTERN irq14_handler
EXTERN irq15_handler

irq0:
  pusha
  call irq0_handler
  popa
  iret

irq1:
  pusha
  call irq1_handler
  popa
  iret

irq2:
  pusha
  call irq2_handler
  popa
  iret

irq3:
  pusha
  call irq3_handler
  popa
  iret

irq4:
  pusha
  call irq4_handler
  popa
  iret

irq5:
  pusha
  call irq5_handler
  popa
  iret

irq6:
  pusha
  call irq6_handler
  popa
  iret

irq7:
  pusha
  call irq7_handler
  popa
  iret

irq8:
  pusha
  call irq8_handler
  popa
  iret

irq9:
  pusha
  call irq9_handler
  popa
  iret

irq10:
  pusha
  call irq10_handler
  popa
  iret

irq11:
  pusha
  call irq11_handler
  popa
  iret

irq12:
  pusha
  call irq12_handler
  popa
  iret

irq13:
  pusha
  call irq13_handler
  popa
  iret

irq14:
  pusha
  call irq14_handler
  popa
  iret

irq15:
  pusha
  call irq15_handler
  popa
  iret

loadIDT:
	mov edx, [esp + 4]
	lidt [edx]
	sti
	ret