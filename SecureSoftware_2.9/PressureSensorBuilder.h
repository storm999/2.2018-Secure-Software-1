#pragma once
#include "pressureSensor.h"

class pressureSensor::pressureSensorBuilder : sensor::sensorBuilder
{
public:
	pressureSensorBuilder(sensor rawSensor);
	~pressureSensorBuilder();
	pressureSensorBuilder& setPressure(int16_t, int16_t);
	pressureSensor* build();

private:
	int16_t pressure;
	int16_t height;
	sensor tempRawSensor;
};

