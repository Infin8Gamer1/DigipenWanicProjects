/**********************************************
File Name = Fibonacci.c
Authors = Jacob Holyfield
Edited On = 9/21/2018
Description = A Program to ask how many terms of Fibonacci and print it out
Compiler Command = gcc -Wall -Wextra -ansi -pedantic -O -o Fibonacci Fibonacci.c
**********************************************/
#include <stdio.h>

/*Main Program*/
int main() 
{
	/*Init Vars*/
	long inputTermsOfFib = 0;
	long counter = 3;
	long Fn = 0;
	long Fn1 = 1;
	long Fn2 = 0;
	
	/*Get num of digits user wants*/
	printf("\nEnter the number of digits of Fibonacci : ");
	scanf("%li", &inputTermsOfFib);
	
	/*Print first 2 digits*/
	printf("\nn = %6i : %6li", 1, Fn2);
	printf("\nn = %6i : %6li", 2, Fn1);
	
	while(counter <= inputTermsOfFib){
		/*calculate and print current term*/
		Fn = Fn1 + Fn2;
		printf("\nn = %6li : %6li", counter, Fn);
		
		/*Set vars so next time it is the right number*/
		Fn2 = Fn1;
		Fn1 = Fn;
		counter += 1;
	}
	
	return 0;
}