#include <systemc.h>

SC_MODULE(nand_gate) {
	public:
		sc_in<bool> inp_a, inp_b;
		sc_out<bool> out;
		SC_HAS_PROCESS(nand_gate);
		nand_gate(sc_module_name nm);

	private:
		void nand_main(void);
};
