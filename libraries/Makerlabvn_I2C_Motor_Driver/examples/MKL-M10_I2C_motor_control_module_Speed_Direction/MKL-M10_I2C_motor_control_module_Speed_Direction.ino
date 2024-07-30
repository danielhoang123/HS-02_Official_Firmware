#include "Makerlabvn_I2C_Motor_Driver.h"

Makerlabvn_I2C_Motor_Driver myDriver(0);

unsigned long timeDelay = 2000; //2000ms 

void setup()
{
    // put your setup code here, to run once:
    myDriver.begin();
}

void loop()
{
    myDriver.writeS1(45);
    myDriver.writeS2(135);
    myDriver.writeMA(1, 50);
    myDriver.writeMB(1, 50);
    delay(timeDelay);

    myDriver.writeS1(90);
    myDriver.writeS2(90);
    myDriver.writeMA(1, 0);
    myDriver.writeMB(1, 0);
    delay(timeDelay);

    myDriver.writeS1(135);
    myDriver.writeS2(45);
    myDriver.writeMA(0, 100);
    myDriver.writeMB(0, 100);
    delay(timeDelay);

    myDriver.writeS1(0);
    myDriver.writeS2(0);
    myDriver.writeMA(0, 0);
    myDriver.writeMB(0, 0);
    delay(timeDelay);
}