#include "Controller_Oled_0_91Inch.h"
#include "debugkxn.h"

Controller_Oled_0_91Inch_Data::Controller_Oled_0_91Inch_Data()
{
  this->nameDevice = "Oled 0.91";
  this->timeInterval = 250;
  this->valueDevice = "No device";
  this->Add_AddressList(0x3C);
  //this->Add_HsCode(947);
  // Add your code here

}

Controller_Oled_0_91Inch_Data::~Controller_Oled_0_91Inch_Data()
{
  
}

bool Controller_Oled_0_91Inch_Data::getData()
{
  // Add your code here
  this->valueDevice = "";
  
  return true;
}

bool Controller_Oled_0_91Inch_Data::init()
{
  deInit();
  // Add your code here
  U8GLIB_SSD1306_128X32 u8g(U8G_I2C_OPT_DEV_0 | U8G_I2C_OPT_NO_ACK | U8G_I2C_OPT_FAST);
  
  u8g.setFont(u8g_font_tpssb);
  u8g.setColorIndex(1);
  
  u8g.firstPage();
  
  do{
   u8g.drawBitmapP(0, 0, 128/8, 64, epd_bitmap_D___n_m_i);
  }while(u8g.nextPage());

  delay(3000);
  
  u8g.firstPage();
  
  do{
   u8g.drawBitmapP(0, 0, 128/8, 64, epd_bitmap_hshop_logo_new);
  }while(u8g.nextPage());

  return 1;
}

bool Controller_Oled_0_91Inch_Data::deInit()
{
  // Add your code here

  return 1;
}

Controller_Oled_0_91Inch_Data device_Controller_Oled_0_91Inch;