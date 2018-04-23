#include "hotspot.h"

Hotspot::Hotspot(){
	this->exitStateTimer = new Timer(EXIT_HOTSPOT_AFTER_MILLISECONDS_IDLE);
	this->connected = false;
	this->wifi = new WIFI_CLASS();
	this->wifi->makeServer(80);
}

Hotspot::~Hotspot(){
	delete(exitStateTimer);
	delete(wifi);
}

void Hotspot::onEnter(){
	this->connected = false;

	this->wifi->disconnect(true);
	this->startHotspot();

	this->defineRoutes();

	this->wifi->beginServer();
}

void Hotspot::onExit(){
	this->stopHotspot();
}

int Hotspot::loop( unsigned long millisSinceLastTick ){
	this->exitStateTimer->update(millisSinceLastTick);

	// if configuration has been set, send hotspot ok signal
	if( this->connected ){
		return SIG_HOTSPOT_OK;
	}

	// after the timer is done, exit hotspot state
	// this case is neccessary, if WiFi is unavailable
	// for longer than the running state accepts, and
	// state is therefore switched to hotspot
	if( this->exitStateTimer->isReady() ){
		return SIG_HOTSPOT_IDLE_TIMEOUT; //returning OK still means that this has failed
	}

	// otherwise handle waiting calls
	this->wifi->serverHandleClient();

	return NO_SIGNAL;
}

bool Hotspot::startHotspot(){

	IPAddress local_IP(HOTSPOT_IP);
	IPAddress gateway(HOTSPOT_GATEWAY);
	IPAddress subnet(HOTSPOT_SUBNET);

	if(!this->wifi->softAPConfig(local_IP, gateway, subnet))
	{
		Serial.println("Soft AP configuration failed!");
		return false;
	}

	const char* ssid = HOTSPOT_SSID;
	const char* password = HOTSPOT_PASSWD;

	if( !this->wifi->softAP(ssid, password) )
	{
		Serial.println("Soft AP failed!");
		return false;
	}

	return true;
}

void Hotspot::stopHotspot(){
	this->wifi->stopServer();

	this->wifi->softAPdisconnect(true);

	this->wifi->disconnect(true);
}

void Hotspot::defineRoutes()
{
	this->wifi->serverOnPost("/", 1, 200, "text/html", CONFIG_HTML);

	this->wifi->serverOnPost("/app.css", 1, 200, "text/css", CONFIG_CSS);

	this->wifi->serverOnPost("/app.js", 1, 200, "text/javascript", CONFIG_JS);

	int numberOfNetworks = this->wifi->scanNetworks();
	this->wifi->serverOn("/ssids", 1, 200, "application/json", getSSIDsAsJSON(numberOfNetworks).c_str());

	this->wifi->serverOn("/ping", 1, 200, "application/json", "\"pong\"");

	this->wifi->serverOnNotFound();
}

String Hotspot::getSSIDsAsJSON(int numberOfNetworks){
	String ssids[numberOfNetworks];
	String jsonString = "[";

  for(int i = 0; i<numberOfNetworks; i++){
      if(isSSIDUnique(ssids, this->wifi->SSID(i))){
				if(i > 0){
					jsonString += ",";
				}
        jsonString += "\"";
        jsonString += this->wifi->SSID(i);
				jsonString += "\"";
      }
  }

	jsonString += "]";
	return jsonString;
}

bool Hotspot::isSSIDUnique(String *ssids, String ssid){
    int newIndex = sizeof(ssids);
    for(uint8_t i = 0; i < sizeof(ssids); i++)
    {
        if(ssids[i] == "")
        {
            newIndex = i;
            break;
        }
        if(ssids[i] == ssid)
        {
            return false;
        }
    }

    ssids[newIndex] = ssid;
    return true;
}
