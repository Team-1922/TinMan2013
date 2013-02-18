#ifndef TinMan_h
#define TinMan_h

#include "WPILib.h"
#include "RobotDefines.h"

#include "Input/DriveTrain.h"
#include "Shooter/Shooter.h"
//#include "Climber.h"


//******************************************************************************
//******************************************************************************
class TinMan : public SimpleRobot
{
public:
	
	//*** constructor ***
	TinMan(void);
	
	//*** destructor ***
	virtual ~TinMan(void);

	//*** autonomous mode code ***
	void Autonomous(void);

	//*** teleop code ***
	void OperatorControl(void);
	
	//*** test mode ***
	void Test(void);

	//*** check inputs for each subsystem ***
	void checkInputs();
	
	//*** check real-time inputs for each subsystem ***
	void checkRealTimeInputs();
	
	//*** indicates DS thread should be cancelled ***
	bool dsThreadCancel() { return cancelDsThread_; };

	//*** indicates DS thread should be cancelled ***
	bool visionThreadCancel() { return cancelVisionThread_; };
	
protected:
	
	//*** SUBSYSTEMS ***
	DriveTrain		*drive_;				// robot drive subsystem
	Shooter			*shooter_;				// frisbee shooter subsystem
	//Climber     	*climber_;				// Climber subsystem
	
	//*** INPUT ***
	Joystick	    *driveStick_;			// Drive joystick
	Joystick    	*throwerStick_;			// Thrower control joystick
      
    //*** MISC VARIABLES ***
    Task        	dsTask_;				// Driverstation task
    Task        	visionTask_;			// Vision task
    DriverStation 	*ds_;					// Driverstation pointer
	bool      		cancelDsThread_;		// flag to cancel ds thread
	bool        	cancelVisionThread_;	// flag to cancel vision thread
    bool        	initialized_;			// initialized flag
	
    void initialize();
	
	//*** THREADS ***
	
	//*** DriverStation thread ***
	static void dsTask( TinMan* p );
	
	//*** Vision thread ***                             
	static void visionTask( TinMan *p );
};

#endif
