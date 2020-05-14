#include "tb.h"
#include <iostream>

tb::tb( sc_module_name nm ) : sc_module (nm), inp_a("inp_a", 4), inp_b("inp_b", 4), sum("sum", 4) {
	SC_THREAD( source );
	SC_METHOD( sink );
	sensitive << sum[0] << sum[1] << sum[2] << sum[3] << co;
	cout << name() << " Constructed" << endl;
	cout << "time\tinp_a\tinp_b\tinp_cin\tsum\tco" << endl;
}


void tb::source(){

	int i = 0, j = 0;
	bool a[6][4] = {{0,1,0,0}, 
		        {0,0,0,1},
			{0,0,1,0},
			{0,1,0,0},
			{1,0,0,0},
			{0,0,0,1}};

        bool b[6][4] = {{0,1,0,0},
		        {0,0,0,1},
			{0,0,1,0},
			{0,1,0,0},
			{1,0,0,0},
			{0,0,0,1}};

	while(true) {
		wait(10, SC_NS);
		for (j = 0; j <= 3; j++) {
			inp_a[j]->write(a[i][3-j]);
			inp_b[j]->write(b[i][3-j]);
		}
		inp_cin->write(true);
		i++;
		if (i >= 7)
			sc_stop();
	}
}

void tb::sink(){
	cout << sc_time_stamp();
	cout << "\t" << inp_a[3] << inp_a[2] << inp_a[1] << inp_a[0];
	cout << "\t" << inp_b[3] << inp_b[2] << inp_b[1] << inp_b[0];
	cout << "\t" << inp_cin;
	cout << "\t" << sum[3] << sum[2] << sum[1] << sum[0];
	cout << "\t" << co << endl;	
}
