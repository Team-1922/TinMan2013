//******************************************************************************
//
// File: Shooter.cpp
//
// Description: This is the Shooter object for the TinMan
//
//******************************************************************************
#include "Feeder.h"
#include "Thrower.h"
#include "TinMan.h"

class Shooter
{
	Thrower* thrower_;
	Feeder* feeder_;
	Task* shooterTask_;
	bool isShooting_;
	int _shoot();
	ReentrantSemaphore shooterLock_;
	Joystick* driveJoystick_;
	Joystick* throwerJoystick_;
public:

   Shooter( Joystick* driveJoystick, Joystick* throwerJoystick );

   void initialize();

   void checkInputs();

   void checkRealTimeInputs();
   
   bool isShooting();
   
   bool shoot();
   
   int shooterRPM();
   
   bool isHealthy();
};

