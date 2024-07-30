#include "Makerlabvn_I2C_Motor_Driver.h"

Makerlabvn_I2C_Motor_Driver myDriver(0);

char tempInput = 0;

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(115200);
    Serial.println("Start Test, input from 1 to 4 (OFF)");
    Serial.println("Baud 115200, No line ending");
    myDriver.begin();
}

void loop()
{
    if (Serial.available() > 0)
    {
        tempInput = Serial.read();
        Serial.write(tempInput);
    }

    if (tempInput == '1')
    {
        myDriver.writeS1(45);
        myDriver.writeS2(135);
        myDriver.writeMA(1, 50);
        myDriver.writeMB(1, 50);
    }
    else if (tempInput == '2')
    {
        myDriver.writeS1(90);
        myDriver.writeS2(90);
        myDriver.writeMA(1, 0);
        myDriver.writeMB(1, 0);
    }
    else if (tempInput == '3')
    {
        myDriver.writeS1(135);
        myDriver.writeS2(45);
        myDriver.writeMA(0, 100);
        myDriver.writeMB(0, 100);
    }
    else if (tempInput == '4')
    {
        myDriver.writeS1(0);
        myDriver.writeS2(0);
        myDriver.writeMA(0, 0);
        myDriver.writeMB(0, 0);
    }
    tempInput = 0;
}