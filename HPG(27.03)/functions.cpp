#include <iostream>
#include <string>
#include <windows.h>
#include "functions.h"
#include "ListOfBags.h"

using namespace std;

static ListOfBags list1("One");

void show(string input,int sleep,int x , int y,	int endline, int fColor , int bColor)
{
	string str = input;
	
	COORD position = {x, y};
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	GetConsoleScreenBufferInfo(console, &screen);
	if(y != 0 || x != 0) 
	{SetConsoleCursorPosition(console,position);}
	if(fColor != 0)
	{SetConsoleTextAttribute(console, (fColor + (bColor * 16)) );}

	

	if(endline == 1)
	{	for(unsigned i = 0; i < str.length();i++)
		{
			cout << str[i];
			Sleep(sleep);
		}
		cout <<  endl;
	}
	else
	{
		for(unsigned i = 0; i < str.length();i++)
		{
			cout << str[i];
			Sleep(sleep);
		}
	}
	SetConsoleTextAttribute(console, (0 + (15 * 16)) );
	return;
}
void ask(int num)
	{
		if(num == 0)
		{
			setQuestStatus("OFF   ");
			printQuestStatus();
			clearBottom();
			int randomNumber = rand()%100;
			if(randomNumber >= 0 && randomNumber < 25)
			{show("Please, make your move:",20,0,0,1);}
			if(randomNumber >= 25 && randomNumber < 50)
			{show("Your next step is welcome:",20,0,0,1);}
			if(randomNumber >= 50 && randomNumber < 75)
			{show("Let's move on:",20,0,0,1);}
			if(randomNumber >= 75 && randomNumber < 100)
			{show("I'm listening:",20,0,0,1);}
		label:	
			cout << ">>";
			string userSays;
			try{getline(cin,userSays);}catch(exception e){clearBottom();show("No comments",100,0,0,1,10);ask();}
			int cmd = itIsCommandNumber(userSays);
			if(cmd != -1)
			{		try{throw cmd;}catch(int e){command(cmd);}}
			else
			{
					clearBottom();
					int randomNumber = rand()%100;
					if(randomNumber >= 0 && randomNumber < 10)
					{show("That doesn't make sense to me...",20,0,0);}
					if(randomNumber >= 10 && randomNumber < 20)
					{show("I don't quite understand...",20,0,0);}
					if(randomNumber >= 20 && randomNumber < 30)
					{show("Hmm, I quite lost with that statement of yours...",20,0,0);}
					if(randomNumber >= 30 && randomNumber < 40)
					{show("Is that an italian dish?",20,0,0);}
					if(randomNumber >= 40 && randomNumber < 50)
					{show("Is that the name of a Moon sea?",20,0,0);}
					if(randomNumber >= 50 && randomNumber < 60)
					{show("Yeah, that's surprisingly unknown to me...",20,0,0);}
					if(randomNumber >= 60 && randomNumber < 70)
					{show("I feel like we speak different languages...",20,0,0);}
					if(randomNumber >= 70 && randomNumber < 80)
					{show("Nothing to add to that...",20,0,0);}
					if(randomNumber >= 80 && randomNumber < 90)
					{show("Unknown command.",20,0,0);}
					if(randomNumber >= 90 && randomNumber < 100)
					{show("No match for that in m dictionary...",20,0,0);}
					Sleep(2000);
					try{throw 0;}catch(int e){ask(1);}
			}
		}
		else
		{
					clearBottom();
					int randomNumber = rand()%100;
					if(randomNumber >= 0 && randomNumber < 10)
					{show("Still hasn't decided?",20,0,0,1);}
					if(randomNumber >= 10 && randomNumber < 20)
					{show("Decision is still yours:",20,0,0,1);}
					if(randomNumber >= 20 && randomNumber < 30)
					{show("We shall continue: ",20,0,0,1);}
					if(randomNumber >= 30 && randomNumber < 40)
					{show("I am patient: ",20,0,0,1);}
					if(randomNumber >= 40 && randomNumber < 50)
					{show("But go on: ",20,0,0,1);}
					if(randomNumber >= 50 && randomNumber < 60)
					{show("Sorry, you were saying :",20,0,0,1);}
					if(randomNumber >= 60 && randomNumber < 70)
					{show("Next please: ",20,0,0,1);}
					if(randomNumber >= 70 && randomNumber < 80)
					{show("Continue your typing:",20,0,0,1);}
					if(randomNumber >= 80 && randomNumber < 90)
					{show("Please, go on:",20,0,0,1);}
					if(randomNumber >= 90 && randomNumber < 100)
					{show("I'm all ears again",20,0,0,1);}
					goto label;
		}

	}

int  askForAnswer(string* expectedAnswer)
{return 0;}
bool checkAnswer(string userSays,vector<string> exAns)
	{
		for(std::vector<string>::iterator it = exAns.begin();it != exAns.end(); ++it)
		{
			if(*it == userSays)
			{
				return true;
			}
		}
		return false;
	}

