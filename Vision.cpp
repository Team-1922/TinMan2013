#include "TinMan.h"


//******************************************************************************
//******************************************************************************
/**
 * Vision thread 
 */
void TinMan::visionTask( TinMan* tm )
{
	//*** get reference to TinMan ***
	TinMan& tinMan = *tm;
	
	//*** do while not cancelled ***
	do
	{
      Wait(1.0);
		
	} while( !tinMan.visionThreadCancel() );

}

