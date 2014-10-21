#include <iostream>	// need for console and keyboard
#include <fstream>	// need for file streams
#include <ctime>
//#include <cstdlib>

using namespace std;
int main()
{
	srand(time(NULL));
	ofstream myfile;
	myfile.open ("example.csv");

	//myfile << "Write this to my text file" << endl;

	myfile << "\niteration, " << "\t" << "random#," << "\t" << "Written Number\n" << endl;

	for (int i=0; i<100; i++)
	{
		int iteration = i+1;
		int randomNumber = rand() % 5 +1;

		myfile << iteration << "," << randomNumber << "," ;

		switch(randomNumber)
		{
			case (1): myfile << "One,\n" ;
				break;
			case (2): myfile << "Two,\n" ;
				break;
			case (3): myfile << "Three,\n" ;
				break;
			case (4): myfile << "Four,\n" ;
				break;
			case (5): myfile << "Five,\n" ;
				break;
			default:
				break;


		}



		


		//cout << "random number between 1 and 4 inclusing is: " << randomNumber << endl;

	}
	myfile.close();

	return 0;

}


