#include "TinMan.h"

//TinMan constructor
TinMan::TinMan():wheels(1,2), stick(1)
{
	dash->init();
	wheels.SetExpiration(0.1);
}

//Run the autonomous
void TinMan::Autonomous()
{
	wheels.SetSafetyEnabled(false);
}

//Run teleop mode.
void TinMan::OperatorControl()
{
	wheels.SetSafetyEnabled(true);
	
	//While teleop is running.
	while (IsOperatorControl())
	{
		wheels.ArcadeDrive(&stick);
		Wait(0.005);
	} 
}

void TinMan::Test()
{
}

START_ROBOT_CLASS(TinMan);
