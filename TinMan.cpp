//******************************************************************************
//
// File: TinMan.cpp
//
// Description: This is the main object for the Robot
//
//******************************************************************************
#include "TinMan.h"

#include "Input/DriveTrain.h"
//#include "Climber.h"
#include "Shooter/Shooter.h"

//*** constants ***

#define MAIN_LOOP_DELAY (0.1)
#define REAL_TIME_DELAY (0.001)


//******************************************************************************
//******************************************************************************
/**
 * Constructor
 */ 
//******************************************************************************
TinMan::TinMan(void) :
	dsTask_( "DsTask",       (FUNCPTR)dsTask       ),
	rtTask_( "RealTimeTask", (FUNCPTR)rtTask )
{
	//*** create joystick objects ***
	driveStick_   = new Joystick( PORT_DRIVER_JOYSTICK  );
	throwerStick_ = new Joystick( PORT_THROWER_JOYSTICK );

	//*** create subsystem objects ***
	drive_   = new DriveTrain( driveStick_ );
   
	shooter_ = new Shooter( throwerStick_ );

    //climber_ = new Climber( throwerStick_ );


	//*** get pointer to driver station ***
//	ds_ = DriverStation::GetInstance();
	
	//*** clear 'end ds thread' flag ***
	cancelDsThread_ = false;
	cancelRtThread_ = false;

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
	cancelDsThread_ = true;
	cancelRtThread_ = true;
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
	rtTask_.Start( (INT32)this );

	//*** initialize subsystems ***
	//climber_->initialize();

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

   //*** make sure thrower is at full speed ***
   shooter_->setThrower( 1.0 );
	
	//*** main while loop ***
	while ( IsOperatorControl() )
	{
		//*** wait a short amount ***
		Wait( MAIN_LOOP_DELAY );
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
	//climber_->checkInputs();
}


//******************************************************************************
//******************************************************************************
/**
 * check real-time inputs for each subsystem 
 */
//******************************************************************************
void TinMan::checkRealTimeInputs()
{
	//*** Drive ***
	drive_->checkRealTimeInputs();
	
	//*** Shooter ***
	shooter_->checkRealTimeInputs();

	//*** Climber ***
	//climber_->checkRealTimeInputs();
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
	while ( !tinMan.dsThreadCancel() )
      {
		//*** wait for input from the driver station ***
		ds.WaitForData();

		//*** check all driverstation inputs ***
		tinMan.checkInputs();
      }
}


//******************************************************************************
//******************************************************************************
/**
 * Real Time thread 
 */
void TinMan::rtTask( TinMan* tm )
{
	//*** get reference to TinMan ***
	TinMan& tinMan = *tm;
	
	//*** do while not cancelled ***
	while ( !tinMan.rtThreadCancel() )
      {
      //*** real time update ***
      tinMan.checkRealTimeInputs();

      //*** wait for a msec ***
      Wait( REAL_TIME_DELAY );
	}
}


//************************************
//*** DO NOT REMOVE THE LAST LINE ****
//************************************
START_ROBOT_CLASS(TinMan);
