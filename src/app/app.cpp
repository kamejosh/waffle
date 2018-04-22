#include "app.h"

App::App(){
	// this gets called when your app class get initialized
	// this happens once and should only set the class
	// to a valid state
	// do not put any logic here
}

App::~App(){
	// this gets called once your class is destroyed
	// you should free all memory allocations that you
	// made in your class here
	// rule of thumb: for every "new XY" you made,
	// you should have a "delete XY" here
}

void App::onEnter(){
	// this gets called (once) everytime the application enters this state
	// put your state startup stuff here (like resetting timers and counters)
}

void App::onExit(){
	// this is called (once) before the applications leaves this state
	// to switch to another state (for example when the wifi connection fails,
	// the framework will automatically switch to the hotspot state)
	// your code will be paused in the meanwhile
}

int App::loop( unsigned long millisSinceLastTick ){
	// this is the main loop of your application
	// it is basically the same as the loop-function
	// in the arduino sketches
	// your main logic should be here.
	// this method should be non blocking. This means that there should
	// not be loops that wait for a specific event here.
	// Instead, just check if an operation is ready in each call of this function
	// and return in the meanwhile.
	// This is neccessary because the framework will take care of other tasks
	// between each App::loop call!
}
