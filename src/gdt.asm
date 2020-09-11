extern pointer
GLOBAL loadGDT:
    lgdt [pointer]
    
    ; load all the segment registers here


    cli
    ret
