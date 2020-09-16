#include <stdint.h>

/* define a struct type for IDTR */
typedef struct {
  uint16_t limit;
  uint32_t offset;
}__attribute__((packed)) idtr_t;

idtr_t idtr;

idtr_t idtr = { 69, 69 }; // TODO: initialize idtr.

void installIDT(){
  loadGDT();
}
