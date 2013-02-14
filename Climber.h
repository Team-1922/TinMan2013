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
#include "ButtonActivated.h"

typedef enum { WINCH_STOPPED, WINCH_OUT, WINCH_IN } WinchAction;


//******************************************************************************
//******************************************************************************
class Climber
{

public:

   Climber( Joystick* joystick );

   void initialize();

   void checkInputs();

   void checkRealTimeInputs();

protected:

   bool farLimitReached();
   bool nearLimitReached();

   void winchOut();
   void winchIn();
   void stopWinch();


   Joystick *stick_;

   Jaguar motor1_;
   Jaguar motor2_;

   Relay  brake_;

   DigitalInput farLimit_;
   DigitalInput nearLimit_;

   AnalogChannel  armPot_;

   WinchAction  winchAction_;

   ButtonActivated winchOutBtn_;
   ButtonActivated winchInBtn_;
   ButtonActivated brakeBtn_;

   static SEM_ID motorSem_;

};

#endif
