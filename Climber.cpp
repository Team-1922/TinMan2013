//******************************************************************************
//
// File: Climber.cpp
//
// Description: This is the definition file for the Climber class
//
//******************************************************************************

#include "Climber.h"
#include "RobotDefines.h"


const float WinchStoppedSpeed =  0.0;
const float WinchOutSpeed     =  1.0;
const float WinchInSpeed      = -1.0;


//******************************************************************************
//******************************************************************************
Climber::Climber( Joystick *actionStick ) :
   stick_( actionStick ),
   motor1_( PWM_CLIMBER_MOTOR1 ),
   motor2_( PWM_CLIMBER_MOTOR2 ),
   brake_( RELAY_CLIMBER_BRAKE ),
   farLimit_( DIG_IN_FAR_LIMIT ),
   nearLimit_( DIG_IN_NEAR_LIMIT ),
   armPot_( ANA_IN_ARM ),
   winchAction_( WINCH_STOPPED ),
   winchOutBtn_( actionStick, BTN_J2_WINCH_OUT ),
   winchInBtn_( actionStick, BTN_J2_WINCH_IN ),
   brakeBtn_( actionStick, BTN_J2_BRAKE )
{
}


//******************************************************************************
//******************************************************************************
void Climber::initialize()
{
   //*** make sure we are pulled in ***
   if ( !nearLimitReached() )
      {
      //*** exclusive access ***
      Synchronized sync( motorSem_ );

      //*** start it moving in ***
      winchIn();
      }
}


//******************************************************************************
//******************************************************************************
void Climber::checkInputs()
{
   //*** exclusive access ***
   Synchronized sync( motorSem_ );

   //*** winch out ***
   if ( winchOutBtn_.isPressed() && !farLimitReached() )
      {
      winchOut();
      }

   //*** winch in ***
   else if ( winchInBtn_.isPressed() && !nearLimitReached() )
      {
      winchIn();
      }

   //*** stop winch ***
   else if ( winchAction_ != WINCH_STOPPED )
      {
      stopWinch();
      }

   //*** brake ***
   brake_.Set( brakeBtn_.isPressed() ? Relay::kOn : Relay::kOff );

}


//******************************************************************************
//******************************************************************************
void Climber::checkRealTimeInputs()
{
   //*** if motor not running, don't bother ***
   if ( winchAction_ == WINCH_STOPPED ) return;

   //*** exclusive access ***
   Synchronized sync( motorSem_ );

   //*** check if we reached a limit ***
   if ( ((winchAction_ == WINCH_OUT) && farLimitReached()  ) ||
        ((winchAction_ == WINCH_IN ) && nearLimitReached() ) )
      {
      stopWinch();
      }
}


//******************************************************************************
//******************************************************************************
void Climber::winchOut()
{
   //*** set motor speed ***
   motor1_.Set( WinchOutSpeed );
   motor2_.Set( WinchOutSpeed );

   //*** set current action ***
   winchAction_ = WINCH_OUT;
}


//******************************************************************************
//******************************************************************************
void Climber::winchIn()
{
   //*** set motor speed ***
   motor1_.Set( WinchInSpeed );
   motor2_.Set( WinchInSpeed );

   //*** set current action ***
   winchAction_ = WINCH_IN;
}


//******************************************************************************
//******************************************************************************
void Climber::stopWinch()
{
   //*** set motor speed ***
   motor1_.Set( WinchStoppedSpeed );
   motor2_.Set( WinchStoppedSpeed );

   //*** set current action ***
   winchAction_ = WINCH_STOPPED;
}


//******************************************************************************
//******************************************************************************
bool Climber::farLimitReached()
{
   return (bool)farLimit_.Get();
}


//******************************************************************************
//******************************************************************************
bool Climber::nearLimitReached()
{
   return (bool)nearLimit_.Get();
}
