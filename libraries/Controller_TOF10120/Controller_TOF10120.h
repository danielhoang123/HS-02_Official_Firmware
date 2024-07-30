#ifndef Controller_TOF10120_H__
#define Controller_TOF10120_H__
#include "Model_I2C_Device.h"

// include your Libraries here
#include <Wire.h>

class Controller_TOF10120_Data: public Model_I2C_Device{
  public:
  // Add your declare here
  unsigned char ok_flag;
  unsigned char fail_flag;

  unsigned short lenth_val = 0;
  unsigned char i2c_rx_buf[16];
  unsigned char dirsend_flag=0;
  void SensorRead(unsigned char addr,unsigned char* datbuf,unsigned char cnt);
  int ReadDistance();


  Controller_TOF10120_Data();
  ~Controller_TOF10120_Data();
  bool getData();
  bool init();
  bool deInit();
};

extern Controller_TOF10120_Data device_Controller_TOF10120;
#endif