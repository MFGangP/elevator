
#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define MACRO 100

static int i,j = 0;
unsigned char p [16] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71};

ISR(INT0_vect)
{
	
	if(++i == 16)
	i = 0;//포트 b는 세그먼트 포트 a는 선택단자 d는 스위치 스위치는 업
	PORTA = 0x0e;
	PORTB = p[i];
	_delay_ms(MACRO);
	while (!(~PIND & 0x01)){
		_delay_ms(MACRO);
	}
	EIFR = (1<<INTF0);
	
}

ISR(INT1_vect)
{
	
	if(--j == -1)
	j = 15;
	PORTA = 0x0d;
	PORTB = p[j];
	_delay_ms(MACRO);
	while (!(~PIND & 0x01)){
		_delay_ms(MACRO);
	}
	EIFR = (1<<INTF0);
	
}

int main(void)
{
	
	DDRA = 0xff;
	DDRB = 0xff;
	PORTA = 0x00;
	PORTB = p[0];
	EICRA = (3<<ISC00);
	EIMSK = 0x03;
	sei();

	while(1)
	{
		PORTA = 0x0e;
		PORTB = p[i];
		_delay_us(200);
		PORTA = 0x0d;
		PORTB = p[j];
		_delay_us(200);
		
	}
}


