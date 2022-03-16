#pragma once
#include <iostream>
#include <fstream>
#include <stack>
#include <chrono>
#include <thread>

using namespace std::this_thread;
using namespace std::chrono;

const uint16_t PROG_MEM_OFFSET = 0x200;
const uint16_t CYCLES_PER_SECOND = 700;
const uint16_t MS_DELAY = 1000 / CYCLES_PER_SECOND;
void copyFileToMemory(std::ifstream&, uint8_t*);
