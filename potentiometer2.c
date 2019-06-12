#define F_CPU 1000000
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#define enable 5
#define registerselection 7
void send_a_command(unsigned char command);
void send_a_character(unsigned char character);
void send_a_string(char *string_of_character);


int main(void)
{
	DDRC=0XFF;
	DDRA=0X00;
	DDRD=0XFF;
	DDRB=0XFF;
	_delay_ms(50);
	ADMUX|=(1<<REFS0)|(1<<REFS1);
	ADCSRA|=(1<<ADEN)|(1<<ADATE)|(1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2);
	int count=0;
	char showa[3];
	send_a_command(0X01);
	_delay_ms(50);
	send_a_command(0x38);
	_delay_ms(50);
	send_a_command(0x0E);
	_delay_ms(50);
	while (1)
	{	
		count=ADC/4;
		send_a_command(0X80+0X40+0);
		send_a_string("Temp(C)= ");
		send_a_command(0X80+0X40+8);
		
		itoa(count,showa,10);
		send_a_string(showa);
		send_a_string("  ");
		send_a_command(0X80+0);
	_delay_ms(2000);
//*	if(count>=50)
	{
		PORTB|=(1<<PB0);
}
if(50<=count<=100)
{
	PORTB|=(1<<PB0);
	PORTB|=(1<<PB1);
}
if(100<=count<=150);
{
	PORTB|=(1<<PB0);
	PORTB|=(1<<PB1);
	PORTB|=(1<<PB2);
	PORTB|=(1<<PB3);
	PORTB|=(1<<PB4);

}
if(150<count<250)
{
	
	PORTB|=(1<<PB0);
	PORTB|=(1<<PB1);
	PORTB|=(1<<PB2);
	PORTB|=(1<<PB3);
	PORTB|=(1<<PB4);
	PORTB|=(1<<PB5);
	PORTB|=(1<<PB6);
	PORTB|=(1<<PB7);
}//*
	}
}
void send_a_command( unsigned char command)
{
	PORTC=command;
	PORTD&=~(1<<registerselection);
	PORTD|=(1<<enable);
	_delay_ms(50);
	PORTD&=~(1<<enable);
	PORTC=0;
}
void send_a_character(unsigned char character)
{
	PORTC=character;
	PORTD|=(1<<registerselection);
	PORTD|=(1<<enable);
	_delay_ms(50);
	PORTD&=~(1<<enable);
	PORTC=0;
}
void send_a_string(char *string_of_character)
{
	while(*string_of_character>0)
	{
		send_a_character(*string_of_character++);
	}
}


