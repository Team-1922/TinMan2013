#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include "WPILib.h"
#include "RobotDefines.h"


//***********************************************************

class DriveTrain

{


public:
	
	
	//constructor
	 DriveTrain( Joystick* joystick );
	
	void checkInputs();
	void autoDrive();

	//Autonomous / functions
	
	void driveStraight( int inches );
	void spin( int degrees );
	void turn( int inches, int degrees );

	
protected:
	
	//Variables
	
	// Motors
	Jaguar* rightDrive_;
	Jaguar* leftDrive_;
//	Talon* bothDrive; //sets values for both motors at same time
	
	//Joystick
	Joystick *stick_;

	//encoder
	Encoder* leftEncode_;
	Encoder* rightEncode_;

};
#endif

