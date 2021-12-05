#define F_CPU 16000000L
#define MACRO 200
#include <avr/io.h>
#include <util/delay.h>

unsigned char pattern[16]
={0x3f,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};

int main(void){

	int i=0;
	DDRA = 0xFF;
	DDRD = 0x00;
	DDRB = 0x00;
	PORTA = pattern[i];
	
	while(1)  {
		
		while (~PINB & 0X01);
			{
			   if(++i==16)i=0;
			   PORTA = pattern[i];
			   _delay_ms(MACRO);
			}
	}
}