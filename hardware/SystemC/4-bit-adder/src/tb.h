#include <systemc.h>

SC_MODULE( tb ) {

	public:
		sc_out<bool> inp_a[4], inp_b[4], inp_cin;
		sc_in<bool> sum[4], co;
		SC_HAS_PROCESS( tb );
		bool a[6][4];
		bool b[6][4];
		tb( sc_module_name nm );

	private:
		void source();
		void sink();
};
