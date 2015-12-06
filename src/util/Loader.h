#ifndef UTIL_LOADER_H_
#define UTIL_LOADER_H_

#include <math.h>
#include <string>
#include <sstream>
#include <iostream>
#include "../util/Customer.h" // customer class
#include "../util/Date.h" // date class
#include "../util/TestimonialClass.h" // TestimonialClass class
#include "../util/MyStack.h" // TestimonialClass class
#include "../util/MyStack.cpp" // TestimonialClass class
#include <vector> // vector for customers
#include <stack> // testimonial stack
#include <fstream> // ifstream/ofstream
#include <algorithm> // sort
#include <limits> // number limits

using namespace std;

bool InFileExistsAndIsNotEmpty(string);

void LoadTestimonials(MyStack<TestimonialClass>*);

void LoadCustomers(vector<Customer>*);

void SaveCustomers(vector<Customer>*);

void SaveTestimonials(MyStack<TestimonialClass>*);

#endif /* UTIL_LOADER_H_ */
