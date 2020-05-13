#include <systemc.h>

SC_MODULE( tb ) {

	public:
		sc_out<bool> inp_a, inp_b;
		sc_in<bool> out;
		SC_HAS_PROCESS( tb );
		tb( sc_module_name nm );

	private:
		void source();
		void sink();
};
