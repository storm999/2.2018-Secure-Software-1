#include "LoggerFactory.h" 
#include "TxtFileLogger.h" 
#include "BinFileLogger.h" 


using namespace std;
Logger *LoggerFactory::selectLogger()
{
	secureInput secureInput;
	uint8_t loggerType = 0;
		

	while (loggerType != 1 && loggerType != 2)
	{
		if (loggerType != 1 && loggerType != 2)
		{
			cout << endl << "Please select logging type: \n1: TXT FILE, 2: BIN FILE";
		}
		loggerType = secureInput.readShortFromUser();
	}
		
	if (loggerType == TEXT_FILE)
	{
		return new TxtFileLogger();
	}
	else if (loggerType == BIN_FILE)
	{
		return new BinFileLogger();
	}
	return NULL;
}