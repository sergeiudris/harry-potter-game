#ifndef LISTOFBAGS_H_
#define LISTOFBAGS_H_




#include "Bag.h"
#include "Item.h"
#include "functions.h"



class ListOfBags
{	
	
	
	friend std::ostream& operator<<(std::ostream& os, const ListOfBags& lob);
	friend class Bag;
public:
	ListOfBags(std::string namel = "ListOne");
	ListOfBags& operator=(const ListOfBags& rhs);
	ListOfBags(const ListOfBags& rhs);
	~ListOfBags();
	void createItemPutItem(std::string newItemn, std::string adressee);
	void destroyItem(const std::string& n);
	void pickItemPutItem(std::string namei, std::string adresser, std::string adressee);
	void printBag(std::string nameofbag);
	void createBag(std::string nameofbag = "hero1",std::string locationofbag = "Hogwarts");
	void destroyBag(std::string nameofbag);
	void printBagsInLocation(std::string location);


	std::string namel;
	Bag* lobHead;
};



#endif /* LISTOFBAGS_H_ */