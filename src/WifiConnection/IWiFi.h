#ifndef WAFFLE_WIFI
#define WAFFLE_WIFI

namespace waffle
{
    class IWiFi
    {
        public:
        // standard constructor
		IWiFi() : m_ssid (nullptr), m_pwd(nullptr){};

        // constructor with ssid and password to allow a connection
		IWiFi(char* ssid, char* pwd) : m_ssid(ssid), m_pwd(pwd) {};

        // destructor
		virtual ~IWiFi()
		{
			delete[]    m_ssid;
			delete[]    m_pwd;
		};

        // connect to the set WiFi, returns true on success, returns false on fail.
        virtual bool connect() = 0;

        // disconnect from WiFi
        virtual void disconnect(bool wifioff = false) = 0;

        // configure Access Point
        //virtual void softAPConfig(IPAddress local_ip, IPAddress gateway, IPAddress subnet) = 0;

        virtual bool softAP(const char* ssid, const char* passphrase, int channel = 1, int ssid_hidden = 0, int max_connection = 4) = 0;

        // disconnect Access Point
        virtual void softAPdisconnect(bool wiifoff = false) = 0;

        // set the SSID
		virtual void setSSID(char* ssid) { m_ssid = ssid; };

        // set the password
		virtual void setPassword(char* pwd) { m_pwd = pwd; };

        protected:
        char* m_ssid;
        char* m_pwd;
    };
}

#endif
