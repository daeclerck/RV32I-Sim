#include "hex.h"
#include "rv32i_decode.h"
#include "registerfile.h"
#include "rv32i_hart.h"
#include "cpu_single_hart.h"

void cpu_single_hart::run(uint64_t exec_limit)
{
	regs.set(2, mem.get_size());

	while( ( is_halted() != true && exec_limit == 0 ) || ( is_halted() != true && get_insn_counter() < exec_limit ) )
		tick();

	if(is_halted())
		std::cout << "Execution terminated. Reason: " << get_halt_reason() << std::endl;

	std::cout << get_insn_counter() <<  " instructions executed" << std::endl;
}
