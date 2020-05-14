#include "full_adder.h"

full_adder::full_adder(sc_module_name nm) : sc_module (nm),
	xor_gate1("xor_gate1"),
	xor_gate2("xor_gate2"),
	and_gate1("and_gate1"),
	and_gate2("and_gate2"),
	or_gate1("or_gate1") {

		xor_gate1.inp_a(inp_a);
		xor_gate1.inp_b(inp_b);
		xor_gate1.out(sig_1);

		xor_gate2.inp_a(sig_1);
                xor_gate2.inp_b(inp_cin);
                xor_gate2.out(sum);

		and_gate1.inp_a(sig_1);
		and_gate1.inp_b(inp_cin);
		and_gate1.out(sig_2);

		and_gate2.inp_a(inp_a);
                and_gate2.inp_b(inp_b);
                and_gate2.out(sig_3);

		or_gate1.inp_a(sig_2);
		or_gate1.inp_b(sig_3);
		or_gate1.out(co);
	}
		

