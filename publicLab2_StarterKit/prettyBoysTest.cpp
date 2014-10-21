#include <iostream>
//#include <stdio.h>
using namespace std;

double input, total = 0, times = 0, average = 0;


int main(void)
{
	while (input >= 0)
	{
		cout << "Enter the number of boys you are friends with : ";

		cin >> input;
		if (input >= 0)
		{
			total = total + input;
			times++;
		}

	}  
	
	average = total/times;
	cout << "total boys seen : " << total << "\n" << endl;
	cout << "total times input : " << (times) << "\n" << endl;
	printf("average boys friends with : %5.2f \n", average);
}