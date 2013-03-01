#ifndef TinMan_h
#define TinMan_h

#include "WPILib.h"
#include "RobotDefines.h"

class DriveTrain;
class Shooter;
//class Climber;



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
	bool rtThreadCancel() { return cancelRtThread_; };
	
protected:
	
	//*** SUBSYSTEMS ***
	DriveTrain		*drive_;				   // robot drive subsystem
	Shooter			*shooter_;				// frisbee shooter subsystem
	//Climber     	*climber_;				// Climber subsystem
	
	//*** INPUT ***
	Joystick	    *driveStick_;			// Drive joystick
	Joystick    	*throwerStick_;			// Thrower control joystick
      
    //*** MISC VARIABLES ***
    Task        	dsTask_;				// Driverstation task
    Task        	rtTask_;			    // Real Time input task
	bool      		cancelDsThread_;		// flag to cancel ds thread
	bool        	cancelRtThread_;	    // flag to cancel rt thread
    bool        	initialized_;			// initialized flag
	
    void initialize();
	
	//*** THREADS ***
	
	//*** DriverStation thread ***
	static void dsTask( TinMan* p );
	
	//*** RealTime update thread ***                             
	static void rtTask( TinMan *p );
	
	//*** for autonomous ***
	bool waitTillFinished( DriveTrain* dt );
};

#endif
