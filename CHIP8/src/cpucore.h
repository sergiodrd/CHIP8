#pragma once
#include <cstdint>

struct opcode {
	uint16_t full;
	uint8_t byte1, byte2;
	uint8_t nibble1, nibble2, nibble3, nibble4;

	opcode(uint8_t b1, uint8_t b2) {
		byte1 = b1;
		byte2 = b2;
		full = (b1 << 8) + b2;
		nibble1 = (b1 & 0xF0) >> 4;
		nibble2 = b1 & 0xF;
		nibble3 = (b2 & 0xF0) >> 4;
		nibble4 = b2 & 0xF;
	}
};

void func0(opcode), funcf(opcode), arithmetic(opcode);

void clrscrn(opcode), subrtret(opcode), jmp(opcode),
	 subrtcall(opcode), skipxnn(opcode), skipnotxnn(opcode),
	 skipxy(opcode), setxnn(opcode), addxnn(opcode),
	 setxy(opcode), orxy(opcode), andxy(opcode),
	 xorxy(opcode), addxy(opcode), subxy(opcode),
	 shiftxy(opcode), skipnotxy(opcode), seti(opcode),
	 jmpoff(opcode), rnd(opcode), display(opcode),
	 skipifkey(opcode), timers(opcode), addi(opcode),
	 getkey(opcode), font(opcode), deccon(opcode), memx(opcode);

extern void (*decode[16])(opcode);
extern void (*arithtable[7])(opcode);