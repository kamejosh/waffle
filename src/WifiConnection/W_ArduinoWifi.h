#ifdef AVR

#include "Wifi.h"
#include "IWiFi.h"

namespace waffle
{
    class ArduinoWiFiClient : IWiFi
    {
        public:
        // standard constructor
		ArduinoWiFiClient();

        // constructor with ssid and password to allow a connection
		ArduinoWiFiClient(char* ssid, char* pwd);
        
        // destructor
        virtual ~ArduinoWiFiClient();

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
        WiFiClass* m_client;
    };
}

#endif