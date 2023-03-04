
#include "drivers/text_driver.h"
#include "OS/boot.h"

extern void kmain() {

	short wave_scale = 10;

	short wave = 0;
	short wave_switch = 0;

	int wave_len;

	while (++wave_len != 20) {

		if (wave == wave_scale)
			wave_switch = -1;
		if (wave == 0) {
			wave_switch = 1;
		}

		wave += wave_switch;

		for (int i = 0; i < wave; i++)
			print_string('2');

		// at the end it goes to the new line
		print_string("\n");
	}
}