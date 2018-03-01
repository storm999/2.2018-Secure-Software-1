#include "OverFlowChecker.h"
using namespace std;

OverFlowChecker::OverFlowChecker()
{
}

OverFlowChecker::~OverFlowChecker()
{
}

int16_t OverFlowChecker::secureAddition(int16_t num1, int16_t num2)
{	
	int16_t result;
	if (	((num2 > 0) && (num1 > (INT16_MAX - num2))) ||	((num2 < 0) && (num1 < (INT16_MIN - num2)))		)
	{
		return NULL;
	}
	else 
	{
		cout << "Overflow!";
		result = num1 + num2;
		return result;
	}
}

int16_t OverFlowChecker::secureSubtraction(int16_t numberToBeSubtractedFrom, int16_t subtrahend)
{
	int16_t result;
	if (((subtrahend > 0) && (numberToBeSubtractedFrom > (INT16_MAX + subtrahend))) || ((subtrahend < 0) && (numberToBeSubtractedFrom < (INT16_MIN + subtrahend))))
	{
		cout << "Overflow!";
		return NULL;
	}
	else
	{
		result = numberToBeSubtractedFrom - subtrahend;
		return result;
	}
}

int16_t OverFlowChecker::secureMultiplication(double num1, double num2)
{
	double result  = num1 * num2;
	int16_t resultValidator;
	
	if(num1 == 0)
	{ 
		return 0;
	}
	else
	{
		if (num2 < num1)
		{
			resultValidator = (int16_t)(result / num2);
		}
		else
		{
			resultValidator = (int16_t)(result / num1);
		}
	}
	
	//result is validated with error margin 1
	if ( (resultValidator - (int16_t) num1) > 1 || (resultValidator - (int16_t)num1) < -1 )
	{
		cout << "Overflow or bad result";
		return NULL;
	}
	else
	{
		return (int16_t) result;
	}
}