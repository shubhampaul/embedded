#include <systemc.h>
#include <full_adder.h>

SC_MODULE(four_bit_adder) {
	public:
		sc_vector<sc_in<bool>> inp_a, inp_b;
	        sc_in<bool> inp_cin;
		sc_vector<sc_out<bool>> sum;
	        sc_out<bool> co;

		SC_HAS_PROCESS(four_bit_adder);
		four_bit_adder(sc_module_name nm);

	private:
		sc_signal<bool> co_0, co_1, co_2;
		full_adder full_adder0, full_adder1, full_adder2, full_adder3;
};

