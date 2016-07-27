#include <avr/io.h>

#include "lib/adc/adc.h"
/*
void Wait();

void Wait()
{
   uint8_t i;
   for(i=0;i<60;i++)
   {
      _delay_loop_2(0);
   }
}*/

int main(void)
{

   //Initialize ADC Peripheral
   InitADC();



    while(1)
    {
      int16_t x,y;

      x=ReadADC(0);  //Read ADC Channel 0
      y=ReadADC(1);  //Read ADC Channel 1

      x=x-512;    //512 is the mid point
      y=y-512;

      _delay_ms(250);
    }
}
//Internet
