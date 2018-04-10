#include <Arduino.h>

#include "../statemachine/state.h"
#include "../../config.h"
#include "../helpers/timer.h"

#ifndef __STATE_HOTSPOT_H
#define __STATE_HOTSPOT_H

#define SIG_HOTSPOT_OK 0
#define SIG_HOTSPOT_IDLE_TIMEOUT 1

class Hotspot : public State {

	private:
		bool startHotspot();
		bool stopHotspot();
		Timer *exitStateTimer;
		// ESP8266WebServer *server; // TODO change to generic server implementation
		bool connected;

	public:
		Hotspot( /* ESP8266WebServer *server */ );
		~Hotspot();
		void onEnter();
		void onExit();
		int loop( unsigned long millisSinceLastTick );

};

#endif
