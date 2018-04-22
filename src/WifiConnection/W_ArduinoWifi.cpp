// only compile this if AVR is defined (meaning we are on a arduino)
#ifdef AVR

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

// connect to the set WiFi, returns true on success, returns false on fail.
bool ArduinoWiFi::connect(){
	return true;
}

// disconnect from WiFi
void ArduinoWiFi::disconnect(bool wifioff){}

bool ArduinoWiFi::softAP(const char* ssid, const char* passphrase, int channel, int ssid_hidden, int max_connection){
	return true;
}

// disconnect Access Point
void ArduinoWiFi::softAPdisconnect(bool wiifoff){}

#endif
