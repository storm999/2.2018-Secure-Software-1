#pragma once
using namespace std;

#include <vector>
#include "sensor.h"
#include "temperatureSensor.h"
#include "temperatureSensorBuilder.h"
#include "pressureSensor.h"
#include "pressureSensorBuilder.h"
#include "windSpeedSensor.h"
#include "windSpeedSensorBuilder.h"
#include <iostream>
#include <stdlib.h>     
#include <time.h> 
#include "Users.h"
#include "Admin.h"
#include "Manager.h"
#include "Assistant.h"
#include <time.h>
#include <sstream>
#include <fstream>
#include <string>
#include "SecureInput.h"
#include "Logger.h"
#include "LoggerFactory.h"

class device
{
	private:
		uint8_t stateOfDevice; // 0 switched off, 1 switched on, 2 suspended to prevend damage
		vector<sensor*> sensorList;
	
	public:
		device();
		~device();
		void setStateOfDevice(uint8_t);
		uint8_t getStateOfDevice();
		string createLogMessage();
		void printLogs();
		void listSensors();
		void run(users*);
		void randomizeValuesOfSensors();
		void getValuesOfSensors();
		void getIntVolOfSensors();
		void getIntTempOfSensors();
		void randomizeIntTempOfSensors();
		void changeIntVoltageOfaSensor();
		void changeStateOfaSensor();
};	

