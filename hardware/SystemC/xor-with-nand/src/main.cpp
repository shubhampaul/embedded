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

	// Connect the modules
	top = new SYSTEM( "top" );
	
	// Set up the tracing
	sc_trace_file* pTraceFile = sc_create_vcd_trace_file("trace_file");
	sc_trace(pTraceFile, top->sig_inp_a, "inp_a");
	sc_trace(pTraceFile, top->sig_inp_b, "inp_b");
	sc_trace(pTraceFile, top->sig_out, "out");
	
	// Start the simulation
	sc_start();
	
	// Close the tracing
	sc_close_vcd_trace_file(pTraceFile);

	return 0;
}
