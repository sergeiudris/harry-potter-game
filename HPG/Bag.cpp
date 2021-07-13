
#include "Bag.h"
using namespace std;



Bag::Bag(std::string n,std::string l)
{
	nameb = n;
	size = 3;
	nextb = 0;
	bagHead = 0;
	locationb = l;
}
Bag& Bag::operator=(const Bag& rhs)
{
	nameb = rhs.nameb + " copy";
	bagHead = rhs.bagHead;
	locationb = rhs.locationb;
	return *this;
}
Bag::Bag(const Bag& rhs)
{
	nameb = rhs.nameb + " copy";
	bagHead = rhs.bagHead;
	locationb = rhs.locationb;
}
Bag::~Bag()
{ }
