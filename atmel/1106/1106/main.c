/*
 * 1106.c
 *
 * Created: 2019-11-06 오후 1:05:23
 * Author : user
 */ 
#define F_CPU 16000000L
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#define DEBOUNCING_DELAY 20
static volatile unsigned char duty = 50;

ISR(INT0_vect)
{
	duty += 50;
	if(duty >= 250) duty = 250;
	_delay_ms(DEBOUNCING_DELAY);
	while(~PIND & 0x01);
	_delay_ms(DEBOUNCING_DELAY);
	EIFR = (1<<INTF0);
}
ISR(INT1_vect)
{
	duty -= 50;
	if(duty <= 0) duty = 0;
	_delay_ms(DEBOUNCING_DELAY);
	while(~PIND & 0x02);
	_delay_ms(DEBOUNCING_DELAY);
	EIFR = (1<<INTF1);
}
int main(void)
{
	DDRB |=(1<<DDB4);
	TCCR0=(1<<WGM01)|(1<<WGM00)|(3<<COM00);
	EICRA = (2<<ISC10)|(2<<ISC00);
	EIMSK = (1<<INT0)|(1<<INT1);
	sei();
	TCCR0 |= (0x02<<CS00);
  
    while (1) 
    {
		OCR0 = duty;
    }
}

