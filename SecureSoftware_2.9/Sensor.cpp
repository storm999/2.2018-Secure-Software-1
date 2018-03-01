#include "sensor.h"
#include "secureInput.h"

sensor::sensor(string newName, int16_t intVol, int16_t intTempe, uint8_t state)
{
	name = newName;
	internalVoltage= intVol;
	internalTemperature = intTempe;
	sensorState = state;	
}

string sensor::getSensorName()
{
	return name;
}

int16_t sensor::getInternalVoltage()
{
	return internalVoltage;
}

int16_t sensor::getInternalTemperaure()
{
	return internalTemperature;
}

void sensor::setIntTempOfSensor(int16_t newTemp)
{
	internalTemperature = newTemp;
}

uint8_t sensor::getStateOfSensor()
{
	return sensorState;
}

void sensor::changeStateOfSensor(uint8_t state)
{
	sensorState = state;
}

bool sensor::setInternalVoltage(int16_t newVol)
{
	secureInput secureInput;
	if (newVol > 50)
	{
		cout << "Sensor may damage because of high voltage, are you sure to continue? Y/N:";
		string yesNo = "";
		do 
		{
			yesNo = secureInput.readStringFromUser();
			if (yesNo != "n" && yesNo != "N" && yesNo != "Y" && yesNo != "y")
			{
				cout << "Invalid input, Y/N: ";
			}
		} while (yesNo != "n" && yesNo != "N" && yesNo != "Y" && yesNo != "y");
		
		if (yesNo == "y" || yesNo == "Y")
			return false;
		else if (yesNo == "n" || yesNo == "N")
		{
			cout << "Voltage hasn't been changed." << endl;
			return true;
		}
	}
	else if (newVol < 3)
	{
		cout << "Sensor may stop working because of low voltage, are you sure to continue? Y/N:";
		string yesNo ="";
		do
		{
			yesNo = secureInput.readStringFromUser();

			if ((yesNo != "n") && (yesNo != "N") && (yesNo != "Y") && (yesNo != "y"))
			{
				cout << "Invalid input, Y/N: ";
			}
		} while ((yesNo != "n") && (yesNo != "N") && (yesNo != "Y") && (yesNo != "y"));
		
		if (yesNo == "y" || yesNo == "Y")
			return false;
		else if (yesNo == "n" || yesNo == "N")
		{
			cout << "Voltage hasn't been changed." << endl;
			return true;
		}
	}
	else
	{
		internalVoltage = newVol;
		cout << "Voltage has been changed." << endl;
		return true;
	}
	return false;
}

sensor::sensorBuilder& sensor::sensorBuilder::setSensorName(const string name_) { this->name = name_; return *this; }
sensor::sensorBuilder& sensor::sensorBuilder::setInternalVoltage(const int16_t internalVoltage_) { this->internalVoltage = internalVoltage_; return *this; }
sensor::sensorBuilder& sensor::sensorBuilder::setInternalTemperature(const int16_t internalTemperature_) { this->internalTemperature = internalTemperature_; return *this; }
sensor::sensorBuilder& sensor::sensorBuilder::setSensorState(const uint8_t sensorState_) { this->sensorState = sensorState_; return *this; }

sensor sensor::sensorBuilder::build()
{
	return sensor(this->name, this->internalVoltage, this->internalTemperature, this->sensorState);
}