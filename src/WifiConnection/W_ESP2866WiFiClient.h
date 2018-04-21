#include "ESP8266WiFi.h"
#include "IWiFiClient.h"

namespace waffle
{
    class ESP2866WiFiClient : IWiFiClient
    {
        public:
        // standard constructor
		ESP2866WiFiClient();

        // constructor with ssid and password to allow a connection
		ESP2866WiFiClient(char* ssid, char* pwd);
        
        // destructor
        virtual ~ESP2866WiFiClient();

        // connect to the set WiFi, returns true on success, returns false on fail.
        virtual bool connectWifi();

        // disconnect from WiFi
        virtual void disconnectWifi();

        // connect to a server, returns true on success, returns false on fail.
        virtual bool connectToServer(char* server);

        // sends a request to the server currently connected to
        virtual void sendRequest(char* request);

        // receives a response from the server currently connected to
        virtual char* receiveResponse(unsigned int& responseLength);

        //Library WiFi-Client
        WiFiClient* m_client;
    };
}
