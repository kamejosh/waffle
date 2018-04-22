/*
	This file bootstraps the framework. Do not change the code here.
	Add your code to "/src/app/..."
*/
#include "WifiConnection/board.h"
#include <Arduino.h>
#include "framework/app/setup.h"
#include "framework/statemachine/statemachine.h"
#include "framework/states/hotspot.h"
#include "app/app.h"

// keep track of millis
unsigned long lastMillis = 0;

StateMachine *mainStatemachine;
int stateIds[2];

#define STATE_HOTSPOT stateIds[0]
#define STATE_APP stateIds[1]

void setup() {

	// call user setup code here


	// setup config and load data TODO implement persistent memory
	//persistentMemory = new persistentMemory();
	//persistentMemory->load(); // load from flash or EEPROM memory

	mainStatemachine = new StateMachine();
	STATE_HOTSPOT = mainStatemachine->registerState( new Hotspot() );
	STATE_APP = mainStatemachine->registerState( new App() );

	// start with hotspot TODO: start with self check
	mainStatemachine->switchToState( STATE_HOTSPOT );

	// avoid instant self check timeout if upload (or, in theory, setup)
	// takes longer than the defined timeout delay
	lastMillis = millis();
}

void loop() {

	// get millis since last loop start
	unsigned long currentMillis = millis();
	unsigned long millisSinceLastTick = 0;
	if( currentMillis < lastMillis ){
		// this situation happens only when millis are overflowing
		unsigned long maxMillis = -1;
		unsigned long millisBeforeOverflow = maxMillis - lastMillis;
		millisSinceLastTick = currentMillis + millisBeforeOverflow;
	}else{
		millisSinceLastTick = currentMillis - lastMillis;
	}
	lastMillis = currentMillis;

	// loop state
	int sig = mainStatemachine->loop(millisSinceLastTick);

	if( sig != NO_SIGNAL ){

		// we currently lack a self-check state and a persitance layer
		// therefore we "ignore" SIG_HOTSPOT_IDLE_TIMEOUT signals
		// and jump right back to the hotspot
		if( mainStatemachine->getCurrentStateId() == STATE_HOTSPOT ){

			mainStatemachine->switchToState( sig == SIG_HOTSPOT_OK ? STATE_APP : STATE_HOTSPOT );

		}else{

			// if the main app returns anything else than NO_SIGNAL
			// the framework asumes the user wants to re-open the hotspot
			// to change settings
			mainStatemachine->switchToState( STATE_HOTSPOT );

		}

	}

}
