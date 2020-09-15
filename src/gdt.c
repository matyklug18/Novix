// #include <stdio.h>
#include <stdint.h>


/* Declare a type/struct for the gdtr (48 bit register)*/
typedef struct {
  uint16_t limit;
  uint32_t offset;
} __attribute__((packed)) gdtr_t;


/* Make a variable with the type gdtr_t for gdt.asm */
extern gdtr_t gdtr = { 69, 69 };


/* Define some extern 32 bit registers */
extern uint32_t gdt_pointer;
extern uint32_t gdt_pointer_2;




extern struct GDT {
    uint32_t pointer;
}__attribute__((packed));

// extern struct gdt_pointer {
//    uint32_t base;
//    uint16_t limit;
// }__attribute__((packed));



extern void installGDT(){
    // testing something
    loadGDT(); // not sure if this will work or not.
}
