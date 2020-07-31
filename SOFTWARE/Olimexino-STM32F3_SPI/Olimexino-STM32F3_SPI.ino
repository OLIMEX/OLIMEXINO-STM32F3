/*
 * Simple SPI demo using MOD-LCD3310 module
 * This demo prints on the screen the messages
 * shown in the setup function with inverted
 * colors on rows 0, 2, 4.
 */

#include "lcd3310_SPI.h"

void setup ()
{
  LCDInit();
  LCDContrast(0x70);
  LCDStr(0, (unsigned char *)"*** OLIMEX ***", 1);
  LCDStr(1, (unsigned char *)"   OLIMEXINO  ", 0);
  LCDStr(2, (unsigned char *)"   STM32F3 +  ", 1);
  LCDStr(3, (unsigned char *)"  MOD-LCD3310 ", 0);
  LCDStr(4, (unsigned char *)"   using SPI  ", 1);
  LCDStr(5, (unsigned char *)"   interface  ", 0);
}

void loop ()
{
}
