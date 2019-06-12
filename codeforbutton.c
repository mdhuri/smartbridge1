/*
 * codeforbutton.c
 *
 * Created: 12-06-2019 19:06:00
 * Author : Madhu
 */ 
#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#include <avr/io.h>
#include <util/delay.h>
int main(void)
{
	DDRC|=(1<<PC0);
	//OR DDRC=0X01;
	DDRD&=~(1<<PD0);
	//OR DDRD=0X00;
	while (1)
	{
		if((PIND&(1<<PD0))==0)
		{
			PORTC|=(1<<PC0);
			_delay_ms(3000);
			PORTC&=~(1<<PC0);
			
		}
	}
}

