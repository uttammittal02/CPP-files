#include <iostream>
#include <set>
#include <stdbool.h>
#include <stdio.h>
#define N 4
using namespace std;

void printSolution(int board[N][N])
{
    cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << (board[i][j] == 0? '.' : 'Q');
		cout << endl;
	}
}

bool isSafe(int board[N][N], int row, int col)
{
	int i, j;

	for (i = 0; i < col; i++)
		if (board[row][i])
			return false;

	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (board[i][j])
			return false;

	for (i = row, j = col; j >= 0 && i < N; i++, j--)
		if (board[i][j])
			return false;

	return true;
}

bool solveNQUtil(int board[N][N], int col)
{

	if (col >= N)
		printSolution(board);

	for (int i = 0; i < N; i++) {
		if (isSafe(board, i, col)) {

			board[i][col] = 1;


			if (solveNQUtil(board, col + 1))
				return true;

	
			board[i][col] = 0;
		}
	}

	return false;
}

bool solveNQ(int n)
{
	int board[N][N] = { { 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 } };

	if (solveNQUtil(board, 0) == false) {
		cout << "Solution does not exist\n";
		return false;
	}

	return true;
}

int main()
{
    int n; 
    cin >> n;
	solveNQ(n);
	return 0;
}

