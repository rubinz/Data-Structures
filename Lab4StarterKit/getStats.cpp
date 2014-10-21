
#include <iostream>
#include <assert.h>

using namespace std;
#include "prototypes.h"



// =========================================================================
 // Summary: A[] has a bunch of information in it. This sorts through each memory block and checks if the number
 // is a max or min or if it should add it to the mean
 // PRE: all A[] are known and there is a hmr number. The rest of the values are empty
 //
 // POST: returns no changes to the array A[] or hmr, DOES return values for all the rest of the values
 //
 // RETURN: returns values for max, min, maxlocation, minlocation, and mean.
 
 void  getStats  (const short A[],  short hmr, 
                 short& max, short& min, double& mean, 
                 short& whereMax, short& whereMin)
{	
	assert (hmr > 0 && "ASSERT FAILED in getStats(): no data in arrays." );
	
	// Assume the first item in array is both min and max
	max = min = A[0];
	whereMax = whereMin = 0;
	
	short sum = 0;
	
	short i = 1;  // no need to check index zero
	
	// Go through the array and find the largest and smallest numbers
	// Don't forget to also save WHERE (what cell#) you found the min and max 
	while (i < hmr)
	{	

		if (A[i] > max){
			
			max = A[i];
			whereMax = i;
		}
		if (A[i] < min)
		{	
			min = A[i];
			whereMin = i;
		}
		
		sum += A[i];
		i++;
		
		
		
		
	} // end while more data in array to check
	
	// Don't forget to compute the mean
	// mean = sum / 
    
    mean = sum/(hmr-1);
	
} // =========== end getStats() ==================================
