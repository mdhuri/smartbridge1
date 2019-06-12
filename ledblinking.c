/*
 * ledblinking.c
 *
 * Created: 12-06-2019 18:57:17
 * Author : Madhu
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include<util/delay.h>


int main(void)
{
	DDRD=0XFF;
	while (1)
	{
		PORTD=0XFF;
		_delay_ms(220);
		PORTD=0X00;
		_delay_ms(220);
	}
}



