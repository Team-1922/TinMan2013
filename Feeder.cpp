#include "Feeder.h"


//Constructor calls the FeederMotor, FeedButton, and FeedSwitch constructors.
Feeder::Feeder(Joystick *stick):
	FeedMotor_(PWM_FEEDER_MOTOR),
	FeedButton_(stick, BTN_J1_SHOOT),
	FeedSwitch_(DIG_IN_FEED_LEVER_FWD)
{
	//Set feeding and starting states to false.
	isFeeding_ = false;
	isStarting_ = false;
}

//Deconstructor
Feeder::~Feeder()
{
}

void Feeder::initialize()
{
	//Create a variable that holds the feederSwitch
	bool switchState = !(bool)FeedSwitch_.Get();

	//If the feeder is not on the switch.
	if(!switchState) {
		feed();
	}
	
	return;
}

void Feeder::checkInputs()
{
	//If the trigger is pressed.
	if(FeedButton_.isActivated()) {
		
		//Feed the launcher
		feed();
	}
	
	return;
}

void Feeder::checkRealTimeInputs()
{
	//TODO: Set Jaguar to stop in here.
	
	//If feeding, return.
	if(!isFeeding_) return;
	
	//Set switchState to the feeder switch.
	bool switchState = !(bool)FeedSwitch_.Get();
	
	//Check if the feeder is starting.
	if(isStarting_) {
		
		//Check if finished starting.
		if(switchState == false) {
			
			//The feeder is not in starting state.
			isStarting_ = false;
		}
		return;
	}
	
	//If the limit switch is pressed.
	if(switchState) {
		
		//Set isfeeding to false and stop the motor.
		isFeeding_ = false;
		
		FeedMotor_.Set(0.0);
	}
	
	return;
}

void Feeder::feed()
{
	//TODO: Set jaguar to start in here.
	
	//If the feeder is ready to feed.
	if(canFeed()) {
		
		//Set isFeeding to true and start the motor.
		isFeeding_ = true;
		FeedMotor_.Set(FEED_SPEED);
	}
	
	//Set the starting flag to the limit switch.
	isStarting_ = FeedSwitch_.Get();
	
	return;
}

bool Feeder::canFeed()
{
	//Check if the motor is feeding and that it is healthy.
	return !isFeeding_;
}
