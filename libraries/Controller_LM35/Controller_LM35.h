#ifndef Controller_LM35_H__
#define Controller_LM35_H__
#include "dataAdapter.h"

// include your Libraries here
#include <SimpleKalmanFilter.h>

class Controller_LM35_Data : public Data_Adapter
{
public:
  // Add your declare here
  // quoc_lm35 lm35x;
  SimpleKalmanFilter *kalmanFilter;
  const float voltageReference = 5.0;
  // double value;
  // double celcius;
  // // Khai báo biến và cấu hình bộ lọc Kalman
  // float Q = 0.001; // Noise covariance process
  // float R = 1;     // Noise covariance measurement
  // float P = 1;     // Estimate error covariance
  // float K = 0;     // Kalman Gain
  // float X = 0;     // Value
  Controller_LM35_Data();
  virtual ~Controller_LM35_Data(){};
  bool getData();
  bool init();
  bool deInit();
};

extern Controller_LM35_Data LM35_Device;
#endif