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
#define ESCAPE "escape"

#define COLORSCREEN "colorscreen"
#define DEFAULT "default"
#define QUIT "quit"

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

	if (key != 224 && key != 27 && key != 13) {				//Right now if key doesn't equal arrow key just return the key.
		throw UI::InputError();
	}
	if (key == 27) {
		return ESCAPE;
	}
	if (key == 13) {
		return ENTER;
	}

	int scanCode = _getch();

	if (key == 224) { //arrow key processing 
		for (map<int, string>::iterator it = inputArrowMap.begin(); it != inputArrowMap.end(); ++it) {
			if (it->first == scanCode)	//224
				return it->second;
		}
		cout << "Error: Recognized key as 224 -- Did not recognize a scan code belonging to an UP/DOWN/L/R Arrow Key press" << endl;
	}
}

void UI::beginProgram() 
{
	bool quitting = false;
	string input;

	while (!quitting) 
	{ 
		system("cls");		//should clear screen if my memory is right
		pixelBoard.printBoard();

		try 
		{
			string input = inputPoll();
		}
		catch (UI::InputError e) 
		{
			cout << e.what() << endl << "Press any key to continue..." << endl;;
			_getch();
			continue;
		}

		try 
		{
			processInput(input, quitting);
		}

		catch (Board::BoundsError e) 
		{
			cout << e.what() << endl << "Press any key to continue..." << endl;
			_getch();
			continue;
		}
	}
}

void UI::processInput(string inputEvent, bool& quitting) 
{

	if (inputEvent == ESCAPE) {
		printScreen(QUIT);
	}

	if (inputEvent == ENTER) {
		printScreen(COLORSCREEN);
	}

	if (inputEvent == UP || inputEvent == DOWN || inputEvent == LEFT || inputEvent == RIGHT) {
		for (map<string, pair<int, int>>::iterator it = dirMap.begin(); it != dirMap.end(); ++it) {
			if (inputEvent == it->first) {
				pair<int, int> dir = it->second;
					pixelBoard.moveCursor(dir.first, dir.second);
	
			}
		}
	}
}

void UI::printScreen(string currBottom) {
	system("cls");
	TextStructs.Header(); 

	cout << endl;
	pixelBoard.printBoard();
	cout << endl;

	if (currBottom == DEFAULT) {
		
	}

	else if (currBottom == COLORSCREEN) {
		
	}

	else if (currBottom == QUIT) {
		
	}


}

bool UI::quit() {
	//cout would you like to quit yn

}

