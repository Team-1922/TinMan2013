#ifndef FEEDER_H
#define FEEDER_H

#include "WPILib.h"
#include "../Input/ButtonActivated.h"

#include "../RobotDefines.h"

const float FEED_SPEED = 0.5;

//Class declaration for the feeder.
class Feeder
{
public:
	//Constructor and deconstructor
	Feeder(Joystick*);
	
	//Check for inputs
	void checkInputs();
	void checkRealTimeInputs();

	void feed(bool); //Feed the frisbee into the thrower.
	
	bool isFeeding();
	
private:
	Jaguar				feederMotor_;	//Feeder motor.
	ButtonActivated 	feederButton_;	//Button to feed.
	DigitalInput		feederSwitch_;	//Limit switch on the feeder.
	
	//Hold the state of the feeder.
	bool isStarting_;
	bool isFeeding_;
};

#endif
