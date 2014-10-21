
#include <iostream>

using namespace std;

int main(void)
{
	// do NOT change float's to double
	const float 
	INCREMENT = 0.1;			// constant to keep adding to sum
   	
	float sum;					// variable to hold the sum
	
	// starting at ZERO, this code will continue to add 
	//  the INCREMENT to sum until reaching 2.0
	
	printf("  %.15f \n", INCREMENT);
	sum = 0.0;
	while (sum != 2.0)   // do NOT change the test; leave it as is
	{
      	
		cout << "Now sum is: " << sum << endl;
      	sum = sum + .1;
      	if (sum >= 2)
      		break;
      	
      		
	} // while
	
	cout << endl << "DONE LOOP and sum is " << sum << endl;
	printf("sum is %.15f \n", sum);
	
	// WINDOWS users (uncomment next line)
	//system("PAUSE");
	
	return 0;
} // main
