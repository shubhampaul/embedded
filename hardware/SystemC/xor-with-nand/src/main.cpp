#include <systemc.h>
#include "xor_gate.h"
#include "tb.h"

SC_MODULE( SYSTEM ) {
	//Module Declarations
	tb *tb0;
	xor_gate *xor_gate0;

	//Local signal declarations
	sc_signal<bool> sig_inp_a, sig_inp_b, sig_out;

	SC_HAS_PROCESS(SYSTEM);
	SYSTEM( sc_module_name nm) : sc_module (nm) {
		//Module instance signal connections
		tb0 = new tb("tb0");
		tb0->inp_a( sig_inp_a );
		tb0->inp_b( sig_inp_b );
		tb0->out( sig_out );

		xor_gate0 = new xor_gate("xor_gate0");
		xor_gate0->inp_a( sig_inp_a );
                xor_gate0->inp_b( sig_inp_b );
                xor_gate0->out( sig_out );
	}

	//Destructor
	~SYSTEM(){
		delete tb0;
		delete xor_gate0;
	}


};

SYSTEM *top = NULL;

int sc_main( int argc, char* argv[] ){

	top = new SYSTEM( "top" );
	sc_start();

	return 0;
}
