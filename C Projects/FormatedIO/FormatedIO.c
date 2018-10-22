/**********************************************
File Name = FormatedIO.c
Authors = Jacob Holyfield
Edited On = 9/13/2018
Description = Shows how to use input and output
Compiler Command = gcc -Wall -Wextra -ansi -pedantic -O -o FormatedIO FormatedIO.c
**********************************************/
#include <stdio.h>

/*Main Program*/
int main() 
{	
	int numberOfGamesOwned = 63;
	char nameOfGameMostPlayed[128] = "TF2";
	int hoursPlayed = 200;
	double preferedPricePerGame = 25.13;
	
	printf("\nEnter Your Number Of Games Owned : ");
	scanf("%i", &numberOfGamesOwned);
	
	printf("\nEnter the name of the game you play the most : ");
	scanf("%s\n", nameOfGameMostPlayed);
	
	printf("\nEnter the number of hours logged : ");
	scanf("%i", &hoursPlayed);
	
	printf("\nEnter your prefered price per game : ");
	scanf("%lf", &preferedPricePerGame);
	
	printf("\nYou have %i Games!\n", numberOfGamesOwned);
	printf("Your Favorite Game is %s\n", nameOfGameMostPlayed);
	printf("You Have %i Hours Played\n", hoursPlayed);
	printf("Your Prefered Price Per Game Is %.2f\n", preferedPricePerGame);
	
	return 0;
}