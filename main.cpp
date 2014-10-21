#include <iostream>	// need for console and keyboard
#include <fstream>	// need for file streams
#include <ctime>
#include "JOB.h"
srand(time(NULL));

int main()
{
cout << "How long do you want your time slices to be: " << endl;//how long for each time slice?
cin >> double howlong;
cout << "how long do you want to run this simulation: " << endl;//how long to simulate this program?
cin >> double simulationTime;

	JOB one;//constructor

	cout << one.getName();//need to write a method to give them the name.


	//within a while statment, I will have one.setRemaining(t); to be equal to 1 instead of 4 or something 


	//inside while ask for a new job. 

	//at end of while, I should print the cueue to see what else is in there.
	// something like this: 
	//JOB J;
	//J = Q.front();
	//Q.pop()
	//print JOB, J.print()
	//push 

	return 0;
}