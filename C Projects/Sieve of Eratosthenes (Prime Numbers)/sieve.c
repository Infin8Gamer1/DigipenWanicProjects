/**********************************************
File Name = main.c
Authors = Jacob Holyfield
Edited On = 10/10/2018
Description = Used to calculate prime numbers between 0 and a given number
Compiler Command = gcc -Wall -Wextra -ansi -pedantic -O -o PrimeNumberCalc main.c sieve.c
**********************************************/
#include <stdio.h> /* printf      */
#include <math.h>  /* sqrt, abs   */
#include "sieve.h" /* TRUE, FALSE */

void sieve(int array[], int size)
{
	int i, j;
	
	/*set 0 and 1 to false*/
	array[0] = array[1] = FALSE;
	/*Set everything to true*/
	for(i = 2; i <= size; i++){
		array[i] = TRUE;
	}
	/*we check each number only up to the sqrt of size since any thing bigger will be accounted for*/
	for (i = 2; i <= sqrt(size); i++)
	{
		if (array[i] == TRUE){
			for (j = i+1; j <= size; j++){
				if (j % i == FALSE){
					array[j] = FALSE;
				}
			}
		}
	}
}

int twin_primes(const int primes[], int size)
{
	/*Init Vars*/
	int output = 0, i, j;
	/*Start a loop to check every number up to the size of the array*/
	for (i = 2, j = 4; j <= size; i++, j++){
		/*Are both numbers prime and is there a diffrence of 2
		  If So then they are twin primes*/
		if (primes[i] && primes[j] && abs(i - j) == 2){
			output++;
			printf("twin prime #%4i: %4i and %4i\n", output, i, j);
		}
	}
	
	return output;
}

double brun_constant(const int primes[], int size)
{
	double brunNum = 0;
	int i;
	
	for (i = 2; i <= size; i++){
		if (primes[i] && primes[i+2] && abs(i - (i+2)) == 2){
			brunNum += (1.0 / i) + (1.0 / (i + 2));
		}
	}
	
	return brunNum;
}