void command(int commandNumber)
{
	try
	{	if(!checkCommandAvailability(commandNumber)){throw 0;}
	}catch(int e){clearBottom();show("Command is not available.",20,0,0,1);Sleep(200);ask();}

	
	     if(commandNumber == 0){try{throw 0;}catch(int cmd){commandExit();}}
	else if(commandNumber == 1){try{throw 1;}catch(int cmd){commandYes();}}
	else if(commandNumber == 2){try{throw 2;}catch(int cmd){commandNo();}}
	else if(commandNumber == 3){try{throw 3;}catch(int cmd){commandContinueQuest();}}
	else if(commandNumber == 4){try{throw 4;}catch(int cmd){commandMoveItem();}}
	else if(commandNumber == 5){try{throw 5;}catch(int cmd){commandHint();}}
	else if(commandNumber == 6){try{throw 6;}catch(int cmd){commandSelectHero();}}
	else if(commandNumber == 7){try{throw 7;}catch(int cmd){commandGoToLocation();}}
	else if(commandNumber == 8){try{throw 8;}catch(int cmd){commandShowLocation();}}
	else if(commandNumber == 9){try{throw 9;}catch(int cmd){commandMenu();}}
	
}
void commandExit()
	{	
		bool confirm = confirmation(0);
		if(confirm)
		{string EXITGAME = "EXITGAME"; throw EXITGAME;}
		else
		{ask();}
	}
void commandYes()
	{try{throw 1;}catch(int e){clearBottom();show("You agree? But why? Strange...",20,0,0);Sleep(2000);ask(1);}}
void commandNo()
	{try{throw 2;}catch(int e){clearBottom();show("You disagree? But why? Strange...",20,0,0);Sleep(2000);ask(1);}}
void commandContinueQuest()
	{try{throw 3;}catch(int e){clearBottom();show("(quest must go on...",20,0,0,1);Sleep(200);ask();}}
void commandMoveItem()
	{
		clearBottom();
		show("What item?",20,0,0,1);
		cout << ">>";
		string userSays,what,who,whom;
		try{getline(cin,userSays);}catch(exception e){clearBottom();show("No comments",100,0,0,1,10);ask();}
		int cmd = itIsCommandNumber(userSays);
	if(cmd != -1){try{throw cmd;}catch(int e){command(cmd);}}
	else
	{

		string what = userSays;

		clearBottom();
		show("Adresser?",20,0,0,1);
		cout << ">>";
		try{getline(cin,userSays);}catch(exception e){clearBottom();show("No comments",100,0,0,1,10);ask();}
		int cmd = itIsCommandNumber(userSays);
			if(cmd != -1){try{throw cmd;}catch(int e){command(cmd);}}
		else
		{string who = userSays;

		clearBottom();
		show("Adressee?",20,0,0,1);
		cout << ">>";
		try{getline(cin,userSays);}catch(exception e){clearBottom();show("No comments",100,0,0,1,10);ask();}
		int cmd = itIsCommandNumber(userSays);
			if(cmd != -1){try{throw cmd;}catch(int e){command(cmd);}}
		else
		{string whom = userSays;

		clearBottom();
		list1.pickItemPutItem(what,who,whom);
		try{throw 4;}catch(int e){ask();}
		}
		}
	}

		
	}
void commandHint()
	{   
		clearBottom();
		show("Hint? What is the best show... in the world?",20,0,0,1);
		cout << ">>";
		string userSays;
		try{getline(cin,userSays);}catch(exception e){clearBottom();show("No comments",100,0,0,1,10);ask();}
		int cmd = itIsCommandNumber(userSays);
			if(cmd != -1)
		{try{throw cmd;}catch(int e){command(cmd);}}
		else
		{
			array<string,2> expectedAnswer = {"TopGear","Top Gear"};
			vector<string> exAns(expectedAnswer.begin(),expectedAnswer.end());
			if(checkAnswer(userSays,exAns))
			{
				clearBottom();
				show("That's what I'm talking about!",20,0,0);
				Sleep(1200);
				clearBottom();
				show("The hint is: finish the quest!",20,0,0);
				Sleep(2000);
				try{throw 5;}catch(int e){ask();}
			}
			else
			{
				clearBottom();
				show("Nope",20,0,0,1);
				Sleep(300);
				try{throw 5;}catch(int e){ask();}
			}
		}


		

	}
void commandSelectHero()
	{
		clearBottom();
		show("What character?",20,0,0,1);
		cout << ">>";
		string userSays;
		try{getline(cin,userSays);}catch(exception e){clearBottom();show("No comments",100,0,0,1,10);ask();}
		int cmd = itIsCommandNumber(userSays);
			if(cmd != -1)
		{try{throw cmd;}catch(int e){command(cmd);}}
		else
		{
			list1.printBag(userSays);
			try{throw 6;}catch(int e){ask();}
		}
		

	}
