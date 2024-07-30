#include "SR04_Kalman.h"

double hbq_SR04::kalman(double U){

  static const double R = 40;
  static const double H = 1.00;
  static double Q = 10;
  static double P = 0;
  static double U_hat = 0;
  static double K = 0;
  K = P*H/(H*P*H+R);
  U_hat += + K*(U-H*U_hat);
  P = (1-K*H)*P+Q;
  return U_hat;

}

void hbq_SR04::usonic_transmit() {
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
}

double hbq_SR04::forLoopFunction(){

  duration = pulseIn(echo, HIGH);
  distance = (duration*.034)/2;
  kaldist = kalman(distance);

  // Serial.print("Corrected distance (in cm): ");
  // Serial.println(kaldist);
  
  //delay(1/30);

  return kaldist;
}