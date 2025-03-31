// Lim Zhi Lit
// Project Tic Tac Toe
// 10/03/2024

#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <regex>

using namespace std;
string validateInput(string __space);
string inputMove(int w, string _space, string _board);
int validateP1(string __board);
int validateP2(string __board);

int main()
{
	string board = "   |   |   \n 1 | 2 | 3 \n---|---|---\n 4 | 5 | 6 \n---|---|---\n 7 | 8 | 9 \n   |   |   \n";
	string space;

	cout << board << endl;

	for (int i = 9; i > 0; i--)
	{
		if (i % 2)
		{
			cout << "Player 1's turn, choose a space: ";
			cin >> space;
			space = validateInput(space);
			board = inputMove(i, space, board);
			cout << board << endl;
			if (validateP1(board))
			{
				cout << "Player 1 wins!" << endl;
				return 0;
			}
		}
		else
		{
			cout << "Player 2's turn, choose a space: ";
			cin >> space;
			space = validateInput(space);
			board = inputMove(i, space, board);
			cout << board << endl;
			if (validateP2(board))
			{
				cout << "Player 2 wins!" << endl;
				return 0;
			}
		}
	}
	cout << "It's a draw!" << endl;
	return 0;
}

string validateInput(string __space)
{
	while (true)
	{
		if (__space[0] < '1' || __space[0] > '9' || __space[1] != '\0')
		{
			cout << "Invalid input, please enter a number between 1 and 9: ";
			cin >> __space;
		}
		else
		{
			return __space;
		}
	}
}

string inputMove(int w, string _space, string _board)
{
	int found = _board.find(_space);
	while (true)
	{
		if (found == -1)
		{
			cout << "The space has been taken, please enter an available space: ";
			cin >> _space;
			found = _board.find(_space);
		}
		else
		{
			if (w % 2)
			{
				_board.replace(found, 1, "x");
				return _board;
			}
			else
			{
				_board.replace(found, 1, "o");
				return _board;
			}
		}
	}
}

int validateP1(string __board)
{
	regex horizontal("x.{3}x.{3}x");
	regex vertical("x[^]{23}x[^]{23}x");
	regex diagonal("x[^]{27}x[^]{27}x");
	regex diagonal2("x[^]{19}x[^]{19}x");
	if (regex_search(__board, horizontal) || regex_search(__board, vertical) || regex_search(__board, diagonal) || regex_search(__board, diagonal2))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int validateP2(string __board)
{
	regex horizontal("o.{3}o.{3}o");
	regex vertical("o[^]{23}o[^]{23}o");
	regex diagonal("o[^]{27}o[^]{27}o");
	regex diagonal2("o[^]{19}o[^]{19}o");
	if (regex_search(__board, horizontal) || regex_search(__board, vertical) || regex_search(__board, diagonal) || regex_search(__board, diagonal2))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}