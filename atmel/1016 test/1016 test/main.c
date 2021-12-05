#define F_CPU 16000000L
#define MACRO 200
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
unsigned char p [16] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};

ISR(INT0_vect)
{
	static int i=0;
	if(++i==16) i=0;
	_delay_ms(MACRO);
	while(PIND & 0x01);
	_delay_ms(MACRO);
	PORTE = 0x0e;
	PORTB = p[i];
}

ISR(INT1_vect)
{
	static int z=0;
	if(--z==-1) z=15;
	_delay_ms(MACRO);
	while(PIND & 0x02);
	_delay_ms(MACRO);
	PORTE = 0x0d;
	PORTB = p[z];
}

int main(void)
{
	DDRD = 0x00;
	DDRB = 0xff;
	DDRE = 0xff;
	
	EICRA = (3<<ISC00)|(3<<ISC10);
	EIMSK = (0<<INT0)|(0<<INT1);
	sei();

	while(1){
		    }
	
	}
