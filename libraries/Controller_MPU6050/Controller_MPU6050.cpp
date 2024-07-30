#include "Controller_MPU6050.h"
// #include "debugkxn.h"

Controller_MPU6050_Data::Controller_MPU6050_Data()
{
  this->nameDevice = "MPU6050";
  this->timeInterval = 250;
  // this->valueDevice = "No device";
  this->Add_AddressList(0x68);
  //this->Add_HsCode(142);
  // Add your code here
}

Controller_MPU6050_Data::~Controller_MPU6050_Data()
{
}

bool Controller_MPU6050_Data::getData()
{
  // Add your code here
  sensors_event_t a, g, temp;
  this->mpu->getEvent(&a, &g, &temp);

  this->valueDevice = "";
  this->valueDevice1 = "";
  this->valueDevice2 = "";

  this->valueDevice += String(a.acceleration.x, 2) + ";" + String(a.acceleration.y, 2) + ";" + String(a.acceleration.z, 2);
  this->valueDevice1 += String(g.gyro.x, 2) + ";" + String(g.gyro.y, 2) + ";" + String(g.gyro.z, 2);
  this->valueDevice2 += String(temp.temperature, 2) + String(char(223)) + "C";
  return true;
}

bool Controller_MPU6050_Data::init()
{
  deInit();
  // Add your code here
  this->mpu = new Adafruit_MPU6050;

  this->mpu->begin();

  this->mpu->setAccelerometerRange(MPU6050_RANGE_8_G);

  this->mpu->setGyroRange(MPU6050_RANGE_500_DEG);

  this->mpu->setFilterBandwidth(MPU6050_BAND_21_HZ);

  return 1;
}

bool Controller_MPU6050_Data::deInit()
{
  // Add your code here
  delete mpu;
  mpu = nullptr;
  return 1;
}

Controller_MPU6050_Data device_Controller_MPU6050;