#include "Controller_NRFRx.h"
#include "MachTest_SP_IO.h"
#include "debugkxn.h"

Controller_NRFRx_Data::Controller_NRFRx_Data()
{
  this->nameDevice = "NRF Rx";
  this->timeInterval = 250;
  this->valueDevice = "No device";
  // Add your code here
}

bool Controller_NRFRx_Data::getData()
{
  // Add your code here
  this->valueDevice = "";

  radio_RX.startListening();

  if (radio_RX.available())
  {
    Serial.println("Hello");
    char text[32] = {0};
    radio_RX.read(&text, sizeof(text));
    this->valueDevice += String(text);
    //analogWrite(A2, 255);
  }
  return true;
}

bool Controller_NRFRx_Data::init()
{
  deInit();
  // Add your code here
  pinMode(A2, OUTPUT);

  RF24 radio_RX(9, 10);
  const byte address1[6] = "12345";

  radio_RX.begin();
  radio_RX.openReadingPipe(0, address1);
  radio_RX.setPALevel(RF24_PA_MAX);
  radio_RX.startListening();

  return 1;
}

bool Controller_NRFRx_Data::deInit()
{
  // Add your code here
  this->valueDevice = "No Device";
  return 1;
}

Controller_NRFRx_Data NRFRx_Device;