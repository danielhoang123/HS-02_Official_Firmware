#ifndef _Makerlabvn_I2C_Motor_Driver_H_
#define _Makerlabvn_I2C_Motor_Driver_H_

#include "Arduino.h"
#include <Wire.h>

#define MAKERLABVN_I2C_DRIVER_MAX_NUMBER_DRIVER_SUPPORT (5)
#define MAKERLABVN_I2C_DRIVER_SLAVE_ADDRESS_MIN (64)
#define MAKERLABVN_I2C_DRIVER_SLAVE_ADDRESS_MAX (MAKERLABVN_I2C_DRIVER_SLAVE_ADDRESS_MIN + MAKERLABVN_I2C_DRIVER_MAX_NUMBER_DRIVER_SUPPORT)

#define MAKERLABVN_I2C_DRIVER_PULSE_TIME_MAX (2350)
#define MAKERLABVN_I2C_DRIVER_PULSE_TIME_MIN (460)

#define MAX_I2C_MOTOR_DC_SIZE (2)
#define MAX_I2C_MOTOR_RC_SIZE (2)

#define DELAY_I2C_SEND (15) //us

#define MAKERLABVN_I2C_DRIVER_INDEX_MA (0)
#define MAKERLABVN_I2C_DRIVER_INDEX_MB (1)

#define MAKERLABVN_I2C_DRIVER_INDEX_S1 (0)
#define MAKERLABVN_I2C_DRIVER_INDEX_S2 (1)

#define I2C_MOTOR_DRIVER_PULSE_DISABLE (3000)
typedef union myValue
{
  uint16_t pulse;
  struct
  {
    uint8_t dir;
    uint8_t pwm;
  };
};

typedef enum
{
  RC_ID = 0,
  DC_ID,
  SADDR_ID,
  END_MODE_ID
} typeModeId;

typedef enum
{
  I2C_MOTOR_DRIVER_CODE_FAIL = 0,
  I2C_MOTOR_DRIVER_CODE_SUCCESS,
  I2C_MOTOR_DRIVER_CODE_NOT_CONNECT,
  I2C_MOTOR_DRIVER_CODE_MANY_CONNECT,
  I2C_MOTOR_DRIVER_CODE_INVALID_ADDRESS,
  END_I2C_MOTOR_DRIVER_CODE
} I2C_Driver_Error_Code;

typedef struct
{
  uint8_t addressId;
  uint8_t modeId;
  uint8_t index;
  myValue value;
  uint8_t checkSum;
} str_serial_data_rcMotor;

typedef struct
{
  uint8_t addressId;
  uint8_t modeId;
  uint8_t index;
  uint8_t pwm; // pwm
  uint8_t dir; // dir
  uint8_t checkSum;
} str_serial_data_dcMotor;

class Makerlabvn_I2C_Motor_Driver
{
public:
  Makerlabvn_I2C_Motor_Driver(uint8_t _address_ = MAKERLABVN_I2C_DRIVER_SLAVE_ADDRESS_MIN);
  void begin();
  I2C_Driver_Error_Code setAddress(uint8_t _address_);
  I2C_Driver_Error_Code scanI2CAddress();
  I2C_Driver_Error_Code ReadI2cOverSerial();
  void S1(uint16_t _pulse_us_);
  void S2(uint16_t _pulse_us_);
  void MA(bool _dir_, uint8_t _PWMspeed_);          // _PWMspeed_: (0->255) ; _dir_: (0, 1)
  void MB(bool _dir_, uint8_t _PWMspeed_);
  void writeMA(bool _dir_, uint8_t _PercentSpeed_); // _PercentSpeed_: (0->100) ; _dir_: (0, 1)
  void writeMB(bool _dir_, uint8_t _PercentSpeed_);
  void SetS1(uint16_t _pulseMin_0_Degree, uint16_t _pulseMax_180_Degree);
  void SetS2(uint16_t _pulseMin_0_Degree, uint16_t _pulseMax_180_Degree);
  void writeS1(uint16_t _degree_);
  void writeS2(uint16_t _degree_);
  void freeS1();
  void freeS2();

private:
  byte addressDriver;
  byte lastAddressDriver;

  struct Str_RC_info
  {
    uint16_t pulseMin;
    uint16_t pulseMax;
  };

  Str_RC_info infoS1, infoS2;

  str_serial_data_dcMotor motorDC[MAX_I2C_MOTOR_DC_SIZE];
  str_serial_data_rcMotor motorRC[MAX_I2C_MOTOR_RC_SIZE]; // kxn add y21m09d12

  void motorRC_Write(uint8_t _index_, uint16_t _pulse_);
  void motorDC_Write(uint8_t _index_, uint8_t _dir_, uint8_t _speed_);
  void checkSumCalculate(str_serial_data_dcMotor *_myMotor_);
  void checkSumCalculate(str_serial_data_rcMotor *_myMotor_);

  void sendI2cMotorDC_Data(str_serial_data_dcMotor *_myMotor_);
  void sendI2cMotorRC_Data(str_serial_data_rcMotor *_myMotor2_);
  void sendI2cAddress_Data(uint8_t _address_, str_serial_data_dcMotor *_myMotor_);

  void motorI2C_init()
  {
    motorDC[0].addressId = addressDriver;
    motorDC[1].addressId = addressDriver;
    motorRC[0].addressId = addressDriver;
    motorRC[1].addressId = addressDriver;
    // motorRC[2].addressId = 8;

    motorDC[0].modeId = DC_ID;
    motorDC[1].modeId = DC_ID;
    motorRC[0].modeId = RC_ID;
    motorRC[1].modeId = RC_ID;
    // motorRC[2].modeId = RC_ID;

    motorDC[0].index = 0;
    motorDC[1].index = 1;
    motorRC[0].index = 1;
    motorRC[1].index = 2;
    // motorRC[2].index = 2;

    infoS1.pulseMax = infoS2.pulseMax = MAKERLABVN_I2C_DRIVER_PULSE_TIME_MAX;
    infoS1.pulseMin = infoS2.pulseMin = MAKERLABVN_I2C_DRIVER_PULSE_TIME_MIN;
  }
};
#endif