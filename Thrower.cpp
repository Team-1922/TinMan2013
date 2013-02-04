#include "Thrower.h"


//Constructor
Thrower::Thrower(Joystick *stickInput):
	ThrowerMotor_(PWM_THROWER_MOTOR),
	SpeedSensor_(DIG_CH_IN_FEEDER_SENSOR),
	LowSpeed_(stickInput, BTN_J2_SPEED_1),
	MidSpeed_(stickInput, BTN_J2_SPEED_2),
	HighSpeed_(stickInput, BTN_J2_SPEED_3)
{
	stick_ = stickInput;
	isUsingRPM_ = false;
}

//Deconstructor
Thrower::~Thrower()
{
}

void Thrower::setRPM(int s)
{
	//Set the motor to use RPM, disable speed, and set the rpm_ variable.
	isUsingRPM_ = true;
	speed_ = 0;
	rpm_ = s;
}

void Thrower::setSpeed(float s)
{
	//Disable the use of RPM, and set the speed;
	isUsingRPM_ = false;
	speed_ = s;
	rpm_ = 0;
}

bool Thrower::isHealthy()
{
	return true;	//ISSUE: Function needs to somehow check if it is healthy.
}

void Thrower::updateMotor()
{
	if(isUsingRPM_) {
		//Handle controlling the motor using RPMs
	}
	else {
		ThrowerMotor_.Set(speed);
	}
}
