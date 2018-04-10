#include <LinkedList.h>
#include "state.h"

#ifndef __STATEMACHINE_STATEMACHINE_H
#define __STATEMACHINE_STATEMACHINE_H

class StateMachine : public State {

	protected:
		LinkedList<State*> states;
		unsigned int currentStateId;

	public:
		StateMachine();
		virtual ~StateMachine();
		virtual void onEnter();
		virtual void onExit();
		virtual int loop( unsigned long millisSinceLastLoop );

		virtual int registerState( State *state );
		virtual void switchToState(int stateId);

};

#endif
