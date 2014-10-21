#include <iostream>	// need for console and keyboard
#include <fstream>	// need for file streams
#include <ctime>


using namespace std;

const char DELIMITER = ',';    // comma-separated-values (.csv)

// ======================================================
//  good example for open files for READING and WRITING
// ======================================================
int main()
{
	string inFile;			// filename to open and search
	ifstream fin;			// stream to connect to input file
	
	
	// ----------------------------------
	inFile = "story.txt";
	
	fin.clear();
	fin.open( inFile.c_str() );		// try to open the file	
	if ( fin.fail() )				// but did the attempt fail?
	{
		cout << "ERROR: file called " << inFile << " did NOT open." << endl;
		exit(-1);
	} // if
	
	// ----------------------------------
	string outFile = inFile + ".csv";
	ofstream fout;                  // stream to connect to output file
	
	fout.open( outFile.c_str() );		
	
	if ( fout.fail() )				// but did the attempt to open fail?
	{
		cout << "ERROR: file called " << outFile << " did NOT open." << endl;
		exit(-1);
	} // if
	
	
	// files opened OK .... time to read the story
	
	string line;
	short  lineNumber=1;
	
	// read lines of the story until End Of File (EOF)
	getline(fin, line);
	while (fin)
	{
		short lineLength;
		lineLength = line.length();
		
		
		fout << lineNumber << DELIMITER << lineLength << endl;
		lineNumber++;
		
        // grab next line
		getline(fin, line);
	} // while not EOF
	
	fin.close();
	fout.close();
	
	
	return 1;
	
}

