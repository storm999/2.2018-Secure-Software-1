#include "secureInput.h"

using namespace std;


secureInput::secureInput()
{
}


secureInput::~secureInput()
{
}

//Input validation
uint8_t secureInput::readShortFromUser()
{
	unsigned short input;
	cout << endl << "Type the number:";
	while (!(cin >> input))
	{
		cout << "Invalid input, try again: ";
		cin.clear();
		cin.ignore(INT64_MAX, '\n');
	}
	uint8_t ret = (uint8_t)input;
	return ret;
}

string secureInput::readStringFromUser()
{
	string input = "";
	cout << endl << "Input:";
	while (!(cin >> input))
	{
		cout << "Invalid input, try again: ";
		cin.clear();
		cin.ignore(INT64_MAX, '\n');
	}
	return input;
}