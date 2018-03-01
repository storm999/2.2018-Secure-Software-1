#include <iostream>
#include <fstream>
#include <string.h>
#include <bitset>
#include "BinFileLogger.h" 
using namespace std;


void BinFileLogger::log(string logMessage) 
{
	ofstream writeLogs("BinLogs.txt", ios::app);
	
	// If output file couldnt be opened 
	if (!writeLogs)
	{
		cerr << "logs.txt could not be opened for writing!" << endl;
		exit(1);
	}

	for (size_t i = 0; i < logMessage.size(); ++i)
	{
		writeLogs << bitset<8>(logMessage.c_str()[i]) << endl;
	}
	
	writeLogs.close();
}



