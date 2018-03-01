#pragma once
#include "SecureInput.h" 
#include <string>
#include <iostream> 
#include "Logger.h" 


class LoggerFactory
{
public:
	Logger* selectLogger();
};

