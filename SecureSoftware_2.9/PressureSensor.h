#pragma once
#include "sensor.h"
#include <time.h> 

class pressureSensor : public sensor
{
private:
	double pressure;

public:
	class pressureSensorBuilder;
	pressureSensor(int16_t, string, int16_t, int16_t, uint8_t);
	~pressureSensor();
	
	int16_t getValueOfSensor();
	void setValueOfSensor(int16_t) {}
	void setValueOfSensor(int16_t newPressure, int16_t height);
	string getValueString();
	void randomizeValueOfSensor();
	string getMeasurementUnit();
};

