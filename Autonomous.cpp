#include "TinMan.h"
#include "Shooter/Shooter.h"
#include "Input/DriveTrain.h"

#define AUTONOMOUS_THROWER_SPEED (1.00)
#define SHOOTER_DELAY (0.500 )
#define SHOOTER_WAIT (0.01)

//******************************************************************************
//******************************************************************************
/**
 *  Shoot and Run
 */

void TinMan::Autonomous(void)
{
	//*** initialize the robot ***
	initialize();

	//*** set thrower speed to autonomous value ***
	shooter_->setThrower( AUTONOMOUS_THROWER_SPEED );
	Wait(4.000);
   
	while(IsAutonomous()) {
		shooter_->shoot();
		Wait(1.000);
	}

   //*** back up a bit ***
	#if 0
   drive_->driveStraight( -0.3f, 1000 );

   if ( !waitTillFinished( drive_ ) ) return;

   //*** spin 180 ***
   while(IsAutonomous()) {
	   drive_->spin( 180 );
   }
	#endif
}

//******************************************************************************
//******************************************************************************
bool TinMan::waitTillFinished( DriveTrain* dt )
{
	while( !drive_->finishedAction() && IsAutonomous() )
	{
		Wait( 0.01 );
	}
	
	return IsAutonomous();
}

