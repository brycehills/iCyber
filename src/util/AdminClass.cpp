#include "../util/AdminClass.h"

AdminClass::AdminClass() {
	username = "CS1C";
	password = "bestclass";
}

string AdminClass::GetUsername() {
	return username;
}

string AdminClass::GetPassword() {
	return password;
}
