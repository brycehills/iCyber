#include "../util/Date.h"

Date::Date() {
    time_t now;
    tm *currentTime;

    now = time(NULL);
    currentTime = localtime(&now);

    year  = 1900 + currentTime -> tm_year;
    month = 1 + currentTime -> tm_mon;
    day   = currentTime -> tm_mday;
}

Date::~Date() {

}

Date::Date(unsigned short newYear, unsigned short newMonth,
		unsigned short newDay) {
	year = newYear;
	month = newMonth;
	day = newDay;
}

void Date::SetDate(unsigned short newYear, unsigned short newMonth,
		unsigned short newDay) {
	year = newYear;
	month = newMonth;
	day = newDay;
}

string Date::GetDate() const {
	ostringstream returnString;

	returnString << month << "/" << day << "/" << year;

	return returnString.str();
}

unsigned short Date::GetYear() const {
	return year;
}
unsigned short Date::GetMonth() const {
	return month;
}
unsigned short Date::GetDay() const {
	return day;
}
