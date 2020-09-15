// #include <stdio.h>
#include <stdint.h>

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
