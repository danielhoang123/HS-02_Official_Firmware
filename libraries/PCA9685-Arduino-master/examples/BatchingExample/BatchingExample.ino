// PCA9685-Arduino Batching Example
// In this example, we randomly select PWM frequencies on all 12 outputs and allow them
// to drive for 5 seconds before changing them.

#include "PCA9685.h"

PCA9685 pwmController(B010101);         // Library using B010101 (A5-A0) i2c address, and default Wire @400kHz

void setup() {
    Serial.begin(115200);               // Begin Serial and Wire interfaces
    Wire.begin();

    pwmController.resetDevices();       // Resets all PCA9685 devices on i2c line

    pwmController.init();               // Initializes module using default totem-pole driver mode, and default phase balancer

    pwmController.setPWMFrequency(500); // Set PWM freq to 500Hz (default is 200Hz, supports 24Hz to 1526Hz)

    randomSeed(analogRead(0));          // Use white noise for our randomness
}

void loop() {
    uint16_t pwms[12];
    pwms[0] = random(0, 4096);
    pwms[1] = random(0, 4096);
    pwms[2] = random(0, 4096);
    pwms[3] = random(0, 4096);
    pwms[4] = random(0, 4096);
    pwms[5] = random(0, 4096);
    pwms[6] = random(0, 4096);
    pwms[7] = random(0, 4096);
    pwms[8] = random(0, 4096);
    pwms[9] = random(0, 4096);
    pwms[10] = random(0, 4096);
    pwms[11] = random(0, 4096);
    pwmController.setChannelsPWM(0, 12, pwms);
    delay(5000);

    // NOTE: Many chips use a BUFFER_LENGTH size of 32, and in that case writing 12
    // channels will take 2 i2c transactions because only 7 channels can fit in a single
    // i2c buffer transaction at a time. This may cause a slight offset flicker between
    // the first 7 and remaining 5 channels, but can be offset by experimenting with a
    // channel update mode of PCA9685_ChannelUpdateMode_AfterAck. This will make each
    // channel update immediately upon sending of the Ack signal after each PWM command
    // is executed rather than at the Stop signal at the end of the i2c transaction.
}
