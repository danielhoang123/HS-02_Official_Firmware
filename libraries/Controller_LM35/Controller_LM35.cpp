#include "Controller_LM35.h"
#include "MachTest_SP_IO.h"
#include "debugkxn.h"

Controller_LM35_Data::Controller_LM35_Data()
{
  this->nameDevice = "LM35";
  this->timeInterval = 4000;
  this->valueDevice = "Ready";
  // Add your code here
}

bool Controller_LM35_Data::getData()
{
  // Add your code here
  int rawValue = analogRead(A0);                   // Đọc giá trị analog từ cảm biến LM35
  float voltage = (rawValue / 1023.0) * voltageReference; // Chuyển đổi giá trị analog thành điện áp
  float temperatureC = voltage * 100.0;                   // Chuyển đổi điện áp thành nhiệt độ theo độ C

  // Áp dụng bộ lọc Kalman
  float filteredTemperature = this->kalmanFilter->updateEstimate(temperatureC);

  // Hiển thị nhiệt độ trước và sau khi lọc
  // Serial.print("Raw Temperature: ");
  // Serial.print(temperatureC);
  // Serial.print(" C, Filtered Temperature: ");
  // Serial.print(filteredTemperature);
  // Serial.println(" C");

  // delay(1000); // Đợi 1 giây trước khi đọc giá trị tiếp theo

  this->valueDevice = String(filteredTemperature);

  return true;
}

bool Controller_LM35_Data::init()
{
  deInit();
  // Add your code here
  this->timeInterval = 100;
  this->kalmanFilter = new SimpleKalmanFilter(2, 2, 0.01);

  return 1;
}

bool Controller_LM35_Data::deInit()
{
  // Add your code here
  delete kalmanFilter;
  kalmanFilter = nullptr;
  // if(this->kalmanFilter != NULL){
  //   delete kalmanFilter;
  // }
  return 1;
}

Controller_LM35_Data LM35_Device;