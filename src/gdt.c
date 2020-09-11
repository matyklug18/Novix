#include <stdlib.h>
#include <stdio.h>


// am i doing this right?

extern struct GDT {
    // items to add
};

// you may want to write this in asm as you will also have to l oad the segment registers
// in protected mode, the segment registers still serve a purpose
// they store "selectors", which is  a fancy term for pointers to your GDT entries
// so CS = byte offset of corresponding entry in your GDT
// this is why the scheme was called "segmentation"

// so how would i write the GDT assembly file?

void installGDT(){
    // testing something
    loadGDT(); // not sure if this will work or not.
}
