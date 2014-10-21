#include <iostream>
using namespace std;

bool checkChar(char oneLetter); //declare all functions - this is function decleration/prototype

int main()
{
	bool answer;
	char c;
	cout << "Enter one charecter: "; //dont endl; and the curser will wait on this line.
	cin >> c;

	answer = checkChar(c);
	if (answer)
		cout  << "Yes you input ! or $ or #" << endl;
	else
		cout << "Not one of !, $, #" << endl;
}
/*
bool checkChar(char oneLetter)
{
	bool answer;
	//char oneLetter;
	if (oneLetter == '!' or oneLetter == '$' or oneLetter == '#')
		answer = true;
	else
		answer = false;
	return answer;
}
*/
/*
bool checkChar(char OL)
{
	bool answer;
	switch (OL)
	{
		case '$': 
			answer = true;
			break;
		case '!':
			answer = true;
			break;
		case '#':
			answer = true;
			break;
		default:
			answer = false;
	
	return answer
	;
	}
}
*/







