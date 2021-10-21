//----------------------------------------------------------------------
// Handles the creation, overriding functions, and deletion of a company
//----------------------------------------------------------------------
#ifndef _COMPANY_H
#define _COMPANY_H
#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include <cstring>
using namespace std;


class Company
{
public:
	//---------------------------------------------------------------------
	// Enums to be used on the company class 
	//---------------------------------------------------------------------
	enum { PHONE_LEN = 10};
	enum { MAX_NAME_LEN = 30 };
	//---------------------------------------------------------------------
	// Declares a new company and sets the name to be NULL
	//---------------------------------------------------------------------
	Company() { name = NULL; }
	//---------------------------------------------------------------------
	// Creates a new company from a previously declared company
	//---------------------------------------------------------------------
	Company(const Company& rhs);
	//---------------------------------------------------------------------
	// Deletes the name of a current company
	//---------------------------------------------------------------------
	~Company() { delete[] name; }
	//---------------------------------------------------------------------
	// Overrides the assignment operator 
	//---------------------------------------------------------------------
	Company& operator=(const Company & rhs);
	//---------------------------------------------------------------------
	// Overrides the less than operator
	//---------------------------------------------------------------------
	bool operator<(const Company & rhs);
	//---------------------------------------------------------------------
	// Overrides the equal to operator 
	//---------------------------------------------------------------------
	bool operator==(const Company & rhs);
	//---------------------------------------------------------------------
	// Overrides the equal to opertor 
	//---------------------------------------------------------------------
	bool operator!=(const Company & rhs);
	//---------------------------------------------------------------------
	// Overrides the input operator
	//---------------------------------------------------------------------
	friend istream & operator>>(istream & in, Company & rhs);
	//---------------------------------------------------------------------
	// Overrides the output operator 
	//---------------------------------------------------------------------
	friend ostream & operator<<(ostream & out, const Company & rhs);
	
private: 
	//---------------------------------------------------------------------
	// Declares the name and phone for a company
    //---------------------------------------------------------------------
    char * name;   
    char phone[PHONE_LEN]; 
};
#endif 