/*▁ ▂ ▄ ▅ ▆ ▇ █ Comp 116 █ ▇ ▆ ▅ ▄ ▂ ▁*\
╓──────────────────────────────────────╖
║  Programmer: Zevi Rubin - Program 0  ║
╟──────────────────────────────────────╙───────────────────────────────────╖
 Summary: 
 
 Date last modified:
 
╟──────────────────────────────────────────────────────────────────────────╢
 INPUT:
 
 OUTPUT:
╙──────────────────────────────────────────────────────────────────────────╜
\*                                                                        */


#include <iostream>
#include <math.h>
using namespace std;



int main(void)
{
	double  A ,     // three coefficients for quadratic equation
            B ,
            C ;
	cout << "Enter a real value for A:" << endl;
    cin >> A;
    cout << "Enter a real value for B:" << endl;
    cin >> B;
    cout << "Enter a real value for C:" << endl;
    cin >> C;        

	double rootONE ,      // first root
	rootTWO ,             // second root
	linearROOT;
	// brute force ... need to do lots of testing ...
    
	// compute the first root
	


	if (A == 0)
	{
		
		linearROOT = (-C/B);
		cout << "This is a linear line. Its root is: " << linearROOT << endl;
	}


	else
		
	{




		if ((B*B - 4*A*C) >= 0)
		{
			rootONE = (-B + sqrt(B*B - 4*A*C)) / (2*A);
			rootTWO = (-B - sqrt(B*B - 4*A*C)) / (2*A);
		}
		else
		{
			cout << "this graph doesn't cross the x axis" << endl;
		}
	    
		
		// now compute the second root

/*
		if ((B*B - 4*A*C) >= 0)
		{
			rootTWO = (-B - sqrt(B*B - 4*A*C)) / (2*A);
		}
		else
		{
			cout << "this graph doesn't cross the x axis" << endl;
		}
*/
		if (rootONE == rootTWO and ((B*B - 4*A*C) >= 0))
		{
			cout << "This function just kisses the x axis at X = " << rootONE << endl;
		}
		else if ((B*B - 4*A*C) >= 0)
		{	
			cout << "First root is: " << rootONE << "\n" << endl;
			cout << "Second root is: " << rootTWO << "\n" << endl;  
		}
	}	
	
	return 0;
	
} // main
