#include "hex.h"

using namespace std;

string hex::to_hex8(uint8_t i)
{
	std::ostringstream os;
	os << std::hex << std::setfill('0') << std::setw(2) << static_cast<uint16_t>(i);
	
	return os.str();
}

string hex::to_hex32(uint32_t i) 
{
	std::ostringstream os;
	os << std::hex << std::setfill('0') << std::setw(8) << static_cast<uint32_t>(i);
	return os.str();
}

string hex::to_hex0x32(uint32_t i)
{
	return std::string("0x")+to_hex32(i);
}

string hex::to_hex0x20(uint32_t i)
{
	std::ostringstream os;
	os << std::string("0x") << std::hex << std::setfill('0') << setw(5) << (i >> 12);
		
	return os.str();
}

string hex::to_hex0x12(uint32_t i)
{
	std::ostringstream os;
	os << std::string("0x") << std::hex << std::setw(3) << std::setfill('0') << (((signed short)i) & 0x0fff);

	return os.str();
}
