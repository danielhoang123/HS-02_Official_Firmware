#include "Arduino.h"

class quoc_lm35{
  public:

  const int sensorPin = A0;
  float getCalculated();

  private:

  //kalman variables
  float varVolt = 1.12184278324081E-05;
  float varProcess = 1e-8;
  float Pc = 0.0;
  float G = 0.0;
  float P = 1.0;
  float Xp = 0.0;
  float Zp = 0.0;
  float Xe = 0.0;

  int WINDOW_SIZE = 50;
  int INDEX = 0;
  float VALUE = 0;
  float SUM = 0;
  float READING[50];
  float AVERAGE = 0;
  
};