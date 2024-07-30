#include "Controller_Oled_0_96Inch.h"
#include "debugkxn.h"

U8GLIB_SSD1306_128X64 u8g1(U8G_I2C_OPT_DEV_0 | U8G_I2C_OPT_NO_ACK | U8G_I2C_OPT_FAST);

Controller_Oled_0_96Inch_Data::Controller_Oled_0_96Inch_Data()
{
  this->nameDevice = "Oled_0.96Inch";
  this->timeInterval = 50;
  this->valueDevice = "No device";
  this->Add_AddressList(0x3C);
  //this->Add_HsCode(617);
  // Add your code here

}

Controller_Oled_0_96Inch_Data::~Controller_Oled_0_96Inch_Data()
{
  
}

bool Controller_Oled_0_96Inch_Data::getData()
{
  // Add your code here
  this->valueDevice = "is Running";
  
  return true;
}

bool Controller_Oled_0_96Inch_Data::init()
{
  deInit();

  mode = 0;
  // u8g1.setFont(u8g_font_tpssb);
  // u8g1.setColorIndex(1);
  // u8g1.firstPage();
  // u8g1.drawBitmapP(0, 0, 128/8, 64, epd_bitmap_D___n_m_i1);

  /*Version 1: Have reset problem*/
  // do{
  //  u8g1.drawBitmapP(0, 0, 128/8, 64, epd_bitmap_D___n_m_i1);
  // }while(u8g1.nextPage());

  // delay(3000);
  
  // u8g1.firstPage();

  // do{
  //   u8g1.drawBitmapP(0, 0, 128/8, 64, epd_bitmap_hshop_logo_new1);
  // }while(u8g1.nextPage());
  
  // u8g1.nextPage();
  // if(u8g1.nextPage() == true){
  //   u8g1.firstPage();
  //   u8g1.drawBitmapP(0, 0, 128/8, 64, epd_bitmap_hshop_logo_new1);
  // }
  u8g1.firstPage();
  do{
   u8g1.drawBitmapP(0, 0, 128/8, 64, epd_bitmap_D___n_m_i1);
  }while(u8g1.nextPage() && mode == 0);

  mode = !mode;
  
  
  do{
    u8g1.drawBitmapP(0, 0, 128/8, 64, epd_bitmap_hshop_logo_new1);
  }while(u8g1.nextPage() && mode == 1);

  return 1;
}

bool Controller_Oled_0_96Inch_Data::deInit()
{
  // if(this->quocOled096 != NULL)
  // {
  //   free(this->quocOled096);
  //   this->quocOled096 = NULL;
  // }

  return 1;
}

Controller_Oled_0_96Inch_Data device_Controller_Oled_0_96Inch;