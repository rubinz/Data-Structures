

#include "vitalSigns.h"
#include <cstdlib>
#include <time.h>

    


double getRandTMP(void)//function to generate a random number between 0 and 10 then add it to 95
{//function takes nothing in, returns a Temperature
	
	double randTMP = rand()%1001;
	randTMP = randTMP/100;
	randTMP = randTMP+95;
	return randTMP;

}


double getRandBPM(void)//function to generate a random number between 0 and 40 then add it to 60
{//function takes nothing in, returns a Heart Beats per Minute value

	double randBPM = rand()%4001;
	randBPM = randBPM/100;
	randBPM = randBPM+60;
	return randBPM;

}


// -------------------\
//  getBodyTemperature \
// --------------------------------------------------------------
// IN: (no arguments)
// RETURNS: simulated body temperature in degrees F
// --------------------------------------------------------------
// double getBodyTemperature_F(void)
// {
//     double temp;
    
//     // for now, just enter value at keyboard
//     cout << "Enter a body temp(F): ";
//     cin >> temp;
//     return temp;
// }


// -------------------\
//  getBodyTemperature \
// --------------------------------------------------------------
// IN: (no arguments)
// RETURNS: simulated body temperature in degrees F
// --------------------------------------------------------------
// double getRespirationRate_BPM(void)
// {
//     double BPM;
//     cout << "Enter a BPM (Beats Per Minute): ";
//     cin >> BPM;

//     return BPM;
//}

