#include "Controller_PAJ7620U2.h"
#include "debugkxn.h"

Controller_PAJ7620U2_Data::Controller_PAJ7620U2_Data()
{
  this->nameDevice = "PAJ7620U2";
  this->timeInterval = 250;
  this->valueDevice = "No device";
  this->Add_AddressList(0x27);
  //this->Add_HsCode(1304);
  // Add your code here

}

Controller_PAJ7620U2_Data::~Controller_PAJ7620U2_Data()
{
  
}

bool Controller_PAJ7620U2_Data::getData()
{
  // Add your code here
  this->valueDevice = "";
  
  uint8_t data = 0, data1 = 0, error;
  
  error = paj7620ReadReg(0x43, 1, &data);       // Read Bank_0_Reg_0x43/0x44 for gesture result.
  if (!error) 
  {
    
    switch (data)                   // When different gestures be detected, the variable 'data' will be set to different values by paj7620ReadReg(0x43, 1, &data).
    {
      case GES_RIGHT_FLAG:
        delay(800);
        paj7620ReadReg(0x43, 1, &data);
        if(data == GES_FORWARD_FLAG) 
        {
          this->valueDevice = "Tien";
          delay(1000);
        }
        else if(data == GES_BACKWARD_FLAG) 
        {
          this->valueDevice = "Lui";
          delay(1000);
        }
        else
        {
          this->valueDevice = "Phai"; 
        }          
        break;
      case GES_LEFT_FLAG: 
        delay(800);
        paj7620ReadReg(0x43, 1, &data);
        if(data == GES_FORWARD_FLAG) 
        {
          this->valueDevice = "Tien";
          delay(1000);
        }
        else if(data == GES_BACKWARD_FLAG) 
        {
          this->valueDevice = "Lui";
          delay(1000);
        }
        else
        {
          this->valueDevice = "Trai";
        }          
        break;
      case GES_UP_FLAG:
        delay(800);
        paj7620ReadReg(0x43, 1, &data);
        if(data == GES_FORWARD_FLAG) 
        {
          //printing();
          this->valueDevice = "Tien";
          delay(1000);
        }
        else if(data == GES_BACKWARD_FLAG) 
        {
//          printing();
          this->valueDevice = "Lui";
          delay(1000);
        }
        else
        {
//          printing();
          this->valueDevice = "Len";
        }          
        break;
      case GES_DOWN_FLAG:
        delay(800);
        paj7620ReadReg(0x43, 1, &data);
        if(data == GES_FORWARD_FLAG) 
        {
//          printing();
          this->valueDevice = "Tien";
          delay(1000);
        }
        else if(data == GES_BACKWARD_FLAG) 
        {
//          printing();
          this->valueDevice = "Lui";
          delay(1000);
        }
        else
        {
//          printing();
          this->valueDevice = "Xuong";
        }          
        break;
      case GES_FORWARD_FLAG:
//        printing();
        this->valueDevice = "Tien";
        delay(1000);
        break;
      case GES_BACKWARD_FLAG: 
//        printing();    
        this->valueDevice = "Lui";
        delay(1000);
        break;
      case GES_CLOCKWISE_FLAG:
//        printing();
        this->valueDevice = "Cung chieu dong ho";
        break;
      case GES_COUNT_CLOCKWISE_FLAG:
//        printing();
        this->valueDevice = "Nguoc chieu dong ho";
        break;  
      default:
        paj7620ReadReg(0x44, 1, &data1);
        if (data1 == GES_WAVE_FLAG) 
        {
//          printing();
          this->valueDevice = "wave";
        }
        break;
    }
  }
  
  delay(100);

  return true;
}

bool Controller_PAJ7620U2_Data::init()
{
  deInit();
  // Add your code here
  paj7620Init();

  return 1;
}

bool Controller_PAJ7620U2_Data::deInit()
{
  // Add your code here

  return 1;
}

Controller_PAJ7620U2_Data device_Controller_PAJ7620U2;