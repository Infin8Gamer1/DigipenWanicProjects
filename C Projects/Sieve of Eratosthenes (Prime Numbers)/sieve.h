/**********************************************
File Name = main.c
Authors = Jacob Holyfield
Edited On = 10/10/2018
Description = Used to calculate prime numbers between 0 and a given number
Compiler Command = gcc -Wall -Wextra -ansi -pedantic -O -o PrimeNumberCalc main.c sieve.c
**********************************************/
#define FALSE 0
#define TRUE  1

void sieve(int array[], int size);
int twin_primes(const int primes[], int size);
double brun_constant(const int primes[], int size);