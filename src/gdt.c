#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

extern struct GDT {
    uint32_t pointer;
};


void installGDT(){
    // testing something
    loadGDT(); // not sure if this will work or not.
}
