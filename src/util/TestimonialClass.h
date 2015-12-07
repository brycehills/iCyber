#ifndef UTIL_TESTIMONIALCLASS_H_
#define UTIL_TESTIMONIALCLASS_H_

#include <string>
#include "../util/Date.h"
using namespace std;

class TestimonialClass {
public:
	TestimonialClass();
	TestimonialClass(string theTestimonial, Date *theDate);
	~TestimonialClass();
	// copy constructor
	TestimonialClass(const TestimonialClass& otherTestimonial);
	void SetDate(Date *theDate);
	Date GetDate() const;
	string GetMessage() const;
private:
	string testimonialString;
	Date *postDate;
};



#endif /* UTIL_TESTIMONIALCLASS_H_ */
