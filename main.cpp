#include "UI.h"
#include <windows.h>

int main() {
	SetConsoleCP(437);
	SetConsoleOutputCP(437);

	UI test;

	string str = test.inputPoll();
	
	return 0;
}