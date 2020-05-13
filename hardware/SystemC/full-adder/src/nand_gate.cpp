#include "nand_gate.h"

nand_gate::nand_gate(sc_module_name nm) : sc_module (nm) {
       SC_METHOD(nand_main);
       sensitive << inp_a << inp_b;
}


void nand_gate::nand_main(void) {
	out = ! (inp_a & inp_b);
}
