#include "Makerlabvn_I2C_Motor_Driver.h"

Makerlabvn_I2C_Motor_Driver myDriver(0);

unsigned long timeUpdate = 10; //10ms
unsigned long lastTimeUpdate = 0;
unsigned char speedDCMotor = 0; // 0->255 pwm
bool dirDCMotor = 0;            // 0 or 1
unsigned char angleRCValue = 0; // 0->180 degrees

void setup()
{
    // put your setup code here, to run once:
    myDriver.begin();
    Serial.begin(9600);
    Serial.println("Start test");
}

void loop()
{
    if (millis() - lastTimeUpdate >= timeUpdate)
    {
        lastTimeUpdate = millis();

        if (speedDCMotor == 0)
        {
            dirDCMotor = !dirDCMotor;
        }

        speedDCMotor = speedDCMotor + 1;
        angleRCValue = angleRCValue + 1;

        if (angleRCValue > 180)
        {
            angleRCValue = 0;
        }

        Serial.print("speedDCMotor: " + String(speedDCMotor) + "\t");
        Serial.print("angleRCValue: " + String(angleRCValue) + "\r\n");
    }

    myDriver.writeS1(angleRCValue);
    myDriver.writeS2(180 - angleRCValue);
    myDriver.MA(dirDCMotor, speedDCMotor);
    myDriver.MB(dirDCMotor, speedDCMotor);
    delay(1);
}