#include "Controller_nRF.h"
#include "MachTest_SP_IO.h"
#include "debugkxn.h"
#include "Btn_Process.h"

float payload = 0.0;

Controller_nRF_Data::Controller_nRF_Data()
{
  this->nameDevice = "NRF Tx";
  this->timeInterval = 250;
  this->valueDevice = "No device";
}

bool Controller_nRF_Data::getData()
{
  this->valueDevice = "x2Click Toggle LED";
  // bool temp =
  radio.write(&payload, sizeof(payload));
  // if (temp)
  // {
  //   payload += 0.01;
  //   this->valueDevice = "Send OK!" + String(payload, 2);
  // }
  // else
  // {
  //   this->valueDevice = "Send Failed!";
  // }
}

bool Controller_nRF_Data::init()
{
  deInit();
  // Add your code here

  // this->radio = new RF24(9, 10);
  // RF24 radio(9, 10);
  RF24 radio(9, 10);
  uint8_t address2[6] = "12345";
  
  radio.begin();
  radio.setPALevel(RF24_PA_LOW);         // RF24_PA_MAX is default.
  radio.setPayloadSize(sizeof(payload)); // float datatype occupies 4 bytes
  radio.openWritingPipe(address2);
  radio.stopListening();

  // gửi để cho Rx nhận, nhận xong rồi phía Rx đảo trạng thái đèn khi nhận được tín hiệu
  // const char text[] = "Your Button State is HIGH";

  return 1;
}

bool Controller_nRF_Data::deInit()
{
  // Add your code here
  // if (this->radio != NULL)
  // {
  //   delete radio;
  // }
  this->valueDevice = "x2Click to Start";
  return 1;
}

Controller_nRF_Data NRF_Device;