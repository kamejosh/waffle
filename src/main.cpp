/*
	This file bootstraps the framework. Do not change the code here.
	Add your code to "/src/app/..."
*/
#include "WifiConnection/board.h"
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

}
