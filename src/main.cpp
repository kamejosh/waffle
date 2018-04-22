/*
	This file bootstraps the framework. Do not change the code here.
	Add your code to "/src/app/..."
*/
#include "board.h"
#include <Arduino.h>
#include "framework/app/setup.h"

// keep track of millis
unsigned long lastMillis = 0;

void setup() {

	// call user setup code here


	// setup config and load data
	//persistentMemory = new persistentMemory();
	//persistentMemory->load(); // load from flash or EEPROM memory

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

}
