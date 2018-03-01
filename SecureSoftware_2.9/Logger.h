#pragma once
#include <string>
#include <iostream> 
using namespace std;

enum LoggerType { TEXT_FILE = 1, BIN_FILE = 2 };

class Logger
{
	unsigned formatType;
public:
	virtual void log(string logMessage) {}
};






