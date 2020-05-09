#define BTN_PIN 5
#define COUNT 64
#include"avr/io.h"

int main(void){
	unsigned char first, fail;
	do{
		first = 1 & (PINB >> BTN_PIN);
		fail = 0;
		for(int i = 0; i < COUNT; i++){
			if( first != (1 & (PINB >> BTN_PIN) ) ){
				fail = 1;
				break;
			}
		}
	} while (fail);
	return 0;
}


