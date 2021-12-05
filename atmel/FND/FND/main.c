#define F_CPU 16000000L
#define MACRO 200
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	unsigned char p [16] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
	int i = 0;
	DDRF = 0x00;
	DDRC = 0x00;
	DDRB = 0xff;
	DDRE = 0xff;
	PORTB = p[i];

	while(1){
		while(PINF & 0x01)
		{
			if(--i==-1)i=15;
			PORTE = 0x0e;
			_delay_ms(MACRO);
			PORTB = p[i];
		   }
		while(PINC & 0x01)
		{
			if(++i==16)i=0;
			PORTE = 0x0d;
			_delay_ms(MACRO);
			PORTB = p[i];
		    }
	}
	}