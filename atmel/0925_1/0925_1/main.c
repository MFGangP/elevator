#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	char pattern_value = 0x01;
	DDRD = 0xFF;

	/* Replace with your application code */
	while (1)
	{
		PORTD = pattern_value;
		pattern_value <<= 1;
		if(pattern_value == 0) pattern_value = 0x01;
		_delay_ms(1000);
	}
}


