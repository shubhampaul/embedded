#include "or_gate.h"

or_gate::or_gate(sc_module_name nm) : sc_module (nm) {
	SC_METHOD(or_main);
	sensitive << inp_a << inp_b;
}

void or_gate::or_main(void) {
	out = inp_a | inp_b;
}
