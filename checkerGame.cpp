#include "checkerGame.h"
#include <iostream>
#include <cstdlib>

using namespace std;

checkerGame::checkerGame()
{
	initBoard();
	loopGame();
	int again = 0;
	system("CLS");
	printBoard();
	cout << "Do you want to play again?" << endl;
	cout << "1 = Yes 0 = No\n";
	cin >> again;
	if (again == 1)
	{
		checkerGame();
	}
	
}

void checkerGame::writeBoard(int x, int y)
{
	if (turn == 'X')
	{
		if (board[x][y] == '.')
		{
			board[x][y] = 'X';
			turn = 'O';
		}
	}
	else
	{
		if (board[x][y] == '.')
		{
			board[x][y] = 'O';
			turn = 'X';
		}
	}
}

void checkerGame::loopGame()
{
	if(trues == 1)
	{
		system("CLS");
		printBoard();

		int x;
		int y;

		cin >> x;
		cin >> y;
		x -= 1;
		y -= 1;
		writeBoard(x,y);
		trues = checkWin();
		loopGame();
	}
}

int checkerGame::checkWin()
{
	for (int pos = 0; pos < 3; pos++)
	{
		if (board[pos][0] == board[pos][1] && board[pos][1] == board[pos][2] && board[pos][0] == 'X' || board[0][pos] == 'O')
		{
			return 0;
		}
		else if (board[0][pos] == board[1][pos] && board[1][pos] == board[2][pos] && board[0][pos] == 'X' || board[0][pos] == 'O')
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	return 1;
}

void checkerGame::initBoard()
{
	turn = 'X';
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			board[x][y] = { '.' };
		}
	}
}


void checkerGame::printBoard()
{
	cout << "---------\n";
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			cout << "|";
			cout << board[x][y];
			cout << "|";
		}
		cout << endl;
		cout << "---------\n";
	}
}