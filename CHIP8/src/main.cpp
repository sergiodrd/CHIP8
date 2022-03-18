#include "core.h"
#include "cpucore.h"

int main(int argc, char* argv[]) {

	// CPU components and memory
	uint8_t memory[4096]{};
	uint8_t	registers[16];
	std::stack<uint16_t> stack;
	uint16_t PC = PROG_MEM_OFFSET;
	uint16_t I;

	// Read ROM file and copy to memory
	std::string fileName = (argc == 2) ? argv[1] : "../../CHIP8/IBMLogo.ch8";
	std::ifstream infile(fileName, std::ios::binary);
	copyFileToMemory(infile, memory);
	
	// Fetch-Decode-Execute Cycle
	while (true) {

		// Fetch
		opcode o(memory[PC], memory[PC + 1]);
		PC += 2;

		// Decode and execute
		(*decode[o.nibble1])(o);

		// Wait
		sleep_for(milliseconds(MS_DELAY));
	}

	return 0;
}