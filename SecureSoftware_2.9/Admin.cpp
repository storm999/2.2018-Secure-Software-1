#include "Admin.h"

admin::admin(string name, string pass, uint8_t type) : users(name, pass, type)
{
}

admin::~admin()
{
}

void admin::printIntro()
{
	cout << endl << "Logged in as admin" << endl;
	cout << "What do you want to do?" << endl;
}

void admin::printUserRights()
{
	userRights rights;
	cout << endl;
	for (uint16_t i = 0; i < rights.get1stLevelRights().size(); i++)
	{
		cout << "Type " << (i + 1) << " to " << rights.get1stLevelRights()[i] << endl;
	}
	for (uint16_t i = 0; i < rights.get2ndLevelRights().size(); i++)
	{
		cout << "Type " << (i + 11) << " to " << rights.get2ndLevelRights()[i] << endl;
	}
	for (uint16_t i = 0; i < rights.get3rdLevelRights().size(); i++)
	{
		cout << "Type " << (i + 21) << " to " << rights.get3rdLevelRights()[i] << endl;
	}
}
