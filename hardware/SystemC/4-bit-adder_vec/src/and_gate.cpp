#include "and_gate.h"

and_gate::and_gate(sc_module_name nm) : sc_module (nm) {
        SC_METHOD(and_main);
        sensitive << inp_a << inp_b;
}

void and_gate::and_main(void) {
        out = inp_a & inp_b;
}
