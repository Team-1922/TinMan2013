#ifndef FEEDER_H
#define FEEDER_H

#include "WPILib.h"
#include "ButtonActivated.h"

#include "RobotDefines.h"

const float FEED_SPEED = 0.5;

//Class declaration for the feeder.
class Feeder
{
public:
	//Constructor and deconstructor
	Feeder(Joystick*);
	~Feeder();
	
	void initialize();
	
	//Check for inputs
	void checkInputs();
	void checkRealTimeInputs();
	
private:
	
	Jaguar				FeedMotor_;		//Feeder motor.
	ButtonActivated 	FeedButton_;	//Button to feed.
	DigitalInput		FeedSwitch_;	//Switch to detect if feeding.
	
	bool isFeeding_;	//Store the state of feeding.
	bool isStarting_;	//Store the state if it is starting.
	
	void feed();	//Feed the frisbee into the thrower.
	
	bool canFeed();		//Check if the feeder can feed.
};

#endif
