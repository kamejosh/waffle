#include <ESP8266WiFi.h>
#include "IWiFi.h"

namespace waffle
{
    class EspWiFi : public IWiFi
    {
        public:
        // standard constructor
		EspWiFi();

        // constructor with ssid and password to allow a connection
		EspWiFi(char* ssid, char* pwd);

        // destructor
        ~EspWiFi();

        // connect to the set WiFi, returns true on success, returns false on fail.
        bool connect();

        // disconnect from WiFi
        void disconnect(bool wifioff);

		bool softAP(const char* ssid, const char* passphrase, int channel, int ssid_hidden, int max_connection);

		// disconnect Access Point
		void softAPdisconnect(bool wiifoff);

protected:
        //Library WiFi-Client
        WiFiClient* m_client;



    };
}
