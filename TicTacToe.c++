// Lim Zhi Lit
// Project Tic Tac Toe
// 10/03/2024

#include <iostream>
using namespace std;

int isValidInputX(int x);
int isValidInputY(int y);
bool hasWon(char board[3][3]);
void printBoard(char board[3][3]);

int main()
{
	char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
	int x, y;

	for (int i = 9; i > 0; i--)
	{
		if (i % 2)
		{
			cout << "Player 1's turn (X): \n";
		}
		else
		{
			cout << "Player 2's turn (O): \n";
		}

		// Input validation and checking if position is occupied
		do
		{
			cout << "Please enter x coordinate (1-3): ";
			cin >> x;
			x = isValidInputX(x);
			cout << "Please enter y coordinate (1-3): ";
			cin >> y;
			y = isValidInputY(y);

			if (board[x - 1][y - 1] != ' ')
			{
				cout << "Position already taken! Choose another.\n";
			}
		} while (board[x - 1][y - 1] != ' ');

		board[x - 1][y - 1] = (i % 2) ? 'X' : 'O';

		printBoard(board);
		if (hasWon(board))
		{
			cout << "Player " << ((i % 2) ? "1" : "2") << " wins!\n";
			return 0;
		}
	}

	cout << "It's a tie!\n";
	return 0;
}

int isValidInputX(int x)
{
	while (x < 1 || x > 3)
	{
		cout << "Invalid input. Please enter a number between 1 and 3: ";
		cin >> x;
	}
	return x;
}

int isValidInputY(int y)
{
	while (y < 1 || y > 3)
	{
		cout << "Invalid input. Please enter a number between 1 and 3: ";
		cin >> y;
	}
	return y;
}

void printBoard(char board[3][3])
{
	cout << "   |   |   \n";
	cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
	cout << "___|___|___\n";
	cout << "   |   |   \n";
	cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
	cout << "___|___|___\n";
	cout << "   |   |   \n";
	cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n";
	cout << "   |   |   \n";
}

bool hasWon(char board[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
			return true;
		if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
			return true;
	}
	if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
		return true;
	if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
		return true;

	return false;
}