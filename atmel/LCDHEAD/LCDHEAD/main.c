#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"

int main(void)
{
	lcd_init();
	lcd_string("hellow avr");
}



