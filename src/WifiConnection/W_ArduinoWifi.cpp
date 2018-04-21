#ifdef AVR

//project includes
#include "W_ArduinoWifi.h"

//set project namespace
using namespace waffle;

//class specific defines
static const unsigned int MAX_CONNECTION_ATTEMPTS = 10;

ArduinoWiFi::ArduinoWiFi() : IWiFi()
{
    m_client = new WiFiClass();
}

ArduinoWiFi::ArduinoWiFi(char* ssid, char* pwd) : IWiFi(ssid, pwd)
{
    m_client = new WiFiClass();
}

ArduinoWiFi::~ArduinoWiFi()
{
    delete m_client;
}

bool ArduinoWiFi::connect()
{
    Serial.print("Connecting to WiFi..");
    WiFi.begin(m_ssid, m_pwd);

    unsigned int connectionAttempts = 0;
    while (WiFi.status() != WL_CONNECTED)
    {
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

#endif