#ifndef UTIL_LOADER_H_
#define UTIL_LOADER_H_

#include <math.h>
#include <string>
#include <sstream>
#include <iostream>
#include "../util/Customer.h" // customer class
#include <vector> // vector for customers
#include <stack> // testimonial stack
#include <fstream> // ifstream/ofstream
#include <algorithm> // sort
#include <limits> // number limits

using namespace std;

bool InFileExistsAndIsNotEmpty(string);

void LoadTestimonials(stack<string>*);

void LoadCustomers(vector<Customer>*);

void SaveCustomers(vector<Customer>*);

void SaveTestimonials(stack<string>*);

#endif /* UTIL_LOADER_H_ */
