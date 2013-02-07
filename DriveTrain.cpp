#include "DriveTrain.h"

//*****************************************************************

//Constructor
DriveTrain::DriveTrain( Joystick* joystick )
{
	
	//initialize motors
	
	rightDrive_ = new Jaguar(PWM_RIGHT_DRIVE_MOTOR);	
	leftDrive_  = new jaguar(PWM_LEFT_DRIVE_MOTOR);
//???	bothDrive = rightDrive, leftDrive;
	
	//Joystick
	stick_ = joystick;
	
	//Encoders
	leftEncode_ = new Encoder(1,2);
	rightEncode_ = new Encoder(1,2);

}

//************************************************************************

void DriveTrain::checkInputs()
{
	//Get the x and y axis and assign them
	float xAxis =  stick_->GetX();
	float yAxis = stick_->GetY();			
			
	//Create arcade drive values
	float leftVal = (xAxis + yAxis)/ 2;
	float rightVal = (xAxis - yAxis) / 2;
			
			
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
	// the autonomous routine will go here.

	rightEncode_->Get();
	leftEncode_->Get();







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


