#ifndef UTIL_DATE_H_
#define UTIL_DATE_H_

#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

class Date {
public:
    /****************************
     * Constructor & Destructor *
     ****************************/
	Date();
	Date(unsigned short newYear, unsigned short newMonth,
			unsigned short newDay);
	~Date();

	/******************
	 ***  MUTATORS  ***
	 ******************/
	void SetDate(unsigned short newYear, unsigned short newMonth,
			unsigned short newDay);

	/******************
	 ***  ACCESSORS ***
	 ******************/
	string GetDate() const;
	unsigned short GetYear() const;
	unsigned short GetMonth() const;
	unsigned short GetDay() const;
private:
	unsigned short year;
	unsigned short month;
	unsigned short day;
};



#endif /* UTIL_DATE_H_ */
