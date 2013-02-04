#ifndef THROWER_H
#define THROWER_H

#include "WPILib.h"
#include "ButtonActivated.h"

#include "RobotDefines.h"

//Class definiton of the thrower.
class Thrower
{
public:
	//Constructor and deconstructor.
	Thrower(Joystick*);
	~Thrower();
	
	//Set the power of the thrower using either direct speed, or RPM.
	void setSpeed(float);
	void setRPM(int);
	
	//Check if the thrower is healthy or not.
	bool isHealthy();
	
	void updateMotor();
	
private:
	//Motor that spins and sensor that tracks speed.
	Jaguar ThrowerMotor_;
	DigitalInput SpeedSensor_;
	
	//Joystick inputs to recognize speed.
	ButtonActivated LowSpeed_;
	ButtonActivated MidSpeed_;
	ButtonActivated HighSpeed_;
	Joystick *stick_;
	
	//Check if the thrower is based on RPM or direct control.
	bool isUsingRPM_;
	
	//Variables for speed and RPM.
	float speed_;
	int rpm_;
};

#endif
