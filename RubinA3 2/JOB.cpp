#include <iostream>	// need for console and keyboard
#include <fstream>	// need for file streams
#include <ctime>	//need for keeping track of time
#include "JOB.h"	//need for referances from main
#include <string>	//need for use of string type
#include <stdlib.h>	//need for use of the standard library
using namespace std;



JOB::JOB()	//declaring the object JOB()
{

	int typeOfJob = rand()%100+1;// generating a random number that will choose what jobtype a new job is

	if (typeOfJob < 20)
	{
		jobType = "print"; //assigns jobtype and total
		total = rand()%5+1; 
		id = 13;
	}
	else if (typeOfJob < 50)
	{
		jobType = "compile"; //assigns jobtype and total
		total = rand()%100+10; 
		id = 14;
	}
	else if (typeOfJob < 90)
	{
		jobType = "email"; //assigns jobtype and total
		total = rand()%20+3; 
		id = 15;
	}
	else {
		jobType = "other"; //assigns jobtype and total
		total = rand()%45+1; 
		id = 16;
	}

	remaining = total;//importnat, sets the remaining value to the total value initially. Remaining balue will decrease while total stays constant


}
string JOB::getName(/*out*/) //function to return the name of the jobs.front() value
{
	return name; //simply returns the name
}
string JOB::getType(/*out*/) //function that returns the type of the item in jobs.front()
{
	
	return jobType;
}
short JOB::getId(/*out*/) //gets the id of the job in jobs.front()
{
	return id;
}
double JOB::getTotal(/*out*/)//returns the total seconds value assigned to the job in jobs.front()
{
	return total;
}
double JOB::getremaining(/*out*/)//gets the remaining time for the job in jobs.front() as it goes through the CPU
{
	return remaining;
}
void JOB::setRemaining(/*in*/ double newT)// sets a new time for jobs.front(). Must take in a new value and returns nothing.
{
	remaining = newT;//takes in the value for the new remaining and sets it to the old remaining. Usually it will be setremaining = remaining-timeslice
}

// JOB::~JOB() {
// 	//deconstructor
// }
