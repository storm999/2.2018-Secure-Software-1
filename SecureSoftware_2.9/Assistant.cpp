#include "assistant.h"



assistant::assistant(string name, string pass, uint8_t type) : users(name, pass, type)
{
}


assistant::~assistant()
{
}

void assistant::printIntro()
{
	cout << endl << "Logged in as assistant" << endl;
	cout << "What do you want to do?" << endl;
}

void assistant::printUserRights()
{
	userRights rights;
	cout << endl;
	for (uint16_t i = 0; i < rights.get1stLevelRights().size(); i++)
	{
		cout << "Type " << (i + 1) << " to " << rights.get1stLevelRights()[i] << endl;
	}
}