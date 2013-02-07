#include "Shooter.h"

Shooter::Shooter(Joystick* driveJoystick, Joystick* throwerJoystick)
{
	driveJoystick_ = driveJoystick;
	throwerJoystick_ = throwerJoystick;
	/* I don't know if throwerJoystick_ is the correct joystick
	 * to pass to these. Whoever wrote Thrower and Feeder needs
	 * to be more clear, even if it seems obvious what stick it is */
	thrower_ = new Thrower(throwerJoystick_);
	feeder_ = new Feeder(throwerJoystick_);
	shooterTask_ = new Task((FUNCPTR)_shoot, "SHOOTER_SHOOT");
}

void Shooter::initialize()
{
	// TODO: Implementation
}

void Shooter::checkInputs()
{
	// TODO: Implementation
}

void Shooter::checkRealTimeInputs()
{
	// TODO: Implementation
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
	return shooterTask_->Start();
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

int Shooter::_shoot()
{
	// TODO: Finish implementation
	// Lock the mutex within this scope
	Synchronized syncLock = Synchronized(shooterLock_);
	isShooting_ = true;
	
	isShooting_ = false;
	return 0;
}
