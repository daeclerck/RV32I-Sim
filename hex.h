#ifndef HEX_H
#define HEX_H

#include <string>
#include <stdint.h>
#include <iostream>
#include <iomanip>
#include <sstream>

class hex
{
public:
	// Function declarations
	static std::string to_hex8(uint8_t i);
	static std::string to_hex32(uint32_t i);
	static std::string to_hex0x32(uint32_t i);

	static std::string to_hex0x20(uint32_t i);
	static std::string to_hex0x12(uint32_t i);
};

#endif
