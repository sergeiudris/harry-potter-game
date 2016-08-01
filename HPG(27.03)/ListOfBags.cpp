#include "ListOfBags.h"
#include <windows.h>

#include <iostream>
#include <string>
using namespace std;




ListOfBags::ListOfBags(std::string name)
{
	namel = name;
	lobHead = 0;
}
ListOfBags& ListOfBags::operator=(const ListOfBags& rhs)
{
	namel = rhs.namel;
	lobHead = rhs.lobHead;
	return *this;
}
ListOfBags::ListOfBags(const ListOfBags& rhs)
{
	namel = rhs.namel;
	lobHead = rhs.lobHead;
}
ListOfBags::~ListOfBags()
{}

void ListOfBags::createItemPutItem(std::string newItemn, std::string adressee)
{
	Item* newItem = new Item(newItemn);
	Bag* curr = lobHead;
	if(lobHead != 0)
	{
		
		while(curr != 0)
		{
			if(curr->nameb == adressee)
			{
				newItem->next = curr->bagHead;
				curr->bagHead = newItem;
				return;
			}
			else
			{
				curr = curr->nextb;	
			}
		}
		if(curr == 0)
		{
			show("No such character in the game...",50,0,0,1);
			return;
		}
	}
	else
	{
		show("There are no characters in the game...",50,0,0,1);
		return;
	}
}


void ListOfBags::destroyItem(const std::string& itn)
{
		Bag* curr = lobHead;
		Bag* trail = 0;
		
	
	if(lobHead != 0)
	{
		

		while(curr != 0)
		{	
			Item* currx = curr->bagHead;
			Item* trailx = 0;
			if(curr->bagHead != 0)
			{
				
				
				
				while(currx != 0)
				{
					if(currx->namei == itn)
					{
						if(currx == curr->bagHead)
						{
							curr->bagHead = currx->next;
							delete currx;
							return;
						}
						else
						{
							trailx->next = currx->next; 
							delete currx;
							return;
						}
					
												
					}
					else
					{
						trailx = currx;
						currx = currx->next;
					}
			
			     }
				
			}
			trail = curr;
			curr = curr->nextb;
			
		}
		if(curr == 0)
		{
			show("No such item to destroy...",50,0,0,1);
			return;
		}

	}
	else
	{
		show("There is no such item...",50,0,0,1);
		return;
	}
}


void ListOfBags::pickItemPutItem(std::string namei, std::string adresser, std::string adressee)
{
	Bag* curr = lobHead;
	Bag* trail = 0;
	
	if(lobHead != 0)
	{
		
		while(curr != 0)
		{
			Item* currx = curr->bagHead;
			Item* trailx = 0;
			if(adresser == curr->nameb)
			{
				if(curr->bagHead != 0)
				{
					while(currx != 0)
					{
						if(namei == currx->namei)
						{
							Bag* curr2 = lobHead;
							while(curr2 != 0)
							{
								if(curr2->nameb == adressee)
								{
									if(trailx != NULL)
									{
										Item* sub = curr2->bagHead;
										curr2->bagHead = trailx->next;
										trailx->next = currx->next;
										currx->next = sub;
									}
									else
									{
										curr->bagHead = currx->next;
										Item* sub2 = curr2->bagHead;
										curr2->bagHead = currx;
										currx->next = sub2;
									}
									
									show(adresser,20,0,0);show(" gave ",20,0,0);show(namei,20,0,0);
									show(" to ",20,0,0);show(adressee,20,0,0);
									Sleep(2000);
									clearMiddle();
									
									return;
								}
								curr2 = curr2->nextb;
							}
							if(curr2 == 0)
							{
								show(adresser,50,0,0);show(" cannot give ",50,0,0);show(namei,50,0,0);
								show(" to ",50,0,0);show(adressee,50,0,0,1);
								show(" : no '",50,0,0);show(adressee,50,0,0,1);
								show("'-character in the game...",50,0,0,1);
								return;
							}
						}
						
							trailx = currx;
							currx = currx->next;
						
					}
					if(currx == 0)
					{
						show(adresser,50,0,0);show(" has no such item...",50,0,0,1);
						return;
					}
				}
				else
				{
					show(adresser,50,0,0);show(" has no items...",50,0,0,1);
					return;
				}
			}
			trail = curr;
			curr = curr->nextb;
		}
		if(curr == 0)
		{
			show("There is no ",50,0,0);show(adresser,50,0,0);
			show(" character in the game...",50,0,0,1);
			return;
		}
		
	}
	else
	{
		show("There is no ",50,0,0);show(adresser,50,0,0);
		show(" character in the game...",50,0,0,1);
		return;
	}
}

