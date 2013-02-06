#include "Thrower.h"


//Constructor
Thrower::Thrower(Joystick *stickInput):
	ThrowerMotor_(PWM_THROWER_MOTOR),
	SpeedSensor_(DIG_IN_SHOOTER_RPM),
	LowSpeed_(stickInput, BTN_J2_SPEED_1),
	MidSpeed_(stickInput, BTN_J2_SPEED_2),
	HighSpeed_(stickInput, BTN_J2_SPEED_3)
{
	stick_ = stickInput;
}

//Deconstructor
Thrower::~Thrower()
{
}

void Thrower::checkInputs()
{
	//If the low speed button is activated.
	if(LowSpeed_.isPressed()) {
		setSpeed(LOW_SPEED);
		return;
	}
	
	//If the mid speed button is activated.
	if(MidSpeed_.isPressed()) {
		setSpeed(MID_SPEED);
		return;
	}
	
	//If the high speed button is activated.
	if(HighSpeed_.isPressed()) {
		setSpeed(HIGH_SPEED);
		return;
	}
	
	//Coerce the speed to be positive.
	float spd = stick_->GetThrottle();
	if(spd < 0.0) {
		spd = 0.0;
	}
	
	//Set the speed to the throttle.
	setSpeed(spd);
	
	return;
}

void Thrower::checkRealTimeInputs()
{
	return;
}

void Thrower::setSpeed(float s)
{
	//Set the speed of the jaguar.
	ThrowerMotor_.Set(s);
	
	return;
}

bool Thrower::isHealthy()
{
	return true;	//ISSUE: Function needs to somehow check if it is healthy.
}
