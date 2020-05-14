#include <systemc.h>
#include "nand_gate.h"

SC_MODULE(xor_gate) {


	private:

		/* Interconnects */
		sc_signal<bool> sig_1,sig_2,sig_3;

		/* Internal NAND gates of a XOR*/
		nand_gate nand_gate1, 
			  nand_gate2,
			  nand_gate3,
			  nand_gate4;


	public:
		sc_in<bool> inp_a, inp_b;
		sc_out<bool> out;
		SC_HAS_PROCESS(xor_gate);
		xor_gate(sc_module_name nm);
};
