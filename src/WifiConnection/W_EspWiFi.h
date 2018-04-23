#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "IWiFi.h"

namespace waffle
{
    class EspWiFi : public IWiFi
    {
        public:
        // standard constructor
		EspWiFi();

        // destructor
        ~EspWiFi();

        // disconnect from WiFi
        void disconnect(bool wifioff);

		bool softAP(const char* ssid, const char* passphrase, int channel, int ssid_hidden, int max_connection);

        // configure Access Point
        bool softAPConfig(IPAddress local_ip, IPAddress gateway, IPAddress subnet);

		// disconnect Access Point
		bool softAPdisconnect(bool wifioff);

        String SSID(uint8_t networkItem);

        void makeServer(int port);

        void beginServer();

        void stopServer();

        void serverHandleClient();

        protected:
        ESP8266WebServer *server;
    };
}
