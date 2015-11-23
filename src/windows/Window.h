#ifndef WINDOWS_WINDOW_H_
#define WINDOWS_WINDOW_H_

#define MAX_BUFFER  64

#include <math.h>
#include <string>
#include <sstream>
#include <iostream>
#include "../Member/Member.h"
#include "../gui/zahnrad.h"
#include "../util/Customer.h" // customer class
#include <vector> // vector for customers
#include <stack> // testimonial stack
#include <fstream> // ifstream/ofstream
#include <algorithm> // sort

using namespace std;

//make sure you add your window to the archive here!
const int CUSTOMER_LIST = 6;
const int CUSTOMER_MENU = 5;
const int TESTIMONIALS = 4;
const int ORDER_PRODUCTS = 3;
const int ADMIN = 2;
const int LOADER = 1;
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

	/**************************************************************************
	 * Function: InFileExistsAndIsNotEmpty
	 *
	 * This function checks if a text file exists and is not empty.
	 *
	 * Returns: Returns a bool of whether a file exists and is not empty.
	 **************************************************************************/
	bool InFileExistsAndIsNotEmpty(string inFileName) {
		ifstream inFile;
		bool existsAndNotEmpty;
		existsAndNotEmpty = false;

		inFile.open(inFileName.c_str());

		if (inFile) {
			if (inFile.peek() == std::ifstream::traits_type::eof()) {
				existsAndNotEmpty = false;
			} else {
				existsAndNotEmpty = true;
				inFile.close();
			}
		} else {
			existsAndNotEmpty = false;
		}

		return existsAndNotEmpty;
	}

	void LoadTestimonials() {
		ifstream inFile;
		string newTestimonial;
		if (InFileExistsAndIsNotEmpty("SavedTestimonials.txt")) {
			inFile.open("SavedTestimonials.txt");
		} else {
			inFile.open("DefaultTestimonials.txt");
		}

		while (!inFile.eof()) {
			getline(inFile, newTestimonial);
			testimonials.push(newTestimonial);
		}

		inFile.close();
	}

	void LoadCustomers() {
		ifstream inFile;
		string newTestimonial;
		bool defaultFile;
		Customer *newCustomer;
		string name;
		string street;
		string stateZipCode;
		bool receivedPamphlet;
		bool isKey;
		string rating;
		string tempString;

		defaultFile = true;
		receivedPamphlet = false;

		if (InFileExistsAndIsNotEmpty("SavedCustomers.txt")) {
			inFile.open("SavedCustomers.txt");
			defaultFile = false;
		} else {
			inFile.open("DefaultCustomers.txt");
			defaultFile = true;
		}

		while (!inFile.eof()) {
			getline(inFile, name);
			getline(inFile, street);
			getline(inFile, stateZipCode);
			if (!defaultFile) {
				getline(inFile, tempString);
				if (tempString == "true") {
					receivedPamphlet = true;
				}
				else {
					receivedPamphlet = false;
				}
			}
			getline(inFile, rating);
			getline(inFile, tempString);
			if (tempString == "key") {
				isKey = true;
			}
			else {
				isKey = false;
			}
			newCustomer = new Customer(name, street, stateZipCode,
					receivedPamphlet, isKey, rating);

			customers.push_back(*newCustomer);
		}

		std::sort(customers.begin(), customers.end());

		inFile.close();
	}
protected:
	Member **members;
	int *num_members;
	stack<string> testimonials;
	vector<Customer> customers;
public:
	void * return_val;
	int ID;
	Window(Member **m, int *n_m) {
		update_data(m, n_m);
		set = false;
		ID_c = 0;
		return_val = NULL;
		ID = -1;
		update = false;
		exit_prog = false;
		// load
		LoadTestimonials();
		LoadCustomers();
	}

	void SaveTestimonials() {
		ofstream outFile;
		stack<string> popStack;
		stack<string> saveStack;

		popStack = testimonials;

		// put testimonials into saveStack in reverse order
		while (!popStack.empty()) {
			saveStack.push(popStack.top());
			popStack.pop();
		}

		outFile.open("SavedTestimonials.txt");

		while (!saveStack.empty()) {
			outFile << saveStack.top();
			saveStack.pop();
			// only make a new line if it isn't the last item
			if (!saveStack.empty()) {
				outFile << endl;
			}
		}
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

	void update_data(Member **m, int *n_m) { //don't call this function
		members = m;
		num_members = n_m;
	}

	void set_data(Member **&m, int *&n_m) { //don't call this function
		m = members;
		n_m = num_members;
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
