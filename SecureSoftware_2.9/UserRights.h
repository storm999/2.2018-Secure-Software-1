#pragma once
#include <vector>
using namespace std;

class userRights
{
private:
	vector<string> Rights1stLevel = {	"see list of sensors",
										"see current values that sensors detecting",
										"see internal voltage of sensors",
										"see internal temperature of sensors",
										"log off"};
	vector<string> Rights2ndLevel = {	"change internal voltage of a sensor",
										"change state of a sensor",
										"display previous records"};
	vector<string> Rights3rdLevel = {	"add an user",
										"delete an user",
										"change authorisation type of an user",
										"list all users"};
public:
	userRights();
	~userRights();
	vector<string> get1stLevelRights();
	vector<string> get2ndLevelRights();
	vector<string> get3rdLevelRights();
};

