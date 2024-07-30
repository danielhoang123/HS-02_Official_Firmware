// PCA9685-Arduino Servo Evaluator Example
// In this example, we utilize the ServoEvaluator class to assist with setting PWM
// frequencies when working with servos. We will be using Wire1, which is only available
// on boards with SDA1/SCL1 (e.g. Due/Mega/etc.) - change to Wire if Wire1 is unavailable.

#include "PCA9685.h"

PCA9685 pwmController(Wire1);           // Library using Wire1 @400kHz, and default B000000 (A5-A0) i2c address

// Linearly interpolates between standard 2.5%/12.5% phase length (102/512) for -90°/+90°
PCA9685_ServoEval pwmServo1;

// Testing our second servo has found that -90° sits at 128, 0° at 324, and +90° at 526.
// Since 324 isn't precisely in the middle, a cubic spline will be used to smoothly
// interpolate PWM values, which will account for said discrepancy. Additionally, since
// 324 is closer to 128 than 526, there is slightly less resolution in the -90° to 0°
// range while slightly more in the 0° to +90° range.
PCA9685_ServoEval pwmServo2(128,324,526);

void setup() {
    Serial.begin(115200);               // Begin Serial and Wire1 interfaces
    Wire1.begin();

    pwmController.resetDevices();       // Resets all PCA9685 devices on i2c line

    pwmController.init();               // Initializes module using default totem-pole driver mode, and default disabled phase balancer

    pwmController.setPWMFreqServo();    // 50Hz provides standard 20ms servo phase length

    pwmController.setChannelPWM(0, pwmServo1.pwmForAngle(-90));
    Serial.println(pwmController.getChannelPWM(0)); // Should output 102 for -90°

    // Showing linearity for midpoint, 205 away from both -90° and 90°
    Serial.println(pwmServo1.pwmForAngle(0));   // Should output 307 for 0°

    pwmController.setChannelPWM(0, pwmServo1.pwmForAngle(90));
    Serial.println(pwmController.getChannelPWM(0)); // Should output 512 for +90°

    pwmController.setChannelPWM(1, pwmServo2.pwmForAngle(-90));
    Serial.println(pwmController.getChannelPWM(1)); // Should output 128 for -90°

    // Showing less resolution in the -90° to 0° range
    Serial.println(pwmServo2.pwmForAngle(-45)); // Should output 225 for -45°, 97 away from -90°

    pwmController.setChannelPWM(1, pwmServo2.pwmForAngle(0));
    Serial.println(pwmController.getChannelPWM(1)); // Should output 324 for 0°

    // Showing more resolution in the 0° to +90° range
    Serial.println(pwmServo2.pwmForAngle(45));  // Should output 424 for +45°, 102 away from +90°

    pwmController.setChannelPWM(1, pwmServo2.pwmForAngle(90));
    Serial.println(pwmController.getChannelPWM(1)); // Should output 526 for +90°
}

void loop() {
}
