#ifndef F_CPU                                                                                          
#define F_CPU 16000000UL                                                                
#endif
#include<avr/io.h>  
#include<stdlib.h> 
#include<string.h>                                                                             
#include<util/delay.h>                                                                           
#include<avr/interrupt.h>

void CMD ()
{
 PORTB&=~(1<<0);                                                                           
 PORTB&=~(1<<1);                                                                         
 PORTB|=(1<<2);                                                                              
 _delay_ms(10);
 PORTB&=~(1<<2);
 _delay_ms(10);                                                                           
}

void DATA ()
{
 PORTB|=(1<<0);                               
 PORTB&=~(1<<1);                                                                        
 PORTB|=(1<<2);                                                                         
 _delay_ms(10);
 PORTB&=~(1<<2);
 _delay_ms(10);                                                                        
}

void LCD_INIT()
{

PORTC=0x38;
CMD ();
_delay_ms(10);
PORTC=0x0E;
CMD ();
_delay_ms(10);
PORTC=0x01;
CMD ();
_delay_ms(10);
PORTC=0x06;
CMD ();
_delay_ms(10);

PORTC=0x80;
CMD ();


PORTC=0x00;
}
unsigned int a,b,i,x,y,z;
char f[3];
int main()
{
 
 

 ADMUX|=(1<<ADLAR);
 DDRD=0xFF;
 DDRB=0x07;                                                    

 DDRC=0xFF;
 sei();
 DDRA=0x00;


 LCD_INIT();

 _delay_ms(10);

 b=0;
 ADCSRA=0xCF;



 while(1)
 {	
	if(b==0)
	{
	ADMUX&=~(1<<0);
	ADMUX&=~(1<<1);
	_delay_ms(1);
	ADCSRA|=0x40;
	_delay_ms(30);

	x=ADCH;

	b=1;
	_delay_ms(1);
	
 	}
	
	if(b==1)
	{
	ADMUX|=(1<<0);
	_delay_ms(10);
	ADCSRA|=0x40;
	_delay_ms(100);
	
	y=ADCH;
	PORTC=0x80;
	CMD();
	if((y>=240)&&(x<170)&&(x>120))
	{
	PORTC=0x80;
	CMD();


	PORTC='N';
	DATA();

	_delay_ms(1);
	PORTC=' ';
	DATA();
	_delay_ms(1000);
	}
	
	if((y<=50)&&(x<170)&&(x>120))
	{
	PORTC=0x80;
	CMD();


	PORTC='S';
	DATA();
	_delay_ms(1);

	PORTC=' ';
	DATA();
	_delay_ms(1000);

	}

	if((x>=240)&&(y<170)&&(y>120))
	{
	PORTC=0x80;
	CMD();


	PORTC='E';
	DATA();
	_delay_ms(1);
	PORTC=' ';
	DATA();

	_delay_ms(1000);

	}
	if((x<=70)&&(y<170)&&(y>110))
	{
	PORTC=0x80;
	CMD();


	PORTC='W';
	DATA();

	_delay_ms(1);
	PORTC=' ';
	DATA();
	_delay_ms(1000);

	}

	if((x>230)&&(y<40))
	{
	PORTC=0x80;
	CMD();


	PORTC='S';
	DATA();
	_delay_ms(1);
	PORTC='E';
	DATA();
	_delay_ms(1000);

	}

	if((x>240)&&(y>240))
	{
	PORTC=0x80;
	CMD();


	PORTC='N';
	DATA();
	_delay_ms(1);
	PORTC='E';
	DATA();
	_delay_ms(1000);

	}

	if((x<30)&&(y<30))
	{

	PORTC=0x80;
	CMD();

	PORTC='S';
	DATA();
	_delay_ms(1);
	PORTC='W';
	DATA();
	_delay_ms(1000);


	}

	if((x<50)&&(y>190))
	{

	PORTC=0x80;
	CMD();

	PORTC='N';
	DATA();
	_delay_ms(1);
	PORTC='W';
	DATA();
	_delay_ms(1000);

	}

	if((x<180)&&(y>110)&&(x>70)&&(y<160))
	{
	PORTC=0x80;
	CMD();
	_delay_ms(1);

	PORTC='C';
	DATA();


	PORTC=' ';
	DATA();
	_delay_ms(1000);

	}
	
	else
	{
	PORTC=0x80;
	CMD();
	_delay_ms(1);
	}

	b=0;

 	}

	
 }
return 0;
}


ISR(ADC_vect)
{
	ADCSRA|=0x40;
}

