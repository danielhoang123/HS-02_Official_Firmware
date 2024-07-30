#ifndef _DEBUG_H_KXN_H__
#define _DEBUG_H_KXN_H__

#define EN_DEBUG_KXN

#define debug(x) Serial.print(x)     // hiện debug
#define debugln(x) Serial.println(x) // hiện debug

#define debug_sieuam(x) Serial.print(x) // hiện debug

#define debug_DHT_ln(x) Serial.println(x) // hiện debug

#define debug_manager_I2C_device(x) Serial.print(x)     // hiện debug
#define debug_manager_I2C_deviceln(x) Serial.println(x) // hiện debug

#ifndef EN_DEBUG_KXN
#define debug(x)   // tắt debug
#define debugln(x) // tắt debug
#endif

#endif
