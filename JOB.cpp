#include <iostream>	// need for console and keyboard
#include <fstream>	// need for file streams
#include <ctime>
#include "JOB.h"
using namespace std;

JOB::JOB()
{
	string jobType;//put these in the job.h file
	short id;
	double total;
	double remaining;

	int typeOfJob = rand()%100+1;

	if (typeOfJob < 20){
		jobType = "print"; total = rand()%5+1; id = 13;}
	else if (typeOfJob > 50){
		jobType = "compile"; total = rand()%100+10; id = 14;}
	else if (typeOfJob > 90){
		jobType = "email"; total = rand()%20+3; id = 15;}
	else;{
		jobType = "other"; total = rand()%45+1; id = 16;}
}
string JOB::getName() 
{
	return name;
}
short JOB::getId()
{
	return id;
}
double JOB::getTotal()
{
	return total;
}
double JOB::getremaining()
{
	return remaining;
}
void JOB::setRemaining(double newT)
{
	remaining = newT;
}
void JOB::printEntireQ(cueue<JOB> Q) const
{
	//function here that will cycle through the cueue and print it
}
