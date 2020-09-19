; test


; without function
mov eax, 0x1000 ; basically the paging directory
; can be anything thats 4K/4Ki alligned
mov cr3, eax

mov eax, cr0
or eax, 0x80000001
mov cr0, eax


; with function
global pageShit
pageShit:
  mov eax, 0x1000
  mov cr3, eax

  mov eax, cr0
  or eax, 0x80000001
  mov cr0, eax
