#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000L

unsigned char pattern[8]
={0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08};

int main(){

	int i=0;
	DDRA =0xFF;
	PORTA = pattern[i];
	while(1)  { //무한루프
		_delay_ms(1000);
		if(++i==8)i=0;
		PORTA = pattern[i];
	}
}