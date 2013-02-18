#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include "WPILib.h"
#include "Math.h"
#include "../Input/ButtonActivated.h"
#include "../RobotDefines.h"

typedef enum { TURN_RIGHT, TURN_LEFT } TurnDir;

typedef enum { NO_ACTION, DRIVE_ACTION, SPIN_ACTION } DriveAction;

//***********************************************************

class DriveTrain
{
public:
	//constructor
	DriveTrain( Joystick* joystick );
	~DriveTrain();
	
	void checkInputs();
	void checkRealTimeInputs();

	//Autonomous / functions
	
	void driveStraight( float speed, int msec );
	void spin( TurnDir dir, float speed, int degrees );

   //*** returns true if driveStraight or spin has completed ***
   bool finishedAction();

	
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

   int driveCount_;
   DriveAction driveAction_;
   
   float tgtHdg_;

   Gyro  gyro_;


};
#endif

