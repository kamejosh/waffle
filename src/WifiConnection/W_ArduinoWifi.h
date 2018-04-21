
#ifdef AVR

#include "WiFi.h"
#include "IWiFi.h"

namespace waffle
{
    class ArduinoWiFi : IWiFi
    {
        public:
        // standard constructor
		ArduinoWiFi();

        // constructor with ssid and password to allow a connection
		ArduinoWiFi(char* ssid, char* pwd);
        
        // destructor
        virtual ~ArduinoWiFi();

        // connect to the set WiFi, returns true on success, returns false on fail.
        virtual bool connect();

        // disconnect from WiFi
        virtual void disconnect();

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