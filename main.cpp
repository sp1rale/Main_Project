#include "Menu.h"

const int col = 100; 
const int row = 40;

int main() {
	setlocale(0, "");
	HANDLE wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT windowSize = { 0,0,col - 1,row - 1 };
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
	COORD bufferSize = { col,row };
	SetConsoleScreenBufferSize(wHnd, bufferSize);
	

	Player a;
	Player b;
	Menu menu(a, b);
	menu.StartGame(a, b);

    return 0;
}

