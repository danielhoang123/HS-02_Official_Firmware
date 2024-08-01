#include "Controller_RC522.h"
#include "MachTest_SP_IO.h"
#include "debugkxn.h"

// MFRC522 rfid(PIN_1, PIN_2);

// Init array that will store new NUID
byte nuidPICC[4];

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
  // this->valueDevice = "";

  // if (!this->rfid->PICC_IsNewCardPresent())
  // {
  //   // return false;
  //   return false;
  // }

  // // // Select one of the cards
  // if (!this->rfid->PICC_ReadCardSerial())
  // {
  //   return false;
  // }

  // this->valueDevice += "UID: ";

  // for (byte i = 0; i < this->rfid->uid.size; i++)
  // {
  //   this->valueDevice += String(this->rfid->uid.uidByte[i], HEX) + " ";
  // }

  // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
  if (!this->rfid->PICC_IsNewCardPresent())
    return;

  // Verify if the NUID has been readed
  if (!this->rfid->PICC_ReadCardSerial())
    return;

  if (this->rfid->uid.uidByte[0] != nuidPICC[0] ||
      this->rfid->uid.uidByte[1] != nuidPICC[1] ||
      this->rfid->uid.uidByte[2] != nuidPICC[2] ||
      this->rfid->uid.uidByte[3] != nuidPICC[3])
  {

    // Store NUID into nuidPICC array
    for (byte i = 0; i < 4; i++)
    {
      nuidPICC[i] = this->rfid->uid.uidByte[i];
    }
    this->valueDevice = "UID: " + String(nuidPICC[0], HEX) + " " + String(nuidPICC[1], HEX) + " " + String(nuidPICC[2], HEX) + " " + String(nuidPICC[3], HEX);
    // this->valueDevice = "UID: " + String(nuidPICC[0], HEX) + " " + String(nuidPICC[1], HEX) + " " + String(nuidPICC[2], HEX + " ") + String(nuidPICC[3], HEX);
    // std::string str = "Hello World";
    // std::transform(this->valueDevice->begin(), this->valueDevice->end(), this->valueDevice->begin(), ::toupper);
  }
  else
    this->valueDevice = "Already Read";

  // Halt PICC
  this->rfid->PICC_HaltA();

  // Stop encryption on PCD
  this->rfid->PCD_StopCrypto1();

  return 1;
}

bool Controller_RC522_Data::init()
{
  deInit();
  // Add your code here
  this->timeInterval = 200;
  this->valueDevice = "Read RFID Card";
  SPI.begin(); // Init SPI bus
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