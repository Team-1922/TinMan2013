//******************************************************************************
//
// File: Shooter.cpp
//
// Description: This is the Shooter object for the TinMan
//
//******************************************************************************
#ifndef SHOOTER_H
#define SHOOTER_H

#include "WPILib.h"
#include "RobotDefines.h"

#include "Feeder.h"
#include "Thrower.h"

class Shooter
{
private:
	//Task for the shooter.
	//Task shooterTask_;
	
	//Thrower and feeder objects.
	Thrower thrower_;
	Feeder feeder_;
	
	//Is the shooter shooting?
	bool isShooting_;
	
	//Shoot
	//static int _shoot();
	
	ReentrantSemaphore shooterLock_;
	
	//Pointers to the joysticks
	Joystick* driveJoystick_;
	Joystick* throwerJoystick_;
	
public:

	//Constructor and deconstructor.
	Shooter( Joystick* driveJoystick, Joystick* throwerJoystick );
	~Shooter();
	
	void initialize();
	
	void checkInputs();
	
	void checkRealTimeInputs();
	
	bool isShooting();
	
	bool shoot();
	
	int shooterRPM();
	
	bool isHealthy();
};

#endif
