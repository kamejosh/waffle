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
    };
}
