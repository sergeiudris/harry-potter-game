#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include "ListOfBags.h"
#include <array>
#include <vector>

using namespace std;


static array<int,10> availableCommands0 = {1,1,1,1,1,1,1,1,1,1};
static vector<int>   availableCommands(availableCommands0.begin(),availableCommands0.end());

static array<string,4> availableLocations0  = {"Hogwarts","Coridor","Shop","Cabinet"};
static vector<string>  availableLocations(availableLocations0.begin(),availableLocations0.end());

static string questStatus = "ON    ";
static int questStage = 0;

static array<string,4>			      quit	={"quit","Quit","exit","Exit"};
static array<string,8>			       yes	={"ok","Yes","y","yes","Ok","yeah","Yeah","sure"};
static array<string,8>			        no	={"no","No","n","not","Not","Nah","never","no way"};
static array<string,2>	      continueQuest	={"continue quest","return to quest"};
static array<string,1>		      moveItem	={"move item"};
static array<string,2>				  hint	={"hint","hint please"};
static array<string,1>		  	selectHero  ={"select hero"};
static array<string,1>		goToLocation	={"move hero"};
static array<string,1>		  showLocation	={"go to"};
static array<string,1>		          menu	={"menu"};

static vector<string>				   quit0	(quit.begin(),quit.end());
static vector<string>				    yes1	(yes.begin(),yes.end());
static vector<string>			         no2	(no.begin(),no.end());
static vector<string>		  continueQuest3	(continueQuest.begin(),continueQuest.end());
static vector<string>			   moveItem4	(moveItem.begin(),moveItem.end());
static vector<string>				   hint5	(hint.begin(),hint.end());
static vector<string>			 selectHero6	(selectHero.begin(),selectHero.end());
static vector<string>			goToLocation7	(goToLocation.begin(),goToLocation.end());
static vector<string>		   showLocation8	(showLocation.begin(),showLocation.end());
static vector<string>				   menu9	(menu.begin(),menu.end());

static array<vector<string>,10>	matrix0		={quit0,yes1,no2,continueQuest3,moveItem4,
												hint5,selectHero6,goToLocation7,
												showLocation8,menu9};
static vector<vector<string>>	matrix		(matrix0.begin(),matrix0.end());

void show(string input,int sleep = 50,int x = 0, int y = 0,
	int endline = 0, int fColor = 0, int bColor = 15);

void ask(int num = 0);

int  askForAnswer(string* expectedAnswer);
bool checkAnswer(string userSays,vector<string> exAns);

void command(int commandNumber);

void commandExit();
void commandYes();
void commandNo();
void commandContinueQuest();
void commandMoveItem();
void commandHint();
void commandSelectHero();
void commandGoToLocation();
void commandShowLocation();
void commandMenu();

int itIsCommandNumber(string userSays);
bool confirmation(int commandNumberToConfirm);

void setQuestStatus(string anything);
void setNotAvailableCommands(int disable[]);

bool checkCommandAvailability(int cmdNumber);
bool checkLocationAvailability(string location);

void printLocation(string location);
void printQuestStatus();
void printCommands();

void clearTop();
void clearMiddle();
void clearBottom();

void chooseChapter();
void chapterOne(int stage = questStage);

#endif