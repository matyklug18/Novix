#pragma once

#include "stddef.h"
#include "stdint.h"

enum vga_color : int
{
	VGA_COLOR_BLACK, VGA_COLOR_BLUE, VGA_COLOR_GREEN, 
	VGA_COLOR_CYAN, VGA_COLOR_RED, VGA_COLOR_MAGENTA, 
	VGA_COLOR_BROWN, VGA_COLOR_LIGHT_GREY, VGA_COLOR_DARK_GREY,
	VGA_COLOR_LIGHT_BLUE, VGA_COLOR_LIGHT_GREEN, VGA_COLOR_LIGHT_CYAN,
	VGA_COLOR_LIGHT_RED, VGA_COLOR_LIGHT_MAGENTA, VGA_COLOR_LIGHT_BROWN,
	VGA_COLOR_WHITE
};

class Terminal
{
	static const size_t VGA_WIDTH = 80;
	static const size_t VGA_HEIGHT = 25;

	size_t row;
	size_t column;
	uint16_t* buffer;

public:
	static Terminal* instance;
	static constexpr const char* Status = "$WHITE![$LIGHT_BLUE!--$WHITE!] $LIGHT_GREY!\0";
	static constexpr const char* Good = "$WHITE![$LIGHT_GREEN!:)$WHITE!] $LIGHT_GREY!\0";

	Terminal();
	void put_entry_at(char c, uint8_t color, size_t x, size_t y);
	void put_char(char c, uint8_t color);
	void write(const char* data, size_t size);
	void write(const char* data);
<<<<<<< HEAD
	void writeline(const char* data = "");
	[deprecated] void println(const char* data = "");
	void shift();
};

Terminal& operator<<(Terminal& term, const char* data);
=======
	void write(int num);
	void println(const char* data = "");
	void shift();
};

template<typename T>
Terminal& operator<<(Terminal& term, T data)
{
	term.write(data);
	return term;
}

template<typename T>
Terminal* operator<<(Terminal* term, T data)
{
	term->write(data);
	return term;
}
>>>>>>> b52e7038a5a993cb8e71e52a9ee7251bb694cc6f
