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

void ArduinoWiFi::disconnect()
{
}

bool ArduinoWiFi::connectToServer(char* server)
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

void ArduinoWiFi::sendRequest(char* request)
{
    m_client->print(request);
}

char* ArduinoWiFi::receiveResponse(unsigned int& responseLength)
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