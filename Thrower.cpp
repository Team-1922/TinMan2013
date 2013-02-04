#include "Thrower.h"


//Constructor
Thrower::Thrower(Joystick *stickInput):
	ThrowerMotor_(PWM_THROWER_MOTOR),
	SpeedSensor_(DIG_CH_IN_FEEDER_SENSOR),
	LowSpeed_(stickInput, BTN_SPEED_1),
	MidSpeed_(stickInput, BTN_SPEED_2),
	HighSpeed_(stickInput, BTN_SPEED_3)
{
	stick_ = stickInput;
}

//Deconstructor
Thrower::~Thrower()
{
}

void Thrower::setRPM(int speed)
{
}

void Thrower::setSpeed(float speed)
{
}

bool Thrower::isHealthy()
{
}
