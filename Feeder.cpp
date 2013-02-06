#include "Feeder.h"


//Constructor
Feeder::Feeder(Joystick *stick):
	FeederMotor_(PWM_FEEDER_MOTOR),
	ShootButton_(stick, BTN_J1_SHOOT),
	ShooterSwitch_(DIG_IN_FEED_LEVER_FWD)
{
	isShooting_ = false;
	isStarting_ = false;
}

//Deconstructor
Feeder::~Feeder()
{
}

void Feeder::initialize()
{
	//If the shooter is not on the switch.
	if(!ShooterSwitch_.Get()) {
		shoot();
	}
	
	return;
}

void Feeder::checkInputs()
{
	//If the trigger is pressed.
	if(ShootButton_.isActivated()) {
		
		//Shoot the launcher
		shoot();
	}
	
	return;
}

void Feeder::checkRealTimeInputs()
{
	//If shooting, return.
	if(!isShooting_) return;
	
	//Set switchState to the shooter switch.
	bool switchState = (bool)ShooterSwitch_.Get();
	
	//Check if the shooter is starting.
	if(isStarting_) {
		
		//Check if finished starting.
		if(switchState == false) {
			
			//The feeder is not in starting state.
			isStarting = false;
		}
		
		return;
	}
	
	//If the limit switch is pressed.
	if(switchState) {
		
		//Set isShooting to false and stop the motor.
		isShooting == false;
		FeederMotor_.Set(0.0);
	}
	
	return;
}

void Feeder::shoot()
{
	//If the shooter is ready to shoot.
	if(canShoot()) {
		FeederMotor_.Set(SHOOT_SPEED);
		isShooting_ = true;
	}
	
	//Set the starting flag to the limit switch.
	isStarting_ = ShooterSwitch_.Get();
	
	return;
}

bool Feeder::canShoot()
{
	//Check if the motor is shooting and that it is healthy.
	return !isShooting_;
}

bool Feeder::isHealthy()
{
	return true;
}
