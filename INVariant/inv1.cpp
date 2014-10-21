// ============ insert this code inside main() ==============

#include <iostream>
#include <cassert>
#include <limits>

using namespace std;


const char BEEP = char(7);

int main()
{

	short i,sum, N;
	cout << "Enter a value for N: ";
	cin >> N;

	i = 0;
	sum = 0;
	//cout << LONG_MAX << " " << SHRT_MAX << endl;

	assert(N < 256);


	while(i < (N+1))       // INV: sum == 0 + 1 + 2 + ... + (i-1)  &&  1 <= i <= N+1
	{
		sum = i + sum;
		i++;
	
		cout << "sum: " << sum << endl;
		cout << "i: " << i << endl;

		
		
	}

	// you may NOT change this assertion
	assert(sum == N/2.0*(N+1)  && i == N+1);

	// if assert doesn't work  :(
	// then uncomment the following:
	
	if (! (sum == N/2.0*(N+1)  && i == N+1)  )
	{
		cout << "ASSERT FAILED!" << endl;
	    //system("PAUSE");
	    exit(-1);
	}
	


	cout << "\n\n**** sum is " << sum << endl;

}
