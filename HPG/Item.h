#ifndef ITEM_H_
#define ITEM_H_


#include <iostream>
#include <string>

class Item
{
	friend std::ostream& operator<<(std::ostream& os, const Item& item);
	friend class Bag;
	friend class ListOfBags;
public:
	Item(std::string namei = "item1");
	Item& operator=(const Item& rhs);
	Item(const Item& rhs);
	~Item();

	std::string namei;
	Item* next;
};

#endif /* ITEM_H_ */