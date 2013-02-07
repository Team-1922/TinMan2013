#include "DriveTrain.h"

//*****************************************************************

//Constructor
DriveTrain::DriveTrain(void)
{
	
	//initialize motors
	
	rightDrive = new Talon(PWM_RIGHT_DRIVE_MOTOR);	
	leftDrive = new Talon(PWM_LEFT_DRIVE_MOTOR);
	bothDrive = rightDrive, leftDrive;
	
	//Joystick
	stick = new Joystick(PORT_DRIVER_JOYSTICK);
	
	//Encoders
	leftEncode = new Encoder(1,2);
	rightEncode = new Encoder(1,2);

}

//************************************************************************

void DriveTrain::opDrive()
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
					
					
Wait(0.005);
		
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


