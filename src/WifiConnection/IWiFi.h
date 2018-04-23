#ifndef WAFFLE_WIFI
#define WAFFLE_WIFI

#include "IPAddress.h"

namespace waffle
{
    class IWiFi
    {
        public:
        // standard constructor
		IWiFi(){};

        // destructor
		virtual ~IWiFi(){};

        // disconnect from WiFi
        virtual void disconnect(bool wifioff = false) = 0;

        // configure Access Point
        virtual bool softAPConfig(IPAddress local_ip, IPAddress gateway, IPAddress subnet) = 0;

        virtual bool softAP(const char* ssid, const char* passphrase, int channel = 1, int ssid_hidden = 0, int max_connection = 4) = 0;

        // disconnect Access Point
        virtual bool softAPdisconnect(bool wiifoff = false) = 0;

        virtual String SSID(uint8_t networkItem) = 0;

        virtual void makeServer(int port = 80) = 0;

        virtual void beginServer() = 0;

        virtual void stopServer() = 0;

        virtual void serverHandleClient() = 0;
    };
}

#endif
