/***********************************
TicTacToe.c
10/9/18
Programmed By: The Masked Programmer and Jacob Holyfield
Brief: Tic Tac Toe game with some missing components to be fixed.
gcc -Wall -Wextra -ansi -pedantic -O -o TicTacToe TicTacToe.c
***********************************/
/*printf scanf*/
#include <stdio.h>

/*function prototypes*/
/*function will need to look at the grid and determine if there is a winner or if it is a tie*/
int CheckGrid(int Grid[][3]);
/*print out the board for the players*/
void printBoard(int Grid[][3]);

/*contains main game loop and player input runs other functions*/
int main(void)
{
	/*2D array for our grid, 3x3*/
	int Grid[3][3] = {{-1,-1,-1},{-1,-1,-1},{-1,-1,-1}};
	/* 0 is for O 1 is for X*/
	int playerTurn = 1;
	int input;
	int gameState = CheckGrid(Grid);
	printf("Welcome to Tic Tac Toe!\nTake turns with another player chosing places.\n");
	
	while(gameState == -1)
	{
		/*display board with numbers*/
		printBoard(Grid);
		if(playerTurn == 1)
		{
			printf("Player X's Turn, select your position:\n");
		}
		else
		{
			printf("Player O's Turn, select your position:\n");
		}
		/*Get input from the current player*/
		while(1)
		{
			scanf(" %i", &input);
			if(input >= 0 && input < 9 && Grid[input/3][input%3] == -1)
			{
				/*legal input found*/
				Grid[input/3][input%3] = playerTurn;
				break;
			}
			printf("Invalid Input\n");
			while(getchar() != '\n');
		}
		/*change playerturn*/
		if(playerTurn)
		{
			playerTurn = 0;
		}
		else
		{
			playerTurn = 1;
		}
		gameState = CheckGrid(Grid);
	}
	printBoard(Grid);
	/*determines winner*/
	switch(gameState)
	{
		case 0:
		printf("Player O Wins!\n");
		break;
		case 1:
		printf("Player X Wins!\n");
		break;
		case 2:
		printf("Tie!\n");
		break;
	}
	return 0;
}

/*function will need to look at the grid and determine if there is a winner or if it is a tie*/
int CheckGrid(int Grid[][3])
{
	int x, y;
	/*horizontal loop through all on one row*/
	for (x = 0; x < 3; x++){
		if((Grid[x][0] == Grid[x][1] && Grid[x][1] == Grid[x][2]) && Grid[x][0] != -1){
			return Grid[x][0];
		}
	}
	/*verticle loop through all on one column*/
	for (y = 0; y < 3; y++){
		if((Grid[0][y] == Grid[1][y] && Grid[1][y] == Grid[2][y]) && Grid[0][y] != -1){
			return Grid[0][y];
		}
	}
	
	/*diagonals check all at once*/
	if((Grid[0][0] == Grid[1][1] && Grid[1][1] == Grid[2][2]) && Grid[0][0] != -1){
		return Grid[0][0];
	}
	if((Grid[2][0] == Grid[1][1] && Grid[1][1] == Grid[0][2]) && Grid[2][0] != -1){
		return Grid[2][0];
	}
	
	/*make sure not tie aka game isnt finished yet*/
	for (x = 0; x < 3; x++) {
		for (y = 0; y < 3; y++){
			if (Grid[x][y] == -1)
			{
				return -1;
			}
		}
	}
	
	/*it is a tie if it gets here*/
	return 2;
}
/*print out the board for the players*/
void printBoard(int Grid[][3])
{
	int i,j;
	for(i = 0; i <3; i++)
	{
		printf("|");
		for(j = 0 ; j < 3 ; j++)
		{
			switch(Grid[i][j])
			{
				case -1:
				printf(" %i |", i * 3 + j );
				break;
				case 0:
				printf(" O |");
				break;
				case 1:
				printf(" X |");
				break;
			}
		}
		printf("\n\n");
	}
	return;
}