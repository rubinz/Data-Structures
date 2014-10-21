
#include <iostream>
using namespace std;

int main(void)
{
    short year;	// user-entered year
    
    cout << "Enter an integer year >> ";
    cin  >> year;
    
    cout << endl;
    cout << "The year " << year;
    
    if ((year%4 == 0) && (year%100 != 0)) 
    {
        
        cout << " IS a leap year!!!" << endl;
    }
    else if (year%400 == 0)
        cout << " IS a leap year!!!" << endl;

    else
		cout << " is NOT a leap year." << endl;
	
	
	return 0;
	
}  // main