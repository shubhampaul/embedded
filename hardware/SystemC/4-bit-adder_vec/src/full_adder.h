#include <systemc.h>
#include "xor_gate.h"
#include "and_gate.h"
#include "or_gate.h"

SC_MODULE(full_adder) {
	public:
		sc_in<bool> inp_a, inp_b, inp_cin;
		sc_out<bool> sum, co;
		SC_HAS_PROCESS(full_adder);
		full_adder(sc_module_name nm);

	private:
		sc_signal<bool> sig_1, sig_2, sig_3;
		xor_gate xor_gate1, xor_gate2;
		or_gate or_gate1;
		and_gate and_gate1, and_gate2;
};
