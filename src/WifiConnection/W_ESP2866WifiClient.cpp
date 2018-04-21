//library includes
#include <ESP8266WiFi.h>

//project includes
#include "W_ESP2866WiFiClient.h"

//set project namespace
using namespace waffle;

//class specific defines
static const unsigned int MAX_CONNECTION_ATTEMPTS = 10;

ESP2866WiFiClient::ESP2866WiFiClient() : IWiFiClient()
{
    m_client    = new WiFiClient();
}

ESP2866WiFiClient::ESP2866WiFiClient(char* ssid, char* pwd) : IWiFiClient(ssid, pwd)
{
    m_client    = new WiFiClient();
}

ESP2866WiFiClient::~ESP2866WiFiClient()
{
    delete      m_client;
}

bool ESP2866WiFiClient::connectWifi()
{
    Serial.print("Connecting to WiFi..");
    WiFi.begin(m_ssid, m_pwd);

    unsigned int connectionAttempts = 0;
    while (WiFi.status() != WL_CONNECTED)
    {
      delay(500);
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

void ESP2866WiFiClient::disconnectWifi()
{
}

bool ESP2866WiFiClient::connectToServer(char* server)
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

void ESP2866WiFiClient::sendRequest(char* request)
{
    m_client->print(request);
}

char* ESP2866WiFiClient::receiveResponse(unsigned int& responseLength)
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

