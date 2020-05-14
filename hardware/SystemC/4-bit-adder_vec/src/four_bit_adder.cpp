#include "four_bit_adder.h"

four_bit_adder::four_bit_adder(sc_module_name nm) : sc_module (nm), inp_a("inp_a", 4), inp_b("inp_b", 4), sum("sum", 4), 
	full_adder0("full_adder0"),
	full_adder1("full_adder1"),
	full_adder2("full_adder2"),
	full_adder3("full_adder3") {

		full_adder0.inp_a(inp_a[0]);
		full_adder0.inp_b(inp_b[0]);
		full_adder0.inp_cin(inp_cin);
		full_adder0.sum(sum[0]);
		full_adder0.co(co_0);

		full_adder1.inp_a(inp_a[1]);
                full_adder1.inp_b(inp_b[1]);
                full_adder1.inp_cin(co_0);
                full_adder1.sum(sum[1]);
                full_adder1.co(co_1);

		full_adder2.inp_a(inp_a[2]);
                full_adder2.inp_b(inp_b[2]);
                full_adder2.inp_cin(co_1);
                full_adder2.sum(sum[2]);
                full_adder2.co(co_2);

		full_adder3.inp_a(inp_a[3]);
                full_adder3.inp_b(inp_b[3]);
                full_adder3.inp_cin(co_2);
                full_adder3.sum(sum[3]);
                full_adder3.co(co);
	}
