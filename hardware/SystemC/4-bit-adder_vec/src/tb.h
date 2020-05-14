#include <systemc.h>

SC_MODULE( tb ) {

	public:
		sc_vector<sc_out<bool>> inp_a, inp_b;
	        sc_out<bool> inp_cin;
		sc_vector<sc_in<bool>> sum;
	        sc_in<bool> co;
		SC_HAS_PROCESS( tb );
		bool a[6][4];
		bool b[6][4];
		tb( sc_module_name nm );

	private:
		void source();
		void sink();
};
