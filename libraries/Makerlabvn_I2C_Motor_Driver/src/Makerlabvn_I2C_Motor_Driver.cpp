#include "Makerlabvn_I2C_Motor_Driver.h"

Makerlabvn_I2C_Motor_Driver::Makerlabvn_I2C_Motor_Driver(uint8_t _address_)
{
  if(_address_ <= MAKERLABVN_I2C_DRIVER_MAX_NUMBER_DRIVER_SUPPORT){
    addressDriver = _address_ + MAKERLABVN_I2C_DRIVER_SLAVE_ADDRESS_MIN;
  }else if((_address_ >= MAKERLABVN_I2C_DRIVER_SLAVE_ADDRESS_MIN) && (_address_ <= MAKERLABVN_I2C_DRIVER_SLAVE_ADDRESS_MAX)){
    addressDriver = _address_;
  }else
  addressDriver = MAKERLABVN_I2C_DRIVER_SLAVE_ADDRESS_MIN;
}

void Makerlabvn_I2C_Motor_Driver::begin()
{
  Wire.begin(); // join i2c bus (address optional for master)
  motorI2C_init();
  ReadI2cOverSerial();
}

void Makerlabvn_I2C_Motor_Driver::checkSumCalculate(str_serial_data_dcMotor *_myMotor_)
{
  uint16_t tempSum = _myMotor_->addressId +
                     _myMotor_->modeId +
                     _myMotor_->index +
                     _myMotor_->pwm +
                     _myMotor_->dir;
  _myMotor_->checkSum = (uint8_t)tempSum;
}

void Makerlabvn_I2C_Motor_Driver::checkSumCalculate(str_serial_data_rcMotor *_myMotor_)
{
  uint16_t tempSum = _myMotor_->addressId +
                     _myMotor_->modeId +
                     _myMotor_->index +
                     _myMotor_->value.pwm +
                     _myMotor_->value.dir;
  _myMotor_->checkSum = (uint8_t)tempSum;
}

I2C_Driver_Error_Code Makerlabvn_I2C_Motor_Driver::scanI2CAddress()
{
  I2C_Driver_Error_Code tempStatus = I2C_MOTOR_DRIVER_CODE_NOT_CONNECT;
  uint8_t tempCount = 0;
  delayMicroseconds(20);
  for (byte address = MAKERLABVN_I2C_DRIVER_SLAVE_ADDRESS_MIN; address <= MAKERLABVN_I2C_DRIVER_SLAVE_ADDRESS_MAX; ++address)
  {
    Wire.beginTransmission(address);
    byte error = Wire.endTransmission();

    if (error == 0)
    {
      tempCount++;
      addressDriver = address;
    }
  }
  if (tempCount == 1)
    tempStatus = I2C_MOTOR_DRIVER_CODE_SUCCESS;
  else if (tempCount > 1)
    tempStatus = I2C_MOTOR_DRIVER_CODE_MANY_CONNECT;
  return tempStatus;
}

I2C_Driver_Error_Code Makerlabvn_I2C_Motor_Driver::setAddress(uint8_t _address_)
{
  I2C_Driver_Error_Code tempStatus = scanI2CAddress();
  if (tempStatus == I2C_MOTOR_DRIVER_CODE_SUCCESS)
  {
    str_serial_data_dcMotor *_myMotor_ = &motorDC[0];
    _myMotor_->modeId = SADDR_ID;
    if(_address_ <= MAKERLABVN_I2C_DRIVER_MAX_NUMBER_DRIVER_SUPPORT){
      _myMotor_->addressId = _address_ + MAKERLABVN_I2C_DRIVER_SLAVE_ADDRESS_MIN;
    }else if((_address_ >= MAKERLABVN_I2C_DRIVER_SLAVE_ADDRESS_MIN) && (_address_ <= MAKERLABVN_I2C_DRIVER_SLAVE_ADDRESS_MAX)){
      _myMotor_->addressId = _address_;
    }else return I2C_MOTOR_DRIVER_CODE_INVALID_ADDRESS;
    
    checkSumCalculate(_myMotor_);
    sendI2cAddress_Data(addressDriver, _myMotor_);
    delayMicroseconds(DELAY_I2C_SEND);

    addressDriver = _myMotor_->addressId;
    return ReadI2cOverSerial();
  }
  return tempStatus;
}

