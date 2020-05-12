#include <systemc.h>
#include "adder.h"
#include "tb.h"

SC_MODULE( SYSTEM ) {
	//Module Declarations
	tb *tb0;
	adder *adder0;

	//Local signal declarations
	sc_signal<bool> rst_sig;
	sc_signal< sc_int<16> > inp_sig_a, inp_sig_b;
	sc_signal< sc_int<16> > outp_sig;
	sc_clock clk_sig;

	//Handshaking
	sc_signal<bool> inp_sig_vld;
	sc_signal<bool> inp_sig_rdy;
	sc_signal<bool> outp_sig_vld;
	sc_signal<bool> outp_sig_rdy;


	SC_CTOR( SYSTEM )
		//Copy constructor clk_sig
		: clk_sig ("clk_sig", 10, SC_NS)
	
	{
		//Module instance signal connections
		tb0 = new tb("tb0");
		tb0->clk( clk_sig );
		tb0->rst( rst_sig );
		tb0->inp_a( inp_sig_a );
		tb0->inp_b( inp_sig_b );
		tb0->inp_vld( inp_sig_vld );
		tb0->inp_rdy( inp_sig_rdy );
		tb0->outp( outp_sig );
		tb0->outp_vld( outp_sig_vld );
		tb0->outp_rdy( outp_sig_rdy );

		adder0 = new adder("adder0");
		adder0->clk( clk_sig );
		adder0->rst( rst_sig );
		adder0->inp_a( inp_sig_a );
		adder0->inp_b( inp_sig_b );
		adder0->inp_vld( inp_sig_vld );
                adder0->inp_rdy( inp_sig_rdy );
		adder0->outp( outp_sig );
		adder0->outp_vld( outp_sig_vld );
                adder0->outp_rdy( outp_sig_rdy );
	}

	//Destructor
	~SYSTEM(){
		delete tb0;
		delete adder0;
	}


};

SYSTEM *top = NULL;

int sc_main( int argc, char* argv[] ){
	top = new SYSTEM( "top" );
	sc_start();
	return 0;
}
