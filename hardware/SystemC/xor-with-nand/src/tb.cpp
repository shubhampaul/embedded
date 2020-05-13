#include "tb.h"
#include <iostream>

tb::tb( sc_module_name nm ) : sc_module (nm) {
	SC_THREAD( source );
	SC_METHOD( sink );
	sensitive << inp_a << inp_b << out;
	cout << name() << " Constructed" << endl;
	cout << "time\tinp_a\tinp_b\tout" << endl;
}


void tb::source(){
	int i = 0;
	bool a[5] = {false, false, true, true, false};
	bool b[5] = {false, true, false, true, false};

	while(true)
	{
		wait(10, SC_NS);
		inp_a->write(a[i]);
		inp_b->write(b[i]);
		i++;
		if (i >= 5)
			sc_stop();
	}
}

void tb::sink(){
	cout << sc_time_stamp() << "\t" << inp_a << "\t" << inp_b << "\t" << out << endl;
}
