// #ifndef hbq_L3G4200D_h
// #define hbq_L3G4200D_h

#include <Wire.h>
#include "Arduino.h"

#define CTRL_REG1 0x20
#define CTRL_REG2 0x21
#define CTRL_REG3 0x22
#define CTRL_REG4 0x23
#define CTRL_REG5 0x24

class hbq_L3G4200D {
  public:

  int L3G4200D_Address = 105; //I2C address of the L3G4200D

  int x;
  int y;
  int z;

  int getGyroValuesX();
  int getGyroValuesY();
  int getGyroValuesZ();
  int setupL3G4200D(int scale);
  void writeRegister(int deviceAddress, byte address, byte val);
  int readRegister(int deviceAddress, byte address);

};