/*▁ ▂ ▄ ▅ ▆ ▇ █ Comp 116 a0 █ ▇ ▆ ▅ ▄ ▂ ▁*\
╓──────────────────────────────────────╖
║  Programmer: Zevi Rubin - Program 0  ║
╟──────────────────────────────────────╙───────────────────────────────────╖
║Summary: This program will tell the user what, if any, the roots are given║
║      input for A, B, and C with regards to the equation ax^2 + bx + c = 0║
║Date last modified: January 28th, 2014									   ║
╟──────────────────────────────────────────────────────────────────────────╢
║INPUT(Keyboard, stdin): Input values for A, B, and C regarding the 	   ║ 	  
║ 						 Quadratic formula: ax^2 + bx + c = 0			   ║
║OUTPUT:The roots, if any, based on the input equation. Output or warnings ║
║		will be printed to the console isomg stdout    					   ║
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
	cout << "Enter a real value for A:" << endl;   	   // taking user input for the three coefficients  |
    cin >> A;									   	  //												|
    cout << "Enter a real value for B:" << endl;   	 // 												|
    cin >> B;									   	//												    |
    cout << "Enter a real value for C:" << endl;   //												    |
    cin >> C;        							  //  												    V

	double rootONE ,      						   // Variable for the first root (+)	|
	rootTWO ,                					  // Variable for the second root (-)	|
	linearROOT;			  						 // Variable for a linear root 			v 	

		
	if (A == 0 && B == 0 && C == 0) 			 // Checks if the input is 0, 0, 0 i.e. a single point at 0 
	{
		cout << "The equation you supplied creates a single point at (0, 0)" << endl;
	}
	if (A == 0 && B != 0) 						// Checks if the input suggests a linear line with slope
	{
		linearROOT = (-C/B);					// Uses input from B and C to find the linear line root
		cout << "This is a linear line. Its root is at X= " << linearROOT << endl;
	}

	if (A==0 && B==0 && C != 0)							// Checks if the input is for a horizontal line of type Y = C
	{
		cout << "The equation you input is for a horizontal line at Y=" << C << ", and will not pass the x axis." << endl;
	}

	else						// Continue checking for roots that are not for linear or horizontal lines
	{ 											 
		if ((B*B - 4*A*C) >= 0)									// Check if the discriminant is positive
		{
			rootONE = (-B + sqrt(B*B - 4*A*C)) / (2*A);         // If it is positive we get its two roots |
			rootTWO = (-B - sqrt(B*B - 4*A*C)) / (2*A);			// 										  V
		}
		else													// If the discriminant IS negative it must not 
		{														// cross the X axis or have imaginary roots.  
			cout << "This graph either doesn't cross the x axis," << endl;
			cout << "Or its roots are imaginary" << endl;
		}
	    
		if (rootONE == rootTWO && ((B*B - 4*A*C) >= 0))		// Checks if there are two roots that are the same
		{														// If yes, then it is a non-linear line that only has one root.
			cout << "This function just kisses the x axis once at X = " << rootONE << endl;
		}
		else if ((B*B - 4*A*C) >= 0 && A != 0)					// If all of the above tests fail,
		{														// This will display the two roots of the function.
			cout << "First root is: " << rootONE << "\n" << endl;
			cout << "Second root is: " << rootTWO << "\n" << endl;  
		}
	}	
	return 0;													// Ends the main() once this point is reached
	
} // main
