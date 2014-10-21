/*--------------------------------------------------------------
Programmer:		
 
Summary: 
 
Date last modified: 
 01/02/2014 (mdl) - Set up StarterKit
----------------------------------------------------------------*/

/*--------------------------------------------------------------
INPUT: 	
 
OUTPUT: 
 
WINDOWS specific:
 #include <windows.h>
 // then use Sleep() function in code
 Sleep(waitThisLongSEC*1000);
---------------------------------------------------------------*/

#include "medPing.h"

#include <cassert>

//-----------------------------------------------------------------------
#include <time.h>

// WINDOWS users: uncomment next line
// #include <windows.h>

const long MAX_HISTORY  = 5;	// can store upto (last) 5 sets of vital signs

const long MAX_WAIT_SEC = 4;	// will random pause from 1 to MAX_WAIT_SEC 

//========================================
struct oneVitalHistoryRecord
{
	double	bodyTemp_F;
	short	pulseRate;
	// :
	// you need more here ...
	// :
	
};
//========================================

// function prototypes for keeping track of HISTORY
// (see bottom of this file where you'll write the definitions)

void AddHistoryRecord(long nSecs,
					  double new_mp_bodyTemp_F, 
					  short  new_mp_pulseRate,
					  // you need more vital signs here
					  
					  oneVitalHistoryRecord vitalHistory[ ],
					  long& hmr
					  );

/*
const long NOT_FOUND = -1;  // used to indicate failure on linear search
long FindVitalRecord(...);

void DeleteHistoryRecord(...);
 */

void printAllVitalRecords(medPing& mP, const oneVitalHistoryRecord vitalHistory[ ], long hmr);
// end function prototypes



//-----------------------------------------------------------------------
//create a medPing object (mP object has global file scope)
medPing mP;	

//--------------
// medPing_Main \
//----------------------------------------------------------------------
// called from iPhone runSim-tab
int medPing_Main()
{
	// print a message to the cell phone
	mP.CELL_PrintF("Hello medPing patient ...\n\n");
	
	//======= DATA STRUCTURE ======================================
	// to hold patient's history of vital signs
	oneVitalHistoryRecord	vitalHistory[MAX_HISTORY];	
	
	// hmr (how many really) vital signs  0 <= hmr < MAX_HISTORY
	long hmr = 0;  
	//=============================================================
	
	RandGen		randGenerator;	// i need a random number generator
	time_t		start, now;		// keep track of time in simulation

	
	// ask user at CELL to input length of simulation
	mP.CELL_PrintF("How many SECONDS would you like to simulate?\n");
	double simulationTime = mP.CELL_fetchReal();
	time(&start);
	
	// simulation loop ....
	time(&now);
	while ( difftime(now,start) < simulationTime )		// while still time to simulate ...
	{
		long waitThisLongSEC = randGenerator.RandInt(1, MAX_WAIT_SEC);
		mP.CELL_PrintF("\n--------------------------\n");
		mP.CELL_PrintF("\n[PAUSE ... (%d seconds) ]\n", waitThisLongSEC);
		sleep(waitThisLongSEC);	// ZZzzzz.....
		// WINDOWS uses the function called: Sleep( milliseconds ) 
		// Sleep(waitThisLongSEC*1000);	// ZZzzzz.....

		
		
		// check our watch ...
		long nSecs = time(&now);
		
		// fetch vital signs from the medPing chip HERE (use mP object, right?)
		double newTemp;
		newTemp = mP.getBodyTemperature_F();
		// :
		// :
		
		
		// now ADD these new vital signs to our history DATA STRUCTURE
		//AddHistoryRecord(nSecs, newTemp, /* ... more here ... ,*/ vitalHistory, hmr);
		
		// PRINT ALL of the series of vital signs so far
		printAllVitalRecords(mP, vitalHistory, hmr);
		

		
	} // while still more to simulate ...
		
		
	mP.CELL_PrintF("\n\nSIMULATION OVER.\n\n");
	
	// prompt for a record to delete HERE,
    
    
    
    // find it (using your Find function)
    
    
    
    // and delete it if found (using your Delete function)
	
	
	
	
	
	mP.CELL_PrintF("\n\nDONE.\n");
	
	// WINDOWS
	// system("PAUSE");
	
	return 0;
	
} // end medPing_Main()


// helpful HISTORY functions below

/*
void AddHistoryRecord(.......
					  oneVitalHistoryRecord vitalHistory[ ],
					  long& hmr )
{
	


}
*/

/*
long FindVitalRecord()
{
	
}
*/

/*
void DeleteHistoryRecord(long recordIndex)
{
 
}
*/

//---------------------\
// printAllVitalRecords \
//---------------------------------------------------------------------------------------------
// Prints history (last set of) hmr vital signs (to medPing output)
// PRE:
// POST:
// SIDE EFFECTS:
//---------------------------------------------------------------------------------------------
void printAllVitalRecords(medPing& mP, const oneVitalHistoryRecord vitalHistory[ ], long hmr)
{
	if (hmr > 0)
	{
		mP.CELL_PrintF("\n---- Records (so far) ----");
		for(long i=0; i < hmr; i++)
		{
			mP.CELL_PrintF("\nRECORD [%02d]\n", i);
			mP.CELL_PrintF("\t temp(F):    \t%4.1f\n", vitalHistory[i].bodyTemp_F);
			mP.CELL_PrintF("\t pulse(BPM): \t%4d\n",   vitalHistory[i].pulseRate);
            
            
		} // for all records so far
		mP.CELL_PrintF("\n---- end History ----\n\n");

	} // if any records
	else 
		mP.CELL_PrintF("\nNo History so far ...\n\n");
	
} // printAllVitalRecords()


