#ifndef UTIL_STRINGOPERATIONS_H_
#define UTIL_STRINGOPERATIONS_H_

#include <string>
#include <sstream>
#include <stdlib.h>     // srand, rand
#include <time.h>       // time
#include <ctime>
using namespace std;

string GenerateUsername (string theString);
string GeneratePassword ();
string trimSpaces (string theString);
bool hasSpaces (string theString);
string toupper(string theString);

#endif /* UTIL_STRINGOPERATIONS_H_ */
