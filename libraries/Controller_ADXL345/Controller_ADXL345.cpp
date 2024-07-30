#include "Controller_ADXL345.h"
// #include "debugkxn.h"

Controller_ADXL345_Data::Controller_ADXL345_Data()
{
  this->nameDevice = "ADXL345";
  this->timeInterval = 250;
  // this->valueDevice = "No device";
  this->Add_AddressList(0x53);
  // this->Add_HsCode(143);
  // Add your code here
}

Controller_ADXL345_Data::~Controller_ADXL345_Data()
{
}

bool Controller_ADXL345_Data::getData()
{
  // Add your code here
  
  this->valueDevice = "";
  int x, y, z;
  this->adxl->readAccel(&x, &y, &z);
  this->valueDevice += String(x) + ";" + String(y) + ";" + String(z);

  // Wire.beginTransmission(ADXL345);
  // Wire.write(0x32); // Start with register 0x32 (ACCEL_XOUT_H)
  // Wire.endTransmission(false);
  // Wire.requestFrom(ADXL345, 6, true); // Read 6 registers total, each axis value is stored in 2 registers
  // X_out = ( Wire.read()| Wire.read() << 8); // X-axis value
  // X_out = X_out/256; //For a range of +-2g, we need to divide the raw values by 256, according to the datasheet
  // Y_out = ( Wire.read()| Wire.read() << 8); // Y-axis value
  // Y_out = Y_out/256;
  // Z_out = ( Wire.read()| Wire.read() << 8); // Z-axis value
  // Z_out = Z_out/256;

  // this->valueDevice += String(X_out, 2);
  // this->valueDevice += ":";
  // this->valueDevice += String(Y_out, 2);
  // this->valueDevice += ":";
  // this->valueDevice += String(Z_out, 2);
  return true;
}

bool Controller_ADXL345_Data::init()
{
  deInit();
  // Add your code here
  // Wire.begin();
  // Wire.beginTransmission(ADXL345);
  // Wire.write(0x2D);
  // Wire.write(8);
  // Wire.endTransmission();

  this->adxl = new ADXL345;

  this->adxl->powerOn(); // Power on the ADXL345

  this->adxl->setRangeSetting(16); // Give the range settings
                                   // Accepted values are 2g, 4g, 8g or 16g
                                   // Higher Values = Wider Measurement Range
                                   // Lower Values = Greater Sensitivity

  this->adxl->setSpiBit(0); // Configure the device to be in 4 wire SPI mode when set to '0' or 3 wire SPI mode when set to 1
                            // Default: Set to 1
                            // SPI pins on the ATMega328: 11, 12 and 13 as reference in SPI Library

  this->adxl->setActivityXYZ(1, 0, 0);  // Set to activate movement detection in the axes "adxl.setActivityXYZ(X, Y, Z);" (1 == ON, 0 == OFF)
  this->adxl->setActivityThreshold(75); // 62.5mg per increment   // Set activity   // Inactivity thresholds (0-255)

  this->adxl->setInactivityXYZ(1, 0, 0);  // Set to detect inactivity in all the axes "adxl.setInactivityXYZ(X, Y, Z);" (1 == ON, 0 == OFF)
  this->adxl->setInactivityThreshold(75); // 62.5mg per increment   // Set inactivity // Inactivity thresholds (0-255)
  this->adxl->setTimeInactivity(10);      // How many seconds of no activity is inactive?

  this->adxl->setTapDetectionOnXYZ(0, 0, 1); // Detect taps in the directions turned ON "adxl.setTapDetectionOnX(X, Y, Z);" (1 == ON, 0 == OFF)

  // Set values for what is considered a TAP and what is a DOUBLE TAP (0-255)
  this->adxl->setTapThreshold(50);     // 62.5 mg per increment
  this->adxl->setTapDuration(15);      // 625 μs per increment
  this->adxl->setDoubleTapLatency(80); // 1.25 ms per increment
  this->adxl->setDoubleTapWindow(200); // 1.25 ms per increment

  // Set values for what is considered FREE FALL (0-255)
  this->adxl->setFreeFallThreshold(7); // (5 - 9) recommended - 62.5mg per increment
  this->adxl->setFreeFallDuration(30); // (20 - 70) recommended - 5ms per increment

  // Setting all interupts to take place on INT1 pin
  // adxl.setImportantInterruptMapping(1, 1, 1, 1, 1);     // Sets "adxl.setEveryInterruptMapping(single tap, double tap, free fall, activity, inactivity);"
  // Accepts only 1 or 2 values for pins INT1 and INT2. This chooses the pin on the ADXL345 to use for Interrupts.
  // This library may have a problem using INT2 pin. Default to INT1 pin.

  // Turn on Interrupts for each mode (1 == ON, 0 == OFF)
  this->adxl->InactivityINT(1);
  this->adxl->ActivityINT(1);
  this->adxl->FreeFallINT(1);
  this->adxl->doubleTapINT(1);
  this->adxl->singleTapINT(1);

  // attachInterrupt(digitalPinToInterrupt(interruptPin), ADXL_ISR, RISING);   // Attach Interrupt

  return 1;
}

bool Controller_ADXL345_Data::deInit()
{
  // Add your code here
  delete adxl;
  adxl = nullptr;
  return 1;
}

Controller_ADXL345_Data device_Controller_ADXL345;