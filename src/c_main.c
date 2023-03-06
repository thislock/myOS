
// standard lib for the tiny c compiler, for things like uint16 and stuff
#include <tcclib.h>

// the idt for handling interrupts in 32 bit mode
struct InterruptDescriptor32 {
  uint16_t offset_1;        // offset bits 0..15
  uint16_t selector;        // a code segment selector in GDT or LDT
  uint8_t  zero=0;          // unused, set to 0
  uint8_t  type_attributes; // gate type, dpl, and p fields
  uint16_t offset_2;        // offset bits 16..31
};

extern void cmain() {

	struct InterruptDescriptor32 idt32;

	for (int i = 0; i < 15; i++) {
		idt32.offset_1 = i;

	}

}