#include "Device.h"
using namespace std;

device::device()
{
	// builder design pattern
	temperatureSensor *tempeSen = temperatureSensor::temperatureSensorBuilder(	sensor::sensorBuilder()
																				.setSensorName("Temperature Sensor 1")
																				.setInternalVoltage(9)
																				.setInternalTemperature(40)
																				.setSensorState(1).build()		).setTemperature(25).build();
	
	pressureSensor *presSen = pressureSensor::pressureSensorBuilder(	sensor::sensorBuilder()
																		.setSensorName("Pressure Sensor 1")
																		.setInternalVoltage(12)
																		.setInternalTemperature(50)
																		.setSensorState(1).build()			).setPressure(55,500).build();
	
	windSpeedSensor *speedSen = windSpeedSensor::windSpeedSensorBuilder(	sensor::sensorBuilder()
																			.setSensorName("Wind Speed Sensor 1")
																			.setInternalVoltage(15)
																			.setInternalTemperature(60)
																			.setSensorState(1).build()		).setWindSpeed(60).build();
	
	sensorList.push_back(tempeSen);
	sensorList.push_back(presSen);
	sensorList.push_back(speedSen);
}

device::~device()
{
}

void device::setStateOfDevice(uint8_t state)
{
	stateOfDevice = state;
}

uint8_t device::getStateOfDevice()
{
	return stateOfDevice;
}

void device::run(users* userHandler)
{
	LoggerFactory logFactory = LoggerFactory();
	secureInput secureInput;
	Logger *logger = logFactory.selectLogger();
	
	bool logOff = false;
	uint8_t inValidCounter = 0;
	uint8_t process;

	while (getStateOfDevice() == 1 && !logOff)
	{
		randomizeValuesOfSensors();
		userHandler->currentUser->printUserRights();

		process = secureInput.readShortFromUser();
		if (userHandler->currentUser->getUserType() == 1 || 2 || 3)
		{
			switch (process)
			{
			case 1: listSensors();
				break;
			case 2: getValuesOfSensors();
				break;
			case 3: getIntVolOfSensors();
				break;
			case 4: getIntTempOfSensors();
				break;
			case 5: logOff = true;;
				break;
			default:
				inValidCounter++;
			}

			if (userHandler->currentUser->getUserType() == 1 || 2)
			{
				switch (process)
				{
				case 11:changeIntVoltageOfaSensor();
					break;
				case 12:changeStateOfaSensor();
					break;
				case 13: printLogs();
					break;
				default:
					inValidCounter++;
				}

				if (userHandler->currentUser->getUserType() == 1)
				{
					switch (process)
					{
					case 21: userHandler->addNewUser();
						break;
					case 22: userHandler->deleteUser();
						break;
					case 23: userHandler->changeAuthorisationOfUser();
						break;
					case 24:userHandler->listUsers();
						break;
					default:
						inValidCounter++;
					}
				}
			}
			logger->log(createLogMessage());
		}
		if (logOff)
		{
			cout << "You logged off successfully" << endl << endl;
			userHandler->currentUser = NULL;
			return;
		}

		if ((inValidCounter == 1 && userHandler->currentUser->getUserType() == 3) || (inValidCounter == 2 && userHandler->currentUser->getUserType() == 2) || (inValidCounter == 3 && userHandler->currentUser->getUserType() == 1))
			cout << "invalid input" << endl;
	}
	delete logger;
	return;
}

void device::listSensors()
{
	cout << "List of sensors:" << endl;
	for (uint16_t i = 0; i < sensorList.size(); i++)
	{
		string state = "";
		if (sensorList[i]->getStateOfSensor() == 1)
			state = "Active";
		else if (sensorList[i]->getStateOfSensor() == 2)
			state = "Inactive";
		else if (sensorList[i]->getStateOfSensor() == 3)
			state = "Suspended";
		cout << i+1 << ": "<< sensorList[i]->getSensorName() << " - " << state << endl;
	}
}

void device::randomizeValuesOfSensors()
{
	for (uint16_t i = 0; i < sensorList.size(); i++)
	{
		if (sensorList[i]->getStateOfSensor() == 1)
		{
			sensorList[i]->randomizeValueOfSensor();
		}
	}
}

