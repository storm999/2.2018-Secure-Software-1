#include "windSpeedSensorBuilder.h"

windSpeedSensor::windSpeedSensorBuilder::windSpeedSensorBuilder(sensor rawSensor)
{
	tempRawSensor = rawSensor;
}

windSpeedSensor::windSpeedSensorBuilder::~windSpeedSensorBuilder()
{
}

windSpeedSensor::windSpeedSensorBuilder& windSpeedSensor::windSpeedSensorBuilder::setWindSpeed(int16_t windSpeed_)
{ 
	this->windSpeed = windSpeed_; 
	return *this;
}

windSpeedSensor* windSpeedSensor::windSpeedSensorBuilder::build()
{
	return new windSpeedSensor(this->windSpeed, tempRawSensor.getSensorName(), tempRawSensor.getInternalVoltage(), tempRawSensor.getInternalTemperaure(), tempRawSensor.getStateOfSensor());
}