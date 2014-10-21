/*--------------------------------------------------------------
Programmer: Zevi Rubin
 
Summary: This program will "ping" a chip in the patients body do get vital signs from the patient. 
		it will prompt the user to enter a number of sample seconds to take data, and has a built in
		memory of 5 data sets. The program will then Print out the data for the user and let the user
		choose if they want to delete a vitals record, and delete it then reprint the current record to the screen. 
 
Date last modified: 
 01/02/2014 (mdl) - Set up StarterKit
 02/11/2014 (ZR) - Read over Main file and all .h headers. Started thinking about how I want the structs to work.
 02/25/2014 (ZR) - Started working REALLY HARD on this program! Ended up scrapping what we did in lab, and just started fresh.
 02/26/2014 (ZR) - More work! Got the array of structs to work, but havent written any of the overwriting for more than 5 inputs... do that tomorrow
 02/27/2014 (ZR) - Time to finish up! Finished the overwriting part of the addtomemory, and wrote the other functions. must comment before submitting

----------------------------------------------------------------*/

/*--------------------------------------------------------------
INPUT: 	User will input data from the KEYBOARD. Data should be a reasonable number of seconds.
		The only other input needed is either 'y' or 'n' when choosing to view/delete a data record.
		The time stamp for a deleted data record can be copy/pasted from the preview of that record.
 
OUTPUT: Data will be printed to SCREEN each second as the data is collected for the entirety of the simulation time.
		Once the duration of the test cycle is done the program will print the most recent 5 data records to the SCREEN.
		The program will then prompt to the SCREEN, if the user wants to edit the data or not. Any changes to the data
		will also be printed to the SCREEN if the user changes anything.
 
---------------------------------------------------------------*/

#include "medPing.h"

#include <cassert>

#include <time.h>

//-----------------------------------------------------------------------

const long MAX_HISTORY  = 5;	// can store upto (last) 5 sets of vital signs

const long MAX_WAIT_SEC = 4;	// will random pause from 1 to MAX_WAIT_SEC 

//========================================
struct oneVitalHistoryRecord
{

	long timeMade;
	short systolic;
	short diastolic;
	double pressure;
	double allBPM;
	double allPulseRates;
	double allTemps;
	double allRespiration;
	
	
};
//========================================

// function prototypes for keeping track of AddHistoryRecord, FindVitalRecord, DeleteHistoryRecord, printAllVitalRecords.

void AddHistoryRecord(long nSecs, short systolic, short diastolic, double allPulseRates, double allTemps, double allRespiration,
					  oneVitalHistoryRecord vitalHistory[ ],
					  long& hmr
					  );

long FindVitalRecord(long rawTime, oneVitalHistoryRecord vitalHistory[ ], short thisRecord);

void DeleteHistoryRecord(long recordIndex, long rawTime, oneVitalHistoryRecord vitalHistory[ ], short thisRecord, long hmr);

