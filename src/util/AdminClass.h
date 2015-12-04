#ifndef UTIL_ADMINCLASS_H_
#define UTIL_ADMINCLASS_H_

#include "../util/User.h"	// base virtual class
#include <string>
using namespace std;

class AdminClass : public User
{
public:
	AdminClass();
	string GetUsername();
	string GetPassword();
};

#endif /* UTIL_ADMINCLASS_H_ */
