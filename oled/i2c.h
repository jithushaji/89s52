#ifndef _I2C_H_
#define _I2C_H_

#define scl P2_0
#define sda P2_2

void clock_gen(int);
void sda_write(char);
void sda_start();
void sda_stop();

#endif