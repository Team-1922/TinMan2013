//******************************************************************************
//
// File: ButtonActivated.cpp
//
// Description: This object will detect an 'activated' state for the specified 
//              joystick/button. A button is considered 'activated' when it
//              transitions from 'button not pressed' to 'button pressed'.
//
//******************************************************************************
#include "ButtonActivated.h"

//******************************************************************************
//******************************************************************************
/**
 * Constructor
 * 
 * @param joyStick Pointer to previously created Joystick object that will be 
 *                 monitored for button presses.
 * @param btnNum   Button number of joystick that will be monitored for activation.
 */
//******************************************************************************
ButtonActivated::ButtonActivated( Joystick* joyStick, int btnNum )
{
   joyStick_ = joyStick;
   btnNum_   = btnNum;

   lastButtonState_ = false;
}


//******************************************************************************
//******************************************************************************
/**
 * This method detects if the associated joystick button has been activated.
 * 
 * @return TRUE if the joystick button is activated, else FALSE
 */
//******************************************************************************
bool ButtonActivated::isActivated()
{
bool activated      = false;
bool newButtonState = false;

	//*** get current button state ***
	newButtonState = joyStick_->GetRawButton( btnNum_ );
	
	//*** check if button transitioned from not pressed to pressed ***
	activated = (lastButtonState_ == false) && (newButtonState == true);
	
	//*** save last button state ***		
	lastButtonState_ = newButtonState;
	
	//*** return activated state ***
	return activated;
}

