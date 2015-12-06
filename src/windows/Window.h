#ifndef WINDOWS_WINDOW_H_
#define WINDOWS_WINDOW_H_

#define MAX_BUFFER  64

#include <math.h>
#include <string>
#include <sstream>
#include <iostream>
#include "../gui/zahnrad.h"
#include "../util/Customer.h" // customer class
#include <vector> // vector for customers
#include <stack> // testimonial stack
#include <fstream> // ifstream/ofstream
#include <algorithm> // sort
#include <limits> // number limits
#include "../util/TestimonialClass.h"
#include "../util/MyStack.h"

using namespace std;

//make sure you add your window to the archive here!
const int EDIT_CUSTOMER = 7;
const int ADD_USER = 6;
const int CUSTOMER_LIST = 5;
const int CUSTOMER_MENU = 4;
const int TESTIMONIALS = 3;
const int ORDER_PRODUCTS = 2;
const int ADMIN = 1;
const int LOGIN = 0;

namespace patch { //this is for to_string
template<typename T> std::string to_string(const T& n) {
	std::ostringstream stm;
	stm << n;
	return stm.str();
}
}

class Window {
private:
	bool set, update, exit_prog;
	int ID_c;
protected:
	MyStack<TestimonialClass>* testimonials;
	vector<Customer>* customers;
	int *customer_index;
public:
	void * return_val;
	int ID;
	Window(MyStack<TestimonialClass>* t, vector<Customer>* c, int *c_i) {
		update_data(t, c, c_i);
		set = false;
		ID_c = 0;
		return_val = NULL;
		ID = -1;
		update = false;
		exit_prog = false;
	}

	void issue_update() {
		update = true;
	}

	bool do_update() { //don't call this function
		if (update) {
			update = false;
			return true;
		}
		return false;
	}

	void update_data(MyStack<TestimonialClass>* t, vector<Customer>* c, int *c_i) { //don't call this function
		testimonials = t;
		customers = c;
		customer_index = c_i;
	}

	void set_data(MyStack<TestimonialClass>*&t, vector<Customer> *&c, int *&c_i) { //don't call this function
		t = testimonials;
		c = customers;
		c_i = customer_index;
	}

	virtual ~Window() {
	}

	virtual void render_main(zr_window *) = 0;

	virtual void init() = 0;

	void changeWindow(int ID) {
		set = true;
		ID_c = ID;
	}

	int setWindow() { //don't call this function
		if (set) {
			set = false;
			return ID_c;
		}
		return ID;
	}

	void exit() {
		exit_prog = true;
	}

	bool exit_program() { //don't call this function
		return exit_prog;
	}
};

#endif /* WINDOWS_WINDOW_H_ */
