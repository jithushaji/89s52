#ifndef _OLED_H_
#define _OLED_H_

#define OLED_ADDR     0x78
#define OLED_ON       0xAF
#define OLED_OFF      0xAE


void send_cmd(char);

#endif