#include "Controller_MPU9250.h"
// #include "debugkxn.h"

Controller_MPU9250_Data::Controller_MPU9250_Data()
{
  this->nameDevice = "MPU9250";
  this->timeInterval = 250;
  // this->valueDevice = "No device";
  this->Add_AddressList(0x68);
  // this->Add_HsCode(195);
  //  Add your code here
}

Controller_MPU9250_Data::~Controller_MPU9250_Data()
{
}

bool Controller_MPU9250_Data::getData()
{
  // Add your code here
  this->valueDevice = "";
  this->valueDevice1 = "";
  this->valueDevice2 = "";

  if (this->imu->Read())
  {
    this->valueDevice = String(this->imu->accel_x_mps2(), 2) + ";" + String(this->imu->accel_y_mps2(), 2) + ";" + String(this->imu->accel_z_mps2(), 2);
    this->valueDevice1 = String(this->imu->gyro_x_radps(), 2) + ";" + String(this->imu->gyro_y_radps(), 2) + ";" + String(this->imu->gyro_z_radps(), 2);
    this->valueDevice2 = String(this->imu->mag_x_ut(), 2) + ";" + String(this->imu->mag_y_ut(), 2) + ";" + String(this->imu->mag_z_ut(), 2);
  }
  return true;
}

bool Controller_MPU9250_Data::init()
{
  deInit();
  // Add your code here
  Wire.begin();
  Wire.setClock(400000);
  this->imu = new bfs::Mpu9250;

  this->imu->Config(&Wire, bfs::Mpu9250::I2C_ADDR_PRIM);
  this->imu->Begin();
  this->imu->ConfigSrd(19);

  return 1;
}

bool Controller_MPU9250_Data::deInit()
{
  // Add your code here
  delete imu;
  imu = nullptr;
  return 1;
}

Controller_MPU9250_Data device_Controller_MPU9250;