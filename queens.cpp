#define N 8 // for 8x8 board
#include <iostream>
#include<stdio.h>

//displays the chessboard as output (8x8 grid)
void disp_board(int chess_board[N][N])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf(" %d ", chess_board[i][j]);
		printf("\n");
	}
}

//check if the queen is in legal position
bool check_queen_position(int chess_board[N][N], int row, int col)
{
	int i, j;

	
	for (i = 0; i < col; i++)
		if (chess_board[row][i]) // if already there
			return false;

	
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (chess_board[i][j]) //go to previous row
			return false;

	
	for (i = row, j = col; j >= 0 && i < N; i++, j--)
		if (chess_board[i][j]) // go to next row
			return false;

	return true;
}



bool n_queens(int chess_board[N][N], int col)
{
	
	if (col >= N) // if reached end of columns
		return true;

	
	for (int i = 0; i < N; i++) {
		
		if (check_queen_position(chess_board, i, col)) {
			
			chess_board[i][col] = 1; // put 1 if position is legal 

			
			if (n_queens(chess_board, col + 1)) //check next
				return true;

			
			chess_board[i][col] = 0; //else put zero in display
		}
	}

	
	return false;
}


bool n_queens_check()
{	//chessboard layout
	int chess_board[N][N] = { { 0, 0, 0, 0 },
							{ 0, 0, 0, 0 },
							{ 0, 0, 0, 0 },
							{ 0, 0, 0, 0 } };

	if (n_queens(chess_board, 0) == false) {
		printf("Error");
		return false;
	}

	disp_board(chess_board);
	return true;
}


int main()
{
	n_queens_check();
	return 0;
}
