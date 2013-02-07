
#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include "WPILib.h"
#include "RobotDefines.h"


//***********************************************************

class DriveTrain

{


public:
	
	
	//constructor
	 DriveTrain(void);
	
	void opDrive();
	void autoDrive();

	
protected:
	
	//Variables
	
	// Motors
	Talon* rightDrive;
	Talon* leftDrive;
	Talon* bothDrive; //sets values for both motors at same time
	
	//Joystick
	Joystick *stick;

	//encoder
	Encoder* leftEncode;
	Encoder* rightEncode;
	
	//Autonomous / functions
	
	void driveStraight_(int inches);
	void Spin_(int degrees);
	void Turn_(int inches, int degrees);




};
#endif

