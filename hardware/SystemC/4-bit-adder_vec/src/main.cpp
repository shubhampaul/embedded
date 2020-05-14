#include <systemc.h>
#include "four_bit_adder.h"
#include "tb.h"

SC_MODULE( SYSTEM ) {
	//Module Declarations
	tb *tb0;
	four_bit_adder *four_bit_adder0;

	//Local signal declarations
	sc_vector<sc_signal<bool>> sig_inp_a, sig_inp_b, sig_sum;
	sc_signal<bool> sig_inp_cin, sig_co;

	SC_HAS_PROCESS(SYSTEM);
	SYSTEM( sc_module_name nm) : sc_module (nm), sig_inp_a("sig_inp_a", 4), sig_inp_b("sig_inp_b", 4), sig_sum("sig_sum", 4) {

		//Module instance signal connections
		tb0 = new tb("tb0");

		tb0->inp_a( sig_inp_a );
                tb0->inp_b( sig_inp_b );
                tb0->sum( sig_sum );

		tb0->inp_cin( sig_inp_cin );
		tb0->co( sig_co );

		four_bit_adder0 = new four_bit_adder("four_bit_adder0");
                four_bit_adder0->inp_a( sig_inp_a );
                four_bit_adder0->inp_b( sig_inp_b );
                four_bit_adder0->sum( sig_sum );

		four_bit_adder0->inp_cin( sig_inp_cin );
                four_bit_adder0->co( sig_co );

	}

	//Destructor
	~SYSTEM(){
		delete tb0;
		delete four_bit_adder0;
	}


};

SYSTEM *top = NULL;
 
int sc_main( int argc, char* argv[] ){

	// Connect the modules
	top = new SYSTEM( "top" );
	
	// Set up the tracing
	sc_trace_file* pTraceFile = sc_create_vcd_trace_file("trace_file");

	sc_trace(pTraceFile, top->sig_inp_cin, "inp_cin");

	// Trace vector objects 
	sc_trace(pTraceFile, top->sig_inp_a[3], "inp_a");
	sc_trace(pTraceFile, top->sig_inp_a[2], "inp_a");
	sc_trace(pTraceFile, top->sig_inp_a[1], "inp_a");
	sc_trace(pTraceFile, top->sig_inp_a[0], "inp_a");

	sc_trace(pTraceFile, top->sig_inp_b[3], "inp_b");
	sc_trace(pTraceFile, top->sig_inp_b[2], "inp_b");
	sc_trace(pTraceFile, top->sig_inp_b[1], "inp_b");
	sc_trace(pTraceFile, top->sig_inp_b[0], "inp_b");

	sc_trace(pTraceFile, top->sig_sum[3], "sum");
	sc_trace(pTraceFile, top->sig_sum[2], "sum");
	sc_trace(pTraceFile, top->sig_sum[1], "sum");
	sc_trace(pTraceFile, top->sig_sum[0], "sum");

	sc_trace(pTraceFile, top->sig_co, "co");
	
	// Start the simulation
	sc_start();
	
	// Close the tracing
	sc_close_vcd_trace_file(pTraceFile);

	return 0;
}
