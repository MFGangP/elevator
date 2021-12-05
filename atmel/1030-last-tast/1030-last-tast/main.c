#define  F_CPU 16000000L
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#define DELAY_TIME 200
#include "lcd.h"

static int i = 0;

unsigned char pattern[9]
= { 0x5B, 0x3F, 0x06, 0x66, 0x3F, 0x66, 0x3F, 0x5B, 0x5B};

ISR(INT0_vect)
{
	lcd_init();
	lcd_string("EMERGENCY");
	
	DDRE = 0Xff;//LED
	
	for (int i=0;i<10;i++)
	{
		PORTE = 0xff;
		_delay_ms(500);
		PORTE = 0x00;
		_delay_ms(500);
	}

}

ISR(INT1_vect)
{
	lcd_init();
	lcd_string("201404022 PSH");

	DDRB = 0xff;
	
	for(int i=0;i<9;i++){
		PORTB = pattern[i];
		_delay_ms(DELAY_TIME);
	}

}

int main(void)

{
	DDRE = 0Xff;//LED
	DDRA = 0Xff;  // lcd
	DDRC = 0Xff;  // lcd sw
	DDRB = 0Xff;  // seg
	DDRD = 0x00;
	PORTD = 0xff;
	PORTB = pattern [i];
	EICRA |= (3<<ISC00)|(3<<ISC00);
	EIMSK = 0x03;
	sei();
	
	while (1) {

	}
	
}
