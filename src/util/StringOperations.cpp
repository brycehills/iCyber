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
	ostringstream password;

	int randNum1, randNum2;
	char randomLowerCase1, randomLowerCase2,
	randomUpperCase1, randomUpperCase2;

	// generate random number between 0 and 99
	randNum1 = rand() % 100;
	randNum2 = rand() % 100;

	// generate random upper case letter
	randomUpperCase1 = 'A' + rand() % 26;
	randomUpperCase2 = 'A' + rand() % 26;

	// generate random lower case letter
	randomLowerCase1 = 'a' + rand() % 26;
	randomLowerCase2 = 'a' + rand() % 26;

	password << randomLowerCase1 << randomUpperCase1 << randNum1
			<< randomUpperCase2 << randomLowerCase1 << randNum2;

	return password.str();
}
