#include <iostream>
#include <fstream>
#include "TxtFileLogger.h" 
using namespace std;


void TxtFileLogger::log(string logMessage) 
{
	ofstream writeLogs("textLogs.txt", ios::app);

	// If output file couldnt be opened 
	if (!writeLogs)
	{
		cerr << "logs.txt could not be opened for writing!" << endl;
		exit(1);
	}

	writeLogs << logMessage;
	writeLogs.close();
}
