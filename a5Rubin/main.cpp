//main 
#include <iostream>
#include <ctype.h>
#include "Tree.h"
#include "Node.h"

using namespace std;

bool didtheysayyes(string text);


int main()
{
	int i;
	char answer;
	cout << "Welcome to 20 Questions!\n" << endl;
	cout << "How many times do you want to simmulate the training of the 20Questions game? \n" << endl; //prompts user for how many times they want to play. 
	cin >> i; //number of times you will run the game


	Tree T("Is it an animal", "Horse", "Ball"); 	//initialize with a starting question, goes to the ctor that takes three inputs
	Node *currP; 	//create a pointer to the node branch of the tree
	currP = T.GetRoot();	//make two roots branching from the node. 
	string text = currP->GetText();		//create 



  	string Answer;

	for (i; i>0; i--)
	{

		bool outcome = didtheysayyes(text);
		
		if (outcome)
		{
			cout << "are thinking of a " << (currP->LChild())->GetText() << " ??? (y/n)" << endl;
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
  				getline(cin, Question);
  				cout << "What were you thinking of: " << endl;
  				cin >> Answer;
  				(currP->LChild())->StoreText(Question);
  				

			}

		}
		else
		{
			cout << "are thinking of a " << (currP->RChild())->GetText() << " ??? (y/n)" << endl;
			cin >> answer;
			if (answer == 'y')
			{
				cout << "Congratulations to me! I won!" << endl;
				cout << "Your object must be a: " << Answer << endl;
			}
			else
			{
				cout << "I guess I didnt guess right this time. " << endl;
				cout << "Please tell me a question that is true for your object, and wrong for " << (currP->RChild())->GetText() << endl; 
				string Question;	
  				cin.get();
  				cout << "Enter your question here: " ;
  				getline(cin, Question);
  				string Answer;
  				cout << "What were you thinking of: " << endl;
  				cin >> Answer;
  				(currP->RChild())->StoreText(Question);
			}

		}
	}

	return 0;
}

bool didtheysayyes(string question)
{
	bool outcome;
	char answer;
	
	
	cout << "answer the question: " << question << ", with a y/n : \n" << endl;
	cin >> answer;
	answer = tolower(answer);


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