void ListOfBags::printBag(std::string nameofbag)
{
	Bag* curr = lobHead;
	Bag* trail = 0;
	
	if(lobHead != 0)
	{
		while(curr != 0)
		{
			if(curr->nameb == nameofbag)
			{
				clearMiddle();

				Item* currx = curr->bagHead;
				Item* trailx = 0;
				show(nameofbag,0,0,12,0,4);show(" has: ",0,0,0,0,0); 
				while(currx != 0)
				{
					cout << "{" << currx->namei << "} ";
					currx = currx->next;
				}
				clearBottom();
				return;
			}
			curr = curr->nextb;
		}
		if(curr == 0)
		{
			clearBottom();
			show("No '",20,0,0);show(nameofbag,20,0,0);show("' character in the game...",20,0,0,1);
			return;
		}
	}
	else
	{
		clearBottom();
		show("No '",20,0,0);show(nameofbag,50,0,0);show("' character in the game...",20,0,0,1);
		return;
	}
}

void ListOfBags::createBag(std::string nameofbag,std::string locationofbag)
{
	Bag* newBag = new Bag(nameofbag,locationofbag);
	Bag* curr = this->lobHead;
	Bag* trail = 0;
	if (lobHead != 0)
	{
		while(curr != 0)
		{
			trail = curr;
			curr = curr->nextb;
		}
		trail->nextb = newBag;
		return;
	}
	else
	{
		lobHead = newBag;
		return;
	}
}
void ListOfBags::destroyBag(std::string nameofbag)
{
	Bag* curr = lobHead;
	Bag* trail = 0;
	if(lobHead != 0)
	{
		
			while(curr != 0)
			{
					
				if(curr->nameb == nameofbag) 
				{
					Item* currx = curr->bagHead;
					
					if(lobHead->nameb == nameofbag) 	
					{
						
						while(currx != 0)
						{
							Item* temporary = 0;
							currx = curr->bagHead;	
							curr->bagHead = currx->next;
							temporary = currx;
							delete temporary;
						}
						delete curr; 
						clearMiddle();
						show("Character ",1,0,12);show(nameofbag,1,0,12);show(" deleted",1,0,12,1);
						clearBottom();
						return;
					}
					else
					{
						while(currx != 0)
						{
							Item* temporary = 0;
							currx = curr->bagHead;	
							curr->bagHead = currx->next;
							temporary = currx;
							delete temporary;
						}
						trail->nextb = curr->nextb;
						delete curr; 
						clearMiddle();
						show("Character ",1,0,12);show(nameofbag,1,0,12);show(" deleted",1,0,12,1);
						clearBottom();
						return;
					}
				}
				else
				{
					trail = curr;
					curr = curr->nextb;
				}
		
			}
	}
	else
	{
		clearBottom();
		show("No characters in the game...",50,0,0,1);
		return;
	}
}
void ListOfBags::printBagsInLocation(std::string location)
{
	
	Bag* curr = lobHead;
	if(curr != 0)
	{	
		int addition = 0;
		while(curr != 0)
		{
			if(curr->locationb == location)
			{
				show(curr->nameb,0,35,1 + addition);
				addition++;
			}
			curr = curr->nextb;
		}
	}
	return;
}



