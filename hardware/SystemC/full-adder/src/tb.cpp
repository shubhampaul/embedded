#include "tb.h"
#include <iostream>

tb::tb( sc_module_name nm ) : sc_module (nm) {
	SC_THREAD( source );
	SC_METHOD( sink );
	sensitive << inp_a << inp_b << inp_cin << sum << co;
	cout << name() << " Constructed" << endl;
	cout << "time\tinp_a\tinp_b\tinp_cin\tsum\tco" << endl;
}


void tb::source(){
	int i = 0;
	bool a[9] = {false, false, false, false, true, true, true, true, false};
        bool b[9] = {false, false, true, true, false, false, true, true, false};
        bool c[9] = {false, true, false, true, false, true, false, true, false};

	while(true)
	{
		wait(10, SC_NS);
		inp_a->write(a[i]);
		inp_b->write(b[i]);
		inp_cin->write(c[i]);
		i++;
		if (i >= 9)
			sc_stop();
	}
}

void tb::sink(){
	cout << sc_time_stamp() << "\t" << inp_a << "\t" << inp_b << "\t" << inp_cin << "\t" << sum << "\t" << co << endl;
}
