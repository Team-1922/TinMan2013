#include "DriveTrain.h"

//************************************************************************
//************************************************************************

//Constructor
DriveTrain::DriveTrain( Joystick* joystick ) :
	rightDrive_( PWM_RIGHT_DRIVE_MOTOR ),
	leftDrive_( PWM_LEFT_DRIVE_MOTOR ),
	drive_( &leftDrive_, &rightDrive_ ),
	aim_( joystick, BTN_J1_AIM ),
	forward_(joystick, BTN_J1_FWD),
	backward_(joystick, BTN_J1_BACK),
	left_(joystick, BTN_J1_LEFT),
	right_(joystick, BTN_J1_RIGHT),
	gyro_( ANA_IN_GYRO )
{
	//Joystick
	stick_ = joystick;
	
	//*** need both motors inverted ***
	drive_.SetInvertedMotor(RobotDrive::kRearLeftMotor, true);
	drive_.SetInvertedMotor(RobotDrive::kRearRightMotor, true);
	
	//Set the magnitude and turning to 0 as default.
	magnitude_ = 0.0;
	turning_ = 0.0;
	
	driveCount_   = 0;
	driveAction_  = NO_ACTION;
}


//************************************************************************
//************************************************************************

void DriveTrain::checkInputs()
{
	//Make magnitude 0.0 if the driver is aiming.
	if(aim_.isPressed()) {
		magnitude_ = 0.0;
	}
	else {
		magnitude_ = stick_->GetY();
	}
	
	//Spin the robot to the direction you wish to go.
	if(forward_.isPressed()) {
		spin(0);
	}
	else if(backward_.isPressed()) {
		spin(180);
	}
	else if(left_.isPressed()) {
		spin(270);
	}
	else if(right_.isPressed()) {
		spin(90);
	}
	else {
		//Otherwise simply set the joystick value to the turning.
		turning_ = stick_->GetX();
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

   //Square and negate the turning if it is negative.
   if(turning_ < 0) {
	   turning_ *= -turning_;
   } else {
	   turning_ *= turning_;
   }
   
   drive_.ArcadeDrive(magnitude_, turning_);
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
void DriveTrain::spin( int target )
{
	//Get the gyro and coerce the angle.
	int gyro = getGyro();
	target = coerceAngle(target);
	
	//Get the difference between the target and gyro.
	int difference = target - gyro;
	
	//If the difference is greater than 180.
	if(difference > 180) {
		//Subtract 360.
		difference -= 360;
	}
	//If the difference is less than -180.
	else if(difference < -180) {
		//Add 360.
		difference += 360;
	}
	
	//Set the turning value between +-0.0 and +-1.0 
	turning_ = difference / 180.0;
}

int DriveTrain::getGyro()
{
	//Get the angle of the robot.
	return coerceAngle(gyro_.GetAngle());
}

int DriveTrain::coerceAngle(float angle)
{
	//Set the angle to positive.
	while(angle < 0)
	{
		angle += 360;
	}
	
	//Return the angle between 0-359.
	return (int)angle % 360;
}
