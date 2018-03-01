#pragma once
#include <string>
#include <iostream>

using namespace std;

class sensor
{
	private:
		string name = "";
		int16_t internalVoltage= -1;
		int16_t internalTemperature = -1;
		uint8_t sensorState = 0;				//1 active , 2 inactive, 3 suspended etc.
	public: 
		class sensorBuilder;
		sensor() {}
		virtual ~sensor() {}
		sensor(string, int16_t, int16_t, uint8_t);
		string getSensorName();
		int16_t getInternalVoltage();
		bool setInternalVoltage(int16_t);
		int16_t getInternalTemperaure();
		void setIntTempOfSensor(int16_t);
		uint8_t getStateOfSensor();
		void changeStateOfSensor(uint8_t);

		virtual int16_t getValueOfSensor() { return -1; }
		virtual void setValueOfSensor(int16_t) {}
		virtual void setValueOfSensor(int16_t, int16_t) {}
		virtual string getValueString() { return "ERROR: getValueString()"; }
		virtual void randomizeValueOfSensor() {}
		virtual string getMeasurementUnit() { return "ERROR: getMeasurementUnit()"; }
		
	class sensorBuilder
	{
		public:
			sensorBuilder() {}
			~sensorBuilder() {}

		private:
			string name = "";
			int16_t internalVoltage = -1;
			int16_t internalTemperature = -1;
			uint8_t sensorState = 0;

		public:
			sensorBuilder& setSensorName(string); 
			sensorBuilder& setInternalVoltage(int16_t);
			sensorBuilder& setInternalTemperature(int16_t);
			sensorBuilder& setSensorState(uint8_t);

			sensor build();
	};
};

