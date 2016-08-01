#ifndef BAG_H_
#define BAG_H_

#include "Item.h"
#include "ListOfBags.h"

#include <iostream>
#include <string>

class Bag
{
	
	friend class ListOfBags;
public:
	Bag(std::string nameb = "hero1",std::string locationb = "Hogwarts");
	Bag& operator=(const Bag& rhs);
	Bag(const Bag& rhs);
	~Bag();

	std::string nameb;
	Bag* nextb;
	Item* bagHead;
	int size;
	std::string locationb;
};

#endif /* BAG_H_ */