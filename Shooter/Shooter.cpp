//******************************************************************************
//
// File: Shooter.h
//
// Description: This is the include file for the Shooter object
//
//******************************************************************************
#include "Shooter.h"

//******************************************************************************
//******************************************************************************
//Constructor 
Shooter::Shooter(Joystick* stick):
	thrower_(stick),
	feeder_(stick)
{
	stick_ = stick;
}


//******************************************************************************
//******************************************************************************
//Call the check inputs of the thrower and feeder.
void Shooter::checkInputs()
{
	thrower_.checkInputs();
	feeder_.checkInputs();
}


//******************************************************************************
//******************************************************************************
//Call the check real time inputs of the thrower and feeder.
void Shooter::checkRealTimeInputs()
{
	thrower_.checkRealTimeInputs();
	feeder_.checkRealTimeInputs();
}


//******************************************************************************
//******************************************************************************
//Shoot
void Shooter::shoot(bool state)
{
	feeder_.feed(state);
}


//******************************************************************************
//******************************************************************************
//Set the thrower to a specified speed.
void Shooter::setThrower(float speed)
{
	thrower_.setSpeed(speed);
}


//******************************************************************************
//******************************************************************************
bool Shooter::isShooting()
{
	return feeder_.isFeeding();
}
