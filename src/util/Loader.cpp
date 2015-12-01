#include "Loader.h"

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

void LoadTestimonials(stack<string>* testimonials) {
	ifstream inFile;
	string newTestimonial;
	if (InFileExistsAndIsNotEmpty("SavedTestimonials.txt")) {
		inFile.open("SavedTestimonials.txt");
	} else {
		inFile.open("DefaultTestimonials.txt");
	}

	while (!inFile.eof()) {
		getline(inFile, newTestimonial);
		testimonials->push(newTestimonial);
	}

	inFile.close();
}

void LoadCustomers(vector<Customer>* customers) {
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
	string username;
	string password;
	unsigned int minimumPurchases;
	unsigned int extremePurchases;
	unsigned int ultimatePurchases;

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
		getline(inFile, rating);
		getline(inFile, tempString);
		if (tempString == "key") {
			isKey = true;
		} else {
			isKey = false;
		}
		if (!defaultFile) {
			getline(inFile, tempString);
			if (tempString == "true") {
				receivedPamphlet = true;
			} else {
				receivedPamphlet = false;
			}
			getline(inFile, username);
			getline(inFile, password);
			inFile >> minimumPurchases;
			inFile >> extremePurchases;
			inFile >> ultimatePurchases;

			inFile.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		if (!defaultFile) {
			newCustomer = new Customer(name, street, stateZipCode,
					receivedPamphlet, isKey, rating, username, password,
					minimumPurchases, extremePurchases, ultimatePurchases);
		} else {
			newCustomer = new Customer(name, street, stateZipCode, isKey,
					rating);
		}

		customers->push_back(*newCustomer);
	}

	std::sort(customers->begin(), customers->end());

	inFile.close();
}

void SaveCustomers(vector<Customer>* customers) {
	ofstream outFile;
	vector<Customer>* outputVector;

	outputVector = customers;

	outFile.open("SavedCustomers.txt");

	while (!outputVector->empty()) {
		outFile << outputVector->front().GetName() << endl;
		outFile << outputVector->front().GetStreet() << endl;
		outFile << outputVector->front().GetStateZipCode() << endl;
		outFile << outputVector->front().GetRating() << endl;
		if (outputVector->front().GetIsKey()) {
			outFile << "key";
		} else {
			outFile << "nice to have";
		}
		outFile << endl;
		if (outputVector->front().GetPamphlet()) {
			outFile << "true";
		} else {
			outFile << "false";
		}
		outFile << endl;
		outFile << outputVector->front().GetUsername() << endl;
		outFile << outputVector->front().GetPassword() << endl;
		outFile << outputVector->front().GetMinimumPurchases() << endl;
		outFile << outputVector->front().GetExtremePurchases() << endl;
		outFile << outputVector->front().GetUltimatePurchases();

		outputVector->erase(outputVector->begin());
		// only make a new line if it isn't the last item
		if (!outputVector->empty()) {
			outFile << endl;
		}
	}
	outFile.close();
}

void SaveTestimonials(stack<string>* testimonials) {
	ofstream outFile;
	stack<string>* popStack;
	stack<string>* saveStack;

	popStack = testimonials;

	// put testimonials into saveStack in reverse order
	while (!popStack->empty()) {
		saveStack->push(popStack->top());
		popStack->pop();
	}

	outFile.open("SavedTestimonials.txt");

	while (!saveStack->empty()) {
		outFile << saveStack->top();
		saveStack->pop();
		// only make a new line if it isn't the last item
		if (!saveStack->empty()) {
			outFile << endl;
		}
	}
	outFile.close();
}
