#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "logo.h"
#include "asm.h"
#include "gdt.h"
#include "terminal.h"
#include "io.h"

extern "C" {

void kernel_main() {
	Terminal terminal;
	terminal << logo;
	terminal << "\n";

	// Show boot message
	terminal.write(Terminal::Status);
	terminal.write("Booting Nova Vita.\0");
	terminal.write("\n");

	outb(0x21 , 0xFD);

	// Show that the boot has been completed.
	terminal.write(Terminal::Good);
	terminal.write("Boot process complete.\0");
	terminal.write("\n");

	while (true) {}
}

}