void commandGoToLocation()
	{
		clearBottom();
		show("Whom to move?",20,0,0,1);
		cout << ">>";
		string userSays;
		try{getline(cin,userSays);}catch(exception e){clearBottom();show("No comments",100,0,0,1,10);ask();}
		int cmd = itIsCommandNumber(userSays);
			if(cmd != -1)
		{try{throw cmd;}catch(int e){command(cmd);}}
		else
		{
			Bag* curr = list1.lobHead;
			while(curr != 0)
			{
				if(curr->nameb == userSays)
				{
					clearBottom();
					show("Where?",20,0,0,1);
					cout << ">>";
					try{getline(cin,userSays);}catch(exception e){clearBottom(); show("No comments",100,0,0,1,10); Sleep(200); ask();}
					int cmd = itIsCommandNumber(userSays);
					if(cmd != -1){try{throw cmd;}catch(int e){command(cmd);}}
					else
					{
					if(checkLocationAvailability(userSays))
					{
						curr->locationb = userSays;
						printLocation(curr->locationb);
						list1.printBag(curr->nameb);
						try{throw 7;}catch(int e){ask();}
					}
					else
					{
						clearBottom();
						show("Location is unavailable",20,0,0,1);
						Sleep(200);
						try{throw 7;}catch(int e){ask();}
					}
					}


				}
				curr = curr->nextb;
			}
			clearBottom();
			show("Who are you talking about?",20,0,0,1);
			Sleep(200);
			try{throw 7;}catch(int e){ask();}
		}
		
	}
void commandShowLocation()
	{
		clearBottom();
		show("What place to show?",20,0,0,1);
		cout << ">>";
		string userSays;
		try{getline(cin,userSays);}catch(exception e){clearBottom();show("No comments",100,0,0,1,10);ask();}
		int cmd = itIsCommandNumber(userSays);
	if(cmd != -1){try{throw cmd;}catch(int e){command(cmd);}}
	else
	{
		if(checkLocationAvailability(userSays))
		{
			printLocation(userSays);
			try{throw 8;}catch(int e){ask();}
		}
		else
		{
			clearBottom();
			show("No such place",20,0,0,1);
			Sleep(200);
			try{throw 8;}catch(int e){ask();}
		}
	}
	}
void commandMenu()
	{
		try{throw 9;}catch(int e){chooseChapter();}
	}

int  itIsCommandNumber(string userSays)
{
		
		int switcher = -1;
		for(std::vector<vector<string>>::iterator it = matrix.begin();it != matrix.end();++it)
		{
			for(std::vector<string>::iterator itt = (*it).begin();itt != (*it).end();++itt)
			{
				if(*itt == userSays)
				{
					switcher = 0;
					for(std::vector<vector<string>>::iterator itTrail = matrix.begin();itTrail != it;++itTrail)
					{
						++switcher;
					}
				}
			}
		}

		return switcher;
}
bool confirmation(int commandNumberToConfirm)
	{
		int counter = 0;
		while(counter < 3)
		{
			show("Are you sure?",20,0,0,1);
			cout<< ">>";
			string userSays;
			try{getline(cin,userSays);}catch(exception e){clearBottom();show("No comments...",100,0,0,1,10);ask();}
			
			clearBottom();
			int switcher = itIsCommandNumber(userSays);
				
			if(switcher == 1 || commandNumberToConfirm)
			{return true;}
			else if(switcher == 2)
			{return false;}
			else if(switcher != -1 && commandNumberToConfirm)
			{	
				try{throw switcher;}catch(int swr){command(switcher);}						
			}
			else
			{
				if(counter < 2)
				show("(yes or no please)",20,0,0,1);
			}
			counter++;
	}
			
			clearBottom();
			show("I think we'll talk later. Goodbye",50,0,0,1);
			Sleep(200);
			string EXITGAME = "EXITGAME"; throw EXITGAME;
		
	
	}

void setQuestStatus(string anything)
{
	questStatus = anything;return;
}
void setNotAvailableCommands(int disable[])
	{
		for(std::vector<int>::iterator itx = availableCommands.begin();itx != availableCommands.end();++itx)
		{*itx = 1;}

		vector<int> dis;
		for(int i = 0;i < sizeof(disable) / sizeof(int); ++i)
		{
			dis.push_back(disable[i]);
		}
		for(std::vector<int>::iterator it = dis.begin();it != dis.end();++it)
		{
			availableCommands[*it] = 0;
		}
		return;
	}

bool checkCommandAvailability(int cmdNumber)
	{
		if(availableCommands[cmdNumber] == 1)
		{
			return true;
		}
		else if(availableCommands[cmdNumber] == 0)
		{
			return false;
		}
	}
