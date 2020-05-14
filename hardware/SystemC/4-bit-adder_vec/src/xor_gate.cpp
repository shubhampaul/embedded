#include "xor_gate.h"

xor_gate::xor_gate(sc_module_name nm) : sc_module (nm), 
	nand_gate1("nand_gate1"), 
	nand_gate2("nand_gate2"), 
	nand_gate3("nand_gate3"), 
	nand_gate4("nand_gate4") {
		nand_gate1.inp_a(inp_a);
		nand_gate1.inp_b(inp_b);
		nand_gate1.out(sig_1);
		
		nand_gate2.inp_a(inp_a);
		nand_gate2.inp_b(sig_1);
		nand_gate2.out(sig_2);
		
		nand_gate3.inp_a(sig_1);
		nand_gate3.inp_b(inp_b);
		nand_gate3.out(sig_3);
		
		nand_gate4.inp_a(sig_2);
		nand_gate4.inp_b(sig_3);
		nand_gate4.out(out);
}
