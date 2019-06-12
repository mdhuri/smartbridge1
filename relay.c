/*
 * relay.c
 *
 * Created: 11-06-2019 15:48:58
 * Author : Madhu
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
int main(void)
{
	DDRD=0XFF;
	DDRB=0X00;
	while (1)
	{
		if((PINB&(1<<PB0))==0)
		PORTD=0X01;
		_delay_ms(500);
	
    
	}
}