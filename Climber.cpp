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

const float joystickThreashold = 0.01;


//******************************************************************************
//******************************************************************************
Climber::Climber( Joystick *actionStick ) :
   stick_( actionStick ),
   winchMotor_( PWM_CLIMBER_MOTOR ),
   armBrake_( SOL_ARM_BRAKE ),
   winchBrake_( SOL_WINCH_BRAKE ),
   farLimit_( DIG_IN_FAR_LIMIT ),
   nearLimit_( DIG_IN_NEAR_LIMIT ),
   winchAction_( WINCH_STOPPED ),
   winchEnableBtn_( actionStick, BTN_J2_WINCH_ENABLE ),
   brakeBtn_( actionStick, BTN_J2_WINCH_BRAKE )
{
}


//******************************************************************************
//******************************************************************************
void Climber::initialize()
{
}


//******************************************************************************
//******************************************************************************
void Climber::checkInputs()
{
   float speed   = WinchStoppedSpeed;
   bool  enabled = winchEnableBtn_.isPressed();

   //*** arm brake ***
   armBrake_.Set( brakeBtn_.isPressed() ? Relay::kOn : Relay::kOff );

   //*** if enabled button is pressed and winch solenoid not activated, ***
   //***   activate the solenoid ***
   if ( enabled && !winchBrake_.Get() )
      {
      //*** activate the solenoid ***
      winchBrake_.Set( true );

      //*** should give it some time ***
      return;
      }

   //*** read the joystick ***
   float yAxis = stick_->GetY();

   //*** assume we're stopped ***
   winchAction_ = WINCH_STOPPED;

   //*** winch out ***
   if ( enabled && (yAxis > joystickThreashold) )
      {
      //*** set intended action ***
      winchAction_ = WINCH_OUT;

      //*** check limit switch ***
      if ( !farLimitReached() )
         {
         speed = yAxis;
         }
      }

   //*** winch in ***
   else if ( enabled && (yAxis < -joystickThreashold) )
      {
      //*** set intended action ***
      winchAction_ = WINCH_IN;

      //*** check limit switch ***
      if ( !nearLimitReached() )
         {
         speed = yAxis;
         }
      }

   //*** exclusive access ***
   Synchronized sync( motorSem_ );

   //*** set the speed ***
   winchMotor_.Set( speed );
}


//******************************************************************************
//******************************************************************************
void Climber::checkRealTimeInputs()
{
   //*** if motor not running, don't bother ***
   if ( winchAction_ == WINCH_STOPPED ) return;

   //*** check if we reached a limit ***
   if ( ((winchAction_ == WINCH_OUT) && farLimitReached()  ) ||
        ((winchAction_ == WINCH_IN ) && nearLimitReached() ) )
      {
      //*** exclusive access ***
      Synchronized sync( motorSem_ );

      //*** stop the winch motor ***
      winchMotor_.Set( WinchStoppedSpeed );

      //*** set action state ***
      winchAction_ = WINCH_STOPPED;
      }
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
