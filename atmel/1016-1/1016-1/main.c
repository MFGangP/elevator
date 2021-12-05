/*
 * 1016 test.c
 *
 * Created: 2019-10-16 오후 4:05:29
 * Author : user
 */ 
#define F_CPU 16000000L
#include <avr/io.h>
#include <avr/interrupt.h>
unsigned char p [16] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
	
ISR(INT0_vect)
{
	static int i=0;
	if(++i==16) i=0;
	PORTB = p[i];
}



int main(void)
{
  
		DDRB = 0xff;
		PORTB = p[0];
		EICRA = (2<<INT0);
		EIMSK = (1<<INT0);
		sei();
		while (1);
}

