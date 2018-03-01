#include "windSpeedSensor.h"

windSpeedSensor::windSpeedSensor(int16_t newSpeed, string newName, int16_t intVol, int16_t intTempe, uint8_t state) : sensor(newName, intVol, intTempe, state)
{
	speed = newSpeed;
}

windSpeedSensor::~windSpeedSensor()
{
}

int16_t windSpeedSensor::getValueOfSensor()
{
	return speed;
}

void windSpeedSensor::setValueOfSensor(int16_t newSpeed)	//•	state of 1 sensor changeable
{
	if (newSpeed > 115)
	{
		changeStateOfSensor(3);
	}
	else
	speed = newSpeed;
}

string windSpeedSensor::getValueString()
{
	return "Value: " + to_string(getValueOfSensor()) + " " + getMeasurementUnit() + "\n";

}

void windSpeedSensor::randomizeValueOfSensor()
{
	unsigned int randomizer = (unsigned int)time(NULL);
	srand(randomizer);
	setValueOfSensor(rand() % 20 + 100);
}


string windSpeedSensor::getMeasurementUnit()
{ 
	return "millibar"; 
}