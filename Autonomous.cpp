#include "TinMan.h"
#include "Shooter/Shooter.h"
#include "Input/DriveTrain.h"

#define AUTONOMOUS_THROWER_SPEED (0.94)
#define SHOOTER_DELAY (0.500 )
#define SHOOTER_WAIT (0.01)

//******************************************************************************
//******************************************************************************
/**
 *  Shoot and Run
 */

#define NUM_AUTO_SHOTS (10)

void TinMan::Autonomous(void)
{
   int numShots = 0;

	//*** initialize the robot ***
	initialize();

   //*** set thrower speed to autonomous value ***
   shooter_->setThrower( AUTONOMOUS_THROWER_SPEED );

   //*** shoot for a number of times ***
   while ( (numShots < NUM_AUTO_SHOTS) && IsAutonomous() )
      {
      //*** wait till we're able to shoot ***
      while ( shooter_->isShooting() && IsAutonomous() ) 
         {
         Wait( SHOOTER_WAIT );
         }

      //*** do we need to exit autonomous??? ***
      if ( !IsAutonomous() ) return;

      //*** shoot ***
      shooter_->shoot();

      //*** increment shot count ***
      numShots++;

      //*** delay for a bit to let shooter get back up to speed ***
      Wait( SHOOTER_DELAY );
      }

   //*** back up a bit ***
   drive_->driveStraight( -0.3f, 1.0f );

   if ( !waitTillFinished( drive_ ) ) return;

   //*** spin 180 ***
   drive_->spin( TURN_RIGHT, 0.3f, 180.0f );

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

