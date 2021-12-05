/*
 * TEST1.c
 *
 * Created: 2019-09-18 오후 1:50:24
 * Author : user
 */ 

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB = 0xFF;
	DDRC = 0xFF;
	PORTB = 0xFF;
    while (1) 
    {
		PORTC = 0xA0;
		_delay_ms (500);
		PORTC = 0x50;
		_delay_ms (500);
		PORTC = 0x28;
		_delay_ms (500);
		PORTC = 0x14;
		_delay_ms (500);
		PORTC = 0x0A;
		_delay_ms (500);
		PORTC = 0x05;
		_delay_ms (500);
		PORTC = 0x82;
		_delay_ms (500);
		PORTC = 0x41;
		_delay_ms (500);
		
	
		
	
    }
}

