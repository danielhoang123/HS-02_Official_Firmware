#include "Controller_PCA9685.h"
#include "debugkxn.h"

Controller_PCA9685_Data::Controller_PCA9685_Data()
{
  this->nameDevice = "PCA9685";
  this->timeInterval = 1500;
  // this->valueDevice = "No device";
  this->Add_AddressList(0x40);
  // this->Add_HsCode(928);
  //  Add your code here
}

Controller_PCA9685_Data::~Controller_PCA9685_Data()
{
}

bool Controller_PCA9685_Data::getData()
{
  // Add your code here
  this->valueDevice = "";

  uint16_t pwms[16];
  pwms[0] = random(0, 4096);
  pwms[1] = random(0, 4096);
  pwms[2] = random(0, 4096);
  pwms[3] = random(0, 4096);
  pwms[4] = random(0, 4096);
  pwms[5] = random(0, 4096);
  pwms[6] = random(0, 4096);
  pwms[7] = random(0, 4096);
  pwms[8] = random(0, 4096);
  pwms[9] = random(0, 4096);
  pwms[10] = random(0, 4096);
  pwms[11] = random(0, 4096);
  pwms[12] = random(0, 4096);
  pwms[13] = random(0, 4096);
  pwms[14] = random(0, 4096);
  pwms[15] = random(0, 4096);
  this->pwmController->setChannelsPWM(0, 15, pwms);
  // delay(5000);

  return true;
}

bool Controller_PCA9685_Data::init()
{
  deInit();
  // Add your code here
  this->pwmController = new PCA9685;

  Wire.begin();

  this->pwmController->resetDevices(); // Resets all PCA9685 devices on i2c line

  this->pwmController->init(); // Initializes module using default totem-pole driver mode, and default phase balancer

  this->pwmController->setPWMFrequency(500); // Set PWM freq to 500Hz (default is 200Hz, supports 24Hz to 1526Hz)

  randomSeed(analogRead(0)); // Use white noise for our randomness
  // Wire.beginTransmission(0x4A);
  return 1;
}

bool Controller_PCA9685_Data::deInit()
{
  // Add your code here
  delete pwmController;
  pwmController = nullptr;
  return 1;
}

Controller_PCA9685_Data device_Controller_PCA9685;