void printAllVitalRecords(medPing& mP, const oneVitalHistoryRecord vitalHistory[ ], long hmr);


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
	int i = 0;
	
	// simulation loop ....
	time(&now);
	while ( difftime(now,start) < simulationTime )		// while still time to simulate ...
	{
		long waitThisLongSEC = 1;

		mP.CELL_PrintF("\n[PAUSE ... (%d seconds) ]\n", waitThisLongSEC);
		sleep(waitThisLongSEC);	
		
		// check our watch ...
		long nSecs = time(&now);
		
		//Declaring variables to be filled with vital signs
		double allTemps, allRespiration, allPulseRates, glucose;
		short systolic, diastolic;

		//pings the chip to get vital signs from the patients
		allTemps = mP.getBodyTemperature_F();
		allRespiration = mP.getRespirationRate_BPM();
		mP.getBloodPressure_mmHg(systolic, diastolic);
		allPulseRates = mP.getPulseRate_BPM();
		glucose = mP.getGlucoseLevel_mgdL();

		//Prints vital signs to screen as they are collected. _-_-_-_-_-_-_-_- This can be commented out when code is being used

		cout << "Temp: \t\t" << allTemps << endl;
		cout << "Pulse Rate: \t" << allPulseRates << endl;
		cout << "Respiration: \t" << allRespiration << endl;
		cout << "Diastolic: \t" << diastolic << endl;
		cout << "Systolic: \t" << systolic << endl;

		// now ADD these new vital signs to our history DATA STRUCTURE
		AddHistoryRecord(nSecs, systolic, diastolic, allPulseRates, allTemps, allRespiration,
					   vitalHistory,
					   hmr);
		hmr++;
		

		
	} 
		
		
	mP.CELL_PrintF("\n\nSIMULATION OVER.\n\n");

	// PRINT ALL of the series of vital signs so far
	printAllVitalRecords(mP, vitalHistory, hmr);
	
    //declare variables to be used in the find/delete functions
    long rawTime;
    bool found;
    short thisRecord;
    char DataEdit;
    char DeleteRecord;

    //prompt user if they want to find it (using your Find function)
    cout << "Do you want to edit a data entry? (y/n): ";
    cin >> DataEdit;

    if (DataEdit == 'y')
    {
    	cout << "Enter a time stamp: ";
    	cin >> rawTime;
    	found = FindVitalRecord(rawTime, vitalHistory, thisRecord);

    	mP.CELL_PrintF("\nRECORD [%02d]\n", found);
		mP.CELL_PrintF("\t time of test: \t\t%d\n", vitalHistory[found].timeMade);
		mP.CELL_PrintF("\t all temp(F):    \t%4.1f\n", vitalHistory[found].allTemps);
		mP.CELL_PrintF("\t all pulse rates: \t%4.1f\n",   vitalHistory[found].allPulseRates);
		mP.CELL_PrintF("\t all respiration: \t%4.1f\n",   vitalHistory[found].allRespiration);
		mP.CELL_PrintF("\t diastolic: \t\t%d\n",   vitalHistory[found].diastolic);
		mP.CELL_PrintF("\t systolic: \t\t%d\n",   vitalHistory[found].systolic);


    	long recordIndex = found;

		// prompt for a record to delete HERE,

		cout << "Do you want to delete this data entry? (y/n): ";
		cin >> DeleteRecord;
		if (DeleteRecord=='y')
		{
    		// and delete it if found (using your Delete function)
			DeleteHistoryRecord( recordIndex, rawTime, vitalHistory, thisRecord, hmr);
    	}

    }
    
	
	
	
	
	//print done to screen
	mP.CELL_PrintF("\n\nDONE.\n");
	
	
	return 0;
	
} // end medPing_Main()



//---------------------\
// AddHistoryRecord    \
//---------------------------------------------------------------------------------------------
// Add History Record (Takes data from main) - adds the data into sets of structs one at a time. Only keeps most recent 5 records.
// PRE: Must have data sent to it from the main. If no data, this function will not work
// POST: saves data into array as groups of a struct.
// SIDE EFFECTS: gradually fills array, then over writes old data when input exceedes 5 data sets
//---------------------------------------------------------------------------------------------
void AddHistoryRecord(long nSecs, short systolic, short diastolic, double allPulseRates, double allTemps, double allRespiration,
					  oneVitalHistoryRecord vitalHistory[ ],
					  long& hmr)
{

	double cellNumber;
	cellNumber = hmr;

	//fills first five cells with data normally
	if (cellNumber < 5)
	{
		vitalHistory[hmr].timeMade = nSecs;
		vitalHistory[hmr].allTemps =  allTemps;
		vitalHistory[hmr].systolic = systolic;
		vitalHistory[hmr].diastolic = diastolic;
		vitalHistory[hmr].allPulseRates =  allPulseRates;
		vitalHistory[hmr].allRespiration =  allRespiration;

		cout << "History added" << endl;
	}
	else
	{
		//if there are more than 5 data entries - this will shift the 4 most recent entries to the first cells
		// freeing up the most recent cell for new data
		for (long i=0; i<MAX_HISTORY-1; i++)
		{
			vitalHistory[i].timeMade =vitalHistory[i+1].timeMade;
			vitalHistory[i].allTemps =  vitalHistory[i+1].allTemps;
			vitalHistory[i].systolic = vitalHistory[i+1].systolic;
			vitalHistory[i].diastolic = vitalHistory[i+1].diastolic;
			vitalHistory[i].allPulseRates = vitalHistory[i+1].allPulseRates;
			vitalHistory[i].allRespiration = vitalHistory[i+1].allRespiration;
		}
		//the new data is then entered into the newly freed array cell
		vitalHistory[4].timeMade = nSecs;
		vitalHistory[4].allTemps =  allTemps;
		vitalHistory[4].systolic = systolic;
		vitalHistory[4].diastolic = diastolic;
		vitalHistory[4].allPulseRates =  allPulseRates;
		vitalHistory[4].allRespiration =  allRespiration;

		cout << "History added" << endl;

	}

}


