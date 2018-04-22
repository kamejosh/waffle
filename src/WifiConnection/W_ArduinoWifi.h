#include <WiFi.h>

#include "IWiFi.h"

namespace waffle
{
    class ArduinoWiFi : public IWiFi
    {
        public:
        // standard constructor
		ArduinoWiFi();

        // constructor with ssid and password to allow a connection
		ArduinoWiFi(char* ssid, char* pwd);

        // destructor
        virtual ~ArduinoWiFi();

		// connect to the set WiFi, returns true on success, returns false on fail.
        bool connect();

        // disconnect from WiFi
        void disconnect(bool wifioff);

		bool softAP(const char* ssid, const char* passphrase, int channel, int ssid_hidden, int max_connection);

		// disconnect Access Point
		void softAPdisconnect(bool wiifoff);
    };
}
