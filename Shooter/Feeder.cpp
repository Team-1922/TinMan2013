#include "Feeder.h"


//Constructor calls the FeederMotor, FeedButton, and FeedSwitch constructors.
Feeder::Feeder(Joystick *stick):
	feederMotor_(RELAY_FEEDER_MOTOR),
	feederButton_(stick, BTN_J1_SHOOT),
	feederSwitch_(DIG_IN_FEED_LEVER_FWD)
{
	//Default state of the feeder is stopped.
	isStarting_ = false;
	isFeeding_  = false;
}

//Check if the feed button is pressed and shoot.
void Feeder::checkInputs()
{
	//Call shoot when the button is pressed.
	if(feederButton_.isPressed()) {
		feed();
	}
	
	return;
}

void Feeder::checkRealTimeInputs()
{
	//If feeding, return.
	if(!isFeeding_) return;
	
	//Set switchState to the feeder switch.
	bool switchState = !(bool)feederSwitch_.Get();
	
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
		
		feederMotor_.Set(0.0);
	}

	return;
}

//Feed the frisbee to the thrower.
void Feeder::feed()
{
	//If the feeder is ready to feed.
	if(!isFeeding_) {
		
		//Set isFeeding to true and start the motor.
		isFeeding_ = true;
		feederMotor_.Set(1.0);
	}
	
	//Set the starting flag to the limit switch.
	isStarting_ = feederSwitch_.Get();
	
	return;
}

bool Feeder::isFeeding()
{
	return isFeeding_;
}
