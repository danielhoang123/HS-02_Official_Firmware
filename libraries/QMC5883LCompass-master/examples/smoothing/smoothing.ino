/*
===============================================================================================================
QMC5883LCompass.h Library XYZ Example Sketch
Learn more at [https://github.com/mprograms/QMC5883Compas]

This example shows how to use smoothing to get more stable readings.

===============================================================================================================
Release under the GNU General Public License v3
[https://www.gnu.org/licenses/gpl-3.0.en.html]
===============================================================================================================
*/
#include <QMC5883LCompass.h>
#include "I2Cdev.h"
#include "MPU6050.h"

MPU6050 accelgyro;
QMC5883LCompass compass;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  accelgyro.setI2CMasterModeEnabled(false);

    accelgyro.setI2CBypassEnabled(true) ;
    accelgyro.setSleepEnabled(false);

  compass.init();

  /*
   *   call setSmoothing(STEPS, ADVANCED);
   *   
   *   STEPS     = int   The number of steps to smooth the results by. Valid 1 to 10.
   *                     Higher steps equals more smoothing but longer process time.
   *                     
   *   ADVANCED  = bool  Turn advanced smmothing on or off. True will remove the max and min values from each step and then process as normal.
   *                     Turning this feature on will results in even more smoothing but will take longer to process.
   *                     
   */
  compass.setSmoothing(10,true);  
}

void loop() {
  // int x, y, z;
  
  // // Read compass values
  // compass.read();

  // // Return XYZ readings
  // x = compass.getX();
  // y = compass.getY();
  // z = compass.getZ();
  
  // Serial.print("X: ");
  // Serial.print(x);
  // Serial.print(" Y: ");
  // Serial.print(y);
  // Serial.print(" Z: ");
  // Serial.print(z);
  // Serial.println();
  
  // delay(250);

  // compass.read();
  
  // byte a = compass.getAzimuth();

  // char myArray[3];
  // compass.getDirection(myArray, a);
  
  // Serial.print(myArray[0]);
  // Serial.print(myArray[1]);
  // Serial.print(myArray[2]);
  // Serial.println();
  
  // delay(250);
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
