/*▁ ▂ ▄ ▅ ▆ ▇ █ Comp 116 a3 █ ▇ ▆ ▅ ▄ ▂ ▁*\
╓──────────────────────────────────────╖
║  Programmer: Zevi Rubin - Program 3  ║
╟──────────────────────────────────────╙───────────────────────────────────╖
║Summary:This program will simmulate the CPU of a simple computer as it    ║
║      processes jobs. These jobs will be processed "simultaniously" using ║
║      a simulated single core multiprocessing machine.              	   ║
║ 																		   ║
║ Date last modified: 													   ║
║ 03/14/2014 (ZR) - started reading spec, tried making my own main  	   ╙─────────────────────────────────────╖
║ 03/17/2014 (ZR) - Started work after lab that tried to prepair us for writing our own class using OOP          ║ 
║ 03/20/2014 (ZR) - Still cant get the hang of OOP. Lab isnt helping with this, and still dont know queue syntex ║
║ 03/26/2014 (ZR) - Worked with devon in the whale lab and he tried teaching me OOP. It actually helped some...  ║
║ 03/27/2014 (ZR) - After working with clayton and devon I managed to get the first part of the program working:/║
║ 																		   ╓─────────────────────────────────────╜
╟──────────────────────────────────────────────────────────────────────────╢
║INPUT(Keyboard, stdin): Input is a number for the timeslice that the CPU  ║ 	  
║ 						 will use, as well as a runtime (from keyboard)	   ║
║OUTPUT:This program will print continually as the jobs are processed      ║
║		through the CPU. Once finished it will dequeue the last job		   ║
╙──────────────────────────────────────────────────────────────────────────╜
\*                                                                        */

#include <iostream>	// need for console and keyboard
#include <fstream>	// need for file streams
#include <ctime>	//need for keeping track of time
#include "JOB.h"	//need for reference to the functions in job.cpp
#include <queue>	//needed to generate queues. needed for the use of queues from the STL.
using namespace std;

double TIMEUSED = 0;//set a variable to keep track of the total time used durring the opperation


int main()//main function

{
	srand(time(NULL));//initiate or "seed" the clock to start running
		
	double timeSlice; //declare three variables that we will get user input for
	double simulationTime;
	double newProbability;

	cout << "How long do you want your time slices to be: " << endl; //user input for how long for each time slice?
	cin >> timeSlice;
	cout << "how long do you want to run this simulation: " << endl; //user input for how long to simulate this program?
	cin >> simulationTime;
	cout << "Probability that a new job will enter queue: " << endl; //user input for Odds of a new job coming along?
	cin >> newProbability;


	queue<JOB> jobs;//make a queue that will hold the class JOB. 
	
	JOB one; //initiate the class JOB with the object ONE.
	jobs.push(one);//Push job ONE to the queue


	JOB two;//initiate the class JOB with the object two.
	jobs.push(two);//Push job two to the queue

	JOB three;//initiate the class JOB with the object three.
	jobs.push(three);//Push job three to the queue

	JOB four;//initiate the class JOB with the object four.
	jobs.push(four);//Push job four to the queue

	JOB five;//initiate the class JOB with the object five.
	jobs.push(five);//Push job five to the queue




	JOB tempJob; //creates a temporary job to store the values of jobs.fron().
	while(!jobs.empty())//while there are still jobs in the CUP (queue), run this loop
	{

		tempJob = jobs.front();//assigns the location of jobs.front() to tempJob.
		cout << "\n--------------" << endl;
		cout << "Job # " << tempJob.getId() << "is DeQueued with: " << (jobs.front()).getremaining() << " seconds remaining." << endl;//takes the first job in, off the queue
		cout << "\nJob # " << tempJob.getId() << " -- " << tempJob.getType() << " -- is now in the CPU" << endl;//states the jobs type and puts it into the CPU for processing
		cout << "Total " << (jobs.front()).getTotal() << endl;//states the jobs initial total


		if ((jobs.front()).getremaining()>timeSlice)//checks if the job will need to be re-added to the queue after processing in the CPU
		{
			(tempJob).setRemaining(((tempJob).getremaining())-timeSlice);//Jobs time remaining is greater than the time slice, so its time is reduced by the time slice
			TIMEUSED = TIMEUSED + timeSlice;//the time used in this CPU process (timeslice) is added to the total run time
			cout << "\nJob # " << tempJob.getId() << "leaves the CPU with: " << (tempJob).getremaining() << " seconds left." << endl; //states how much time is left as job leaves the CPU
			cout << "\nCPU time used so far: " << TIMEUSED << endl;
			cout << "assignment is enqueued again." << endl;//tells user that the job is being added to the end of the queue again
			//cout << "Total " << (tempJob).getTotal() << endl;

			jobs.push(tempJob);//pushes job to the end of the fifo queue
			jobs.pop();//pops the job off the begining of the queue

		}//end if

		else//If this runs, the jobs remaining time must be LESS than the timeslice, so therefore there will be idle time.
		{
			double idleTime;	//declare a variable to hold how long the computer idled for
			(tempJob).setRemaining(timeSlice-(tempJob).getremaining());//temporarily makes the jobs remaining time the time spent idling
			idleTime = (tempJob).getremaining();//sets the idle time based on the timeslice-remaining time
			TIMEUSED = TIMEUSED + timeSlice;//adds the total time 
			cout << "Job # " << tempJob.getId() << "is DeQueued with less than " << timeSlice << " seconds remaining and: " << tempJob.getremaining() << " seconds idled." << endl;
			cout << "\nJob # " << tempJob.getId() << " -- " << tempJob.getType() << " -- is now in the CPU" << endl;//adds the job to the CPU for its last time
			cout << "Job # " << tempJob.getId() << " didnt use all the timeslice. The idle time is: " << idleTime << endl;
			cout << "\n0 time remaining with: " << TIMEUSED << " CPU time used so far." << endl;// prints out that the job is done and has used some amount of CPU time
			//cout << "Total " << (tempJob).getTotal() << endl;

			jobs.pop();//ONLY pops the job, and doesnt add it to the queue again. It is gone forever

		}//end else

	}//end while


	return 0;//allows int main to close
}// end main