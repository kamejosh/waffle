#include "timer.h"

Timer::Timer( unsigned long triggerAt ) : Timer(triggerAt, false) {}

Timer::Timer( unsigned long triggerAt, bool oneShot ) : triggerAt(triggerAt), oneShot(oneShot){
	this->reset();
}

void Timer::reset(){
	this->temporaryNextTriggerAt = 0;
	this->timePast = 0;
	this->ready = false;
}

unsigned long Timer::getTriggerAt(){
	if( this->temporaryNextTriggerAt > 0 ){
		return this->temporaryNextTriggerAt;
	}
	return this->triggerAt;
}

void Timer::changeTriggerAt( unsigned long triggerAt ){
	this->triggerAt = triggerAt;
}

/* Sets a temporary trigger that automatically gets cleared once reached */
void Timer::setNextTriggerAt( unsigned long millis ){
	this->temporaryNextTriggerAt = millis;
}

void Timer::update( unsigned long millis ){
	this->timePast += millis;

	unsigned long realTriggerAt = this->getTriggerAt();

	if( this->timePast > realTriggerAt ){
		this->ready = true;
		this->timePast = this->timePast - realTriggerAt;
		this->temporaryNextTriggerAt = 0;
	}else{
		if( !this->oneShot ){
			this->ready = false;
		}
	}

}

bool Timer::isReady(){
	return this->ready;
}

double Timer::getProgress(){
	if( this->timePast >= this->getTriggerAt() ){
		return 1.0;
	}
	return (timePast + 0.0) / this->getTriggerAt();
}
