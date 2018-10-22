/**********************************************
File Name = BitwiseOperators.c
Authors = Jacob Holyfield
Edited On = 9/12/2018
Description = To show how & and | work
Compiler Command = gcc -Wall -Wextra -ansi -pedantic -O -o BitWise BitwiseOperators.c
**********************************************/
#include <stdio.h>
#include <string.h>


/*Main Program*/
int main() 
{
	char a = 100;
	char b = 125;
	char c = 75;
	
	printf("Starting Numbers a = %x b = %x c = %x\n", a, b, c);
	
	printf("a & b is %x, a & c is %x, b & c is %x\n", a&b, a&c, b&c);
	
	printf("a | b is %x, a | c is %x, b | c is %x\n", a|b, a|c, b|c);
	
	return 0;
}