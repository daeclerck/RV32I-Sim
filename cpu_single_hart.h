#ifndef CPU_H
#define CPU_H

class cpu_single_hart : public rv32i_hart
{
	public:
		cpu_single_hart(memory& mem) : rv32i_hart(mem) {}
		void run(uint64_t exec_limit);		
};


#endif
