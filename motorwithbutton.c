/* 
 * motorwithbutton.c
 *
 * Created: 11-06-2019 10:57:41
 * Author : Madhu
 */ 
#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#include <avr/io.h>
#include <util/delay.h>



int main(void)
{
	DDRC&=~(1<<PC0);
	DDRC&=~(1<<PC1); 
	
	
    DDRD=0XFF;
	
  
    while (1) 
    {	
		if((PINC&(1<<PC0))==0)
		{
		PORTD|=(1<<PD0);
		PORTD&=~(1<<PD1);
		_delay_ms(2000);
		
		}
		if((PINC&(1<<PC1))==0)
		{
			PORTD&=~(1<<PD0);
			PORTD|=(1<<PD1);
			_delay_ms(2000);
			
    }
	}
}

