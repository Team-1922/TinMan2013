//******************************************************************************
//
// File: TinMan.cpp
//
// Description: This is the main object for the Robot
//
//******************************************************************************
#include "TinMan.h"

//*** constants ***

#define REAL_TIME_DELAY (0.001)


//******************************************************************************
//******************************************************************************
/**
 * Constructor
 */ 
//******************************************************************************
TinMan::TinMan(void) :
   dsTask_(     "DsTask",     (FUNCPTR)dsTask     ),
   visionTask_( "VisionTask", (FUNCPTR)visionTask )
{

   //*** create joystick objects ***
   driveStick_   = new Joystick( PORT_DRIVER_JOYSTICK );
   throwerStick_ = new Joystick( PORT_THROWER_JOYSTICK );

   //*** create subsystem objects ***
   drive_   = new DriveTrain;
   shooter_ = new Shooter( driveStick_, throwerStick_ );
   climber_ = new Climber;


	//*** get pointer to driver station ***
	ds_ = DriverStation::GetInstance();
	
	//*** clear 'end ds thread' flag ***
	cancelDsThread_ = false;

   initialized_ = false;
	
}


//******************************************************************************
//******************************************************************************
/**
 * Destructor
 */ 
//******************************************************************************
TinMan::~TinMan(void)
{
	//*** set flag for threads to cancel ***
	cancelDsThread_     = true;
	cancelVisionThread_ = true;
	
}


//******************************************************************************
//******************************************************************************
/**
 * Initialize the robot 
 */
//******************************************************************************
void TinMan::initialize()
{
   //*** if already initialized, then get out ***
   if ( initialized_ ) return;

   //*** start the vision thread ***
   visionTask_.Start( (INT32)this );

   //*** initialize subsystems ***
   shooter_->initialize();
   climber_->initialize();

   //*** set initialized flag ***
   initialized_ = true;
}


//******************************************************************************
//******************************************************************************
/**
 * Runs the motors with arcade steering. 
 */
//******************************************************************************
void TinMan::OperatorControl(void)
{
   //*** initialize the robot (if not already done in autonomous) ***
   initialize();

	//*** start the driver station input thread ***
	dsTask_.Start( (INT32)this );
	
	//*** main while loop ***
	while ( IsOperatorControl() )
	{
      //*** Check all real-time inputs (limit switches, etc ***
      checkRealTimeInputs();

		//*** wait a short amount ***
		Wait( REAL_TIME_DELAY );
	}
}


//******************************************************************************
//******************************************************************************
/**
 * Check inputs for each subsystem 
 */
//******************************************************************************
void TinMan::checkInputs()
{
   //*** DriveTrain ***
   drive_->checkInputs();

   //*** Shooter ***
   shooter_->checkInputs();

   //*** Climber ***
   climber_->checkInputs();
}


//******************************************************************************
//******************************************************************************
/**
 * check real-time inputs for each subsystem 
 */
//******************************************************************************
void TinMan::checkRealTimeInputs()
{
   //*** DriveTrain ***
   drive_->checkRealTimeInputs();

   //*** Shooter ***
   shooter_->checkRealTimeInputs();

   //*** Climber ***
   climber_->checkRealTimeInputs();
}
	


//******************************************************************************
//******************************************************************************
/**
 * Driver Station Input thread 
 */
//******************************************************************************
void TinMan::dsTask( TinMan* tm )
{
   //*** get reference to driver station ***
   DriverStation& ds = *(DriverStation::GetInstance());
	
   //*** get reference to TinMan ***
   TinMan& tinMan = *tm;
	
   //*** do while in teleop and not cancelled ***
   do
      {
      //*** wait for input from the driver station ***
      ds.WaitForData();

      //*** check all driverstation inputs ***
      tinMan.checkInputs();
		
      } while( !tinMan.dsThreadCancel() && ds.IsOperatorControl() );
}


//************************************
//*** DO NOT REMOVE THE LAST LINE ****
//************************************
START_ROBOT_CLASS(TinMan);

