#pragma once
#include "userRights.h"
#include <string>
#include <vector>

using namespace std;

 class users
{
	private:
		string userName = "";
		string userPass = "";
		uint8_t userType;				//1 admin, 2 manager, 3 assistant
		vector<string> usersRights = {"you have no right to be here!"};

	public:
		users();
		virtual ~users() {}
		users(string, string, uint8_t);
		
		users* currentUser = NULL;
		vector<users*> usersList;	//List of users registered to the system

		void setUserName(string);
		string getUserName();
		
		void setUserPass(string);
		string getUserPass();
		
		uint8_t getUserType();
		void setUserType(uint8_t);
		
		users* logIn();

		void addNewUser();
		void listUsers();
		void deleteUser();
		void changeAuthorisationOfUser();

		virtual void printIntro();
		virtual void printUserRights();
};
