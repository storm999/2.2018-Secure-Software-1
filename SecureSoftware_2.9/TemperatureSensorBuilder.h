#pragma once
#include "temperatureSensor.h"

class temperatureSensor::temperatureSensorBuilder : sensor::sensorBuilder
{
public:
	temperatureSensorBuilder(sensor rawSensor);
	~temperatureSensorBuilder();
private:
	int16_t temperature;
	sensor tempRawSensor;
public:

	temperatureSensorBuilder& setTemperature(int16_t);

	temperatureSensor* build();
};

