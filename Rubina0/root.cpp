/*▁ ▂ ▄ ▅ ▆ ▇ █ Comp 116 a0 █ ▇ ▆ ▅ ▄ ▂ ▁*\
╓──────────────────────────────────────╖
║  Programmer: Zevi Rubin - Program 0  ║
╟──────────────────────────────────────╙───────────────────────────────────╖
║Summary:This program will tell the user what, if any, the roots are, given║
║      input for A, B, and C with regards to the equation ax^2 + bx + c = 0║
║Date last modified: January 30th, 2014									   ║
╟──────────────────────────────────────────────────────────────────────────╢
║INPUT(Keyboard, stdin): Input values for A, B, and C regarding the 	   ║ 	  
║ 						 Quadratic formula: ax^2 + bx + c = 0			   ║
║OUTPUT:The roots, if any, based on the input equation. Output or warnings ║
║		will be printed to the console using stdout    					   ║
╙──────────────────────────────────────────────────────────────────────────╜
\*                                                                        */
#include <iostream>
#include <math.h>
using namespace std;

int main(void)
{
	double  A ,     // three coefficients for the quadratic equation   |
            B ,	   //												   |
            C ;	  //												   V
	cout << "\n" << "Enter a real value for A:";   	   // taking user input for the three coefficients  |
    cin >> A;									   	  //												|
    cout << "\n" << "Enter a real value for B:";   	 // 												|
    cin >> B;									   	//												    |
    cout << "\n" << "Enter a real value for C:";   //												    |
    cin >> C;        							  //  												    V

	double rootONE ,      						   // Variable for the first root (+)	|
	rootTWO ,                					  // Variable for the second root (-)	|
	linearROOT;			  						 // Variable for a linear root 			v 	

		
	if (A == 0 && B == 0 && C == 0) 			 // Checks if the input is 0, 0, 0 i.e. a single point at 0 
	{
		cout << "\n" << "The equation you supplied creates a single infinite line on the x axis." << endl;
	}
	if (A == 0 && B != 0) 						// Checks if the input suggests a linear line with slope
	{
		linearROOT = (-C/B);
		cout << "\n" << "This is a linear line. Its root is at X= " << linearROOT << endl;
	}

	if (A==0 && B==0 && C != 0)							// Checks if the input is for a horizontal line of type Y = C
	{
		cout << "\n" << "The equation you input is for a horizontal line at Y = " << C << ", and has no real roots on the x axis." << endl;
	}

	else						// Continue checking for roots that are not for linear or horizontal lines
	{ 	
		double disc = (B*B - 4*A*C);   //create a variable that does the b^2-4ac calculation and stores the result for later use.

		if (disc >= 0)									// Check if the discriminant is positive
		{
			rootONE = (-B + sqrt(disc)) / (2*A);         // If it is positive we get its two roots |
			rootTWO = (-B - sqrt(disc)) / (2*A);			// 										  V
		}
		else													// If the discriminant IS negative it must not 
		{														// cross the X axis or have imaginary roots.  
			cout << "\n" << "This graph either doesn't cross the x axis," << endl;
			cout << "\n" << "Or its roots are imaginary" << endl;
		}
	    
		if (rootONE == rootTWO && ((disc) >= 0))		// Checks if there are two roots that are the same
		{														// If yes, then it is a non-linear line that only has one root.
			cout << "\n" << "This function just kisses the x axis once at X = " << rootONE << endl;
		}
		else if ((B*B - 4*A*C) >= 0 && A != 0)					// If all of the above tests fail,
		{														// This will display the two roots of the function.
			cout << "\n" << "First root is: " << rootONE  << endl;
			cout << "\n" << "Second root is: " << rootTWO  << endl;  
		}
	cout << "\n" << "" << endl;
	}	
	return 0;													// Ends the main() once this point is reached
	
} // main
