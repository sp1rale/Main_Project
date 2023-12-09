#include "Player.h"
void printRules();
char LoadFields;

struct Menu {
	Menu(Player& a, Player& b) {
		int choise;
		cout << "Welcome to sea battle!!!" << endl;
		do {
			cout << "1.New game" << endl << "2.Сontinue the game" << endl << "3.Rules" << endl << "4.Exit" << endl;
			cin >> choise;
			system("cls");
			switch (choise) {
			case 1: {
				Gamemode(a.autoPut, b.autoPut, a.autoPlay, b.autoPlay);
				int playerNumber = 1;
				a.SettingFlot(playerNumber);
				playerNumber = 2;
				b.SettingFlot(playerNumber);
			}break;
			case 2: {
				LoadGame(a, "Files\\Player 1.bin", "Files\\Player 1 Flot.bin");
				LoadGame(b, "Files\\Player 2.bin", "Files\\Player 2 Flot.bin");
			}break;

			case 3:
				printRules();
				break;
			default:exit(0);
			}
			system("cls");
		} while (choise != 1 && choise != 2);

		cout << "Press any key to continue" << endl;
		_getch();
	}
	void StartGame(Player a, Player b) {
		bool turn = true;
		bool gameOver = false;
		while (!gameOver) {
			if (!gameOver) {
				while (turn) {
					gameOver = a.PlayerTurn(a, b, 1, turn);
					turn = false;
				}
			}
			if (gameOver) {
				cout << "Player 1 wins!!!" << endl;
				system("pause");
				exit(0);
			}
			if (!gameOver) {
				while (!turn) {
					gameOver = b.PlayerTurn(b, a, 2, turn);
					turn = true;
				}
			}
			if (gameOver) {
				cout << "Player 2 wins!!!" << endl;
				system("pause");
				exit(0);
			}

		}
	}
};


void printRules() {

	cout << "Battleship rules" << endl;
	cout << "1.\t= - Empty cell " << endl << "\tS - Ship " << endl << "\tX - Destroyed ship" << endl;
	cout << "2.\tShips can't be stacked next to each other." << endl << "\t(only like this)\n";
	cout << "\t  0 1 2 3 4 5 6 7 8 9" << endl << "\tA = = = = = = = = = =" << endl << "\tB = = = = = S S S = =" << endl << "\tC = = S S S = = = = =" << endl << "\tD = = = = = = = = = =" << endl;
	cout << "3.\tTo save the game, enter  \"save\"" << endl;
	system("pause");
	system("cls");
}

