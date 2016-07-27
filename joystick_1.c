#ifndef F_CPU
#define F_CPU 1000000UL
#endif
#include<avr/io.h>
#include<util/delay.h>

//int a=0;
int main(void)
{

DDRD=0xF0; //0123 in input and 4567 in output mode
PORTD=0x0F;
//DDRB=0xff;
 while (1) 
{
PORTD&=~(1<<4);
PORTD&=~(1<<6);

if(~PIND &(1<<1))

{
PORTD|=(1<<4);
}

if(PIND &(1<<1))

{
PORTD|=(1<<6);
}

else
{
PORTD&=~(1<<4);
PORTD&=~(1<<6);


}

}

}

