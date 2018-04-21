#ifdef AVR

//project includes
#include "W_ArduinoWifi.h"

//set project namespace
using namespace waffle;

ArduinoWiFi::ArduinoWiFi() : IWiFi()
{

}

ArduinoWiFi::ArduinoWiFi(char* ssid, char* pwd) : IWiFi(ssid, pwd)
{

}

ArduinoWiFi::~ArduinoWiFi()
{

}

#endif
