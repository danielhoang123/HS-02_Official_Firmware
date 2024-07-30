/*
===============================================================================================================
QMC5883LCompass.h Library Azimuth Example Sketch
Learn more at [https://github.com/mprograms/QMC5883Compas]
===============================================================================================================
v0.3 - June 12, 2019
Written by MRPrograms 
Github: [https://github.com/mprograms/]

Release under the GNU General Public License v3
[https://www.gnu.org/licenses/gpl-3.0.en.html]
===============================================================================================================
*/
#include <QMC5883LCompass.h>
#include "Wire.h"
#include "I2Cdev.h"
#include "MPU6050.h"

MPU6050 accelgyro;
QMC5883LCompass compass;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  accelgyro.setI2CMasterModeEnabled(false);

  accelgyro.setI2CBypassEnabled(true);
  accelgyro.setSleepEnabled(false);
  compass.init();
}

void loop() {
  int a;

  // Read compass values
  compass.read();

  // Return Azimuth reading
  a = compass.getAzimuth();

  Serial.print("A: ");
  Serial.print(a);
  Serial.println();

  delay(250);
}
