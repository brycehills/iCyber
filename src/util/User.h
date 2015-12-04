#ifndef UTIL_USER_H_
#define UTIL_USER_H_

#include <string>
using namespace std;

class User {
protected:
	User () {}
	virtual ~User () = 0;
	virtual string GetUsername() = 0;
	virtual string GetPassword() = 0;

	string username;
	string password;
};



#endif /* UTIL_USER_H_ */
