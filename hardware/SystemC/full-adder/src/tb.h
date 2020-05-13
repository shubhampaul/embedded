#include <systemc.h>

SC_MODULE( tb ) {

	public:
		sc_out<bool> inp_a, inp_b, inp_cin;
		sc_in<bool> sum, co;
		SC_HAS_PROCESS( tb );
		tb( sc_module_name nm );

	private:
		void source();
		void sink();
};
