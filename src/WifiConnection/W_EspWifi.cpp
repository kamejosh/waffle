#ifndef AVR

//library includes
#include <ESP8266WiFi.h>

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

void EspWiFi::disconnect()
{
}

bool EspWiFi::connectToServer(char* server)
{
    Serial.println("Connecting to server...");

    if(m_client->connect(server, 80))
    {
      Serial.println("Connection to Server successful!");
      return true;
    }
    else
    {
      Serial.println("Connection to Server failed!");
      return false;
    }
}

void EspWiFi::sendRequest(char* request)
{
    m_client->print(request);
}

char* EspWiFi::receiveResponse(unsigned int& responseLength)
{
    Serial.println("Reading message response...");
    responseLength = m_client->available();
    Serial.print("Message length: ");
    Serial.println(responseLength);
    char* message = new char[responseLength];
    for(unsigned int n = 0; n < responseLength; ++n)
    {
        char* current = (message+n);
        *current = m_client->read();
        Serial.println(current);
    }
    Serial.println(message);
    return message;
}

#endif