#include "Controller_RC522.h"
#include "MachTest_SP_IO.h"
#include "debugkxn.h"

// MFRC522 rfid(PIN_1, PIN_2);

Controller_RC522_Data::Controller_RC522_Data()
{
  this->nameDevice = "RC522";
  this->timeInterval = 4000;
  this->valueDevice = "Ready";
  // Add your code here
}

bool Controller_RC522_Data::getData()
{
  // Add your code here
  this->valueDevice = "";
  this->valueDevice += "Insert Tag";
  if (!this->rfid->PICC_IsNewCardPresent())
  {
    return false;
  }

  // Select one of the cards
  if (!this->rfid->PICC_ReadCardSerial())
  {
    return false;
  }

  this->valueDevice += "UID: ";

  for (byte i = 0; i < this->rfid->uid.size; i++)
  {
    this->valueDevice += String(this->rfid->uid.uidByte[i], HEX) + " ";
  }

  return 1;
}

bool Controller_RC522_Data::init()
{
  deInit();
  // Add your code here
  this->timeInterval = 100;
  SPI.begin();     // Init SPI bus
  // rfid.PCD_Init(); // Init MFRC522
  this->rfid = new MFRC522(PIN_1, PIN_2);
  this->rfid->PCD_Init();
  return 1;
}

bool Controller_RC522_Data::deInit()
{
  // Add your code here
  delete rfid;
  rfid = nullptr;
  return 1;
}

Controller_RC522_Data RC522_Device;