#pragma once
#include "sensor.h"
#include <time.h> 

class windSpeedSensor : public sensor
{
private:
	int16_t speed=-1;
public:
	class windSpeedSensorBuilder;
	windSpeedSensor(int16_t, string, int16_t, int16_t, uint8_t);
	~windSpeedSensor();

	int16_t getValueOfSensor();
	void setValueOfSensor(int16_t newValue);
	void setValueOfSensor(int16_t, int16_t) {}
	string getValueString();
	void randomizeValueOfSensor();
	string getMeasurementUnit();
};

