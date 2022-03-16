#include "core.h"

void copyFileToMemory(std::ifstream& infile, uint8_t* memory) {
	if (!infile.good())
		std::cout << "ROM open failure." << std::endl;
	else {
		int i = PROG_MEM_OFFSET;
		char b;
		while (!infile.eof()) {
			infile.read(&b, 1);
			memory[i] = static_cast<uint8_t>(b);
			i++;
		}
	}
	infile.close();
}