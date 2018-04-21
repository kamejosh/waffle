#ifdef AVR

//project includes
#include "W_ArduinoWifi.h"

//set project namespace
using namespace waffle;

ArduinoWiFi::ArduinoWiFi() : IWiFi()
{
    m_client = new WiFiClient();
}

ArduinoWiFi::ArduinoWiFi(char* ssid, char* pwd) : IWiFi(ssid, pwd)
{
    m_client = new WiFiClient();
}

ArduinoWiFi::~ArduinoWiFi()
{
    delete m_client;
}

bool ArduinoWiFi::connect()
{
    
}

#endif
