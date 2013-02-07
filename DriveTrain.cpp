#include "DriveTrain.h"

//*****************************************************************

//Constructor
DriveTrain::DriveTrain( Joystick* joystick )
{
	
	//initialize motors
	
	rightDrive = new Jaguar(PWM_RIGHT_DRIVE_MOTOR);	
	leftDrive  = new jaguar(PWM_LEFT_DRIVE_MOTOR);
//???	bothDrive = rightDrive, leftDrive;
	
	//Joystick
	stick = joystick;
	
	//Encoders
	leftEncode = new Encoder(1,2);
	rightEncode = new Encoder(1,2);

}

//************************************************************************

void DriveTrain::checkInputs()
{
	//Get the x and y axis and assign them
	float xAxis =  stick->GetX();
	float yAxis = stick->GetY();			
			
	//Create arcade drive values
	float leftVal = (xAxis + yAxis)/ 2;
	float rightVal = (xAxis - yAxis) / 2;
			
			
	//Assigning values to motors
	leftDrive->Set(leftVal);
	rightDrive->Set(rightVal);
}

//************************************************************************

void DriveTrain::autoDrive()
{
	// the autonomous routine will go here.

	rightEncode->Get();
	leftEncode->Get();







}
//************************************************************************

void DriveTrain::driveStraight_(int inches)
{	

	
	
	
	
	
	

}

//************************************************************************

void DriveTrain::Spin_(int degrees)
{
	



}

//************************************************************************

void DriveTrain::Turn_(int inches, int degrees)
{
	


}


