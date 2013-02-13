#include "Thrower.h"


//Constructor calls the constructors of the motor, limit switch, buttons,
//an RPM task, and a revolutions counter.
Thrower::Thrower(Joystick *stickInput):
	ThrowerMotor_(PWM_THROWER_MOTOR),
	SpeedSensor_(DIG_IN_SHOOTER_RPM),
	LowSpeed_(stickInput, BTN_J2_SPEED_1),
	MidSpeed_(stickInput, BTN_J2_SPEED_2),
	HighSpeed_(stickInput, BTN_J2_SPEED_3),
	ThrowerRPM_((TimerEventHandler)updateRPMFunction, this),
	Revolutions_(new DigitalInput(DIG_IN_SHOOTER_RPM))
{
	//Set the stick pointer
	stick_ = stickInput;
	
	//Start the RPM task and the revolutions counter.
	ThrowerRPM_.StartPeriodic(RPM_TIME);
	Revolutions_.Start();
}

//Deconstructor
Thrower::~Thrower()
{
	//Stop the RPM task and revolutions counter.
	ThrowerRPM_.Stop();
	Revolutions_.Stop();
}

//Check and handle inputs from the joystick.
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
	
	//Coerce the speed from the throttle to be positive.
	float spd = stick_->GetThrottle();
	if(spd < 0.0) {
		spd = 0.0;
	}
	
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

//Function called by the RPM task that calls the updateRPM function.
void Thrower::updateRPMFunction(Thrower* thrower)
{
	thrower->updateRPM();
	return;
}

//Update the RPMs on the dashboard.
void Thrower::updateRPM()
{
	//Calculate and send the RPMs on the dashboard.
	double rpm = Revolutions_.Get() * (60.0 / RPM_TIME);
	SmartDashboard::PutNumber("RPM", rpm);
	Revolutions_.Reset();
}
