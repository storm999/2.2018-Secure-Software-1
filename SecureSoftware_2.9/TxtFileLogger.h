#pragma once
#include "Logger.h" 
using namespace std;

class TxtFileLogger : public Logger 
{
	public:
		void log(string logMessage);
};

