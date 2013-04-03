//******************************************************************************
//
// File: Climber.h
//
// Description: This is the include file for the Climber class
//
//******************************************************************************
#ifndef Climber_h
#define Climber_h

#include "TinMan.h"
#include "input/ButtonActivated.h"

//******************************************************************************
//******************************************************************************
class Climber
{

public:

   Climber( Joystick* joystick );

   void checkInputs();

   void checkRealTimeInputs();

protected:
   Joystick       *stick_;
   
   Jaguar          winchMotor_;

   ButtonActivated winchEnableBtn_;
   ButtonActivated brakeBtn_;
   

   Servo	       *winchBrake_;
   
   bool lock;
};

#endif
