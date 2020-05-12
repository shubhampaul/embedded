#include <systemc.h>

SC_MODULE( adder ){

	sc_in<bool> clk;
        sc_in<bool> rst;

	sc_in< sc_int<16> > inp_a;
	sc_in< sc_int<16> > inp_b;
	sc_in<bool> inp_vld;
	sc_out<bool> inp_rdy;

	sc_out< sc_int<16> > outp;
	sc_out<bool> outp_vld;
	sc_in<bool> outp_rdy;

	void adder_main();

	SC_CTOR( adder ){
		SC_CTHREAD( adder_main, clk.pos() );
		reset_signal_is( rst, true );
	}
};
