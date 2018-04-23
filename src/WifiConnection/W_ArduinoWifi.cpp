// only compile this if AVR is defined (meaning we are on a arduino)
#ifdef AVR

#include "W_ArduinoWifi.h"

//set project namespace
using namespace waffle;

ArduinoWiFi::ArduinoWiFi() : IWiFi(){}

ArduinoWiFi::~ArduinoWiFi(){}

void ArduinoWiFi::disconnect(bool wifioff)
{

}

bool ArduinoWiFi::softAP(const char* ssid, const char* passphrase, int channel, int ssid_hidden, int max_connection)
{
	return false;
}

bool ArduinoWiFi::softAPConfig(IPAddress local_ip, IPAddress gateway, IPAddress subnet)
{
	return false;
}

// disconnect Access Point
bool ArduinoWiFi::softAPdisconnect(bool wifioff)
{
	return false;
}

#endif
