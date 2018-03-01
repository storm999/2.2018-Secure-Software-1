#pragma once
#include "users.h"
#include "userRights.h"
#include <iostream>
#include <vector>

class admin : public users
{
private:

public:
	admin(string,string, uint8_t);
	~admin();
	void printIntro();
	void printUserRights();
};
