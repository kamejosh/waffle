// only compile this on esp boards (currently NON-AVR)
#ifndef AVR

//project includes
#include "W_EspWiFi.h"

//set project namespace
using namespace waffle;

EspWiFi::EspWiFi() : IWiFi(){}

EspWiFi::~EspWiFi(){
    delete(server);
}

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

String EspWiFi::SSID(uint8_t networkItem)
{
    return WiFi.SSID(networkItem);
}

int8_t EspWiFi::scanNetworks()
{
    return WiFi.scanNetworks();
}

void EspWiFi::makeServer(int port)
{
    this->server = new ESP8266WebServer(port);
}

void EspWiFi::beginServer()
{
    this->server->begin();
}

void EspWiFi::stopServer()
{
    this->server->stop();
}

void EspWiFi::serverHandleClient()
{
    this->server->handleClient();
}

void EspWiFi::serverOn(const String &uri, int method, int code, const char* contentType, const char* content)
{
    this->server->on(uri, HTTP_GET, [=](){
        this->server->send_P(code, contentType, content);
    });
}

void EspWiFi::serverOnPost(const String &uri, int method, int code, const char* contentType, String content)
{
    this->server->on(uri, HTTP_GET, [=](){
        this->server->send(code, contentType, content.c_str());
    });
}

void EspWiFi::serverOnConfig(const String &uri, int method, int code, const char* contentType, const char* content)
{

}

void EspWiFi::serverOnNotFound()
{
    this->server->onNotFound([this](){
		this->server->send(404, "text/plain", "404 - Not found");
	});
}

#endif
