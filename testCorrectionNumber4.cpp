#include <iostream>
#include <string>

using namespace std;
int fill_dataBase();

struct studentInfo
{
	string Name;
	short Years;
	char ManWoman;
	short Number;

};

studentInfo allRecords[100]; //struct name 

studentInfo myInfo[1];
// struct studentInfo = foobar;


int main()
{

	int i = 0;

	string Name; 
	short Years;
	char ManWoman;
	short Number;
	cout << "Enter your first name: ";
	cin >> Name;
	cout << "Enter your age: ";
	cin >> Years;
	cout << "Enter your gender (m/f): ";
	cin >> ManWoman;
	cout << "Enter your ssn: ";
	cin >> Number;

	// myInfo[0] = foobar;

	// foobar.Name = Name;
	// foobar.Years = Years;
	// foobar.ManWoman = ManWoman;
	// foobar.Number = Number;

	myInfo[i].Name = Name;
	myInfo[1].Years = Years;
	myInfo[1].ManWoman = ManWoman;
	myInfo[1].Number = Number; 

	//printf("\nYour name is: ", myInfo[i].Name);
	printf("\nYour age is: ", myInfo[0].Years);
	printf("\nYour gender is: ", myInfo[0].ManWoman);
	printf("\nYour ssn is: ", myInfo[0].Number);

	// printf("\nYour age is: ", foobar[0].Years);
	// printf("\nYour gender is: ", foobar[0].ManWoman);
	// printf("\nYour ssn is: ", foobar[0].Number);
	fill_dataBase();
}

int fill_dataBase()
	{
		int i = 0;
		string Name;
		short Years;
		char ManWoman;
		short Number;

		cout << "Enter name: ";
		cin >> Name;
		while (Name != "Done")
		{
			cout << "Enter age: ";
			cin >> Years;
			cout << "Enter gender: ";
			cin >> ManWoman;
			cout << "Enter ssn: ";
			cin >> Number;


			allRecords[i].Name = Name;
			allRecords[i].Years = Years;
			allRecords[i].ManWoman = ManWoman;
			allRecords[i].Number = Number; 

			i++;
			cout << "Enter name: ";
			cin >> Name;

		}
		cout << "DONE" << endl;
	}








	