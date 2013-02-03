#ifndef THROWER_H
#define THROWER_H

#include "WPILib.h"
#include "ButtonActivated.h"

//Class definiton of the thrower.
class Thrower
{
public:
	//Constructor and deconstructor.
	Thrower();
	~Thrower();
	
	//Set the power of the thrower using either direct speed, or RPM.
	void setSpeed(float);
	void setRPM(int);
	
	//Check if the thrower is healthy or not.
	bool isHealthy();
	
private:
	//Motor that spins and sensor that tracks speed.
	Jaguar ThrowerMotor_;
	DigitalInput SpeedSensor_;
	
	//Joystick inputs to recognize speed.
	ButtonActivated LowSpeed_;
	ButtonActivated MidSpeed_;
	ButtonActivated HighSpeed_;
	Joystick *stick_;
};

#endif
