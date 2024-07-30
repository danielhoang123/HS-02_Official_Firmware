/*
  This example will show the second method control the DC motor
*/
#include "Makerlabvn_I2C_Motor_Driver.h"

Makerlabvn_I2C_Motor_Driver myDriver;
void setup() {
  // put your setup code here, to run once:
  myDriver.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  bool dirValue = 1;  // Direction (1 or 0)
  unsigned char pwmSpeedValue = 0;  // (0->255)
  myDriver.MA(dirValue, pwmSpeedValue);    // Stop motor A
  myDriver.MB(dirValue, pwmSpeedValue);    // Stop motor B
  delay(2000);

  dirValue = 1; // Direction 1
  pwmSpeedValue = 255; // 255 (Max Speed)  
  myDriver.MA(dirValue, pwmSpeedValue);    // Run motor A max Speed
  myDriver.MB(dirValue, pwmSpeedValue);    // Run motor B max Speed
  delay(2000);

  dirValue = 1; // Direction 1
  pwmSpeedValue = 127; // 50% speed
  myDriver.MA(dirValue, pwmSpeedValue);    // Run motor A half Speed
  myDriver.MB(dirValue, pwmSpeedValue);    // Run motor B half Speed
  delay(2000);

  dirValue = 1; // Direction 1
  pwmSpeedValue = 0; // 0 => Stop
  myDriver.MA(dirValue, pwmSpeedValue);    // Run motor A max Speed
  myDriver.MB(dirValue, pwmSpeedValue);    // Run motor B max Speed
  delay(2000);

  dirValue = 0; // Direction 0
  pwmSpeedValue = 127; // 50% speed
  myDriver.MA(dirValue, pwmSpeedValue);    // Run motor A half Speed
  myDriver.MB(dirValue, pwmSpeedValue);    // Run motor B half Speed
  delay(2000);

  dirValue = 0; // Direction 0
  pwmSpeedValue = 255; // 255 (Max Speed)  
  myDriver.MA(dirValue, pwmSpeedValue);    // Run motor A max Speed
  myDriver.MB(dirValue, pwmSpeedValue);    // Run motor B max Speed
  delay(2000);
}
