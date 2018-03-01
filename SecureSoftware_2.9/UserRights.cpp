#include "userRights.h"



userRights::userRights()
{
}


userRights::~userRights()
{
}


vector<string> userRights::get1stLevelRights()
{
	return Rights1stLevel;
}

vector<string> userRights::get2ndLevelRights()
{
	return Rights2ndLevel;
}

vector<string> userRights::get3rdLevelRights()
{
	return Rights3rdLevel;
}