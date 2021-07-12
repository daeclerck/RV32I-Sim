#ifndef HART_H
#define HART_H
#include "registerfile.h"
#include "memory.h"

class rv32i_hart : public rv32i_decode
{

	public:
		// Constructor initializing the memory
		rv32i_hart(memory &m) : mem (m) { }

		// Determine if instructions will be showin in output
		void set_show_instructions(bool b) { show_instructions = b; }

		// Determine if registers will be showin in output
		void set_show_registers(bool b) { show_registers = b; }

		// Determine if the hart has been halted for any reason
		bool is_halted() const { return halt; }

		// Determine the reason why the hart was being halted 
		const std::string &get_halt_reason() const { return halt_reason; }

		// Determine the number of instructions that have been executed
		uint64_t get_insn_counter() const { return insn_counter; }

		// Set the hart ID for the csrrs instruction
		void set_mhartid(int i) { mhartid = i; }

		// Tells the simulator to execute a given instruction
		void tick(const std::string &hdr = "");

		// Dumps the entire state of the hart
 		void dump(const std::string &hdr = "") const;

		// Resets the hart
 		void reset();

 	private:
 		static constexpr int instruction_width = 35;

		// Executing any given RV32I instruction
 		void exec(uint32_t insn, std::ostream*);
		void exec_illegal_insn(uint32_t insn, std::ostream*);

		void exec_lui(uint32_t insn, std::ostream*);
		void exec_auipc(uint32_t insn, std::ostream*);
		void exec_jal(uint32_t insn, std::ostream*);
		void exec_jalr(uint32_t insn, std::ostream*);
		void exec_bne(uint32_t insn, std::ostream*);
		void exec_blt(uint32_t insn, std::ostream*);
		void exec_bge(uint32_t insn, std::ostream*);
		void exec_bltu(uint32_t insn, std::ostream*);
		void exec_bgeu(uint32_t insn, std::ostream*);
		void exec_beq(uint32_t insn, std::ostream*);
		void exec_addi(uint32_t insn, std::ostream*);
		void exec_lbu(uint32_t insn, std::ostream*);
		void exec_lhu(uint32_t insn, std::ostream*);
		void exec_lb(uint32_t insn, std::ostream*);
		void exec_lh(uint32_t insn, std::ostream*);
		void exec_lw(uint32_t insn, std::ostream*);
		void exec_sb(uint32_t insn, std::ostream*);
		void exec_sh(uint32_t insn, std::ostream*);
		void exec_sw(uint32_t insn, std::ostream*);
		void exec_slti(uint32_t insn, std::ostream*);
		void exec_sltiu(uint32_t insn, std::ostream*);
		void exec_xori(uint32_t insn, std::ostream*);
		void exec_ori(uint32_t insn, std::ostream*);
		void exec_andi(uint32_t insn, std::ostream*);
		void exec_slli(uint32_t insn, std::ostream*);
		void exec_srli(uint32_t insn, std::ostream*);
		void exec_srai(uint32_t insn, std::ostream*);
		void exec_add(uint32_t insn, std::ostream*);
		void exec_sub(uint32_t insn, std::ostream*);
		void exec_sll(uint32_t insn, std::ostream*);
		void exec_slt(uint32_t insn, std::ostream*);
		void exec_sltu(uint32_t insn, std::ostream*);
		void exec_xor(uint32_t insn, std::ostream*);
		void exec_srl(uint32_t insn, std::ostream*);
		void exec_sra(uint32_t insn, std::ostream*);
		void exec_or(uint32_t insn, std::ostream*);
		void exec_and(uint32_t insn, std::ostream*);
		void exec_ebreak(uint32_t insn, std::ostream*);
		void exec_csrrs(uint32_t insn, std::ostream*);

		// Initializing all necessary variables
		bool halt = { false };
		std::string halt_reason = { "none" };

 		uint64_t insn_counter = { 0 };
 		uint32_t pc = { 0 };
 		uint32_t mhartid = { 0 };

		bool show_instructions = false;
		bool show_registers = false;

 	protected:
 		registerfile regs;
 		memory &mem;
};

#endif
