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
#define CONTINUE "continue"

map<string, pair<int, int>> dirMap {
	{ UP, {-1, 0} },    // Moving up decreases row (Y-axis) I always get this shit fucked up god dammit
	{ RIGHT, {0, 1} },  // Moving right increases column (X-axis)
	{ DOWN, {1, 0} },   // Moving down increases row (Y-axis)
	{ LEFT, {0, -1} }   // Moving left decreases column (X-axis)
};

map <int, string> inputArrowMap = {		//key scancode maps to direction of arrow key
	{72, UP},
	{77, RIGHT},
	{80, DOWN},
	{75, LEFT}
};

map <int, string> colorMap = {
	{0, RED},
	{1, ORANGE},
	{2, YELLOW },
	{3, GREEN},
	{4, BLUE},
	{5, MAGENTA},
	{6, WHITE},
	{7, BLACK},
	{8, CYAN},
	{9, GREY}
};


string UI::inputPoll() {			//stops program and waits for input currently. Most likely this will be intended behavior.
	int key = _getch();

	if (key == 27) {
		return ESCAPE;
	}

	if (key >= 48 && key <= 57) {
		int value = key - 49;
		return to_string(value);
	}

	int scanCode = _getch();

	if (key == 224) { //arrow key processing 
		for (map<int, string>::iterator it = inputArrowMap.begin(); it != inputArrowMap.end(); ++it) {
			if (it->first == scanCode)	//224
				return it->second;
		
		}
	}
	else {
		throw UI::InputError();
	}
}

void UI::beginProgram() 
{
	bool quitting = false;
	string input;
	int anyKey; 

	while (!quitting) 
	{ 
		system("cls");

		printScreen();

		try 
		{
			input = inputPoll();
		}

		catch (UI::InputError e) 
		{
			cout << e.what() << endl << "Press any key to continue..." << endl;;
			anyKey = _getch();
			continue;
		}

		try 
		{
			processInput(input, quitting);
		}

		catch (Board::BoundsError e) 
		{
			cout << e.what() << endl << "Press any key to continue..." << endl;
			anyKey = _getch();
			continue;
		}
	}
}

void UI::processInput(string inputEvent, bool& quitting) 
{

	if (inputEvent == ESCAPE) {
		quit();
		return;
	}

	if (inputEvent == UP || inputEvent == DOWN || inputEvent == LEFT || inputEvent == RIGHT) {
		for (map<string, pair<int, int>>::iterator it = dirMap.begin(); it != dirMap.end(); ++it) {
			if (inputEvent == it->first) {
				pair<int, int> dir = it->second;
					pixelBoard.moveCursor(dir.first, dir.second);
					return;
	
			}
		}
	}

	else if (isdigit(inputEvent[0])) {
		int keyVal = stoi(inputEvent);
		
		auto it = colorMap.find(keyVal);
		if (it != colorMap.end()) {
			pixelBoard.getCurrPixel()->setColor(it->second);
		}
		else {
			cout << "Error: color code nto found";
		}
	}
}

void UI::printScreen() {

	//system("cls");

	TextStructs.HeaderStruct.print();

	cout << endl;

	pixelBoard.printBoard();

	cout << endl;

	TextStructs.DefaultStruct.print();

}

bool UI::quit() {
	system("cls");
	TextStructs.QuitStruct.print();
	
	bool inputValid = false;
	while(!inputValid) {
		string input;

		try {
			input = inputPoll();
		}
		
		catch (UI::InputError e) {
			cout << e.what() << endl;
			continue;
		}

		if (input == CONTINUE) {
			return false;
		}
		else if (input == QUIT) {
			return true;
		}

		inputValid = true;

	}
	return false;
}

