#pragma once
#include "users.h"
#include "userRights.h"
#include <iostream>
#include <vector>

class manager : public users
{
private:

public:
	manager(string, string, uint8_t);
	~manager();
	void printIntro();
	void printUserRights();
};

