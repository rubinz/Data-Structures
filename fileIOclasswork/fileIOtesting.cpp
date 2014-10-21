#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){
	string inFile;
	ifstream fin;
	cout << "Enter the full name of an input file: " ;
	cin >> inFile;
	// inFile = "lifeGetsBetter.txt";

	fin.clear();
	fin.open( inFile.c_str());
	if (fin.fail())
	{
		cout << "ERROR: File Called " << inFile << " Could not be found " << endl;
		exit(-1); 
	}

	string outFile = inFile + ".xls";
	ofstream fout;
	fout.open( outFile.c_str() );

	if ( fout.fail())
	{
		cout << " ERROR: File called " << outFile << " failed to open " << endl;
		exit(-1);
	}

	string line, charecters;
	short lineNumber = 1;
	double numVol = 0;
	double charCount;
	double lineChar;
	string vowels = "aeiouAEIOU";
	double vowelNumber = 0;
	double mostChar = 0, mostVow = 0;


	getline(fin, line);


	fout << "Line" << "\t" << " Charecters" << "\t" << "Vowels" << "\t" << "What the line reads" << endl; 
	while(fin)
	{
		short lineLength;
		lineLength = line.length();



		string str (line);
		cout << "The size of this Line is: " << str.size() << " characters.\n";
		lineChar = str.size();
		charCount = charCount + str.size();
		if (str.size() > mostChar)
			mostChar = str.size();

		double vowelNumber = 0;

		for (short i = 0; i < lineLength; i++){
			for (short vowelI = 0; vowelI < vowels.length(); vowelI++){

				if (line[i] == vowels[vowelI]){

					vowelNumber++;
					
				}
			}


		}
		if (vowelNumber > mostVow)
			mostVow = vowelNumber;

		cout << "The number of vowels in this line is: " << vowelNumber << endl;

		fout << lineNumber << "\t" << lineChar  << "\t" << vowelNumber << "\t" << line << endl;

		
    	




		
		// int vowcnt=0;
		// for(int i=0;i<strlen[];i++);
		// {
		// if(line[i] == 'a' || line[i] == 'e'||line[i] == 'i'||line[i] == 'o'||line[i] == 'u')
		// {
		// 	vowcnt++;
		// 	return vowcnt;
		// }
		// }	
		// cout << "Vowel Count in this Line is: " << vowcnt << endl;

		lineNumber++;
		getline(fin, line);
	}

	fout << "Most Charecters: " << "\t" << mostChar << "\t" <<"Most vowels: " << "\t" << mostVow << endl;
	fin.close();
	fout.close();
	return 1;

}