#include "Controller_Oled_1_3Inch.h"
#include "debugkxn.h"

Controller_Oled_1_3Inch_Data::Controller_Oled_1_3Inch_Data()
{
  this->nameDevice = "Oled";
  this->timeInterval = 1500;
  // this->valueDevice = "No device";
  this->Add_AddressList(0x3C);
  // this->Add_HsCode(618);
  //  Add your code here
}

Controller_Oled_1_3Inch_Data::~Controller_Oled_1_3Inch_Data()
{
}

bool Controller_Oled_1_3Inch_Data::getData()
{
  // Add your code here
  return true;
}

bool Controller_Oled_1_3Inch_Data::init()
{
  deInit();

  // u8g.setDefaultBackgroundColor();
  this->u8g2 = new (U8GLIB_SH1106_128X64)(U8G_I2C_OPT_DEV_0 | U8G_I2C_OPT_NO_ACK | U8G_I2C_OPT_FAST);
  this->u8g2->setColorIndex(1);
  this->u8g2->firstPage();
  this->valueDevice = "Turn all pixel";
  do
  {
    this->u8g2->drawBitmapP(0, 0, 128 / 8, 64, epd_bitmap_D___n_m_i2_13);
  } while (this->u8g2->nextPage());

  delay(2000);

  this->u8g2->firstPage();

  do
  {
    this->u8g2->setFont(u8g_font_fub17);
    this->u8g2->drawStr(28, 42, "Hshop");
  } while (this->u8g2->nextPage());

  delay(1000);

  // delete u8g2;

  // delay(50);

  // this->valueDevice = "All Pixel On";
  // this->u8g3 = new (U8GLIB_SSD1306_128X64)(U8G_I2C_OPT_DEV_0 | U8G_I2C_OPT_NO_ACK | U8G_I2C_OPT_FAST);
  // this->u8g3->setColorIndex(1);
  // this->u8g3->firstPage();
  // do
  // {
  //   this->u8g3->drawBitmapP(0, 0, 128 / 8, 64, epd_bitmap_D___n_m_i2_13);
  // } while (this->u8g3->nextPage());

  // delay(2000);

  // this->u8g3->firstPage();

  // do
  // {
  //   this->u8g3->setFont(u8g_font_fub17);
  //   this->u8g3->drawStr(28, 42, "Hshop");
  // } while (this->u8g3->nextPage());

  // delay(1000);
  return 1;
}

bool Controller_Oled_1_3Inch_Data::deInit()
{
  delete u8g2;
  u8g2 = nullptr;
  // if(this->u8g3 != NULL){
  //   delete u8g3;
  // }
  return 1;
}

Controller_Oled_1_3Inch_Data device_Controller_Oled_1_3Inch;