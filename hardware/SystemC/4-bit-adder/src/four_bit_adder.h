#include <systemc.h>
#include <full_adder.h>

SC_MODULE(four_bit_adder) {
	public:
		sc_in<bool> inp_a[4], inp_b[4], inp_cin;
		sc_out<bool> sum[4], co;

		SC_HAS_PROCESS(four_bit_adder);
		four_bit_adder(sc_module_name nm);

	private:
		sc_signal<bool> co_0, co_1, co_2;
		full_adder full_adder0, full_adder1, full_adder2, full_adder3;
};

