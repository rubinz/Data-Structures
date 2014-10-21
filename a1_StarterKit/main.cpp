/*▁ ▂ ▄ ▅ ▆ ▇ █ Comp 116 a0 █ ▇ ▆ ▅ ▄ ▂ ▁*\
╓──────────────────────────────────────╖
║  Programmer: Zevi Rubin - Program 1  ║
╟──────────────────────────────────────╙───────────────────────────────────╖
║Summary:This program will calculate the Strength of Association between   ║
║        heart rate and temperature. I.E. Does one correlate with the other║
║Date last modified: Feb 6th, 2014                                         ║
╟──────────────────────────────────────────────────────────────────────────╢
║INPUT(Optional Keyboard, stdin): OPTIONAL input can come from the keyboard║      
║                                                                          ║
║OUTPUT:The Correlation Coefficient, and the Strength of Association for   ║
║       the correlation between heart rate and temperature.                ║
╙──────────────────────────────────────────────────────────────────────────╜
\*                                                                        */

#include <iostream>//import necessary librarys.
#include <cmath>
#include "vitalSigns.cpp"


using namespace std;
int main()
{	
	// DECLARE CONSTANTS

	// XXXXXXXshort inputNumber = 3
	const short								// ----- CONSTANT declarations -----
            inputNumber = 3;                          // number of (x,y) pairs
	
	const double STRENGTH = 0.50;			// value to measure strength of association
	
	
	// DECLARE VARIABLES	
	
	double									// ----- VARIABLE declarations -----
	x1, y1,									// first  (x,y) pair
	x2, y2,									// second (x,y) pair
	x3, y3;		                            // third  (x,y) pair

    srand (time(NULL)); // this sets an initial time stamp so the three later calls wont all have the same time stamp.

	double //declaring various calculation variables. 
	nSumXY, sumXsumY,
    sumX, sumY, 
    sumXsqr, sumYsqr, 
	firstRoot, secondRoot,
	numerator, denominator,
	strAss, strAssSq;

    //For Example inputs:
    // x1 = 98.6;
    // x2 = 97.4;
    // x3 = 96.8;
    // y1 = 18;
    // y2 = 17;
    // y3 = 7;


    //For Manual inputs:
	// x1 = getBodyTemperature_F();
	// y1 = getRespirationRate_BPM();
	// x2 = getBodyTemperature_F();
	// y2 = getRespirationRate_BPM();
	// x3 = getBodyTemperature_F();
	// y3 = getRespirationRate_BPM();

    // Calls vitalSigns.cpp file to run a randomizer function.
    //gatRandTMP adds a number between 0-10 to 95.
    x1 = getRandTMP();
    x2 = getRandTMP();
    x3 = getRandTMP();
    //getRandBPM adds a number between 0-40 to 60.
    y1 = getRandBPM();
    y2 = getRandBPM();
    y3 = getRandBPM();


    sumX = x1+x2+x3;  //sum of temperature values
    sumY = y1+y2+y3;  //sum of Heart Rate values
    sumXsqr = x1*x1+x2*x2+x3*x3; //sum of x^2 values
    sumYsqr = y1*y1+y2*y2+y3*y3; //sum of y^2 values
    nSumXY = inputNumber*((x1*y1)+(x2*y2)+(x3*y3)); //number of inputs times sum of xy values
    sumXsumY = (sumX)*(sumY); //multiplies the sum of x values with the sum of y values.
    firstRoot = sqrt((inputNumber*(sumXsqr)-(sumX)*(sumX))); //calculates the first root
    secondRoot = sqrt((inputNumber*(sumYsqr)-(sumY)*(sumY))); //calculates the second root

    if (firstRoot <= 0 || secondRoot <= 0){ //loop to check if either of the denomenator values are 0 or negative
    	cout << "\n*****************************************" << endl;//If yes, error message prints to consile
    	cout << "First root: " << firstRoot << " Second root: " << secondRoot << endl;
    	cout << "ERROR: there is a form of division by zero from your input" << endl;
    	cout << "\n*****************************************" << endl;
        exit (-1);

    }

    else //if the denomenator is not zero, continue calculations.
    {    	
    	numerator = nSumXY - sumXsumY; //calculate numerator value
    	denominator = firstRoot * secondRoot; // calculate denominator value
    	if (numerator == 0)//short cut to make the strength association value 0 if the numerator is 0.
    	{
    		strAss = 0;
    		strAssSq = 0;
    	}
    	else
    		strAss = numerator/denominator; 
    		strAssSq = (strAss*strAss);

    }

    //output graphics and title:
    cout << "\n*****************************************" << endl;
    cout << "Regression analysis on three pairs of" << "\n" << "BodyTempF and RespirationRate Values" << endl;
    cout << "*****************************************" << endl;

    if ((nSumXY - sumXsumY) == 0){//tells user that the value is zero if the numerator is 0.
    	cout << "The numerator is equal to 0. \n" << endl; }

   	cout << "Your three (BodyTempF, RespirationRate) pairs are: \n" << endl;//print to console the values of the inputs.
    printf("(x,y) pair 1:  (%6.2f, %6.2f)\n", x1, y1);
    printf("(x,y) pair 2:  (%6.2f, %6.2f)\n", x2, y2);
    printf("(x,y) pair 3:  (%6.2f, %6.2f)\n", x3, y3);
        
    cout << "\nCorrelation Coefficient: " << strAss << "\nStrength of Association: " << strAssSq << endl;
    
    if (strAssSq >= .5)//checks to see if the strength of association is Strong or not.
    {
    	printf("The Strength of Associaltion is: (%1.2f)\n", strAssSq);
    	printf("Therefore the Strength of Associaltion of is STRONG");
    }
    else
    {
        cout << "\nThe Strength of Association for these inputs is NOT particularly strong." << endl;

    }
    cout << endl << "\nDone." << endl << endl;//end of program!
	return 0;
	
} // end main()
