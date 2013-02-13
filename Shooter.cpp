#include "Shooter.h"

Shooter::Shooter(Joystick* driveJoystick, Joystick* throwerJoystick):
	//shooterTask_("SHOOTER_SHOOT", (FUNCPTR)_shoot),
	thrower_(throwerJoystick),
	feeder_(throwerJoystick)
{
	driveJoystick_ = driveJoystick;
	throwerJoystick_ = throwerJoystick;
}

void Shooter::initialize()
{
	// TODO: Implementation
	feeder_.initialize();
}

void Shooter::checkInputs()
{
	// TODO: Implementation
	feeder_.checkInputs();
	thrower_.checkInputs();
}

void Shooter::checkRealTimeInputs()
{
	// TODO: Implementation
	feeder_.checkRealTimeInputs();
	thrower_.checkRealTimeInputs();
}

bool Shooter::isShooting()
{
	/* I'm not sure if this creates race conditions since it's
	 * possible (though extremely unlikely) that this could run
	 * at between locking the mutex and setting isShooting to true
	 * in the shooter task */
	return isShooting_;
}

bool Shooter::shoot()
{
	//feeder_.shoot();
	return true;
	//return shooterTask_.Start();
}

int Shooter::shooterRPM()
{
	// TODO: Implementation
	return 0;
}

bool Shooter::isHealthy()
{
	// TODO: Implementation
	return true;
}

/*int Shooter::_shoot()
{
	// TODO: Finish implementation
	// Lock the mutex within this scope
	Synchronized syncLock = Synchronized(shooterLock_);
	isShooting_ = true;
	
	isShooting_ = false;
	//feeder_.shoot();
	return 0;
}*/