void Makerlabvn_I2C_Motor_Driver::motorRC_Write(uint8_t _index_, uint16_t _pulse_)
{
  str_serial_data_rcMotor *_myMotor_ = &motorRC[_index_];
  if (_index_ < MAX_I2C_MOTOR_RC_SIZE)
  {
    _myMotor_->modeId = RC_ID;
    _myMotor_->value.pulse = _pulse_;
    checkSumCalculate(_myMotor_);
    sendI2cMotorRC_Data((str_serial_data_rcMotor *)_myMotor_);
  }
}

void Makerlabvn_I2C_Motor_Driver::motorDC_Write(uint8_t _index_, uint8_t _dir_, uint8_t _speed_)
{
  if (_index_ < MAX_I2C_MOTOR_DC_SIZE)
  {
    motorDC[_index_].pwm = _speed_;
    motorDC[_index_].dir = _dir_;
    checkSumCalculate(&motorDC[_index_]);
    sendI2cMotorDC_Data(&motorDC[_index_]);
  }
}

void Makerlabvn_I2C_Motor_Driver::sendI2cMotorDC_Data(str_serial_data_dcMotor *_myMotor_)
{
  delayMicroseconds(DELAY_I2C_SEND);
  Wire.beginTransmission(addressDriver); // transmit to device #8
  Wire.write(_myMotor_->addressId);      // sends one byte
  Wire.write(_myMotor_->modeId);         // sends one byte
  Wire.write(_myMotor_->index);          // sends one byte
  Wire.write(_myMotor_->pwm);            // sends one byte
  Wire.write(_myMotor_->dir);            // sends one byte
  Wire.write(_myMotor_->checkSum);       // sends one byte
  Wire.endTransmission();                // stop transmitting
}

void Makerlabvn_I2C_Motor_Driver::sendI2cMotorRC_Data(str_serial_data_rcMotor *_myMotor2_)
{
  str_serial_data_rcMotor *_myMotor_ = (str_serial_data_rcMotor *)_myMotor2_;
  // ReadI2cOverSerial();
  delayMicroseconds(DELAY_I2C_SEND);
  Wire.beginTransmission(addressDriver); // transmit to device #8
  Wire.write(_myMotor_->addressId);      // sends one byte
  Wire.write(_myMotor_->modeId);         // sends one byte
  Wire.write(_myMotor_->index);          // sends one byte
  Wire.write(_myMotor_->value.pwm);      // sends one byte
  Wire.write(_myMotor_->value.dir);      // sends one byte
  Wire.write(_myMotor_->checkSum);       // sends one byte
  Wire.endTransmission();                // stop transmitting
}

void Makerlabvn_I2C_Motor_Driver::sendI2cAddress_Data(uint8_t _address_, str_serial_data_dcMotor *_myMotor_)
{
  // ReadI2cOverSerial();
  delayMicroseconds(DELAY_I2C_SEND);
  Wire.beginTransmission(_address_); // transmit to device #8
  Wire.write(_myMotor_->addressId);  // sends one byte
  Wire.write(_myMotor_->modeId);     // sends one byte
  Wire.write(_myMotor_->index);      // sends one byte
  Wire.write(_myMotor_->pwm);        // sends one byte
  Wire.write(_myMotor_->dir);        // sends one byte
  Wire.write(_myMotor_->checkSum);   // sends one byte
  Wire.endTransmission();            // stop transmitting
}

