#ifndef _VIEW_LCD_TEXT_H_
#define _VIEW_LCD_TEXT_H_

#include "Arduino.h"
#include <LiquidCrystal_I2C.h>

extern LiquidCrystal_I2C lcd;
extern void View_LCD_Text_Init();
extern void ShowLCD(String nameDevice__, String valueDevice__, String valueDevice1__, String valueDevice2__);
#endif