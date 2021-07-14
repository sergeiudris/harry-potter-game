#include <windows.h>
#include <iostream>
#include <string>
#include "ListOfBags.h"
#include "functions.h"
using namespace std;







int main ()
{
	system("color F0");
	
	try{
	show("Greetings!",100,35,10);
	Sleep(500);

	
	
	chooseChapter();
	}
	catch(string x)
	{
		if(x == "EXITGAME")
		{
			clearMiddle();clearTop();clearBottom();
			show("See you",100,35,10);
			COORD position = {38,11};
			HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleCursorPosition(console,position);
			cin.get();			
			return 0;
		}
		else
		{
			cout << "That's it. Fatal error. What a cruel world." << endl;
			cin.get();
			return 0;
		}
	} 
			
}

