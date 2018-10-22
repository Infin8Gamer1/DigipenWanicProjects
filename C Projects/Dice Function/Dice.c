/**********************************************
File Name = Dice.c
Authors = Jacob Holyfield
Edited On = 9/25/2018
Description = A Program to roll a dice!
Compiler Command = gcc -Wall -Wextra -ansi -pedantic -O -o Dice Dice.c
**********************************************/
/*printf, scanf*/
#include <stdio.h>
/*rand, srand*/
#include <stdlib.h>
/*time*/
#include <time.h>

int RollDice(int dieType, int numOfDice);

/*Main Program*/
int main() 
{
	/*init vars*/
	int dieType, numODice;
	
	/*set random seed*/
	srand(time(NULL));
	
	/*Get Input*/
	printf("Input NumODice and DieType. Use format (#d#) : ");
	scanf(" %i d %i", &numODice, &dieType);
	
	/*Return Output*/
	printf("\nYou Rolled : %i\n\n", RollDice(dieType, numODice));
	
	return 0;
}

int RollDice(int dieType, int numOfDice) {
	/*Init local vars*/
	int rollTotal = 0, i;
	
	/*Calculate rollTotal*/
	for(i = 0; i < numOfDice; i++){
		int diceRoll = (rand() % dieType) + 1;
		rollTotal += diceRoll;
	}
	
	return rollTotal;
}