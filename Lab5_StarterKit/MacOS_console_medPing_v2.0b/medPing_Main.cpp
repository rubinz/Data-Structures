/*--------------------------------------------------------------
Programmer:
Summary:
Date last modified:
----------------------------------------------------------------*/

/*--------------------------------------------------------------
INPUT:
OUTPUT:
---------------------------------------------------------------*/


#include "medPing.h"
const short MAX = 5;

int printHistory();

struct data
{
	short systolic;
	short diatolic;
	double allPulseRates;
	double allTemps;
	double allRespiration;
	double allBPM;

};
data allRecords[MAX];



//--------------
// medPing_Main \
//----------------------------------------------------------------------
int medPing_Main()
{
	// create a medPing object
	medPing mP;

	mP.CELL_PrintF("\nHello medPing patient ...\n\n");

	double temp, bpm, pressure, pulse, glucose;
	short systolic, diastolic;
	temp = mP.getBodyTemperature_F();
	bpm = mP.getRespirationRate_BPM();
	mP.getBloodPressure_mmHg(systolic, diastolic);
	pulse = mP.getPulseRate_BPM();
	glucose = mP. getGlucoseLevel_mgdL();

	// mP.CELL_PrintF("\n The temp is: %5.2f and your bpm is: %5.2f\n", temp, bpm);
	// mP.CELL_PrintF("\n The blood pressure is: %5.2f over %5.2f", systolic, diastolic);
	// mP.CELL_PrintF("\n The glucose level is: %5.2f and your pulse is: %5.2f\n", glucose, pulse);


	int i = 0;

	data oneRec;


	while (i < MAX)
	{
		short systolic;
	short diatolic;
	double allPulseRates;
	double allTemps;
	double allRespiration;
	double allBPM;

		allRecords[i].allTemps =  mP.getBodyTemperature_F();
		allRecords[i].systolic =  mP.getBodyTemperature_F();
		allRecords[i].diatolic =  mP.getBodyTemperature_F();
		allRecords[i].allPulseRates =  mP.getBodyTemperature_F();
		allRecords[i].allRespiration =  mP.getBodyTemperature_F();
		allRecords[i].allBPM =  mP.getBodyTemperature_F();


		cout << " waiting... " << endl;
		i++;
		sleep(1);


	}

	printHistory();





	return 0;

} // end medPing_Main()

int printHistory()
{	
	medPing mP;
	int i = 0;
	while (i < MAX){

		mP.CELL_PrintF("================================================");
		mP.CELL_PrintF("\n Hello User - Your Health History is as Follows: \n");
		mP.CELL_PrintF("\nThe patients temperature is: %6.2f\n", allRecords[i].allTemps);
		mP.CELL_PrintF("\nThe patients pulse rate is: %6.2f\n", allRecords[i].allPulseRates);
		mP.CELL_PrintF("\nThe patients respiration rate is: %6.2f\n", allRecords[i].allRespiration);
		mP.CELL_PrintF("\nThe patients heart rate is: %6.2f\n", allRecords[i].allBPM);
		mP.CELL_PrintF("\nThe patients systolic is: %6.2f\n", allRecords[i].systolic);
		mP.CELL_PrintF("\nThe patients diatolic is: %6.2f\n", allRecords[i].diatolic);

		i++;
	}

	return 0;

}

// void saveHistory()
// {
// 	medPing mP;
// 	int i = 0;
// 	while (i<MAX){
		
		
// 	}

// }
