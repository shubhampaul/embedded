#include <systemc.h>
#include "four_bit_adder.h"
#include "tb.h"

SC_MODULE( SYSTEM ) {
	//Module Declarations
	tb *tb0;
	four_bit_adder *four_bit_adder0;

	//Local signal declarations
	sc_signal<bool> sig_inp_a[4], sig_inp_b[4],
	       	sig_inp_cin, sig_sum[4], sig_co;

	SC_HAS_PROCESS(SYSTEM);
	SYSTEM( sc_module_name nm) : sc_module (nm) {
		//Module instance signal connections
		tb0 = new tb("tb0");

		for (int i = 0; i < 4; i++) {
			tb0->inp_a[i]( sig_inp_a[i] );
			tb0->inp_b[i]( sig_inp_b[i] );
			tb0->sum[i]( sig_sum[i] );
		}

		tb0->inp_cin( sig_inp_cin );
		tb0->co( sig_co );

		four_bit_adder0 = new four_bit_adder("four_bit_adder0");
		for (int i = 0; i < 4; i++) {
                        four_bit_adder0->inp_a[i]( sig_inp_a[i] );
                        four_bit_adder0->inp_b[i]( sig_inp_b[i] );
                        four_bit_adder0->sum[i]( sig_sum[i] );
                }

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
	
	for (int i = 0; i < 4; i++) {
		char str[4];
		sprintf(str, "[%d]",i);
		sc_trace(pTraceFile, top->sig_inp_a[i], "inp_a" + std::string(str));
		sc_trace(pTraceFile, top->sig_inp_b[i], "inp_b" + std::string(str));
		sc_trace(pTraceFile, top->sig_sum[i], "sum" + std::string(str));
	}
	


	sc_trace(pTraceFile, top->sig_inp_cin, "inp_cin");
	sc_trace(pTraceFile, top->sig_co, "co");
	
	// Start the simulation
	sc_start();
	
	// Close the tracing
	sc_close_vcd_trace_file(pTraceFile);

	return 0;
}
