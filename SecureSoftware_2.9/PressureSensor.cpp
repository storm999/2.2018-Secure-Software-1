#include "pressureSensor.h"
#include "OverFlowChecker.h"


pressureSensor::pressureSensor(int16_t newPressure, string newName, int16_t intVol, int16_t intTempe, uint8_t state) : sensor(newName, intVol, intTempe, state)
{
	pressure = newPressure;
}


pressureSensor::~pressureSensor()
{
}

int16_t pressureSensor::getValueOfSensor()
{
	return (int16_t) pressure;
}

void pressureSensor::setValueOfSensor(int16_t newPressure, int16_t height)     //•	data processing of input from 1 sensor
{
	OverFlowChecker checker;
	int16_t processedHeight = (int16_t) checker.secureMultiplication(height , 0.005);
	pressure = checker.secureSubtraction(newPressure, processedHeight);  
}

string pressureSensor::getValueString()
{
	return "Value: " + to_string(getValueOfSensor()) + " " + getMeasurementUnit() + "\n";

}

void pressureSensor::randomizeValueOfSensor()
{
	unsigned int randomizer = (unsigned int)time(NULL);
	srand(randomizer);
	setValueOfSensor(rand() % 20 + 20, rand() % 1000);
}

string pressureSensor::getMeasurementUnit()
{
	return "celcius degree";
}