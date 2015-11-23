/*************************************************************************
 * AUTHOR        : Bryce Hills
 * STUDENT ID    : 104910
 * Project 1	 : iCyber Project
 * CLASS         : CS1C
 * SECTION       : M-W 5:30pm
 * DUE DATE      : eventually
 ************************************************************************/
#include "CustomerList.h"
/************************************************************************
 *  Method  : MemberList() -  Class: MemberList
 * ______________________________________________________________________
 * Constructor
 * ---------------------------------------------------------------------
 * This method receives no parameters. It is the default constructor
 * for the memberlist class. It will create a default object for
 * memberlist
 * ---------------------------------------------------------------------
 * Returns: none
 ***********************************************************************/
CustomerList::CustomerList()
{
	head = NULL;
	customerCount = 0;
}

/************************************************************************
 *  Method  : ~MemberList() -  Class: MemberList
 * ______________________________________________________________________
 * Destructor
 * ---------------------------------------------------------------------
 * This method receives no parameters. This method is the destructor for
 * the memberlist class and will delete an object of this class when its
 * lifetime is out of scope.
 * ---------------------------------------------------------------------
 * Returns: none
 ***********************************************************************/
CustomerList::~CustomerList()
{
	CustomerNode* ptr;
	ptr = head;
	///loop over linked list and delete all values of the allocated memory
	while(ptr != NULL)
	{
		head = ptr->next;
		delete ptr;
		ptr = head;

	} ///end while(head != NULL)}
	head = NULL;
}

void CustomerList::ClearList()
{
	CustomerNode* ptr;
	ptr = head;
	///loop over linked list and delete all values of the allocated memory
	while(ptr != NULL)
	{
		head = ptr->next;
		delete ptr;
		ptr = head;

	} ///end while(head != NULL)}
	head = NULL;
}

/************************************************************************
 *  Method  : AddMember() -  Class: MemberList
 * ______________________________________________________________________
 * Mutator
 * ---------------------------------------------------------------------
 * This method receives member name, number, type and exp date as
 *  parameters. It will add a member to the linked list of members and
 *  increment the number of member in the list.
 * Returns:
 * 	none
 ***********************************************************************/
bool CustomerList::AddCustomer(string customerName, string customerNum,
		bool customerPamphlet, char customerType, int customerRating)
{
	bool success = true;

	/********************** DEBUG *************************************/
	///	cout << "name :" << memName << endl;
	///	cout << "Num  :" << memNum << endl;
	///	cout << "type :" << memType << endl;
	///	cout << "Date :" << memExp.DisplayDate() << endl << endl;
	/*********************** END DEBUG ********************************/

	CustomerNode* ptr;	/// CALC & OUT - auxiliary pointer variable

	///PROCESSING - allocate memory for the node
	ptr = new CustomerNode;

	/// PROCESSING - set all attributes of the new member object
	//ptr -> currentCustomer.SetValues(customerName, customerNum, customerPamphlet, customerType, customerRating);

	success = (ValidateCustomer(customerName) == false && ValidateCustomer(customerNum) == false);
	if(success)
	{
		ptr -> next = NULL;

		if(head == NULL)
		{
			head = ptr;
		}
		else
		{
			/// PROCESSING - new node is now front of list
			ptr -> next = head;

			///PROCESSING - points head to new front of list
			head = ptr;
		}
		/// PROCESSING - deallocate memory
		ptr = NULL;

		customerCount++;

	}

	return success;

}

/************************************************************************
 *  Method  : RemoveMember() -  Class: MemberList
 * ______________________________________________________________________
 * Accessor
 * ---------------------------------------------------------------------
 * This method receives input as a parameter. The input string will be
 * compared to member names and numbers. If the strings match, the
 * respective node will be removed form the list.
 * ---------------------------------------------------------------------
 * Returns: bool found	: if member was found or not
 ***********************************************************************/
bool CustomerList::RemoveCustomer( string input )
{
	CustomerNode *ptr; /// CALC - auxiliary pointer
	CustomerNode *delPtr; /// CALC - auxiliary pointer

	bool found = false;

	/// points perPtr to what head in pointing to
	ptr = head;

	/// Checks if list is empty
	if(ptr != NULL)
	{
		///checks if item is in front of list
		if(ptr->currentCustomer.GetName() == input)
		{
			found = true;
			delPtr = ptr;
			head = ptr->next;
			delete delPtr;
			delPtr = NULL;
			ptr  = NULL;
		}
		else
		{

			while(ptr->next != NULL && !found)
			{
				if(ptr->next->currentCustomer.GetName() == input)
				{
					found = true;
					/// Case where node is last in list
					if(ptr->next->next == NULL)
					{
						delPtr = ptr->next;
						ptr->next = NULL;
						delete delPtr;
						delPtr = NULL;
					}
					/// removing from middle
					else
					{
						/// assign temp to the found item node
						delPtr = ptr->next;

						/// passes over next node
						ptr->next = ptr->next->next;

						///delete selected node
						delete delPtr;

						///to be safe
						delPtr = NULL;
					}
				}
				else
				{
					ptr = ptr -> next;
				}
			}
		}
	}

	return found;
}


bool CustomerList::ValidateCustomer(string input)
{

	CustomerNode *ptr;	///CALC - auxiliary ptr

	ptr = head;

    bool inValid; 		///CALC - bool to be returned

	/// initializes valid to false
    inValid = false;


//    while(ptr!=NULL && !inValid)
//	{
//		if(input == ptr->currentCustomer.GetName() || input == ptr->currentCustomer.GetCustomerAddress())
//		{
//            inValid = true;
//
//		}
//		else
//		{
//			ptr = ptr -> next;
//		}
//	}



    return inValid;

}

/************************************************************************
 * Method : PrintMemberList() - Class: MemberList
 * _____________________________________________________________________
 * Accessor:
 * ---------------------------------------------------------------------
 * This method deletes a purchase and is passed a member number as a
 * string.
 * ---------------------------------------------------------------------
 * Returns: nothing
 ***********************************************************************/
string CustomerList::PrintCustomerList()
{
    ostringstream out;		/// OUTPUT - output variable
    CustomerNode* ptr;		/// CALC   - auxiliary pointer

	/// pointers ptr to head of list
	ptr = head;

	/// OUTPUT - outputs header to table
	out << left;
	out << setw(25) << "NAME";
	out << setw(15) << "ADDRESS";
	out << setw(10) << "TYPE";
	out << setw(10) << "RATING";
	out << setw(10) << "PAMPHLET STATUS";
	out << endl;
	out << right;
	out << setw(85) << setfill('-') << '-' << setfill(' ') << endl;

	/// WHILE LOOP - runs through list and prints member data
	while(ptr != NULL)
	{
        out << ptr->currentCustomer.Print();

		ptr = ptr->next;
	}

    return out.str();
}



