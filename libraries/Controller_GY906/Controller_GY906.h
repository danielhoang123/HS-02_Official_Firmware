#ifndef Controller_GY906_H__
#define Controller_GY906_H__
#include "Model_I2C_Device.h"

// include your Libraries here
#include <Adafruit_MLX90614.h>

class Controller_GY906_Data: public Model_I2C_Device{
  public:
  // Add your declare here
  // Adafruit_MLX90614 mlx = Adafruit_MLX90614();
  Adafruit_MLX90614 * mlx;
  Controller_GY906_Data();
  ~Controller_GY906_Data();
  bool getData();
  bool init();
  bool deInit();
};

extern Controller_GY906_Data device_Controller_GY906;
#endif