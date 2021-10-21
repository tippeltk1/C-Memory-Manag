//----------------------------------------------------------------------
// Handles the creation, overriding functions, and deletion of a company
//----------------------------------------------------------------------
#include "Company.h"
#include "LeakWatcher.h"
#include <iomanip>
#include <cstring>

Company::Company(const Company& rhs)
{
	*this = rhs;
}

Company& Company::operator=(const Company & rhs)
{
	if (this != &rhs)
	{
		if (name != NULL) 
			delete name;
		this->name = rhs.name;
		for (int i = 0; i < PHONE_LEN; i++)
			this->phone[i] = rhs.phone[i];
	}
	return *this;
}

bool Company::operator<(const Company & rhs)
{
	int cmp = strcmp(this->name, rhs.name);
	if (cmp < 0)
		return true;
	return false;
}

bool Company::operator==(const Company & rhs)
{
	int cmp = strcmp(name, rhs.name);
	if (cmp == 0)
		return true;
	return false;
}

bool Company::operator!=(const Company & rhs)
{
	return !(*this == rhs);
}

istream & operator>>(istream & in, Company & rhs)
{
	char tname[Company::MAX_NAME_LEN + 1];
	in >> tname;
	int nameLength = strlen(tname) + 1;
	if (rhs.name != NULL)
		delete rhs.name;
	rhs.name = new char[nameLength];
	strcpy_s(rhs.name, nameLength, tname);
	char number;
	for (int j = 0; j < Company::PHONE_LEN; j++)
	{
		in >> number;
		rhs.phone[j] = number;
	}
	return in;
}

ostream & operator<<(ostream & out, const Company & rhs)
{
	out << setiosflags(ios::left) << setw(Company::MAX_NAME_LEN) << rhs.name << " ";
	for (int i = 0; i < Company::PHONE_LEN; i++)
		out << rhs.phone[i];
	out << endl;
	return out;
}

//#ifdef TESTING_COMPANY
//
//// ------------------------------
//// Testbed main
//// ------------------------------
//void main()
//{
//	Company *c1 = new Company();
//	Company *c2 = new Company();
//	Company *c3 = new Company();
//	cin >> *c1;
//	cin >> *c2;
//	cin >> *c3;
//	cout << *c1;
//	cout << *c2;
//	*c1 = *c2;
//	cout << *c1;
//	cout << (*c1 < *c3);
//	cout << (*c1 == *c3);
//	cout << (*c1 != *c3);
//	cout << (*c1 == *c2);
//}
//
//#endif