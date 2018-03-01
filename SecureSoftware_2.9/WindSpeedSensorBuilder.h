#pragma once
#include "windSpeedSensor.h"

class windSpeedSensor::windSpeedSensorBuilder : sensor::sensorBuilder
{
public:
	windSpeedSensorBuilder(sensor rawSensor);
	~windSpeedSensorBuilder();
	windSpeedSensorBuilder& setWindSpeed(int16_t);
	windSpeedSensor* build();

private:
	int16_t windSpeed;
	sensor tempRawSensor;
};

