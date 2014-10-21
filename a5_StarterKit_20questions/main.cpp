//main 
#include <iostream>
#include <ctype.h>
#include "Tree.h"
#include "Node.h"

using namespace std;

bool didtheysayyes(string text); // prototyping a function I will use later on to get user input. 


int main()
{
	char answer;
	cout << "Welcome to 20 Questions!\n" << endl;

	Tree T("Is it an animal", "Horse", "Ball"); 	//initialize with a starting question, goes to the ctor that takes three inputs
	Node *currP; 	//create a pointer to the node branch of the tree
	currP = T.GetRoot();	//make two roots branching from the node. 
	string text = currP->GetText();		//create 

	int i = 3; //number of times you want it to run. for this example I have it set manually to 3 for the 3-5 times


  	string Answer;

	for (i; i>0; i--)
	{

		bool outcome = didtheysayyes(text); //checks what the users input is for the first question
		
		if (outcome) //if the object the user is thinking of IS an animal, it will follow this side
		{
			cout << "are thinking of a " << (currP->LChild())->GetText() << " ??? (y/n)" << endl;//asks the user the node question.
			cin >> answer;
			if (answer == 'y')
			{
				cout << "Congratulations to me! I won!" << endl;
				cout << "You were thinking of: " << Answer << endl;
			}
			else
			{
				cout << "I guess I didnt guess right this time. " << endl;
				
				cout << "Please tell me a question that is true for your object, and wrong for " << (currP->LChild())->GetText() << endl; 
  				string Question;	
  				cin.get();
  				cout << "Enter your question here: " ;
  				getline(cin, Question);						//gets an updated question from the user to use in the game.
  				cout << "What were you thinking of: " << endl;
  				cin >> Answer;
  				(currP->LChild())->StoreText(Question); //appends the new question to the tree so it will be asked. 
  				

			}

		}
		else	//if the object the user was thinking of IS NOT an animal it will follow this thread. 
		{
			cout << "are thinking of a " << (currP->RChild())->GetText() << " ??? (y/n)" << endl;
			cin >> answer;
			if (answer == 'y')
			{
				cout << "Congratulations to me! I won!" << endl;
				cout << "Your object must be a: " << Answer endl;
			}
			else
			{
				cout << "I guess I didnt guess right this time. " << endl;
				cout << "Please tell me a question that is true for your object, and wrong for " << (currP->RChild())->GetText() << endl; 
				string Question;	
  				cin.get();
  				cout << "Enter your question here: " ;
  				getline(cin, Question); //gets an updated question from the user to use in the game.
  				string Answer;
  				cout << "What were you thinking of: " << endl;
  				cin >> Answer;
  				(currP->RChild())->StoreText(Question); //appends the new question to the tree so it will be asked. 
			}

		}
	}

	return 0;
}

bool didtheysayyes(string question) //This function takes in the question, and lets the user type y/n in response, 
{									//and returns a boolean value response
	bool outcome;
	char answer;
	
	
	cout << "answer the question: " << question << ", with a y/n : \n" << endl;
	cin >> answer;
	answer = tolower(answer);//makes it possible for the user to type caps inputs too, and the program will still read it.


	if (answer == 'y')
	{
		outcome = true;

	}
	else 

	{

		outcome = false;

	}
	return outcome;

}