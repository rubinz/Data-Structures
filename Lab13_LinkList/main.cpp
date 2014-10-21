#include "eList.h"
#include <iostream>
	// #include <string>
// #include <string.h>
using namespace std;

// anElephant* create(void);
// anElephant* create(string newName);
void createNode();
void createNode(string name);
void createNode(string name, int age);



int main()
{
	anElephant *head, *one, *two, *three, *temp;

	head = new anElephant;
	head->name = "buffer";

	one = new anElephant;
	one-> name = "Elmer";
	head-> next = one;

	two = new anElephant;
	two-> name = "Edna";
	one-> next = two;

	three = new anElephant;
	three-> name = "Eloise";
	two-> next = three;

	
	temp = head->next;
	while (temp != 0)
	{
		cout << temp->name << endl;
		temp = temp->next;
	}

	anElephant *temporary;
	temporary = createNode("elmer", 13); 
}

void createNode()
{
	
	temp = new anElephant;
	temp->name = "test";
	temp->age = 13;
	temp->next = 0;
	// return temp;

}

void createNode(string name)
{
	string Ename;
	temp = new anElephant;
	temp->name = Ename;
	temp->age = 13;
	temp->next = 0;
	// return temp;

}

void createNode(string name, int age)
{
	string Ename;
	short age;
	temp = new anElephant;
	temp->name = Ename;
	temp->age = age;
	temp->next = 0;
	// return temp;

}

