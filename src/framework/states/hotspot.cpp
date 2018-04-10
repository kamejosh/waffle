#include "hotspot.h"

Hotspot::Hotspot(){
	this->exitStateTimer = new Timer(EXIT_HOTSPOT_AFTER_MILLISECONDS_IDLE);
	this->connected = false;
}

Hotspot::~Hotspot(){
	delete(exitStateTimer);
}

void Hotspot::onEnter(){
	this->connected = false;
	this->startHotspot();

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
	// TODO handle server

	return NO_SIGNAL;
}

bool Hotspot::startHotspot(){

	// TODO change to generic implementation
	/*// define IP addresses
	IPAddress local_IP(HOTSPOT_IP);
	IPAddress gateway(HOTSPOT_GATEWAY);
	IPAddress subnet(HOTSPOT_SUBNET);

	// set fixed ip address
	if( !WiFi.softAPConfig(local_IP, gateway, subnet) ){
		Serial.println("Soft AP configuration failed!");
		return false;
	}*/

	const char* ssid = HOTSPOT_SSID;
	const char* password = HOTSPOT_PASSWD;

	// TODO change to generic implementation
	/*if( !WiFi.softAP( apssid, appassword ) ){
		Serial.println("Soft AP failed!");
		return false;
	}*/

	return true;

}

bool Hotspot::stopHotspot(){

	// TODO change to generic implementation
	/*
	// stop soft AP mode
	WiFi.softAPdisconnect(true);

	// disconnect wifi
	WiFi.disconnect(true);
	*/
}
