#ifndef FEEDER_H
#define FEEDER_H

#include "WPILib.h"
#include "ButtonActivated.h"

#include "RobotDefines.h"

const float SHOOT_SPEED = 0.5;

//Class declaration for the feeder.
class Feeder
{
public:
	//Constructor and deconstructor
	Feeder(Joystick*);
	~Feeder();
	
	void initialize();
	
	//Check for inputs
	void checkInputs();
	void checkRealTimeInputs();
	
private:
	//Motor that controls the feeder.
	Jaguar FeederMotor_;
	
	//Button to make feeder shoot.
	ButtonActivated ShootButton_;
	
	//Limit switch to check if shooting.
	DigitalInput ShooterSwitch_;
	
	//Boolean to store shooting state.
	bool isShooting_;
	bool isStarting_;
	
	//Shoot the feeder.
	void shoot();
	
	//Check if the feeder can shoot.
	bool canShoot();
	bool isHealthy();
};

#endif
