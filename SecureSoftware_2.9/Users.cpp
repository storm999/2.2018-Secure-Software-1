#include "users.h"
#include <iostream>
#include "admin.h"
#include "manager.h"
#include "assistant.h"
#include "secureInput.h"

users::users()
{
	users* admin1 = new admin("ad", "ad", 1);
	users* manager1 = new manager("m", "m", 2);
	users* assistant1 = new assistant("as", "as", 3);	//predefined users

	usersList.push_back(admin1);
	usersList.push_back(manager1);
	usersList.push_back(assistant1);
}

users::users(string name, string pass, uint8_t type)
{
	userName = name;
	userPass = pass;
	userType = type;
}

void users::setUserName(string name)
{
	userName = name;
}
string users::getUserName()
{
	return userName;
}
void users::setUserPass(string pass)
{
	userPass = pass;
}
string users::getUserPass()
{
	return userPass;
}

uint8_t users::getUserType()
{
	return userType;
}
void users::setUserType(uint8_t newType)
{
	userType = newType;
}
void users::printIntro()
{
	cout << "Seems you logged as an invalid user type!" << endl;
}

void users::printUserRights()
{
	cout << "Seems you no right to be here!" << endl;
}

users* users::logIn()
{
	secureInput secureInput;
	bool tryLog = false;
	string userNameToCheck = "", pass = "";

	while (tryLog == false)
	{		
		cout << "Enter your credentials " << endl << "User Name";
		userNameToCheck = secureInput.readStringFromUser();
		
		cout << "Password";
		pass = secureInput.readStringFromUser();

		for (uint16_t i = 0; i < usersList.size(); i++)
		{
			if (userNameToCheck == usersList[i]->getUserName() && pass == usersList[i]->getUserPass())
			{
				tryLog = true;
				return usersList[i];
			}
		}
		if (!tryLog)
			cout << endl << "Wrong user name or password, try again." << endl << endl;
	}
	return NULL;
}


void users::addNewUser()
{
	secureInput secureInput;
	string name = "";
	string pass = "";
	uint8_t type;

	cout << endl << "Enter name of new user";
	name = secureInput.readStringFromUser();

	cout << "Enter pass of new user";
	pass = secureInput.readStringFromUser();

	cout << "Enter autorisation type of new user (1 admin, 2 manager, 3 assistant): ";
	do {
		type = secureInput.readShortFromUser();

		if (type > 3 || type < 1)
		{
			cout << "Invalid user type, try again: ";
		}
	} while (type > 3 || type < 1);

	if (type == 1)
	{
		usersList.push_back(new admin(name, pass, 1));
	}
	else if (type == 2)
	{
		usersList.push_back(new manager(name, pass, 2));
	}
	else if (type == 3)
	{
		usersList.push_back(new assistant(name, pass, 3));
	}
}

void users::listUsers()
{
	cout << endl << "List of users: " << endl;
	for (uint16_t i = 0; i < usersList.size(); i++)
	{
		cout << endl << "User " << i + 1 << endl;
		cout << "Name: " << usersList[i]->getUserName() << endl;
		if (usersList[i]->getUserType() == 1)
			cout << "Type: Admin" << endl;
		else if (usersList[i]->getUserType() == 2)
			cout << "Type: Manager" << endl;
		else if (usersList[i]->getUserType() == 3)
			cout << "Type: Assistant" << endl;
	}
}

void users::deleteUser()
{
	secureInput secureInput;
	listUsers();
	bool found = false;
	string name = "";
	string yesNo = "";
	cout << endl << "Enter name of the user you want to delete";
	do
	{
		name = secureInput.readStringFromUser();

		if (name == currentUser->getUserName())
		{
			cout << "You can not delete yourself" << endl;
			cout << "Do you want to enter another name? Y/N" << endl;

			do
			{
				yesNo = secureInput.readStringFromUser();
				if ((yesNo != "n") && (yesNo != "N") && (yesNo != "Y") && (yesNo != "y"))
				{
					cout << "Invalid input, Y/N: ";
				}
			} while ((yesNo != "n") && (yesNo != "N") && (yesNo != "Y") && (yesNo != "y"));

			if (yesNo == "n" || yesNo == "N")
			{
				cout << "No changes have done." << endl;
				return;
			}
			else if (yesNo == "y" || yesNo == "Y")
			{
				cout << "try again :" << endl;
			}
		}
	} while (yesNo == "y" || yesNo == "Y");

	uint16_t i = 0;		// UserList cant be bigger than uint64_t_MAX. flow check isnt needed.
	while (!found && i < usersList.size())
	{
		if (usersList[i]->getUserName() == name)
		{
			found = true;
			usersList.erase(usersList.begin() + i);
			cout << "User has been deleted;" << endl;
		}
		i++;
	}
	if (!found)
	{
		cout << "User not found" << endl;
	}

}

void users::changeAuthorisationOfUser()
{
	secureInput secureInput;
	listUsers();
	string name = "";
	cout << endl << "Enter name of the user you want to change type: ";
	bool isFound = false;
	do
	{
		uint16_t i = 0;		// UserList cant be bigger than uint16_t_MAX. flow check isnt needed.
		do
		{
			name = secureInput.readStringFromUser();

			while (!isFound && i < usersList.size())
			{
				if (usersList[i]->getUserName() == name)
				{
					if (usersList[i]->getUserName() == currentUser->getUserName())
					{
						cout << "You can not change your own authorisation type, try again: ";
						return;
					}
					isFound = true;
				}
				i++;
			}
		} while (!isFound && i < usersList.size());

		if (!isFound)
		{
			cout << "User name couldn't found, try again: ";
		}
	} while (!isFound);

	uint8_t aut;
	cout << "Enter new authorisation type (1 admin, 2 manager, 3 assistant)";
	do
	{
		aut = secureInput.readShortFromUser();
		if (aut > 3 || aut < 1)
		{
			cout << "Invalid autorisation type, try again (1 admin, 2 manager, 3 assistant) ";
		}
	} while (aut > 3 || aut < 1);

	for (uint16_t i = 0; i < usersList.size(); i++)
	{
		if (usersList[i]->getUserName() == name)
		{
			usersList[i]->setUserType(aut);
			cout << "Authorisation type of the user has been changed." << endl;
		}
	}
}
