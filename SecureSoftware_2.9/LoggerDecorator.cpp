#include <iostream>
#include "LoggerDecorator.h" 
using namespace std;

LoggerDecorator::LoggerDecorator(Logger* newLogger) 
{
	logger = newLogger;
}

void LoggerDecorator::log(string logMessage)
{
	logger->log(logMessage);
}
