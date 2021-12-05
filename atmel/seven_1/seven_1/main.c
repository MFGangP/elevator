#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>

unsigned char pattern[8]
={0x01,0x02,0x03,0x04,0x10,0x20,0x30,0x40};

int main(){

	int i=0;
	DDRA = 0xFF;
	DDRD = 0x00;
	PORTA = pattern[i];
	
	while(1)  {
		while(~PIND & 0X01);
		_delay_ms(200);
		if(++i==8)i=0;
		PORTA = pattern[i];
	}
}