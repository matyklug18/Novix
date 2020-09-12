#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

extern struct GDT {
    uint32_t pointer;
}__attribute__((packed));

extern struct gdt_pointer {
   uint16_t limit;
   uint32_t base;
} __attribute__((packed));

uint32_t pointer;

void installGDT(){
    // testing something
    loadGDT(); // not sure if this will work or not.
}
