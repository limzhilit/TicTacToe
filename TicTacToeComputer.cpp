// Lim Zhi Lit
// Project Tic Tac Toe
// 10/03/2024

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int isValidInputX(int x);
int isValidInputY(int y);
bool hasWon(char *ptr);
void printBoard(char *ptr);

int main()
{
	srand(time(0));
	char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
	char *ptr = &board[0][0];
	int x, y;

	for (int i = 9; i > 0; i--)
	{
		if (i % 2)
		{
			cout << "Player 1's turn (X): \n";
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
		}
		else
		{
			cout << "Computer's turn (O): \n";
			do
			{
				x = rand() % 3 + 1; // Random x coordinate (1-3)
				y = rand() % 3 + 1; // Random y coordinate (1-3)
			} while (board[x - 1][y - 1] != ' '); // Check if position is occupied
			cout << "Computer chose: " << x << ", " << y << "\n";
		}

		// Input validation and checking if position is occupied

		board[x - 1][y - 1] = (i % 2) ? 'X' : 'O';

		printBoard(ptr);
		if (hasWon(ptr))
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
	while (cin.fail() || x < 1 || x > 3)
	{
		cout << "Invalid input. Please enter a number between 1 and 3: ";
		cin.clear();			// Clear error state
		cin.ignore(1000, '\n'); // Discard invalid input
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

void printBoard(char *ptr)
{
	cout << "   |   |   \n";
	cout << " " << *(ptr) << " | " << *(ptr + 1) << " | " << *(ptr + 2) << "\n";
	cout << "___|___|___\n";
	cout << "   |   |   \n";
	cout << " " << *(ptr + 3) << " | " << *(ptr + 4) << " | " << *(ptr + 5) << "\n";
	cout << "___|___|___\n";
	cout << "   |   |   \n";
	cout << " " << *(ptr + 6) << " | " << *(ptr + 7) << " | " << *(ptr + 8) << "\n";
	cout << "   |   |   \n";
}

bool hasWon(char *ptr)
{
	for (int i = 0; i < 3; i++)
	{
		// Check rows
		if (*(ptr + i * 3) != ' ' && *(ptr + i * 3) == *(ptr + i * 3 + 1) && *(ptr + i * 3 + 1) == *(ptr + i * 3 + 2))
			return true;

		// Check columns
		if (*(ptr + i) != ' ' && *(ptr + i) == *(ptr + i + 3) && *(ptr + i + 3) == *(ptr + i + 6))
			return true;
	}

	// Check diagonals
	if (*(ptr) != ' ' && *(ptr) == *(ptr + 4) && *(ptr + 4) == *(ptr + 8))
		return true;
	if (*(ptr + 2) != ' ' && *(ptr + 2) == *(ptr + 4) && *(ptr + 4) == *(ptr + 6))
		return true;

	return false;
}