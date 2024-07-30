// #ifndef SR04_Kalman_h
// #define SR04_Kalman_h

#include "Arduino.h"

class hbq_SR04{

  public:
  const int echo = 7;
  const int trig = 6;

  double kalman(double U);
  void usonic_transmit();
  double forLoopFunction();

  private:
  const int maxdist = 335;
  const float mindist = 2.5;

  double distance, duration;
  double kaldist;
  double U;
};