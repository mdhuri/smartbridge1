/*
 * usart.c
 *
 * Created: 13-06-2019 11:25:37
 
 * Author : Madhu
 */ 
#ifndef F_CPU
#define F_CPU16000000UL
#endif
#include <avr/io.h>
#include <inttypes.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define LED PORTB
char buffer[10];
 
void USARTINIT(uint16_t ubrr_value)
{
	UBRRL=ubrr_value;
	UBRRH=(ubrr_value>>8);
	UCSRC=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
	UCSRB=(1<<RXEN)|(1<TXEN);
}
char USARTReadchar()
{
	while(!(UCSRA&(1<<RXC)))
	{
		//do nothing
	}
	return UDR;
}
void USARTwritechar(char data)
{
	while(!(UCSRA & (1<<UDRE)))
	{
		// Do nothing
	}
	UDR=data;
}
int main(void)
{
   
    USARTINIT(77);
	DDRB=0XFF;
	char data;
	LED=0;
	while(1)
	{
		data=USARTReadchar();
		if(data=='1')
		{
			LED|=0XFF;
		}
		else if(data=='2')
		{
			LED=0X00;
		}
		return 0;
		}
}

