#include <Arduino.h>

#include "../../WifiConnection/IWiFi.h"

#include "../statemachine/state.h"
#include "../../config.h"
#include "../helpers/timer.h"

#include WIFI_HEADER_FILE

#ifndef __STATE_HOTSPOT_H
#define __STATE_HOTSPOT_H

#define SIG_HOTSPOT_OK 0
#define SIG_HOTSPOT_IDLE_TIMEOUT 1

class Hotspot : public State {

	private:
		Timer *exitStateTimer;
		waffle::IWiFi *wifi;
		bool connected;
		
		bool startHotspot();
		void stopHotspot();
		void defineRoutes();
		void openHotspot();
		String getSSIDsAsJSON(int numberOfNetworks);
		bool isSSIDUnique(String *ssids, String ssid);

	public:
		Hotspot();
		~Hotspot();
		void onEnter();
		void onExit();
		int loop( unsigned long millisSinceLastTick );
};

#endif
