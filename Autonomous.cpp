#include "TinMan.h"

//******************************************************************************
//******************************************************************************
/**
 *  Shoot and Run
 */
void TinMan::Autonomous(void)
{
	//*** start the vision thread ***
	visionTask_.Start( (INT32)this );
	
   //*** REPLACE THIS WITH AUTONOMOUS CODE ***

   while ( IsAutonomous() )
      {



      Wait( 0.10 );
      }
}

