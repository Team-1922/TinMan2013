#include "Thrower.h"


//Constructor calls the constructors of the motor, limit switch, buttons,
//an RPM task, and a revolutions counter.
Thrower::Thrower(Joystick *stickInput):
	ThrowerMotor_(PWM_THROWER_MOTOR)
{
	//Set the stick pointer
	stick_ = stickInput;
}

//Deconstructor
Thrower::~Thrower()
{
}

//Check and handle inputs from the joystick.
void Thrower::checkInputs()
{
	//Coerce the speed from the throttle to be positive.
	float spd = (1.0-stick_->GetThrottle()) / 2.0;
	SmartDashboard::PutNumber("Throttle", spd);
	
	//Set the speed to the throttle.
	setSpeed(spd);
	
	return;
}

//The thrower does not have any real time inputs to check.
void Thrower::checkRealTimeInputs() {}

//Set the speed of the motor.
void Thrower::setSpeed(float s)
{
	ThrowerMotor_.Set(s);
}
