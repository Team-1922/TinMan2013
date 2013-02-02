#include "ButtonActivated.h"

//******************************************************************************
//******************************************************************************
ButtonActivated::ButtonActivated( Joystick* joyStick, int btnNum )
{
   joyStick_ = joyStick;
   btnNum_   = btnNum;

   lastButtonState_ = false;
}


//******************************************************************************
//******************************************************************************
bool ButtonActivated::isActivated()
{
bool activated      = false;
bool newButtonState = false;

	//*** get button state ***
	newButtonState = joyStick_->GetRawButton( btnNum_ );
	
	//*** check if button transitioned from not pressed to pressed ***
	activated = (lastButtonState_ == false) && (newButtonState == true);
	
	//*** save last button state ***		
	lastButtonState_ = newButtonState;
	
	//*** return activated state ***
	return activated;
}

