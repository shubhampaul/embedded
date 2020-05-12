#include "adder.h"

void adder::adder_main(void){

	// Reset
	
	//Initializa handshake
	inp_rdy.write( 0 );
	outp_vld.write( 0 );

	outp.write( 0 );
	wait();

	while( true ){

		sc_int<16> in_val_a, in_val_b;
		sc_int<16> out_val;

		inp_rdy.write( 1 );
		do{
			wait();
		} while ( !inp_vld.read() );
		in_val_a = inp_a.read();
		in_val_b = inp_b.read();
		inp_rdy.write( 0 );

		//Implement adder
		out_val = in_val_a + in_val_b;
		
		outp_vld.write( 1 );
		outp.write( out_val );
		do{
			wait();
		} while ( !outp_rdy.read() );
		outp_vld.write( 0 );
	}
}
