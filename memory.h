//******************************************************************
//
// Troy DeClerck
// Z1877438
// CSCI 463 - Section 1
//
// Assignment 5 - RISC-V Simulator
//
// I certify that this is my own work and where appropriate an 
// extension of the starter code provided for the assignment.
//
//******************************************************************
#ifndef MEMORY_H
#define MEMORY_H

#include <string>
#include <stdint.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <bitset>

using namespace std;

class memory
{
	public:
		// Function declarations
		memory(uint32_t s);
		~memory();

		// Check legality of an address
		bool check_illegal(uint32_t addr) const;

		// Get appropriate values for any 
		// given address
		uint32_t get_size() const;		
		uint8_t get8(uint32_t addr) const;	
		uint16_t get16(uint32_t addr) const;	
		uint32_t get32(uint32_t addr) const;

		int32_t get8_sx(uint32_t addr) const;
		int32_t get16_sx(uint32_t addr) const;
		int32_t get32_sx(uint32_t addr) const;

		// Set appropriate values for any 
		// given address
		void set8(uint32_t addr, uint8_t val);	
		void set16(uint32_t addr, uint16_t val);
		void set32(uint32_t addr, uint32_t val);	

		// Display the memory dump
		void dump() const;			
		
		// Check for successful file load
		bool load_file(const string& fname);	

	private:
		// Vector used to store each address
		vector <uint8_t> mem; 
};

#endif
