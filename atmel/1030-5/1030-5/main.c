#define F_CPU 16000000	
#include <avr/io.h>
#include <avr/interrupt.h>

volatile int count = 0;
volatile int state = 0;

ISR(TIMER0_COMP_vect)
{
	count++;
	TCNT0 = 0;
	
}

int main(void)
{
	DDRB = 0x01;
	PORTB = 0x00;
	
	TCCR0 |=(1<<CS02)|(1<<CS01)|(1<<CS00);
	
	OCR0 = 128;
	
	TIMSK |= (1<<OCIE0);
	
	sei();
    /* Replace with your application code */
    while (1) {
		if (count == 64){
			count = 0;
			state = !state;
			if(state) PORTB = 0x01;
			else PORTB = 0x00;
		}
	}
}

