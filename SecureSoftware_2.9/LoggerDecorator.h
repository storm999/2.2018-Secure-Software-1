#pragma once
#include "Logger.h" 
using namespace std;

class LoggerDecorator : public Logger {
	Logger * logger;
protected:
	void log(string msg);
public:
	LoggerDecorator(Logger * logger);

};

