#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include "WPILib.h"
#include "Math.h"
#include "../Input/ButtonActivated.h"
#include "../RobotDefines.h"

#define BTN_AIM (8)

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
	Jaguar rightDrive_;
	Jaguar leftDrive_;
	
	//Robot Drive
	RobotDrive drive_;
	
	//Button for aiming.
	ButtonActivated aim_;

	//Joystick
	Joystick *stick_;
	
	//Variables for input modifier.
	int curveModifier;
	float startingPoint;
	float ignoreRange;
	
	//Modify the joystick value.
	float modifyMagnitude(float);
};
#endif

