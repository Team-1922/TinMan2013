#include "DriveTrain.h"

//************************************************************************
//************************************************************************

//Constructor
DriveTrain::DriveTrain( Joystick* joystick ) :
	rightDrive_( PWM_RIGHT_DRIVE_MOTOR ),
	leftDrive_( PWM_LEFT_DRIVE_MOTOR ),
	drive_( &leftDrive_, &rightDrive_ ),
	aim_( joystick, BTN_J1_AIM ),
   gyro_( ANA_IN_GYRO )
{
	//Joystick
	stick_ = joystick;
	
   //*** need both motors inverted ***
	drive_.SetInvertedMotor(RobotDrive::kRearLeftMotor, true);
	drive_.SetInvertedMotor(RobotDrive::kRearRightMotor, true);
	
   driveCount_   = 0;
   driveAction_  = NO_ACTION;

	//Variables for input modifier.
	curveModifier = 2;
	startingPoint = 0.2;
	ignoreRange = 0.1;
}


//************************************************************************
//************************************************************************

void DriveTrain::checkInputs()
{
   //*** using 'aim' feature ***
	if(aim_.isPressed()) {
		drive_.ArcadeDrive( 0, stick_->GetX() );
	}

   //*** normal driving ***
	else {
		drive_.ArcadeDrive( stick_ );
	}
}


//************************************************************************
//************************************************************************
void DriveTrain::checkRealTimeInputs()
{
   //*** check driving straight ***
   if ( driveCount_ > 0 )
      {
      //*** decrement the count ***
      driveCount_--;

      //*** check if we're done ***
      if ( driveCount_ == 0 )
         {
         //*** stop the motors ***
         drive_.Drive( 0.0, 0.0 );

         //*** change the action ***
         driveAction_ = NO_ACTION;
         }
      }

   //*** check spinning ***
   if ( driveAction_ == SPIN_ACTION )
      {
      float curHdg = fabs( gyro_.GetAngle() );

      //*** check for end ***
      if ( curHdg > tgtHdg_ )
         {
         //*** stop the motors ***
         drive_.Drive( 0.0, 0.0 );

         //*** change the action ***
         driveAction_ = NO_ACTION;
         }
      }
}


//************************************************************************
//************************************************************************
bool DriveTrain::finishedAction()
{
   return ( driveAction_ == NO_ACTION );
}


//************************************************************************
//************************************************************************
void DriveTrain::driveStraight( float speed, int msec )
{
   //*** set the time to drive ***
   driveCount_ = msec;

   //*** set action ***
   driveAction_ = DRIVE_ACTION;

   //*** set the drive speed ***
   drive_.Drive( speed, 0.0 );
}


//************************************************************************
//************************************************************************
void DriveTrain::spin( TurnDir dir, float speed, int degrees )
{
   //*** reset the gyro ***
   gyro_.Reset();

   //*** set target heading ***
   tgtHdg_ = degrees;

   //*** set action ***
   driveAction_ = SPIN_ACTION;

   //*** start it spinning ***
   drive_.Drive( 0.0, (dir == TURN_RIGHT) ? speed : -speed );
}


//************************************************************************
//************************************************************************
float DriveTrain::modifyMagnitude(float axis)
{
	//Return 0 if the axis is between the ignore range.
	if(axis < ignoreRange && axis > -ignoreRange) {
		return 0.0;
	}
	
	axis *= (1.0 - startingPoint);
	
	//Check if the axis is positive or negative.
	if(axis > 0) {
		axis += startingPoint;
	}
	else {
		axis -= startingPoint;
	}
	
	//Return the modified value.
	return axis;
}
