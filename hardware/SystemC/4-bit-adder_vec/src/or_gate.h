#include <systemc.h>

SC_MODULE(or_gate) {
	public:
		sc_in<bool> inp_a, inp_b;
		sc_out<bool> out;

		SC_HAS_PROCESS(or_gate);

		or_gate(sc_module_name nm);

	private:
		void or_main(void);
};
