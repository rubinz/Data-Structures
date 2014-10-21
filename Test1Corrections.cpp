#include <iostream>
using namespace std;
int INIT(double A[], short& hmr);
int getData(double A[], short& hmr);
int printData(double A[], short hmr);

const long MAX = 20000;
int main()
{
	
	double A[MAX];
	short hmr = 0;

	INIT(A, hmr);
	getData(A, hmr);
	printData(A, hmr);
	return 0;
}

int INIT(double A[], short& hmr)
{
	int i=0;
	while (i < MAX)
	{
		A[i] = 0;
		i++;
	}
	return 0;
}

int getData(double A[], short& hmr)
{
	int input;
	cout << "Enter a number: ";
	cin >> input;
	while (input >= 0)
	{ 	
		A[hmr] = input;
		hmr++;
		cout << "Enter another number: ";
		cin >> input;
	}

	return 0;
}

int printData(double A[], short hmr)
{
	int i = 0;
	while (i < hmr)
	{
		double output = A[i];
		cout << output << ", " << endl;
		i++;
	} 
	cout << "DONE" << endl;
}







