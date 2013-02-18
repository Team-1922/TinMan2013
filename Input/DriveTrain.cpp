#include "DriveTrain.h"

//*****************************************************************

//Constructor
DriveTrain::DriveTrain( Joystick* joystick ):
	rightDrive_(PWM_RIGHT_DRIVE_MOTOR),
	leftDrive_(PWM_LEFT_DRIVE_MOTOR),
	drive_(&leftDrive_, &rightDrive_),
	aim_(joystick, BTN_AIM)
{
	//Joystick
	stick_ = joystick;
	
	drive_.SetInvertedMotor(RobotDrive::kRearLeftMotor, true);
	drive_.SetInvertedMotor(RobotDrive::kRearRightMotor, true);
	
	//Variables for input modifier.
	curveModifier = 2;
	startingPoint = 0.2;
	ignoreRange = 0.1;
}

//************************************************************************

void DriveTrain::checkInputs()
{
	if(aim_.isPressed()) {
		drive_.ArcadeDrive(0, stick_->GetX());
	}
	else {
		drive_.ArcadeDrive(stick_);
	}
}


//************************************************************************
void DriveTrain::checkRealTimeInputs()
{
}


//***********************************************************************

void DriveTrain::autoDrive()
{
}
//************************************************************************

void DriveTrain::driveStraight(int inches)
{
}
//************************************************************************

void DriveTrain::spin(int degrees)
{
}

//************************************************************************

void DriveTrain::turn(int inches, int degrees)
{
}

float DriveTrain::modifyMagnitude(float axis)
{
	//Return 0 if the axis is between the ignore range.
	if(axis < ignoreRange && axis > -ignoreRange) {
		return 0.0;
	}
	
	//Create a variable to hold the modified input.
	float modified = 0;
	
	//Check if the axis is positive or negative.
	if(axis > 0) {
		modified = powf(axis, curveModifier);
		modified /= startingPoint;
		modified += (1.0 - (1.0 / startingPoint));
	}
	else if(axis < 0) {
		if(curveModifier % 2 == 0) {
			modified = -powf(axis, curveModifier);
			modified /= startingPoint;
			modified -= (1.0 - (1.0 / startingPoint));
		}
	}
	
	//Return the modified value.
	return modified;
}
