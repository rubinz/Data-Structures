#include <iostream>
#include <fstream>
#include "MyCharStack.cpp"

using namespace std;


int main()
{
	ifstream FIN;
	string line;
	FIN.open("test2.cpp");

	MyCharStack S;
	bool okayLine = true;

	if (FIN.is_open())
	{
		cout << "YES OPEN" << endl;
		while (getline(FIN, line))
		{
			cout << "    " << line << endl;
		
		    // if (!S.IsFull())
		    // {
		    	for (short digit=0; digit <= line.length(); digit++)
		    	{
		    		switch (line[digit]) 
		    		{
		    			case '(':
		    				if (!S.IsFull())
		    				{
		    					S.Push(line[digit]);
		    				}
		    				else
		    				{
		    					// cout << "Missing Right Paren ')' : " << line << endl;
								okayLine = false;
		    				}
		    				break;

		    			case ')':
							
							if (!S.IsEmpty())
		    				{
		    					S.Pop();

		    				}
		    				else
		    				{
		    					cout << "Missing Left Paren '(' : " << line << endl;
		    					okayLine = false;
		    				}
		    				break;

		    			default:
		    				break;

		    		}


		    	}

		    	if (!S.IsEmpty())
		    	{
		    		cout << "Missing Right Parenth ')' :" << endl; 
				}
		    	
				
				// if (okayLine == true)
				// {
				// 	cout << "Ok" << line << endl;
				// }

		    	while (!S.IsEmpty())
		    	{
		    		S.Pop();
		    	}
		    	// getline(FIN, line);

		     //    S.Push('X');
		    	// char c;
		    	// c = S.Top();
		    	// cout << "I just popped an: " << c << endl;
		    	// S.Pop();
			// }
		}



		FIN.close();
	}


	
	else
	{
		cout << "not open" << endl;
	}
	return 0;

}