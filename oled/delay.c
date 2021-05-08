#include "delay.h"

void DELAY_us(int us_count)
 {    
    while(us_count!=0)
      {
         us_count--;
       }
 }
 
 void DELAY_ms(int ms_count)
 {
     while(ms_count!=0)
      {
         DELAY_us(112);     //DELAY_us is called to generate 1ms delay
          ms_count--;
      }

 }
 