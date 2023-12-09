
#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<string>
#include<fstream>

using namespace std;	

struct ship {
	int x = 0;
	int y = 0;
	int direction = 0;
	int deckNum = 0;
	bool isDestroyed = false;
};



#define width 10