bool checkLocationAvailability(string location)
	{
		for(std::vector<string>::iterator it = availableLocations.begin(); it != availableLocations.end();++it)
		{
			if(location == *it)
			{return true;}
		}
		return false;
	}

void printLocation(string location)
{
	clearTop();
	clearMiddle();
	clearBottom();
	show(location,0,3,3,0,14);
	printQuestStatus();
	printCommands();
	list1.printBagsInLocation(location);
	clearBottom();
	return;
}
void printQuestStatus()
{
	show("Quest is ",0,0,8);show(questStatus,0,10,8,0,9);
	return;
}
void printCommands()
{
	int addition = 0;
	int counter = 0;
	for(std::vector<vector<string>>::iterator it = matrix.begin();it != matrix.end();++it)
	{
		if(checkCommandAvailability(counter))
		{
			std::vector<string>::iterator itt = (*it).begin();
			show(*itt,0,60,1+addition,0,1);
			addition++;
		}
		counter++;
	}
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
	GetConsoleScreenBufferInfo(console, &screen);
	counter = 0;
	int addition2 = 0;

	for(std::vector<vector<string>>::iterator it = matrix.begin();it != matrix.end();++it)
	{
		if(!checkCommandAvailability(counter))
		{
			std::vector<string>::iterator itt = (*it).begin();
			show(*itt,0,60,addition+1+addition2,0,4);
			addition2++;
		}
		counter++;
	}
	return;
}

void clearTop()
{
    COORD position  = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
	COORD lastPositionCursor = {screen.dwCursorPosition.X,screen.dwCursorPosition.Y};


    FillConsoleOutputCharacterA(console, ' ', screen.dwSize.X * 10, position, &written);
    FillConsoleOutputAttribute(console, 240,screen.dwSize.X * 10, position, &written );
    SetConsoleCursorPosition(console, lastPositionCursor);
}
void clearMiddle()
{
	COORD position  = { 0, 10 };
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;
	GetConsoleScreenBufferInfo(console, &screen);
	COORD lastPositionCursor = {screen.dwCursorPosition.X,screen.dwCursorPosition.Y};
	    
    FillConsoleOutputCharacterA(console, ' ', screen.dwSize.X * 6, position, &written);
    FillConsoleOutputAttribute(console, 240,screen.dwSize.X * 6, position, &written );
    SetConsoleCursorPosition(console, lastPositionCursor);
}
void clearBottom()
{
     COORD position  = { 0, 16 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

	GetConsoleScreenBufferInfo(console, &screen);
	    
    FillConsoleOutputCharacterA(console, ' ', screen.dwSize.X * 100, position, &written);
    FillConsoleOutputAttribute(console, 240,screen.dwSize.X * 100, position, &written );
    SetConsoleCursorPosition(console, position);
	
}

void chooseChapter()
{
		int counter = 0;
	label:
		clearBottom();
		show("Please choose the chapter: ",20,0,0,1);
		cout << ">>";
		string userSays;
		try{getline(cin,userSays);}catch(exception e){clearBottom();show("No comments",100,0,0,1,10);string EXITGAME = "EXITGAME";throw EXITGAME;}
		int cmd = itIsCommandNumber(userSays);
	if(cmd != -1)
	{	try{throw cmd;}catch(int e){command(cmd);}}
	else
	{
		clearBottom();
		array<string,3> expectedAnswer = {"1","one","One"};
		vector<string> exAns(expectedAnswer.begin(),expectedAnswer.end());
		if(checkAnswer(userSays,exAns))
		{
			try{throw 1;}catch(int e){chapterOne();}
		}
		else
		{
			if(counter < 2)
			{
			clearBottom();
			show("Sorry?",20,0,0);
			Sleep(1200);
			counter++;
			goto label;
			}
			else
			{
				clearBottom();
				show("I think we'll talk later. Bye!",20,0,0,1);
				Sleep(1200);
				string EXITGAME = "EXITGAME";throw EXITGAME;
			}
			
		}
	}

	
}
void chapterOne(int stage)

{
	clearTop();clearMiddle();clearBottom();
	
	list1.createBag("Harry Potter");
	list1.createItemPutItem("Wand","Harry Potter");
	list1.createItemPutItem("Cloak","Harry Potter");
	
	list1.createBag("Albus Dumbledore");
	
	list1.createItemPutItem("Elder wand", "Albus Dumbledore");
	list1.createItemPutItem("Horcrux", "Albus Dumbledore");
	
	list1.createBag("Lucius Malfoy","Coridor");
	list1.createItemPutItem("TR's diary", "Lucius Malfoy");

	int n[] = {1,2};
	setNotAvailableCommands(n);
	

	printLocation("Hogwarts");
	clearBottom();ask();
	
	
}