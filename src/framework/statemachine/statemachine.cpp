#include "statemachine.h"

StateMachine::StateMachine(){
	this->currentStateId = 0;
}

StateMachine::~StateMachine(){

}

void StateMachine::onEnter(){
	this->states.get( this->currentStateId )->onEnter();
}

void StateMachine::onExit(){
	this->states.get( this->currentStateId )->onExit();
}

int StateMachine::loop( unsigned long millisSinceLastLoop ){

	// return no signal if no states are registered
	if( this->states.size() == 0 ){
		return NO_SIGNAL;
	}

	return this->states.get( this->currentStateId )->loop(millisSinceLastLoop);

}

int StateMachine::registerState( State *state ){
	int stateId = this->states.size();
	this->states.add(state);
	return stateId;
}

void StateMachine::switchToState( int stateId ){
	if( stateId >= 0 && stateId < this->states.size() ){
		this->states.get( this->currentStateId )->onExit();
		this->currentStateId = stateId;
		this->states.get( this->currentStateId )->onEnter();
	}
}
