#include "memory.h"
#include "hex.h"

memory::memory(uint32_t siz)
{
	siz = (siz+15)&0xfffffff0;
	
	// Resizes vector to size value and sets every element to 0xa5
	mem.resize(siz, 0xa5);
}

memory::~ memory()
{
	// Destructor
	mem.clear();
}

bool memory::check_illegal(uint32_t i) const
{
	if(i < mem.size()) // Checks if i is less than the size
	{
		return true;
	}
	else // Print warning if address out of range
	{
		cout << "WARNING: Address out of range: " << hex::to_hex0x32(i) << endl;
		return 0;
	}
}	

uint32_t memory::get_size() const
{
	return mem.size();
}

uint8_t memory::get8(uint32_t addr) const
{
	// Checks if check address is true
	if(check_illegal(addr))
	{
		return mem[addr];
	}
	else
	{
		return 0;
	}
}

uint16_t memory::get16(uint32_t addr) const
{
	uint16_t sum;

	// Sets sum to the addresses in little-endian format
	sum = (get8(addr) | get8(addr+1) << 8);
	return sum;
}

uint32_t memory::get32(uint32_t addr) const
{
	uint32_t sum;

	// Sets sum to the addresses in little endiend format
	sum = get16(addr) | get16(addr+2) << 16;
	return sum;
}

int32_t memory::get8_sx(uint32_t addr) const
{	
	return (int8_t)get8(addr);
}

int32_t memory::get16_sx(uint32_t addr) const
{
	return (int16_t)get16(addr);
}

int32_t memory::get32_sx(uint32_t addr) const
{
	return get32(addr);

}

void memory::set8(uint32_t addr, uint8_t val)
{
	//checks if address is valid
	if(check_illegal(addr))
	{
		mem[addr] = val;
	}
}

void memory::set16(uint32_t addr, uint16_t val)
{
	// Shift value 8 bits and increment the address
	set8(addr+1, val>>8);
	set8(addr, val);
	mem[addr] = val;
}

void memory::set32(uint32_t addr, uint32_t val)
{
	// Shift value 8 bits and increment the address
	// Shift value 16 bits and increment again for next set of 16
	set16(addr+1, val>>8);
	set16(addr+2, val>>16);
	mem[addr] = val;
}

void memory::dump() const
{
	string reg = ""; // used for registers
	int count = 16;  // used for numbering registers 
	int count2 = 0;  // used for formatting output

	for(unsigned u = 0; u < mem.size()/16; u++){
		if(u != 0)
		{
			// Set the register string to the correct
			// output line in the dump using the to_hex32 function.
			// Increment the count by a value of 10 in hex
			reg = hex::to_hex32(count);
			reg.append(":");
			cout << reg;
			count += 16;	
		}
		else if (u == 0)
		{
			// Prints out the default value at the start of the dump
			cout << "00000000:";
		}

		// Loop for printing out the hex values of each element in the dump
		for(int j = count2; j < 16 + count2 ; j++)
		{
			// Checks if address is the default 0xa5
			// Prints a5 or the proper hex value of the current element
			if(mem[j] == 0xa5)
			{
				// Create correct spacing
				if(j % 8 == 0 && j != 0 && j % 16 != 0 ) cout << "  a5";
				else cout << " a5";
			}
			else
			{
				if(j % 8 == 0 && j != 0 && j % 16 != 0) 
					cout << "  " << hex::to_hex8(mem[j]);
				else
					cout << " " << hex::to_hex8(mem[j]);
			}
		}
		cout << " *";

		// Loop for printing out the printable characters in the memory dump
		for(int k = count2; k < 16 + count2; k++){
			// Checks if address is 0xa5 and if it is printable
			if(mem[k] == 0xa5 || !isprint(mem[k]))
			{
				cout << ".";
			}
			else
			{
				// Prints address content
				cout << mem[k];
			}
		}	

		cout << "*";		
		cout << endl;
		
		// Increment the count2 by a hex value of 10
		count2 += 16;
	}
}

bool memory::load_file(const string& fname)
{
	// Create the input file variable and open in binary
	ifstream infile(fname, ios::in|ios::binary);

	// Check if file exists or can be opened
	if(!infile)
	{
		cout << "Can't open file " << fname << " for reading" << endl;
		return false;
	}
	
	// Read one byte at a time and accept whitespaces as
	// valid characters. Insert that value into the memory 
	// vector or return an error message.
	uint8_t i;
	infile >> std::noskipws;
	for (uint32_t addr = 0; infile >> i; ++addr)
	{
		if(check_illegal(addr))
		{
			mem[addr] = i;
		}
		else
		{
			cerr << "Program too big." << endl;
			return false;
		}
	}

	return true;
}
