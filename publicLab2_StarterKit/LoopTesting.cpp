#include <iostream>
using namespace std;

double times;

int main ()
{
    //for (int n=2; n>0; n--)
    cout << "Enter an interger number of times : ";
    cin >> times;
    double i = 0;
    while (i < times) 
    {
        cout << i << ", ";
	   cout << "Such a lovely place" << "\n" << endl;
	   ++i;
	}
	
	return 0;
}