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

String ArduinoWiFi::SSID(uint8_t networkItem)
{
	return "";
}

int8_t ArduinoWiFi::scanNetworks()
{
	return 0;
}

void ArduinoWiFi::makeServer(int port)
{

}

void ArduinoWiFi::beginServer()
{

}

void ArduinoWiFi::stopServer()
{

}

void ArduinoWiFi::serverHandleClient()
{

}

void ArduinoWiFi::serverOn(const String &uri, int method, int code, const char* contentType, const char* content)
{

}

void ArduinoWiFi::serverOnPost(const String &uri, int method, int code, const char* contentType, String content)
{

}

void ArduinoWiFi::serverOnConfig(const String &uri, int method, int code, const char* contentType, const char* content)
{

}

void ArduinoWiFi::serverOnNotFound()
{

}

#endif
