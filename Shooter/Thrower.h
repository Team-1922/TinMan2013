#ifndef THROWER_H
#define THROWER_H

#include "WPILib.h"
#include "../Input/ButtonActivated.h"

#include "../RobotDefines.h"

//Class definiton of the thrower.
class Thrower
{
public:
	//Constructor and deconstructor.
	Thrower(Joystick*);
	~Thrower();
	
	//Check for inputs
	void checkInputs();
	void checkRealTimeInputs();
	
	//Set the power of the thrower using either direct speed, or RPM.
	void setSpeed(float);
	
private:
	//Motor that spins and sensor that tracks speed.
	Jaguar ThrowerMotor_;
	
	//Joystick inputs to recognize speed.
	Joystick *stick_;
};

#endif
