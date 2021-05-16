#include <REGX51.H>
#include "i2c.h"
#include "oled.h"

void main()
{
  clock_gen(9600);
  sda_start();
  sda_write(OLED_ADDR);
  send_cmd(OLED_ON);
  sda_stop();
}
