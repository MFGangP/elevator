#define F_CPU 16000000
#include <avr/io.h>
#include <avr/interrupt.h>
static unsigned char pattern[8]={0xFE,0xFD,0xFB,0xF7,0xEF,0xDF,0xBF,0x7F};
	
ISR(TIMER0_OVF_vect)
{
	static int index = 0;
	static char n_enter=0;
	TCNT0 = 100;
	n_enter++;
	if (n_enter == 20)
	{
		n_enter=0;
		PORTA = pattern[index++];
		if (index==8) index = 0;
	}
}

int main(void)
{
    DDRA = 0xFF;
	PORTA = 0xFF;
	
	TCCR0 = 0x00;
	TCNT0 = 100;
	
	TIMSK = (1<<TOIE0);
	
	TCCR0 |= (7<<CS00);
	
	sei();
	
    while (1); 
}

