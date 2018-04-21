namespace waffle
{
    class IWiFiClient
    {
        public:
        // standard constructor
		IWiFiClient() : m_ssid (nullptr), m_pwd(nullptr){};

        // constructor with ssid and password to allow a connection
		IWiFiClient(char* ssid, char* pwd) : m_ssid(ssid), m_pwd(pwd) {};
        
        // destructor
		virtual ~IWiFiClient()
		{
			delete[]    m_ssid;
			delete[]    m_pwd;
		};

        // connect to the set WiFi, returns true on success, returns false on fail.
        virtual bool connectWiFi() = 0;

        // disconnect from WiFi
        virtual void disconnectWiFi() = 0;

        // connect to a server, returns true on success, returns false on fail.
        virtual bool connectToServer(char* server) = 0;

        // sends a request to the server currently connected to
        virtual void sendRequest(char* request) = 0;

        // receives a response from the server currently connected to
        virtual char* receiveResponse(unsigned int& responseLength) = 0;

        // set the SSID
		virtual void setSSID(char* ssid) { m_ssid = ssid; };

        // set the password
		virtual void setPassword(char* pwd) { m_pwd = pwd; };

        protected:
        char* m_ssid;
        char* m_pwd;
    };
}
