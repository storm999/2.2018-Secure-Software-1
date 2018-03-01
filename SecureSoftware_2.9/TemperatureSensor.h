#pragma once
using namespace std;
#include "Sensor.h"
#include <time.h> 

class temperatureSensor : public sensor
{
private:
	int16_t temperature;
public:
	class temperatureSensorBuilder;
	temperatureSensor(int16_t, string, int16_t, int16_t, uint8_t);
	~temperatureSensor();

	int16_t getValueOfSensor();
	void setValueOfSensor(int16_t newValue);
	void setValueOfSensor(int16_t, int16_t) {}
	string getValueString();
	void randomizeValueOfSensor();
	string getMeasurementUnit();
};

