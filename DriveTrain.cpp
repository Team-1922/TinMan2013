#include "DriveTrain.h"

//*****************************************************************

//Constructor
DriveTrain::DriveTrain( Joystick* joystick )
{
	//initialize motors
	rightDrive_ = new Jaguar(PWM_RIGHT_DRIVE_MOTOR);	
	leftDrive_  = new Jaguar(PWM_LEFT_DRIVE_MOTOR);
	
	//Joystick
	stick_ = joystick;
}

//************************************************************************

void DriveTrain::checkInputs()
{
	//Retrieve and modify the joystick value.
	float xAxis = modifyJoystick(stick_->GetX());
	float yAxis = -modifyJoystick(stick_->GetY());
	
	//Create arcade drive values
	float rightVal = -(yAxis - xAxis) / 2.0;
	float leftVal = (yAxis + xAxis) / 2.0;
	
	//Assigning values to motors
	leftDrive_->Set(leftVal);
	rightDrive_->Set(rightVal);
}


//************************************************************************
void DriveTrain::checkRealTimeInputs()
{
}


//************************************************************************

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

float DriveTrain::modifyJoystick(float axis)
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
