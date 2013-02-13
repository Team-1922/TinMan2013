#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include "WPILib.h"
#include "Math.h"
#include "RobotDefines.h"


//***********************************************************

class DriveTrain
{
public:
	//constructor
	DriveTrain( Joystick* joystick );
	~DriveTrain();
	
	void checkInputs();
	void checkRealTimeInputs();
	void autoDrive();

	//Autonomous / functions
	
	void driveStraight( int inches );
	void spin( int degrees );
	void turn( int inches, int degrees );

	
protected:
	// Motors
	Jaguar* rightDrive_;
	Jaguar* leftDrive_;
	
	//Joystick
	Joystick *stick_;
	
	//Variables for input modifier.
	int curveModifier;
	float startingPoint;
	float ignoreRange;
	
	//Modify the joystick value.
	float modifyJoystick(float);
};
#endif

