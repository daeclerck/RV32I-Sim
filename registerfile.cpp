#include "registerfile.h"
#include "hex.h"
#include <cstdint>
#include <iostream>
#include <iomanip>

registerfile::registerfile()
{
	reset();
}

void registerfile::reset()
{
	reg[0] = 0x0;

	for (int i = 1; i < 32; i++)
	{
		reg[i] = 0xf0f0f0f0;
	}
}

void registerfile::set(uint32_t r, int32_t val)
{
	if (r == 0)
	{
		return;
	}
	else
	{
		reg[r] = val;
	}
}


int32_t registerfile::get(uint32_t r) const
{
	if (r == 0)
	{
		return 0;
	}
	else
	{
		return reg[r];
	}
}

void registerfile::dump(const std::string &hdr) const
{
	// Dump contents
	for(size_t i = 0; i < 32; i++)
	{
		// Print new line
		if (i != 0 && i % 8 == 0)
		{
			std::cout << std::endl;
		}
		if (i % 8 == 0)
		{
			std::string h;
			if (i == 0)
			{
				h = "x0";
			}
			else if (i == 8)
			{
			    h = "x8";
            }
            else if(i == 16)
            {
                h = "x16";
            }
            else if(i == 24)
            {
                h = "x24";
            }
			std::cout << hdr << std::dec << std::right << std::setw(3) << std::setfill(' ') << h << " ";
        }

        //print contents of the register
        if(i % 8 == 7)
        {
            std::cout << hex::to_hex32(reg[i]);
        }
		else if (i % 4 == 0 && i != 0 && i % 8 != 0)
		{
			std::cout << " " << hex::to_hex32(reg[i]) << " ";
		}
        else
        {
            std::cout << hex::to_hex32(reg[i]) << " ";
        }
    }
	std::cout << std::endl;
}
