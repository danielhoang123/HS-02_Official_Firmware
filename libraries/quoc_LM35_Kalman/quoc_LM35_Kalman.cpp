#include "quoc_LM35_Kalman.h"

float quoc_lm35::getCalculated(){

  int sensorVal = analogRead(sensorPin);
  float voltage = sensorVal * 0.488;

  //kalman process
  Pc = P + varProcess;  //predict covariance
  Xp = Xe;              //predict state

  G = Pc/(Pc+varVolt);

  Zp = Xp;
  Xe =  G*(voltage-Zp)+Xp;
  P=(1-G)*Pc; 

  // Serial.print(voltage);
  // Serial.print(",");
  // Serial.print(Xe);

  SUM = SUM - READING[INDEX];

  READING[INDEX] = voltage;
  SUM = SUM + voltage;
  INDEX = (INDEX+1) % WINDOW_SIZE;

  AVERAGE = SUM / WINDOW_SIZE;

  // Serial.print(",");
  // Serial.println(AVERAGE);
  // delay(20);

  return AVERAGE;
}