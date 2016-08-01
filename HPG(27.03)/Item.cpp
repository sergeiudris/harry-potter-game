#include "Item.h"
using namespace std;

ostream& operator<<(ostream& os, const Item& item)
{
	return os << endl;
}

Item::Item(std::string n)
{
	namei = n;
	next = 0;	
}

Item& Item::operator=(const Item& rhs)
{
	if(this == &rhs)
	{
		return *this;
	}
	namei = rhs.namei + " copy";
	next = rhs.next;
	return *this;
}

Item::Item(const Item& rhs)
{
	namei = rhs.namei;
	next = rhs.next;
}

Item::~Item()
{
}