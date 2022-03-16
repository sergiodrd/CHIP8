#include "cpucore.h"

// Order of functions is important
void (*decode[16])(opcode o) = {
	&func0, &jmp, &subrtcall, &skipxnn, &skipnotxnn,
	&skipxy, &setxnn, &addxnn, &arithmetic, &skipnotxy,
	&seti, &jmpoff, &rnd, &display, &skipifkey, &funcf
};

void (*arithtable[7])(opcode o) = {
	&setxy, &orxy, &andxy, &xorxy, &addxy, &subxy, &shiftxy
};

void func0(opcode o) {
	if (o.full == 0x00E0)
		clrscrn(o);
	else
		subrtret(o);
}

void arithmetic(opcode o) {
	uint8_t nibble = o.nibble4;
	if (nibble == 0x7) nibble = 0x5;
	else if (nibble == 0xE) nibble = 0x6;
	(*arithtable[nibble])(o);
}

void funcf(opcode o) {
	switch (o.byte2) {
		case 0x07:
		case 0x15:
		case 0x18:
			timers(o);
		case 0x1E:
			addi(o);
		case 0x0A:
			getkey(o);
		case 0x29:
			font(o);
		case 0x33:
			deccon(o);
		case 0x55:
		case 0x65:
			memx(o);
	}
}