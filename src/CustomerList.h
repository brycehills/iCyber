/*************************************************************************
 * AUTHOR        : Bryce Hills
 * STUDENT ID    : 104910
 * Project 1	 : iCyber Project
 * CLASS         : CS1C
 * SECTION       : M-W 5:30pm
 * DUE DATE      : eventually
 ************************************************************************/
#ifndef CUSTOMERLIST_H_
#define CUSTOMERLIST_H_

#include "Customer.h"

// STRUCT - of type personNode
struct CustomerNode
{
	Customer    currentCustomer;	// CALC & OUT - current member variable
	CustomerNode *next;			// CALC - next pointer
};

/************************************************************************
 * CustomerList CLASS
 * This class represents operations to perform to the queue. It is
 * associated with the member class and can add or remove a member
 ***********************************************************************/
class CustomerList{

public:

	/*********************************************************************
	 * CONSTRUCTORS & DESTRUCTOR
	 *********************************************************************/
	CustomerList();

	void CreateMember(Customer *newCustomer);

	virtual ~CustomerList();

	void ClearList();


	/******************
	 ***  MUTATORS  ***
	 ******************/

	bool InitializeList(const string fileName);

	bool AddCustomer(string customerName, string customerAddress,
			bool customerPamphlet, char customerType, int customerRating);

	bool RemoveCustomer(string input);

	//void SortByCustomerNumber();
	//bool TestPurchase(string input);

	bool ValidateCustomer(string input);

	/******************
	 ***  ACCESSORS ***
	 ******************/
	int TotalCustomers() const;


//	CustomerNode* SearchCustomer(string CustomerNum);

//	CustomerNode* SearchCustomerName(string CustomerName);

//	string PrintCustomerNumPurchases(string CustomerNum);

//	string PrintCustomerNamePurchases(string CustomerName);

	string PrintCustomerList();


private:

	CustomerNode *head;		// CALC - pointer to track head
	int customerCount;		// CALC & OUT - number of Customers in list

};


#endif /* CUSTOMERLIST_H_ */
