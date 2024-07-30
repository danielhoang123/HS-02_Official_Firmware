/*
*  How to use:
*    - After upload code to your Arduino board, open Serial Monitor (on Tools menu).
*       Choose "Both NL & CR" and "115200 baud"
*/
#include "Makerlabvn_I2C_Motor_Driver.h"

Makerlabvn_I2C_Motor_Driver myDriver; // Defaule ID = 0. Ex: myDriver <=> myDriver(0)
void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Example Set the ID for MKL-M10 I2C motor control module");
  Serial.println("Please only connect one module at a time");
  Serial.println("ID\tI2C Address");
  Serial.println("0 \t    64");
  Serial.println("1 \t    65");
  Serial.println("2 \t    66");
  Serial.println("3 \t    67");
  Serial.println("4 \t    68");

  Serial.println("Input number 0 -> 4 to set the ID for your driver");

  myDriver.begin();
}

void loop()
{
  // put your main code here, to run repeatedly:
  if (Serial.available())
  {
    unsigned int idNumber = Serial.readStringUntil('\n').toInt();

    if (idNumber <= 4)
    {
      I2C_Driver_Error_Code result = myDriver.setAddress(idNumber);

      switch (result)
      {
      case I2C_MOTOR_DRIVER_CODE_SUCCESS:
        Serial.println("****Set Address Success****");
        Serial.println("Example declare:");
        if (idNumber > 0)
          Serial.println("Makerlabvn_I2C_Motor_Driver myDriver(" + String(idNumber) + ");");
        else
        {
          Serial.println("Makerlabvn_I2C_Motor_Driver myDriver;");
          Serial.println("Or");
          Serial.println("Makerlabvn_I2C_Motor_Driver myDriver(0);");
        }

        break;
      case I2C_MOTOR_DRIVER_CODE_NOT_CONNECT:
        Serial.println("Please Check Wiring (Power Port and I2C Port)");
        break;
      case I2C_MOTOR_DRIVER_CODE_INVALID_ADDRESS:
        Serial.println("INVALID ID. Please input the number 0 -> 4 to set the ID for your driver module");
        break;
      default:
        Serial.println("Input number 0 -> 4 to set the ID for your driver");
      }
    }
  }
}
