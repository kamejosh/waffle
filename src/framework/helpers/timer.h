#ifndef __TIMER_H
#define __TIMER_H

class Timer {

private:
	unsigned long temporaryNextTriggerAt;
	unsigned long triggerAt;
	unsigned long timePast;
	bool ready;
	bool oneShot;

	unsigned long getTriggerAt();

public:
	explicit Timer( unsigned long triggerAt );
	Timer( unsigned long triggerAt, bool oneShot );
	void reset();
	void changeTriggerAt( unsigned long millis );
	void setNextTriggerAt( unsigned long millis );
	void update( unsigned long millis );
	bool isReady();
	double getProgress();

};

#endif
