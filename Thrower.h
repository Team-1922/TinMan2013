#ifndef THROWER_H
#define THROWER_H

#include "WPILib.h"
#include "ButtonActivated.h"

#include "RobotDefines.h"

const float LOW_SPEED = -0.3;
const float MID_SPEED = -0.6;
const float HIGH_SPEED = -0.9;

const float RPM_TIME = 0.2;

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
	
	//Check if the thrower is healthy or not.
	bool isHealthy();
	
	void updateRPM();
	
private:
	//Motor that spins and sensor that tracks speed.
	Jaguar ThrowerMotor_;
	DigitalInput SpeedSensor_;
	
	//Joystick inputs to recognize speed.
	ButtonActivated LowSpeed_;
	ButtonActivated MidSpeed_;
	ButtonActivated HighSpeed_;
	Joystick *stick_;
	
	//Create variables and a static function to check the RPM.
	Notifier ThrowerRPM_;
	Counter Revolutions_;
	static void updateRPMFunction(Thrower*);
};

#endif
