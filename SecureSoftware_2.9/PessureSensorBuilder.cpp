#include "pressureSensorBuilder.h"

pressureSensor::pressureSensorBuilder::pressureSensorBuilder(sensor rawSensor)
{
	tempRawSensor = rawSensor;
}

pressureSensor::pressureSensorBuilder::~pressureSensorBuilder()
{
}

pressureSensor::pressureSensorBuilder& pressureSensor::pressureSensorBuilder::setPressure(int16_t Pressure, int16_t newHeight)
{ 
	this->pressure = Pressure; 
	this->height = newHeight;
	return *this;
}

pressureSensor* pressureSensor::pressureSensorBuilder::build()
{
	return new pressureSensor(this->pressure, tempRawSensor.getSensorName(), tempRawSensor.getInternalVoltage(), tempRawSensor.getInternalTemperaure(), tempRawSensor.getStateOfSensor());
}