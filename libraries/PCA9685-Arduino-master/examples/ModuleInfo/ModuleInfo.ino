// PCA9685-Arduino Module Info
// In this example, we enable debug output support to print out module diagnostic
// information. If one uncomments the line below inside the main header file (or defines
// it via custom build flag), debug output support will be enabled and the
// printModuleInfo() method will become available. Calling this method will display
// information about the module itself, including initalized states, register values,
// current settings, etc. Additionally, all library calls being made will display
// internal debug information about the structure of the call itself. You may refer to
// https://forum.arduino.cc/index.php?topic=602603.0 on how to define custom build flags
// manually via modifying platform[.local].txt.
//
// In PCA9685.h:
// // Uncomment or -D this define to enable debug output.
// #define PCA9685_ENABLE_DEBUG_OUTPUT
//
// Alternatively, in platform[.local].txt:
// build.extra_flags=-DPCA9685_ENABLE_DEBUG_OUTPUT

#include "PCA9685.h"

PCA9685 pwmController;                  // Library using default B000000 (A5-A0) i2c address, and default Wire @400kHz

void setup() {
    Serial.begin(115200);               // Begin Serial and Wire interfaces
    Wire.begin();

    pwmController.init();               // Initializes module using default totem-pole driver mode, and default disabled phase balancer

    pwmController.printModuleInfo();    // Prints module diagnostic information
}

void loop() {
}
