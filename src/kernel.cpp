#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "logo.h"
#include "asm.h"

/* Check if the compiler thinks you are targeting the wrong operating system. */
// #if defined(__linux__)
// #error "You are not using a cross-compiler, you will most certainly run into trouble"
// #endif

// /* This tutorial will only work for the 32-bit ix86 targets. */
// #if !defined(__i386__)
// #error "This tutorial needs to be compiled with a ix86-elf compiler"
// #endif

/* Hardware text mode color constants. */
enum vga_color {
	VGA_COLOR_BLACK = 0,
	VGA_COLOR_BLUE = 1,
	VGA_COLOR_GREEN = 2,
	VGA_COLOR_CYAN = 3,
	VGA_COLOR_RED = 4,
	VGA_COLOR_MAGENTA = 5,
	VGA_COLOR_BROWN = 6,
	VGA_COLOR_LIGHT_GREY = 7,
	VGA_COLOR_DARK_GREY = 8,
	VGA_COLOR_LIGHT_BLUE = 9,
	VGA_COLOR_LIGHT_GREEN = 10,
	VGA_COLOR_LIGHT_CYAN = 11,
	VGA_COLOR_LIGHT_RED = 12,
	VGA_COLOR_LIGHT_MAGENTA = 13,
	VGA_COLOR_LIGHT_BROWN = 14,
	VGA_COLOR_WHITE = 15,
};

static inline uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg)
{
	return fg | bg << 4;
}

static inline uint16_t vga_entry(unsigned char uc, uint8_t color)
{
	return (uint16_t) uc | (uint16_t) color << 8;
}

size_t strlen(const char* str)
{
	size_t len = 0;
	while (str[len])
		len++;
	return len;
}

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;

size_t terminal_row;
size_t terminal_column;
uint16_t* terminal_buffer;

void terminal_initialize(void)
{
	terminal_row = 0;
	terminal_column = 0;
	terminal_buffer = (uint16_t*) 0xB8000;
	for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			terminal_buffer[index] = vga_entry(' ', VGA_COLOR_LIGHT_GREY);
		}
	}
}

void terminal_putentryat(char c, uint8_t color, size_t x, size_t y)
{
	const size_t index = y * VGA_WIDTH + x;
	terminal_buffer[index] = vga_entry(c, color);
}

void terminal_putchar(char c, uint8_t color)
{
	if (c != '\n') {
		terminal_putentryat(c, color, terminal_column, terminal_row);
	}
	if (++terminal_column == VGA_WIDTH) {
		terminal_column = 0;
		if (++terminal_row == VGA_HEIGHT)
			terminal_row = 0;
	}
	if (c == '\n'){
		terminal_row++;
		terminal_column = 0;
	}
}

#define CHECK_COLOR(farbe) if (strcomp(#farbe, colorCode)) color = VGA_COLOR_ ## farbe;
#define STATUS "$WHITE![$LIGHT_BLUE!--$WHITE!] $LIGHT_GREY!"
#define GOOD "$WHITE![$LIGHT_GREEN!:)$WHITE!] $LIGHT_GREY!"

bool strcomp(const char* lhs, const char *rhs) {
	for (; *lhs; lhs++) {
		if (*lhs != *rhs) {
			return false;
		}
		rhs++;
	}
	return true;
}

void terminal_write(const char* data, size_t size)
{
	uint8_t color = VGA_COLOR_LIGHT_GREY;
	char colorCode[15];

	for (; *data != '\0'; data++) {
		if (*data == '$') {
			int iter = 0;
			data++;
			while (true) {
				if (*data != '!') {
					colorCode[iter] = *data;
					iter++;
					data++;
				} else {
					data++;
					break;
				}
			}
			colorCode[iter+1] = 0;
			CHECK_COLOR(BLACK)
			CHECK_COLOR(BLUE)
			CHECK_COLOR(GREEN)
			CHECK_COLOR(CYAN)
			CHECK_COLOR(RED)
			CHECK_COLOR(MAGENTA)
			CHECK_COLOR(BROWN)
			CHECK_COLOR(LIGHT_GREY)
			CHECK_COLOR(DARK_GREY)
			CHECK_COLOR(LIGHT_BLUE)
			CHECK_COLOR(LIGHT_GREEN)
			CHECK_COLOR(LIGHT_CYAN)
			CHECK_COLOR(LIGHT_RED)
			CHECK_COLOR(LIGHT_MAGENTA)
			CHECK_COLOR(LIGHT_BROWN)
			CHECK_COLOR(WHITE)
		}
		terminal_putchar(*data, color);
	}
}

void terminal_writestring(const char* data)
{
	terminal_write(data, strlen(data));
}

void terminal_println(const char* data)
{
	terminal_write(data, strlen(data));
	terminal_write("\n", 1);
}

extern "C" {

void kernel_main(void) {
	terminal_initialize();
	terminal_println(logo);
	terminal_println("");
	terminal_println("");

	terminal_println(STATUS "Booting Nova Vita...");

	// First we load the GDT and IDT
	loadGDT();
	installIDT();

	terminal_println(GOOD "Boot process complete.");
}

}
