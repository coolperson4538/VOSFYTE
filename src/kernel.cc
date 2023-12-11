#include <drivers/keyboard.h>
#include <common/cli.h>
#include <drivers/windowing_system.h> // VGA Framebuffer
#include <filesys/fs.h>
#include <mm/heap/heap.h>
#include <mm/stack/stack.h>

void print_string(unsigned char ch, unsigned char forecolor, 
		unsigned char backcolor, uint8_t x, uint8_t y) {

	uint16_t attrib = (backcolor << 4) | (forecolor & 0x0f);
	volatile uint16_t* vidmem;
	vidmem = (volatile uint16_t*)0xb8000 + (80*y+x);
	*vidmem = ch | (attrib << 8);
}

void kernelMain()
{
	keyboard_init();
}