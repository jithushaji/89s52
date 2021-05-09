#include <REGX51.H>
#include "i2c.h"

char sda_data = 0;
int sda_bit = 0;
int sda_begin = 0;
int sda_end = 0;
int sda_strt = 0;
int sda_ack = 0;
int sda_ = 0;


void clock_gen(int rate)
{
  TMOD = 0x20;
  TL1 = 256-(28800/rate);
  TH1 = TL1;
  EA = 1;
  ET1 = 1;
  TR1 = 1;
}

void sda_write(char c)
{
  sda_data = c;
  sda_begin = 1;
  while(sda_begin);
}

void sda_start()
{
  sda_strt = 1;
}

void sda_stop()
{
  sda_end = 1;
}

void intr_ser(void) interrupt 3
{
   
   if((scl == 0) && (sda_begin == 1) && (sda_ == 1))
     {
      sda = ((sda_data >> sda_bit++) & 0x01);
      if(sda_bit >= 8)
        {
          sda_begin = 0;
          sda_ack = 1;
          //sda = 1;      //ack bit
          sda_bit = 0;    //what i need is GO TO THE NEXT BYTE FROM HERE !!!!!
          goto here;
        }
      } 
     
    scl =(~scl);  // clock
      
    if((sda_ack == 1) && (scl == 0))  // acknowledge
    {
      sda = 1;
      sda_ack = 0;
    }
    here:
   if((scl == 1) && (sda_strt == 1))  // send start condition
    {  
      sda = 0;
      sda_strt = 0;
      sda_ = 1;
    }

   if ((scl == 1) && (sda_end == 1))  // send stop condition
     {
       sda = 1;
       sda_end = 0;
       sda_= 0;
     }
     
}