void device::randomizeIntTempOfSensors()
{
	unsigned int randomizer = (unsigned int)time(NULL);
	srand(randomizer);
	for (uint16_t i = 0; i < sensorList.size(); i++)
	{
		if (sensorList[i]->getStateOfSensor() != 2)
			sensorList[i]->setIntTempOfSensor(rand() % 10 + 50);
	}
}

void device::getValuesOfSensors()
{
	for (uint16_t i = 0; i < sensorList.size(); i++)
	{
		cout << sensorList[i]->getSensorName() + " " + sensorList[i]->getValueString();
	}
}

void device::changeIntVoltageOfaSensor()
{
	secureInput secureInput;

	listSensors();
	cout << endl <<"Which sensor would you like to change voltage of?" << endl;
	uint16_t which;
	do
	{
		which = secureInput.readShortFromUser();
		if (which > sensorList.size() || which <= 0)
		{
			cout << "Sensor couldn't be found, try again: ";
		}
	} while (which > sensorList.size() || which <= 0);

	
	cout << "What is new voltage: ";
	uint8_t newVol;
	do 
	{
		newVol = secureInput.readShortFromUser();

		if (newVol < 0)
		{
			cout << "Voltage can not be negative, try again: ";
		}
	} while (newVol < 0);

	if (!sensorList[which - 1]->setInternalVoltage(newVol))
	{
		cout << "Sensor has been inactivated." << endl;
		sensorList[which - 1]->changeStateOfSensor(2);
	}
}

void device::changeStateOfaSensor()
{
	secureInput secureInput;
	cout << "Which sensor would you like to change state of?" << endl;
	listSensors();
	
	uint8_t which;
	do {
		which = secureInput.readShortFromUser();

		if (which <= 0 || which > sensorList.size())
		{
			cout << "Sensor couldn't be found, try again: ";
		}
	} while (which <= 0 || which > sensorList.size());

	cout << "What is new state (1 Active, 2 Inactive, 3 Suspended): ";
	uint8_t newState;
	do 
	{
		newState = secureInput.readShortFromUser();
		if (newState <= 0 || newState > 3)
		{
			cout << "Invalid state, try again: ";
		}
	} while (newState <= 0 || newState > 3);

	sensorList[which - 1]->changeStateOfSensor(newState);
	cout << "Sensor state has been changed." << endl;
}

void device::getIntVolOfSensors()
{
	for (uint16_t i = 0; i < sensorList.size(); i++)
	{
		cout << sensorList[i]->getSensorName() << ": ";
		cout << sensorList[i]->getInternalVoltage() << " volt" << endl;
	}	
}

void device::getIntTempOfSensors() 
{
	randomizeIntTempOfSensors();
	for (uint16_t i = 0; i < sensorList.size(); i++)
	{
		cout << sensorList[i]->getSensorName() << ": ";
		cout << sensorList[i]->getInternalTemperaure() << " celsius degree" << endl;
	}
}

string device::createLogMessage()		//•	persistent storage of sensor and device data in a log
{
	stringstream stringStream;
	
	time_t rawtime;
	struct tm timeinfo;
	char buffer[80];

	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);

	strftime(buffer, 80, "Time: %c", &timeinfo);
	stringStream << endl << buffer << endl;

	for (uint16_t i = 0; i < sensorList.size(); i++)
	{
		stringStream << sensorList[i]->getSensorName() << ":" << endl;
		stringStream << "Internal temperature: " << sensorList[i]->getInternalTemperaure() << " celcius degree" << endl;;
		stringStream << "Internal voltage: " << sensorList[i]->getInternalVoltage() << " volt" << endl;
		stringStream << sensorList[i]->getValueString();
	}
	
	string logMessage = stringStream.str();
	return logMessage;
}

void device::printLogs()
{
	ifstream fileIN("textLogs.txt");
	string toBeDisplayed;

	while (getline(fileIN, toBeDisplayed))
	{
		cout << toBeDisplayed << endl;
	}
	fileIN.close();
	fileIN.clear();
}
