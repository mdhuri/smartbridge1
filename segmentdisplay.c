/*
 * segmentdisplay.c
 *
 * Created: 10-06-2019 10:04:02
 * Author : Madhu
 */ 

#include <avr/io.h>
#define F_CPU 1000000
#include <util/delay.h>
#include <stdlib.h>




int main(void)
{
    
    while (1) 
    {
		DDRD=0XFF;
		PORTD=0b00111111;
		
		_delay_ms(500);
		
		PORTD=0b00000110;
		
		_delay_ms(500);
		PORTD=0b01011011;
		
		_delay_ms(500);
		 PORTD=0b01001111;
		 
		 _delay_ms(500);
		 PORTD=0b01100110;
		 
		 _delay_ms(500);
		 PORTD=0b01101101;
		 
		 _delay_ms(500);
		 PORTD=0b01111101;
		 
		 _delay_ms(500);
		 PORTD=0b00000111;
		 
		 _delay_ms(500);
		 PORTD=0b01111111;
		 
		 _delay_ms(500);
		 PORTD=0b01001111;
		 
		 _delay_ms(500);
	}
    
}

