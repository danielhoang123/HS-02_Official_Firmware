#include "Controller_TOF10120.h"
#include "debugkxn.h"

Controller_TOF10120_Data::Controller_TOF10120_Data()
{
  this->nameDevice = "TOF10120";
  this->timeInterval = 250;
  // this->valueDevice = "No device";
  this->Add_AddressList(0x52);
  //this->Add_HsCode(1318);
  // Add your code here

}

Controller_TOF10120_Data::~Controller_TOF10120_Data()
{
  
}

void Controller_TOF10120_Data::SensorRead(unsigned char addr,unsigned char* datbuf,unsigned char cnt)
{
  unsigned short result=0;
  // step 1: instruct sensor to read echoes
  Wire.beginTransmission(82); // transmit to device #82 (0x52)
  // the address specified in the datasheet is 164 (0xa4)
  // but i2c adressing uses the high 7 bits so it's 82
  Wire.write(byte(addr));      // sets distance data address (addr)
  Wire.endTransmission();      // stop transmitting
  // step 2: wait for readings to happen
  delay(1);                   // datasheet suggests at least 30uS
  // step 3: request reading from sensor
  Wire.requestFrom(82, cnt);    // request cnt bytes from slave device #82 (0x52)
  // step 5: receive reading from sensor
  if (cnt <= Wire.available()) { // if two bytes were received
    *datbuf++ = Wire.read();  // receive high byte (overwrites previous reading)
    *datbuf++ = Wire.read(); // receive low byte as lower 8 bits
  }
}

int Controller_TOF10120_Data::ReadDistance()
{
  SensorRead(0x00,i2c_rx_buf,2);
  lenth_val=i2c_rx_buf[0];
  lenth_val=lenth_val<<8;
  lenth_val|=i2c_rx_buf[1];
  delay(300); 
  return lenth_val;
}

bool Controller_TOF10120_Data::getData()
{
  // Add your code here
  this->valueDevice = "";
  int x=ReadDistance();
  this->valueDevice += String(x);
  this->valueDevice += "mm";
  return true;
}

bool Controller_TOF10120_Data::init()
{
  deInit();
  // Add your code here
  Wire.begin();
  return 1;
}

bool Controller_TOF10120_Data::deInit()
{
  // Add your code here

  return 1;
}

Controller_TOF10120_Data device_Controller_TOF10120;