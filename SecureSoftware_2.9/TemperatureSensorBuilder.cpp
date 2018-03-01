#include "temperatureSensorBuilder.h"

temperatureSensor::temperatureSensorBuilder::temperatureSensorBuilder(sensor rawSensor)
{
	tempRawSensor = rawSensor;
}


temperatureSensor::temperatureSensorBuilder::~temperatureSensorBuilder()
{
}

temperatureSensor::temperatureSensorBuilder& temperatureSensor::temperatureSensorBuilder::setTemperature(int16_t temperature_)
{ 
	this->temperature = temperature_; return *this; 
}

temperatureSensor* temperatureSensor::temperatureSensorBuilder::build() 
{
	return new temperatureSensor(this->temperature, tempRawSensor.getSensorName(), tempRawSensor.getInternalVoltage(), tempRawSensor.getInternalTemperaure(), tempRawSensor.getStateOfSensor());
}