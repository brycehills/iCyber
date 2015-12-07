#include "../util/TestimonialClass.h"

TestimonialClass::TestimonialClass()  {
}

TestimonialClass::TestimonialClass(string theTestimonial, Date *theDate)  {
	testimonialString = theTestimonial;
	postDate = theDate;
}

// copy constructor
TestimonialClass::TestimonialClass(const TestimonialClass& otherTestimonial)  {
	testimonialString = otherTestimonial.testimonialString;
	postDate = new Date;
	postDate->SetDate(otherTestimonial.GetDate().GetYear(),
			otherTestimonial.GetDate().GetMonth(),
			otherTestimonial.GetDate().GetDay());
}

TestimonialClass::~TestimonialClass(){
	//delete postDate;
}

Date TestimonialClass::GetDate() const {
	return *postDate;
}


void TestimonialClass::SetDate(Date *theDate) {
	postDate = theDate;
}

string TestimonialClass::GetMessage() const {
	return testimonialString;
}


