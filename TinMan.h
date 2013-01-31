#include "WPILib.h"

//Class declaration for TinMan
class TinMan : public SimpleRobot
{
private:
	RobotDrive	wheels;
	Joystick	stick;

public:
	TinMan(void);
	void Autonomous(void);
	void OperatorControl(void);
	void Test();
};
