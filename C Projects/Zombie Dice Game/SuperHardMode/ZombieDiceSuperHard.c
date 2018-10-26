/**********************************************
File Name = ZombieDiceSuperHard.c
Authors = Jacob Holyfield
Edited On = 10/26/2018
Description = A program to simulate the zombie dice game
Compiler Command = gcc -Wall -Wextra -ansi -pedantic -O -o ZombieDice ZombieDiceSuperHard.c
**********************************************/
#include <stdio.h>
#include <string.h>

enum HumanType{
	Runner,
	Brains,
	Shotgun
}

enum HumanColor{
	Red,
	Yellow,
	Green
}

/*Main Program*/
int main() 
{	
	int numPlayers;
	
	
	printf("Welcome To Zombie Dice! To win you must be the first player to collect 13 brains. On your turn you get 3 random dice from the pool of 13 dice. Each dice is a human.\n");
	
	printf("\nEnter Number Of Players : ");
	scanf("%i", numPlayers);
	
	
	
	return 0;
}