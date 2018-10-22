/**********************************************
File Name = HelloWorld.c
Authors = Jacob Holyfield
Edited On = 9/12/2018
Description = First C file to get style and HELLO WORLD!
Compiler Command = gcc -Wall -Wextra -ansi -pedantic -O -o Hello HelloWorld.c
**********************************************/
#include <stdio.h>
#include <string.h>


/*Main Program*/
int main() 
{
	char inputName[20];
	char outputName[20];
	
	int age;
	
	printf("Hello World!\n");
	
	printf("\nEnter Your Name : ");
	scanf("%s", inputName);
	/*gets(inputName);*/
	
	strcpy(outputName, inputName);
	/* outputName = inputName; */
	
	printf("\nEnter Your Age : ");
	scanf("%i", age);
	
	printf("\nYour Name Is %s and you are %i years old", outputName, age);
	
	return 0;
}