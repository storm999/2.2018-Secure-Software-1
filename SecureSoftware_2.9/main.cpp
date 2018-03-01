#include <iostream>
#include "Users.h"
#include "Device.h"
using namespace std;

int main()
{
	device device;
	device.setStateOfDevice(1);

	if (device.getStateOfDevice() != 1)
	{
		cout << "Device couldnt be activated!";
		return 0;
	}
	// User handler is created here (not in device class) because another device may be added to the system later.
	// So same user can use other device without entering login credentials again.
	users userHandler = users();	
	
	while (true)	// Provides changing account without closing the application
	{
		if (userHandler.currentUser == NULL)
		{
			userHandler.currentUser = userHandler.logIn();
		}			

		device.run(&userHandler);
	}
	system("pause");
	return 0;
}

//Default login credentials: 
//admin->      ad ad
//assistant->  as as
//manager->    m m

//Invalid input can not crash the program.
//Compiler security options are as desired (warning level 4).
//PressureSensor.cpp line 23 •	data processing of input from 1 sensor.
//PressureSensor.cpp line 23-24 integer flow checking.
//string is prefered to char array, All strings are initilized.
//Sensor.cpp line 50-100  •The state of 1 sensor can be changed in a complex process that is very realistic and fully working.
//Device.cpp line  140-150  • All 3 sensors produce fully realistic data.
//WindSpeedSensor line 20-25  •	state of 1 sensor changeable (inactivation in case of extreme input).
//Builder pattern and Logger pattern are implemented.
//Permissions of each user type are different from each other.
//Device.cpp line 119, deleting object that was created by using 'new' keyword. Users and sensors that were created by using 'new' werent deleted.
//Because they are required until program is halt.
