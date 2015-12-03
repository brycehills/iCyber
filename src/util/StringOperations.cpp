#include "StringOperations.h"


string toupper(string theString) {
	for (unsigned int i = 0; i < theString.length(); i++) {
		theString.at(i) = char(toupper(theString.c_str()[i]));
	}
	return theString;
}

string GenerateUsername (string theString) {
	ostringstream usernameStream;
	ostringstream spaceStream;

	// Loop appends stream with the positions of spaces in the username
	//	this will prevent the names "LosAngeles Air Port" and
	//	"Los Angeles AirPort" from creating the same username
	for (unsigned int i = 0; i < theString.length(); i++) {
		if (theString.at(i) == ' ') {
			spaceStream << i;
		}
		else {
			usernameStream << theString.at(i);
		}
	}
	usernameStream << spaceStream.str();

	return usernameStream.str();
}

bool hasSpaces (string theString) {
	bool stringHasSpaces;
	unsigned int index;

	stringHasSpaces = false;
	index = 0;

	while (index < theString.length() && !stringHasSpaces) {
		if (theString.at(index) == ' ') {
			stringHasSpaces = true;
		}
		else {
			index++;
		}
	}

	return stringHasSpaces;
}

string trimSpaces (string theString) {
	// erase leading spaces
	theString.erase(0, theString.find_first_not_of(' '));
	// erase trailing spaces
	theString.erase(theString.find_last_not_of(' ')+1);

	return theString;
}

string GeneratePassword () {
	return "password";
}
