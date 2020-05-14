#include <systemc.h>

SC_MODULE(and_gate) {
        public:
                sc_in<bool> inp_a, inp_b;
                sc_out<bool> out;

                SC_HAS_PROCESS(and_gate);

                and_gate(sc_module_name nm);

        private:
                void and_main(void);
};

