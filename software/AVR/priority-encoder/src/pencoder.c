#include"pencoder.h"
#include"avr/io.h"

int main(void){
	DDRB = 0;
	DDRC = 0xFF;
	PORTC = 0xFF;
	PORTB = 0xFF;

	while(1){
		priority_encoder();
	}
	return 0;
}

void one_to_one(void){
	PORTC = PINB;
}

void priority_encoder(void){
	for( int i=7; i >=0; i--){
		if( (~PINB) & (1<<i) ){
			PORTC = ~i;
			break;
		}
	}
}

