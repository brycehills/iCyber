
#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <iostream>
#include <sstream>
#include<iomanip>

using namespace std;

/************************************************************************
 * Customer CLASS
 * This class represents Customer of the iCyber product. It is used to
 * store information on the customer.
 ***********************************************************************/
class Customer
{

public:

	//CONSTRUCTORS
	Customer();
	Customer(string customerName, string customerStreet,
			string customerStateZipCode, bool customerPamphlet,
			bool customerIsKey, string customerRating);

	//DESTRUCTOR
	~Customer();


	/******************
	 ***  MUTATORS  ***
	 ******************/

	void SetValues(string customerName, string customerStreet,
			string customerStateZipCode, bool customerPamphlet,
			bool customerIsKey, string customerRating);

	/************************************************************************
	 * void SetName(string memName);
	 * MUTATOR: Changes the Customers name
	 * Return: none
	 ***********************************************************************/
	void SetName(string memName);

	/************************************************************************
	 * void SetStreet(string customerStreet);
	 * MUTATOR: Changes the Customer's street
	 * Return: none
	 ***********************************************************************/
	void SetStreet(string customerStreet);

	/************************************************************************
	 * void SetStateZipCode (string customerStateZipCode);
	 * MUTATOR: Changes the Customer's state and zip code
	 * Return: none
	 ***********************************************************************/
	void SetStateZipCode(string customerStateZipCode);

	/************************************************************************
	 * void SetType(char customerType);
	 * MUTATOR: Changes whether the Customer is a regular or key customer
	 * Return: none
	 ***********************************************************************/
	void SetReceivedPamphlet(bool customerPamphlet);

	/************************************************************************
	 * 	void SetType(bool customerIsKey);
	 * MUTATOR: Changes whether the Customer is a regular or key customer
	 * Return: none
	 ***********************************************************************/
	void SetType(bool customerIsKey);

	/************************************************************************
	 * void SetRating(string customerRating);
	 * MUTATOR: Changes whether the Customer rating
	 * Return: none
	 ***********************************************************************/
	void SetRating(string customerRating);


	/******************
	 ***  ACCESSORS ***
	 ******************/

	/************************************************************************
	 * string GetName();
	 * ACCESSOR: none
	 * Return: CustomerName
	 ***********************************************************************/
	string GetName();

	/************************************************************************
	 * string GetStreet();
	 * ACCESSOR: none
	 * Return: street
	 ***********************************************************************/
	string GetStreet();

	/************************************************************************
	 * string GetStateZipCode();
	 * ACCESSOR: none
	 * Return: stateZipCode
	 ***********************************************************************/
	string GetStateZipCode();

	/************************************************************************
	 * bool GetPamphlet();
	 * ACCESSOR: none
	 * Return: Bool if customer has pamphlet
	 ***********************************************************************/
	bool GetPamphlet();


	/************************************************************************
	 * bool GetIsKey;
	 * ACCESSOR: none
	 * Return: isKey
	 ***********************************************************************/
	bool GetIsKey();

	/************************************************************************
	 * int GetRating();
	 * ACCESSOR: none
	 * Return: int - rating of customer
	 ***********************************************************************/
	string GetRating();


	/******************
	 ***  METHODS   ***
	 ******************/



	/************************************************************************
	 * string Print()
	 * MUTATOR: none
	 * Return: a string with all the Customer's data
	 ***********************************************************************/
	string Print();

	/******************
	 ***  UTILITY ***
	 ******************/

	/************************************************************************
	 * bool operator<(const Customer &otherCustomer) const
	 * DESCRIPTION: Overloads < operator for sorting
	 * MUTATOR: none
	 * Return: whether the object's name is alphabetically lower than the
	 * other object's name
	 ***********************************************************************/
	bool operator<(const Customer &otherCustomer) const;


private:
    string name;			/// OUT - name of customer
    string street;
    string stateZipCode;
    bool receivedPamphlet;	/// OUT - if customer has received pamphlet or not
    bool isKey;				/// OUT - tells if Customer is regular or executive
    string rating;			/// OUT - Customer rating
};


#endif /* CUSTOMER_H_ */
