#define  F_CPU 16000000L
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#define DELAY_TIME 100

int i,j = 0;
unsigned char pattern[16]
= { 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71
};


ISR(INT0_vect)
{
	if(--i==-1)
	i=15;
	PORTC = 0xfe;
	PORTA = pattern[i];
	_delay_ms(DELAY_TIME);
	while (~PIND & 0X01){
		_delay_ms(DELAY_TIME);
	}
	EIFR = (1<<INTF0);
}

ISR(INT1_vect)
{
	if(++j==16)
	j=0;
	PORTC = 0xfd;
	PORTA = pattern[j];
	_delay_ms(DELAY_TIME);
	while(~PIND & 0x01){
		_delay_ms(DELAY_TIME);
	}
	EIFR = (1<<INTF0);
}

int main(void)

{
	DDRA = 0Xff;  // 출력
	DDRC = 0Xff;
	PORTC = 0x00;
	PORTA = pattern [0];
	EICRA = (3<<ISC00);
	EIMSK = 0x03;
	sei();
	
	while (1) {
		PORTC = 0xfe;
		PORTA = pattern[i];
		_delay_us(100);
		PORTC = 0xfd;
		PORTA = pattern[j];
		_delay_us(100);
		
	}
	
}
