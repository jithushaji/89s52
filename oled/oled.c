#include "i2c.h"
#include "oled.h"

void send_cmd(char cmd)
{
  sda_write(0x00);
  sda_write(cmd);
}

