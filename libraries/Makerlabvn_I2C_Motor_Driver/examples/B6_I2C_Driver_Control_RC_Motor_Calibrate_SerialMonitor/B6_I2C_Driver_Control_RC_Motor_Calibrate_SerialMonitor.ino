/*
* Description: 
*     This example will show you:
*         how to adjust pulse RC servo S1 (similar to S2) to calibrate Angle (0->180) on the module.
*         how to disable RC servo S1 (similar to S2) on the module which uses freeS1() function. Note: This function only works with analog RC Servo.
* How to use:
*     - After upload code to your Arduino board, open Serial Monitor (on Tools menu).
*       Choose "Both NL & CR" and "115200 baud"
*     - To set pulse for S1, example: Pulse Min = 460 (at 0 degree); Pulse Max = 2350 (at 180 degrees)
*         + Step 1:Setup pulse for 0 degree and 180 degrees
*             Type number 460 then hit Enter
*             Type 3001 then hit Enter  (3001: save number to Pulse Min)
*             Type 2350 then hit Enter
*             Type 3002 then hit Enter  (3002: save number to Pulse Max)
*      
*         + Step 2: Run test
*             Type numer 0 or 90 or 180 then hit Enter to see how RC motor run.
*     P/S: if RC motor runs incorrectly, try again with another pulse value (Pulse Min, Pulse Max)
*/
#include "Makerlabvn_I2C_Motor_Driver.h"

// Declare Module:
Makerlabvn_I2C_Motor_Driver myDriver(0);
unsigned int pulseMin = 460;
unsigned int pulseMax = 2350;
unsigned int pulseFromSerial = 0;

void setup() {
  Serial.begin(115200);
  // Init Module
  myDriver.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  SetRC_FromSerial();
}

void SetRC_FromSerial() {
  if(Serial.available()){
    unsigned int tempValue = Serial.readStringUntil('\n').toInt();

    Serial.println("Intput: " + String(tempValue));

    if(tempValue <= 300){                               // if (tempValue <= 300). We input tempValue in degree
      myDriver.writeS1(tempValue);
      Serial.println("Run " + String(tempValue) + " degree");

    }else if((tempValue > 300) && (tempValue < 2950)){  // if (300 < tempValue < 2550). We input tempValue in pulse (Micro second)
      myDriver.S1(tempValue);
      pulseFromSerial = tempValue;

    }else if(tempValue == 3001){
      pulseMin = pulseFromSerial;
      Serial.println("Set " + String(pulseFromSerial) + " us to PulseMin");
      myDriver.SetS1(pulseMin, pulseMax);

    }else if(tempValue == 3002){
      pulseMax = pulseFromSerial;
      Serial.println("Set " + String(pulseFromSerial) + " us to PulseMax");
      myDriver.SetS1(pulseMin, pulseMax);

    }else{
      myDriver.freeS1();  // Not work with digital RC Servo
      Serial.println("Free S1");
    }
    Serial.println("Setup pulse min: " + String(pulseMin));
    Serial.println("Setup pulse max: " + String(pulseMax));
  }
}