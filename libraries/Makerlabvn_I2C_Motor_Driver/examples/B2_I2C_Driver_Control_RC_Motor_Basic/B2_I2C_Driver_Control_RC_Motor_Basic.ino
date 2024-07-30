/*
* Description: 
*     This example will show you how to control 2 RC servo (S1, S2) on the module.
*/
#include "Makerlabvn_I2C_Motor_Driver.h"

// Declare Module:
Makerlabvn_I2C_Motor_Driver myDriver(0);

void setup() {
  // Init Module
  myDriver.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned char AngleInDegree = 0;
  myDriver.writeS1(AngleInDegree);
  myDriver.writeS2(AngleInDegree);
  delay(2000);

  myDriver.writeS1(90);   // S1: 90 degrees
  myDriver.writeS2(45);   // S2: 45 degrees
  delay(2000);
  
  myDriver.writeS1(180);  // S2: 180 degrees
  myDriver.writeS2(180);  // S2: 180 degrees
  delay(2000);

  myDriver.freeS2();  // Disable (stop) RC Motor at S2. This function only works with analog RC Servo like MG996
  delay(4000);
  
}
