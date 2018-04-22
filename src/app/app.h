#include <Arduino.h>

#include "../framework/statemachine/state.h"

#ifndef __STATE__APP_H
#define __STATE__APP_H

class App : public State {

	public:
		App();
		~App();
		void onEnter();
		void onExit();
		int loop( unsigned long millisSinceLastTick );

};

#endif
