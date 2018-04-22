// only compile this on esp boards (currently NON-AVR)
#ifndef AVR

//project includes
#include "W_EspWiFi.h"

//set project namespace
using namespace waffle;

//class specific defines
static const unsigned int MAX_CONNECTION_ATTEMPTS = 10;

EspWiFi::EspWiFi() : IWiFi()
{
    m_client = new WiFiClient();
}

EspWiFi::EspWiFi(char* ssid, char* pwd) : IWiFi(ssid, pwd)
{
    m_client = new WiFiClient();
}

EspWiFi::~EspWiFi()
{
    delete m_client;
}

bool EspWiFi::connect()
{
    Serial.print("Connecting to WiFi..");
    WiFi.begin(m_ssid, m_pwd);

    unsigned int connectionAttempts = 0;
    while (WiFi.status() != WL_CONNECTED)
    {
      //delay(500);
      Serial.print(".");
      ++connectionAttempts;

      if(connectionAttempts >= MAX_CONNECTION_ATTEMPTS)
      {
        Serial.println("Maximum number of connection attempts exceeded. Abort.");
        return false;
      }
    }

    Serial.println("\nConnection to WiFi successful!");
    return true;
}

void EspWiFi::disconnect(bool wifioff)
{

}

bool EspWiFi::softAP(const char* ssid, const char* passphrase, int channel, int ssid_hidden, int max_connection){
	return true; // TODO
};

// disconnect Access Point
void EspWiFi::softAPdisconnect(bool wiifoff) {
	 // TODO
};

#endif
