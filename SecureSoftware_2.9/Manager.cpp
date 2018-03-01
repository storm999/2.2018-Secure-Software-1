#include "manager.h" 

manager::manager(string name, string pass, uint8_t type) : users(name, pass, type)
{

}

manager::~manager()
{
}

void manager::printIntro()
{
	cout << endl << "Logged in as manager" << endl;
	cout << "What do you want to do?" << endl;
}

void manager::printUserRights()
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
}