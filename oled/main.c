#include <REGX51.H>
#include "i2c.h"


void main()
{
  clock_gen(9600);
  sda_start();
  sda_write(0x75);
  sda_write(0xAA);
  sda_write(0xBA);
  sda_write(0x1A);
  sda_write(0xB1);
  sda_write(0x71);
  sda_stop();
}
