#ifndef UTIL_STRINGOPERATIONS_H_
#define UTIL_STRINGOPERATIONS_H_

#include <string>
using namespace std;

string RemoveSpaces (string theString) {
	theString.erase(std::remove(theString.begin(), theString.end(), ' '), theString.end());
	return theString;
}


#endif /* UTIL_STRINGOPERATIONS_H_ */
