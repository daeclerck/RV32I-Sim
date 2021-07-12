#ifndef REG_H
#define REG_H

#include <stdint.h>
#include <string>

using namespace std;

class registerfile
{
	public:
		registerfile();
		void reset();
		void set(uint32_t r, int32_t val);
		int32_t get(uint32_t r) const;
		void dump(const std::string &hdr) const;

	private:
		int32_t reg[32];
};

#endif
