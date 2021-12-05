#define F_CPU 16000000L
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

unsigned char p[16] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};

int interval;

ISR(INT4_vect)
{
	interval = 1;
}
ISR(INT5_vect)
{
	interval = 2;
}
ISR(INT6_vect)
{
	interval = -2;
}
ISR(INT7_vect)
{
	interval = -1;
}

int main(void)
{
	int i = 0;

	DDRB = 0xff;
	DDRD = 0x00;
	DDRA = 0xff;
	PORTD = 0xf0;
	
	EIMSK = 0xf0;
	EICRB = 0xaa;
	SREG = 0x80;
	
	PORTA = p[i];
	
	while(1){
	i = i + interval;
	if(i>=16) i= 0;
	if(i<0) i =15;
	_delay_ms(1000);
	}
}
