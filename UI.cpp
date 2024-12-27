#include "UI.h"
#include <conio.h>	//input polling
#include <iostream>
#include <utility>	//pairs
#include <map>		

using namespace std;

#define UP "up"
#define DOWN "down"
#define LEFT "left"
#define RIGHT "right"
#define ENTER "enter"

map <string, pair<int, int>> dirMap { //for taking return string from input poll and then changing selected piece on board
	{ UP, {0,1} },
	{ RIGHT, {1,0} },
	{ DOWN, {0,-1} },
	{ LEFT, {-1, 0}}
};

map <int, string> inputArrowMap = {		//key scancode maps to direction of arrow key
	{72, UP},
	{77, RIGHT},
	{80, DOWN},
	{75, LEFT}

};

string UI::inputPoll() {			//stops program and waits for input currently. Most likely this will be intended behavior.
	int key = _getch();
	
	if (key != 224 || key != 27 || key != 13) {				//Right now if key doesn't equal arrow key just return the key.
		throw UI::InputError();
	}

	int scanCode = _getch();


	//27 is code for escape key
	//13 is enter 
	if(key == 224 ) { //arrow key processing 
		for (map<int, string>::iterator it = inputArrowMap.begin(); it != inputArrowMap.end(); ++it) {
			if (it->first == scanCode)	//224
				return it->second;	
			}
		cout << "Error: Recognized key as 224 -- Did not recognize a scan code belonging to an UP/DOWN/L/R Arrow Key press" << endl;
	}
	

	//if key == enter
}

void UI::beginProgram() {

}

void UI::processInput(string inputEvent) {

}


