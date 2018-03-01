#pragma once
#include <inttypes.h>
#include <iostream>

class OverFlowChecker
{
	public:
		OverFlowChecker();
		~OverFlowChecker();
		
		int16_t secureAddition(int16_t, int16_t);
		int16_t secureSubtraction(int16_t, int16_t);

		int16_t secureMultiplication(double, double);
};

