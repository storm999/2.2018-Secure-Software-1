#include "temperatureSensor.h"

temperatureSensor::temperatureSensor(int16_t newTempe, string newName, int16_t intVol, int16_t intTempe, uint8_t state) :sensor(newName, intVol, intTempe, state)
{
	temperature = newTempe;
}

temperatureSensor::~temperatureSensor()
{
}

int16_t temperatureSensor::getValueOfSensor()
{
	return temperature;
}

void temperatureSensor::setValueOfSensor(int16_t newTemperature)
{
	temperature = newTemperature;
}

string temperatureSensor::getValueString()
{
	return "Value: " + to_string(getValueOfSensor()) + " " + getMeasurementUnit() + "\n";
}

void temperatureSensor::randomizeValueOfSensor()
{
	unsigned int randomizer = (unsigned int)time(NULL);
	srand(randomizer);
	setValueOfSensor(rand() % 10 + 50);
}


string temperatureSensor::getMeasurementUnit() 
{ 
	return "m per second"; 
}
