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
#include "../RobotDefines.h"

#include "Feeder.h"
#include "Thrower.h"

class Shooter
{
public:
	//Constructor and deconstructor.
	Shooter( Joystick* );
	
	//Main functions to control shooter.
	void checkInputs();
	void checkRealTimeInputs();

	//Functions to shoot and start the thrower.
	void shoot(bool);
	void setThrower(float);
	
	bool isShooting();

private:
	
	//Thrower and feeder objects.
	Thrower thrower_;
	Feeder feeder_;
	
	//Pointers to the joysticks
	Joystick* stick_;
};

#endif
