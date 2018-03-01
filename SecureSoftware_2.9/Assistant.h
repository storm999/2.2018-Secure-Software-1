#pragma once
#include "users.h"
#include "userRights.h"
#include <iostream>
#include <vector>

class assistant : public users
{
private:

public:
	assistant(string, string, uint8_t);
	~assistant();
	void printIntro();
	void printUserRights();
};

