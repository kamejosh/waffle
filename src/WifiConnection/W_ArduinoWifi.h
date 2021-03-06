#include <WiFi.h>

#include "IWiFi.h"

namespace waffle
{
    class ArduinoWiFi : public IWiFi
    {
        public:
        // standard constructor
		ArduinoWiFi();

        // destructor
        virtual ~ArduinoWiFi();

		// disconnect from WiFi
        void disconnect(bool wifioff);

		bool softAP(const char* ssid, const char* passphrase, int channel, int ssid_hidden, int max_connection);

        // configure Access Point
        bool softAPConfig(IPAddress local_ip, IPAddress gateway, IPAddress subnet);

		// disconnect Access Point
		bool softAPdisconnect(bool wifioff);

        String SSID(uint8_t networkItem);

        int8_t scanNetworks();

        void makeServer(int port);

        void beginServer();

        void stopServer();

        void serverHandleClient();

        void serverOn(const String &uri, int method, int code, const char* contentType, const char* content);
        void serverOnPost(const String &uri, int method, int code, const char* contentType, const char* content);
        void serverOnConfig(const String &uri, int method, int code, const char* contentType, const char* content);
        void serverOnNotFound();

        protected:
        WiFiServer *server;
    };
}