I2C_Driver_Error_Code Makerlabvn_I2C_Motor_Driver::ReadI2cOverSerial()
{
  I2C_Driver_Error_Code tempStatus = I2C_MOTOR_DRIVER_CODE_FAIL;
  delay(DELAY_I2C_SEND);
  Wire.requestFrom(addressDriver, 1); // request 6 bytes from slave device #8
  while (Wire.available())
  {                                // slave may send less than requested
    unsigned char c = Wire.read(); // receive a byte as character
    if (c == addressDriver)
      tempStatus = I2C_MOTOR_DRIVER_CODE_SUCCESS;
  }
  return tempStatus;
}

void Makerlabvn_I2C_Motor_Driver::S1(uint16_t _pulse_us_)
{
  motorRC_Write(MAKERLABVN_I2C_DRIVER_INDEX_S1, _pulse_us_);
}

void Makerlabvn_I2C_Motor_Driver::S2(uint16_t _pulse_us_)
{
  motorRC_Write(MAKERLABVN_I2C_DRIVER_INDEX_S2, _pulse_us_);
}

void Makerlabvn_I2C_Motor_Driver::MA(bool _dir_, uint8_t _PWMspeed_)
{
  motorDC_Write(MAKERLABVN_I2C_DRIVER_INDEX_MA, _dir_, _PWMspeed_);
}

void Makerlabvn_I2C_Motor_Driver::MB(bool _dir_, uint8_t _PWMspeed_)
{
  motorDC_Write(MAKERLABVN_I2C_DRIVER_INDEX_MB, _dir_, _PWMspeed_);
}

void Makerlabvn_I2C_Motor_Driver::writeMA(bool _dir_, uint8_t _PercentSpeed_)
{
  uint8_t tempPercentSpeed = constrain(_PercentSpeed_,0,100);
  uint8_t tempPwm = map(tempPercentSpeed,0,100,0,255);
  Makerlabvn_I2C_Motor_Driver::MA(_dir_, tempPwm);
}

void Makerlabvn_I2C_Motor_Driver::writeMB(bool _dir_, uint8_t _PercentSpeed_)
{
  uint8_t tempPercentSpeed = constrain(_PercentSpeed_,0,100);
  uint8_t tempPwm = map(tempPercentSpeed,0,100,0,255);
  Makerlabvn_I2C_Motor_Driver::MB(_dir_, tempPwm);
}

void Makerlabvn_I2C_Motor_Driver::SetS1(uint16_t _pulseMin_0_Degree, uint16_t _pulseMax_180_Degree)
{
  infoS1.pulseMin = _pulseMin_0_Degree;
  infoS1.pulseMax = _pulseMax_180_Degree;
}

void Makerlabvn_I2C_Motor_Driver::SetS2(uint16_t _pulseMin_0_Degree, uint16_t _pulseMax_180_Degree)
{
  infoS2.pulseMin = _pulseMin_0_Degree;
  infoS2.pulseMax = _pulseMax_180_Degree;
}

void Makerlabvn_I2C_Motor_Driver::writeS1(uint16_t _degree_)
{
  uint16_t tempPulse = map(_degree_, 0, 180, infoS1.pulseMin, infoS1.pulseMax);
  Makerlabvn_I2C_Motor_Driver::S1(tempPulse);
}

void Makerlabvn_I2C_Motor_Driver::writeS2(uint16_t _degree_)
{
  uint16_t tempPulse = map(_degree_, 0, 180, infoS2.pulseMin, infoS2.pulseMax);
  Makerlabvn_I2C_Motor_Driver::S2(tempPulse);
}

void Makerlabvn_I2C_Motor_Driver::freeS1(){
  Makerlabvn_I2C_Motor_Driver::S1(I2C_MOTOR_DRIVER_PULSE_DISABLE);
}

void Makerlabvn_I2C_Motor_Driver::freeS2(){
  Makerlabvn_I2C_Motor_Driver::S2(I2C_MOTOR_DRIVER_PULSE_DISABLE);
}