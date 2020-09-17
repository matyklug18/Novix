#include "asm.h"
#include "gdt.h"
#include "terminal.h"

extern "C"
{

extern void flushGDT(uint32_t);
extern void flushIDT(uint32_t);
extern void initGDT();
extern void gdtSetGate(int32_t, uint32_t, uint32_t, uint8_t, uint8_t);

GDTEntry gdtEntries[5];
GDTPointer gdtPointer;

IDTEntry   idtEntries[256];
IDTPointer idtPointer;

void loadGDT()
{
    auto gdt_set_gate = [](int32_t num, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran)
    {
        gdtEntries[num].base_low    = (base & 0xFFFF);
        gdtEntries[num].base_middle = (base >> 16) & 0xFF;
        gdtEntries[num].base_high   = (base >> 24) & 0xFF;

        gdtEntries[num].limit_low   = (limit & 0xFFFF);
        gdtEntries[num].granularity = (limit >> 16) & 0x0F;

        gdtEntries[num].granularity |= gran & 0xF0;
        gdtEntries[num].access      = access;
    };

    gdtPointer.limit = (sizeof(GDTEntry) * 5) - 1;
    gdtPointer.base = (uint32_t) &gdtEntries;

    gdt_set_gate(0, 0, 0, 0, 0);                // Null segment
    gdt_set_gate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF); // Code segment
    gdt_set_gate(2, 0, 0xFFFFFFFF, 0x92, 0xCF); // Data segment
    gdt_set_gate(3, 0, 0xFFFFFFFF, 0xFA, 0xCF); // User mode code segment
    gdt_set_gate(4, 0, 0xFFFFFFFF, 0xF2, 0xCF); // User mode data segment

    flushGDT((uint32_t)&gdtPointer);
}

extern void isr0();
extern void isr1();
extern void isr2();
extern void isr3();
extern void isr4();
extern void isr5();
extern void isr6();
extern void isr7();
extern void isr8();
extern void isr9();
extern void isr10();
extern void isr11();
extern void isr12();
extern void isr13();
extern void isr14();
extern void isr15();
extern void isr16();
extern void isr17();
extern void isr18();
extern void isr19();
extern void isr20();
extern void isr21();
extern void isr22();
extern void isr23();
extern void isr24();
extern void isr25();
extern void isr26();
extern void isr27();
extern void isr28();
extern void isr29();
extern void isr30();
extern void isr31();

void loadIDT()
{
    auto idt_set_gate = [](uint8_t num, uint32_t base, uint16_t sel, uint8_t flags)
    {
        idtEntries[num].base_lower = base & 0xFFFF;
        idtEntries[num].base_upper = (base >> 16) & 0xFFFF;

        idtEntries[num].sel     = sel;
        idtEntries[num].always0 = 0;
        idtEntries[num].flags   = flags;
    };

    idtPointer.limit = sizeof(IDTEntry) * 256 -1;
    idtPointer.base  = (uint32_t)&idtEntries;

    memset(&idtEntries, 0, sizeof(IDTEntry)*256);

    idt_set_gate(0, (uint32_t)isr0, 0x08, 0x8E);
    idt_set_gate(1, (uint32_t)isr1, 0x08, 0x8E);
    idt_set_gate(2, (uint32_t)isr2, 0x08, 0x8E);
    idt_set_gate(3, (uint32_t)isr3, 0x08, 0x8E);
    idt_set_gate(4, (uint32_t)isr4, 0x08, 0x8E);
    idt_set_gate(5, (uint32_t)isr5, 0x08, 0x8E);
    idt_set_gate(6, (uint32_t)isr6, 0x08, 0x8E);
    idt_set_gate(7, (uint32_t)isr7, 0x08, 0x8E);
    idt_set_gate(8, (uint32_t)isr8, 0x08, 0x8E);
    idt_set_gate(9, (uint32_t)isr9, 0x08, 0x8E);
    idt_set_gate(10, (uint32_t)isr10, 0x08, 0x8E);
    idt_set_gate(11, (uint32_t)isr11, 0x08, 0x8E);
    idt_set_gate(12, (uint32_t)isr12, 0x08, 0x8E);
    idt_set_gate(13, (uint32_t)isr13, 0x08, 0x8E);
    idt_set_gate(14, (uint32_t)isr14, 0x08, 0x8E);
    idt_set_gate(15, (uint32_t)isr15, 0x08, 0x8E);
    idt_set_gate(16, (uint32_t)isr16, 0x08, 0x8E);
    idt_set_gate(17, (uint32_t)isr17, 0x08, 0x8E);
    idt_set_gate(18, (uint32_t)isr18, 0x08, 0x8E);
    idt_set_gate(19, (uint32_t)isr19, 0x08, 0x8E);
    idt_set_gate(20, (uint32_t)isr20, 0x08, 0x8E);
    idt_set_gate(21, (uint32_t)isr21, 0x08, 0x8E);
    idt_set_gate(22, (uint32_t)isr22, 0x08, 0x8E);
    idt_set_gate(23, (uint32_t)isr23, 0x08, 0x8E);
    idt_set_gate(24, (uint32_t)isr24, 0x08, 0x8E);
    idt_set_gate(25, (uint32_t)isr25, 0x08, 0x8E);
    idt_set_gate(26, (uint32_t)isr26, 0x08, 0x8E);
    idt_set_gate(27, (uint32_t)isr27, 0x08, 0x8E);
    idt_set_gate(28, (uint32_t)isr28, 0x08, 0x8E);
    idt_set_gate(29, (uint32_t)isr29, 0x08, 0x8E);
    idt_set_gate(30, (uint32_t)isr30, 0x08, 0x8E);
    idt_set_gate(31, (uint32_t)isr31, 0x08, 0x8E);

    flushIDT((uint32_t)&idtPointer);
}

struct Registers
{
   uint32_t ds;
   uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax;
   uint32_t interruptNumber, errorCode;
   uint32_t eip, cs, eflags, useresp, ss;
};

void ISRHandler(Registers registers)
{
    Terminal::instance->println("Got an interrupt!");
}

void loadTables()
{
    loadGDT();
    loadIDT();
}

}