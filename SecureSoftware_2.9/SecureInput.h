#pragma once
#include <string>
#include <iostream>
using namespace std;

class secureInput
{
	public:
		secureInput();
		~secureInput();

		string readStringFromUser();
		uint8_t readShortFromUser();
};
