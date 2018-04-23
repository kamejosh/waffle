// only compile this on esp boards (currently NON-AVR)
#ifndef AVR

//project includes
#include "W_EspWiFi.h"

//set project namespace
using namespace waffle;

EspWiFi::EspWiFi() : IWiFi(){}

EspWiFi::~EspWiFi(){}

void EspWiFi::disconnect(bool wifioff)
{
    WiFi.disconnect(wifioff);
}

bool EspWiFi::softAP(const char* ssid, const char* passphrase, int channel, int ssid_hidden, int max_connection){
	return WiFi.softAP(ssid, passphrase, channel, ssid_hidden, max_connection);
};

bool EspWiFi::softAPConfig(IPAddress local_ip, IPAddress gateway, IPAddress subnet)
{
    return WiFi.softAPConfig(local_ip, gateway, subnet);
}

// disconnect Access Point
bool EspWiFi::softAPdisconnect(bool wifioff) {
	return WiFi.softAPdisconnect(wifioff);
};

#endif
