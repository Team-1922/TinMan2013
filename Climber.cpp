//******************************************************************************
//
// File: Climber.cpp
//
// Description: This is the definition file for the Climber class
//
//******************************************************************************

#include "Climber.h"
#include "RobotDefines.h"

const float brakePosition = 0.0;
const float openPosition = 1.0;


//******************************************************************************
//******************************************************************************
Climber::Climber( Joystick *actionStick ) :
   stick_( actionStick ),
   winchMotor_(PWM_CLIMBER_MOTOR),
   winchEnableBtn_( actionStick, BTN_J2_WINCH_ENABLE ),
   brakeBtn_( actionStick, BTN_J2_WINCH_BRAKE )
{

	winchBrake_ = new Servo( SOL_WINCH_BRAKE );
	lock = true;
}


//******************************************************************************
//******************************************************************************
void Climber::checkInputs()
{
	//If the enable button is pressed.
	if(winchEnableBtn_.isPressed() && !lock) {
		
		//Set the motor to the stick's value.
		winchMotor_.Set(stick_->GetY());
	} else {
		
		//Set the motor to 0 if we are not pressing it.
		winchMotor_.Set(0.0);
	}

	//Reverse the lock status when the brake button is activated.
	if(brakeBtn_.isActivated()) {
		lock = !lock;
	}
}


//******************************************************************************
//******************************************************************************
void Climber::checkRealTimeInputs()
{
	SmartDashboard::PutBoolean("Locked", lock);
	
	//If we are locking.
	if(lock) {
		//Set the servo to the lock position.
		winchBrake_->Set(brakePosition);
	} else {
		//Otherwise set it to the open position.
		winchBrake_->Set(openPosition);
	}
}
