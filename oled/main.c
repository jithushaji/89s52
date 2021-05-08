#include <REGX51.H>
#include "i2c.h"


void main()
{
  clock_gen(9600);
  sda_start();
  sda_write(0x75);
  sda_write(0x95);
  sda_stop();
  //while(1);
}
