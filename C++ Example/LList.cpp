//------------------------------------------------------------------------
// A linked list that holds all the companies, allows inderting, deleting
// and displaying
//------------------------------------------------------------------------
#include "LList.h"
#include "Company.h"
typedef Company InfoType;

LList::~LList()
{
	Node * p = list;
	while (p != NULL)
	{
		list = p->next;
		delete p;
		p = list;
	}
	delete list;
}

bool LList::IsEmpty() const
{
	if (list == NULL)
		return true;
	return false; 
}

bool LList::Insert(InfoType * x_ptr)  
{
	Node * p = list;
	if (IsEmpty())
	{
		list = new Node(x_ptr);
		return true;
	}
	else if (*x_ptr < *p->infoPtr)
	{
		list = new Node(x_ptr, p);
		return true;
	}
	else if(p->next != NULL && *p->next->infoPtr == *x_ptr)
		return false;
	else
	{
		while (p->next != NULL && *p->next->infoPtr < *x_ptr)
		{
			if (p->next->next != NULL && *p->next->next->infoPtr == *x_ptr)
				return false;
			p = p->next;
		}
		p->next = new Node(x_ptr, p->next);
		return true;
	}
}

bool LList::Delete(const InfoType & x)
{
	Node * p = list;
	if (p == NULL)
	{
		return false; 
	}
	else if (*p->infoPtr == x)
	{
		if (p->next == NULL)
		{
			delete p;
			list = NULL;
		}
		else if (p->next != NULL)
		{
			list = p->next; 
			delete p;
		}
		return true;
	}
	else if (p->next != NULL)
	{
		while (p->next != NULL)
		{
			if (*p->next->infoPtr == x)
			{
				Node * q = p->next;
				p->next = p->next->next;
				delete q;
				return true;
			}
			p = p->next;
		}
	}
	return false; 
}

void LList::Display(ostream & out_stream) const
{
	Node *p = list;
	while (p != NULL)
	{
		out_stream << *p->infoPtr;
		p = p->next;
	}
}

//#ifdef TESTING_LLIST
//
//// ------------------------------
//// Testbed main
//// ------------------------------
//void main()
//{
//	LList testList;
//	Company *c1 = new Company();
//	Company *c2 = new Company();
//	Company *c3 = new Company();
//	cin >> *c1;
//	cin >> *c2;
//	cin >> *c3;
//	cout << testList.IsEmpty();
//	cout << testList.Insert(c1);
//	testList.Display(cout);
//	cout << testList.Delete(*c1);
//	cout << testList.Delete(*c1);
//	cout << testList.Insert(c1);
//	cout << testList.Insert(c2);
//	cout << testList.Insert(c3);
//	cout << testList.IsEmpty();
//	testList.Display(cout);
//	cout << testList.Insert(c1);
//	testList.Display(cout);
//	testList.~LList();
//}
//
//#endif