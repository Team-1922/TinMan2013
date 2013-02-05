//******************************************************************************
//
// File: ButtonActivated.h
//
// Description: Include file for ButtonActivated object
//
//******************************************************************************
#ifndef ButtonActivated_h
#define ButtonActivated_h


#include "WPILib.h"

//******************************************************************************
//******************************************************************************
class ButtonActivated
{
public:

   //*** constructor ***
   ButtonActivated( Joystick* joyStick, int btnNum );

   //*** returns activated state ***
   bool isActivated();

   //*** return pressed state ***
   bool isPressed();


protected:

   Joystick *joyStick_;          // joystick to check

   int       btnNum_;            // button on joystick

   bool      lastButtonState_;   // save last button state

};



#endif 
