#include <iostream>
#include <string.h>
#include "main.h"
using namespace std;

int main() {
	char s[99];
	strcpy(s, "icecr");
	short L;
	short P;
	L = myStrLen(s);
	P = myStrLenP(s);
	char oldCopy[20], newCopy[20];
	strcpy(oldCopy, "afeaeiwhf");
	myStrCpy(newCopy, oldCopy);
	myStrCpyP(newCopy, oldCopy);
}

short myStrLen(char s[]) {
	short size = 0;
	
	for (int i=0; s[i]!='\0';i++)
	{
		size++;
	}

	cout << "String size is: " << size << endl;
	return size;
}

short myStrLenP(char *ps) {
	short size = 0;

	while (*ps != '\0')
	{
		size++;
		ps++;
	}

	cout << "PString size is: " << size << endl;
	return size;
}

void myStrCpy( char to[], char from[] )
{
	cout << "got into myStrCpy():\t";
	short i = 0;
		
	for (i=0; to[i] = from[i]; i++)
		;
						// while (from[i] != '\0')
						// {
						// 	to[i] = from[i];
						// 	i++;
						// }
	to[i] = '\0';
	
	for (i = 0; to[i] != '\0'; i++)
	{
		cout << to[i];
	}
	cout << endl;
}

void myStrCpyP( char *pTo, char *pFrom )
{
	cout << "got into myStrCpyP():\t";
	short i = 0;
	while (pFrom[i] != '\0')
	{
		pTo[i] = pFrom[i];
		i++;
	}
	pTo[i] = '\0';
	for (i = 0; pTo[i] != '\0'; i++)
	{
		cout << pTo[i];
	}
	cout << endl;
}