//---------------------\
// FindVitalRecord     \
//---------------------------------------------------------------------------------------------
// Find Vital Records (takes keyboard input) searches the array for corresponding data records
// PRE: Must have at least one record in the array VitalHistory
// POST: Tells user if it found a corresponding data set, if yes prompts user if they want to delete it.
// SIDE EFFECTS: N/A
//---------------------------------------------------------------------------------------------
long FindVitalRecord(long rawTime, oneVitalHistoryRecord vitalHistory[ ], short thisRecord)
{
	//searches through each of the data cells checking if the search time matches the data recovery time.
	for (long i=0; i<MAX_HISTORY; i++)
	{
		if (vitalHistory[i].timeMade == rawTime)
		{
			cout << " Found it!" << endl;
			thisRecord = i;
		}
		else
		{
			// cout << "Not Found.\n" << endl;
		}
	}
}

//---------------------\
// DeleteHistoryRecord \
//---------------------------------------------------------------------------------------------
// Delete History (History Record input from Keyboard) - deletes the corresponding record
// PRE: Must have at least one record in the array VitalHistory
// POST: Deletes the record from VitalHistory and fills it with 0's
// SIDE EFFECTS: Deleted array cells now have 0's in them
//---------------------------------------------------------------------------------------------
void DeleteHistoryRecord(long recordIndex, long rawTime, oneVitalHistoryRecord vitalHistory[ ], short thisRecord, long hmr)
{
	//finds the cell that the user wants to delete
	for (long i=0; i<MAX_HISTORY; i++)
	{
		if (vitalHistory[i].timeMade == rawTime)
		{
			cout << " Found it!" << endl;
			thisRecord = i;
		}
		else
		{
			cout << "Not Found.\n" << endl;
		}
	}

//tells user what cell was deleted, and zeros out all the data from that cell
	vitalHistory[thisRecord].timeMade = 0;
	vitalHistory[thisRecord].allTemps = 0;
	vitalHistory[thisRecord].systolic = 0;
	vitalHistory[thisRecord].diastolic = 0;
	vitalHistory[thisRecord].allPulseRates = 0;
	vitalHistory[thisRecord].allRespiration = 0;

	cout << "Deleted Record: " << thisRecord << endl;

	printAllVitalRecords(mP, vitalHistory, hmr);
}

//---------------------\
// printAllVitalRecords \
//---------------------------------------------------------------------------------------------
// Prints history (last set of) hmr vital signs (to medPing output)
// PRE: needs to have at least one vital sign within the array of structs. 
// POST: prints the 5 most recent data sets in the array. Doesnt change anything
// SIDE EFFECTS: No side effects, this isnt a disease or something!
//---------------------------------------------------------------------------------------------
void printAllVitalRecords(medPing& mP, const oneVitalHistoryRecord vitalHistory[ ], long hmr)
{
	double thisMany;
	//while there is data to be printed.... it prints it
	if (hmr > 0)
	{
		//checks how many cells there are before printing the data.
		//prints the number of cells that data is stored it. Greatfully there will never be more than 5 cells with data
		if (hmr < 5)
		{
			thisMany = hmr;
		}
		else
		{
			thisMany = 5;
		}


		mP.CELL_PrintF("\n---- Records (so far) ----");
		for(long i=0; i < thisMany; i++)
		{
			
			mP.CELL_PrintF("\nRECORD [%02d]\n", i);
			mP.CELL_PrintF("\t time of test: \t\t%d\n", vitalHistory[i].timeMade);
			mP.CELL_PrintF("\t all temp(F):    \t%4.1f\n", vitalHistory[i].allTemps);
			mP.CELL_PrintF("\t all pulse rates: \t%4.1f\n",   vitalHistory[i].allPulseRates);
			mP.CELL_PrintF("\t all respiration: \t%4.1f\n",   vitalHistory[i].allRespiration);
			mP.CELL_PrintF("\t diastolic: \t\t%d\n",   vitalHistory[i].diastolic);
			mP.CELL_PrintF("\t systolic: \t\t%d\n",   vitalHistory[i].systolic);

            
		} 
		mP.CELL_PrintF("\n---- end History ----\n\n");

	} 
	else 
		mP.CELL_PrintF("\nNo History so far ...\n\n");
} // End printAllVitalRecords()


