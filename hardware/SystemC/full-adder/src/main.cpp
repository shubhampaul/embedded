#include <systemc.h>
#include "full_adder.h"
#include "tb.h"

SC_MODULE( SYSTEM ) {
	//Module Declarations
	tb *tb0;
	full_adder *full_adder0;

	//Local signal declarations
	sc_signal<bool> sig_inp_a, sig_inp_b,
	       	sig_inp_cin, sig_sum, sig_co;

	SC_HAS_PROCESS(SYSTEM);
	SYSTEM( sc_module_name nm) : sc_module (nm) {
		//Module instance signal connections
		tb0 = new tb("tb0");
		tb0->inp_a( sig_inp_a );
		tb0->inp_b( sig_inp_b );
		tb0->inp_cin( sig_inp_cin );
		tb0->sum( sig_sum );
		tb0->co( sig_co );

		full_adder0 = new full_adder("full_adder0");
		full_adder0->inp_a( sig_inp_a );
                full_adder0->inp_b( sig_inp_b );
		full_adder0->inp_cin( sig_inp_cin );
		full_adder0->sum( sig_sum );
                full_adder0->co( sig_co );

	}

	//Destructor
	~SYSTEM(){
		delete tb0;
		delete full_adder0;
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
	sc_trace(pTraceFile, top->sig_inp_cin, "inp_cin");
	sc_trace(pTraceFile, top->sig_sum, "sum");
	sc_trace(pTraceFile, top->sig_co, "co");
	
	// Start the simulation
	sc_start();
	
	// Close the tracing
	sc_close_vcd_trace_file(pTraceFile);

	return 0;
}
