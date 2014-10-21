#include <iostream>
#include <queue>
using namespace std;

//need methods

//example of a cue:

char one, two;
queue<char> Q1;
queue<char> Q2;
//assert: Q1 = (D, B, C) and Q2 == (O, G)

one = Q1.front();
Q1.pop();

while (!Q1.empty())
{
	Q1.pop();

} //at the end of the while, Q1 is empty
Q1.push(one);
while (!Q2.empty())
{
	char next;
	next = Q2.front();
	Q2.pop();
	Q1.push(next);
	
}






//its going to need public:

//its goign to need private: