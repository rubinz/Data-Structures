#include <iostream>
using namespace std;

const short MAX=10;    // I'm guessing that I won't need more than MAX 
#include "prototypes.h"


int main(void)
{
	short A[MAX];	// array to hold input data
	short hmr;		// HowManyReally (hmr) get put into A (<= MAX)
	
	getData(A, hmr);
	cout << "A was filled with " << hmr << " elements." << endl;
	
    
	printData(A, hmr);
    
    short max, min, whereMax, whereMin;
    double mean;
    
	getStats(A, hmr, max, min, mean, whereMax, whereMin);
    
	cout << "There were: " << hmr << " Inputs." << endl;
	cout << "The max input was: " << max << " at the location: " << whereMax << endl;
	cout << "The min input was: " << min << " at the location: " << whereMin << endl;
	cout << "The mean of the inputs was: " << mean << endl;



    
    
    
	
	// WINDOWS
	//system("PAUSE");
	
	return 0;
} // =========== end main() ==================================


void getData( /* out  */   short A[]    ,   /* out */ short& hmr   )
{	/*---------------------------------------------------------
	 SUMMARY: read values from keyboard into array A until a negative
	 
	 Global: MAX is maximum number of elements in A
	 
	 PRE: 		A is empty; hmr is unknown
	 POST:	 	(by reference): 
        hmr indicates number of input values put into A
        A is filled with hmr elements
	 ------------------------------------------------------------*/
	short temp, i=0;
	cout << "Enter some stats: ";
	cin >> temp;
	while (temp >= 0 && i < MAX) // while non-neg and still have room in A
	{
    	A[i] = temp; 
    	i++;                 // store input into A
		
        cout << "Enter more stats: ";
		if (i <= 9)
		{
			cin >> temp;	// try to read next input
		}
        
	} // while not negative input and array is not full
	
	hmr = i;			// hmr elements were read in
	if (hmr == MAX)
		cout << "WARNING: array is FULL" << endl;
	
} // =========== end getData() ==================================


void printData( /*  in  */        const short A[],    /*  in  */  short hmr     )
{	/*---------------------------------------------------
	 SUMMARY: print values in array A to the console
	 
	 PRE: 	hmr indicates number of elements actually in A
	        A is filled with hmr elements
	 POST:  nothing
     Side Effect: values printed to console (stdout)
	 -----------------------------------------------------*/	
	for (short i=0;  i < hmr;   i++)
		cout << "A[" << i << "] = " << A[i] << endl;
	
} // =========== end printData() ==================================



