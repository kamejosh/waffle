#ifndef __STATEMACHINE_STATE_H
#define __STATEMACHINE_STATE_H

#define NO_SIGNAL -1

class State {

	public:
		virtual ~State() {}
		virtual void onEnter() = 0;
		virtual void onExit() = 0;
		virtual int loop( unsigned long millisSinceLastTick ) = 0;

};

#endif
