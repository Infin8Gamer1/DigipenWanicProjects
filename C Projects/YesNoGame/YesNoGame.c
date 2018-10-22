/****************************
Filename: YesNoGame.c
Author: Jacob Holyfield
Date Last Edited: 9/20/18
Brief Description: A Yes/No Game where you are stuck on an island and are trying to escape/not die

gcc -Wall -Wextra -O -ansi -pedantic -o YesNoGame YesNoGame.c
****************************/

/*printf, scanf*/
#include <stdio.h>
/*rand, srand*/
#include <stdlib.h>
/*time*/
#include <time.h>

int main(void)
{	
	/*valid inputs will be y, n, and q to quit*/
	char input;
	/*-1 descibes the starter event, -2 describes end event*/
	int eventID = -1;
	int previousEventID = -1;
	/*change this if you want to add more events*/
	int maxEventID = 3;
	/*Add other game variables here, this could include a currency, special event triggers, how far down a specific event chain they are, ect.*/
	
	int TurnCounter = 0;
	/*Increment eventID or not 0-false 1-true*/
	int IncrementEventID = 1;
	
	/*Players Health*/
	int PlayerHealth = 100;
	/*Players Lazyness*/
	int PlayerLazyness = 100;
	
	/*EXAMPLE extra variable*/
	int event0Seq = 0;
	int event1Seq = 0;
	int event2Seq = 0;
	
	/*set random seed*/
	srand(time(NULL));
	/*Add the introduction to the game here, explain the rules to user */
	
	do
	{
		/*Reset Flags*/
		IncrementEventID = 1;
		/*setting input to 'a' resets the input*/
		input = 'a';
		
		/*increase turn timer by 1*/
		TurnCounter += 1;
		/*print Player HUD*/
		printf("\nTurn : %i\nHealth : %i\n", TurnCounter, PlayerHealth);
		
		/*print Debug stuff (have comented for normal gameplay but if you want to uncomment it you can)*/
		/*printf("\nDEBUG : EventID = %i Lazyness = %i\n", eventID, PlayerLazyness);*/
		
		/*Ask Questions here*/
		/*switch on the event, in each have something desribe what the options are (y/n)*/
		switch(eventID)
		{
			case -4:
				printf("You were way to lazy and died on the island. (Play GTA Wasted Sound Here (Or not because you were too lazy))\n\nWould You Like to Play Again?\n");
				break;
			case -3:
				printf("You Died on the island and are a failure. (Play GTA Wasted Sound Here)\n\nWould You Like to Play Again?\n");
				break;
			case -2:
				printf("Congrats You Escaped The island! You Had %i Health\n\nWould You Like to Play Again?\n", PlayerHealth);
				break;
			case -1:
				printf("Welcome your plane just crashed on a deserted island and you are the only survivor! Are you ready to start?\n");
				/*Reset Values To starting values if user decides to restart game*/
				PlayerLazyness = 100;
				PlayerHealth = 100;
				event0Seq = 0;
				event1Seq = 0;
				event2Seq = 0;
				break;
			case 0:
				if(event0Seq == 0)
				{
					printf("There are a ton of plane parts on the beach. Do you want to go look closer?\n");
				}
				else if(event0Seq == 1)
				{
					printf("Do you want to keep looking around?\n");
				}
				break;
			case 1:
				if(event1Seq == 0)
				{
					printf("Do you want to go investigate the glimmer?\n");
				}
				else if(event1Seq == 1)
				{
					printf("Would you like to take a bath in the river?\n");
				}
				else if(event1Seq == 2)
				{
					printf("Would You Like to fish?\n");
				}
				break;
			case 2:
				if(event2Seq == 0)
				{
					printf("You turn around and find a angry bear charging you! Should you run (yes) or should you fight it (no)?\n");
				}
				else if(event2Seq == 1)
				{
					printf("Where should you run to?\nDo You want to climb the hill (yes) or go to the plane crash(no)?\n");
				}
				else if(event2Seq == 2){
					printf("You find a spear laying on the ground! Use it to fight the bear?\n");
				}
				break;
			case 3:
				printf("You Hear a plane in the distance! Should you light a siginal flare that you found in the wreakage?\n");
				break;
		}
		
		printf("\n");
		/*Get User Input*/
		/*accept a character as input q quits everyting else should be n or y if none keep checking*/
		while(input != 'n' && input != 'y'&& input != 'q')
		{
			printf("Enter 'y' for yes or 'n' for no ('q' to quit): ");
			/*scanf goes here*/
			scanf(" %c", &input);
		}
		
		printf("\n");
		/*Output Answer to baised on input and eventID*/
		switch(eventID)
		{
			/*What to do if it is a game over/win state*/
			case -4:
			case -3:
			case -2:
				if (input == 'y'){
					/*Reset Values To starting values if user decides to restart game*/
					PlayerLazyness = 100;
					PlayerHealth = 100;
					IncrementEventID = 0;
					TurnCounter = 0;
					eventID = -1;
					event0Seq = 0;
					event1Seq = 0;
					event2Seq = 0;
					printf("Reseting ...");
				} else if(input == 'n'){
					input = 'q';
				}
				break;
			case -1:
				if(input == 'y')
				{
					printf("With any luck you will survive!\n");
				}
				else if(input == 'n')
				{
					printf("This is going to be fun... Don't be lazy!\n");
					PlayerLazyness -= 10;
				}
				break;
			case 0:
				switch(event0Seq){
					case 0:
						if(input == 'y')
						{
							int randHeal = 10 + rand() % (30 - 10);
							PlayerHealth += randHeal;
							printf("Good Choice! You find a medkit and heal %i\n", randHeal);
							++event0Seq;
							IncrementEventID = 0;
						}
						else if(input == 'n')
						{
							printf("You get up and see a glimmer on the hill!\n");
							PlayerLazyness -= 50;
						}
						break;
					case 1:
						if(input == 'y')
						{
							int randHeal2 = 10 + rand() % (30 - 10);
							PlayerHealth -= randHeal2;
							printf("You see a shiny object and try to pick it up. You accedently cut yourself and loose %i health.\n", randHeal2);
							printf("You notice a shiny object on the hill.\n");
						}
						else if(input == 'n')
						{
							printf("A glimmer on the hill catches your eye\n");
							
						}
						break;
				}
				break;
			case 1:
				switch(event1Seq){
					case 0:
						if(input == 'y')
						{
							printf("Very Wise. You found a river!\n");
							++event1Seq;
							IncrementEventID = 0;
						}
						else if(input == 'n')
						{
							printf("You are a lazy one aren't you.\n");
							PlayerLazyness -= 50;
						}
						break;
					case 1:
						if(input == 'y')
						{
							int randHeal3 = 20 + rand() % (50 - 20);
							PlayerHealth -= randHeal3;
							printf("The fish don't like this and are revolting!\n");
							printf("You loose %i health because they bit you\n", randHeal3);
						}
						else if(input == 'n')
						{
							printf("Thats probably a good idea! You look down and VERY CONVENIENTLY find a fishing pole!\n");
							++event1Seq;
							IncrementEventID = 0;
						}
						break;
					case 2:
						if(input == 'y')
						{
							int randHeal4 = 5 + rand() % (20 - 5);
							PlayerHealth += randHeal4;
							printf("The fish don't like this! However you still catch a few.\n");
							printf("You gain %i health because you ate the fish\n", randHeal4);
						}
						else if(input == 'n')
						{
							printf("You Drop the fishing pole!\n");
						}
						break;
				}
				break;
			case 2:
				switch(event2Seq){
					case 0:
						if(input == 'y')
						{
							printf("You start running but you look more like a duck!\n");
							++event2Seq;
							IncrementEventID = 0;
						}
						else if(input == 'n')
						{
							printf("The bear mauls you and you...\n");
							PlayerHealth -= 100;
							if(PlayerHealth <= 0){
								printf("DIE ): RIP\n");
							} else {
								printf("You were able to strangle it to death but it was a hard fight.\n");
							}
						}
						break;
					case 1:
						if(input == 'y')
						{
							printf("You run towards the hill to climb it but, the bear gets you and you are torn to shreads!\n");
							PlayerHealth -= 300;
						}
						else if(input == 'n')
						{
							printf("You run back to the crash site to find something to fight the bear with!\n");
							++event2Seq;
							IncrementEventID = 0;
						}
						break;
					case 2:
						if(input == 'y')
						{
							int missOrNot = rand() % 2;
							printf("You Throw the spear at the bear.\n");
							if(missOrNot == 0){
								printf("\nYou miss...\n");
								PlayerHealth -= 300;
							} else if(missOrNot == 1){
								printf("\nIt went strait into the bears face and it died!\n");
							} else {
								printf("ERROR RAND VALUE NOT 0 or 1\n");
							}
						}
						else if(input == 'n')
						{
							printf("You Stand there waiting for the bear. You have accepted your fate. This is the end. Good bye!\n\nThe bear stops and walks away.\n");
						}
						break;
				}
				break;
			case 3:
				if(input == 'y')
				{
					printf("The plane sees your siginal flare and tips its wing to let you know it sees you.\nAfter a few hours a hilicopter comes and rescues you!\n");
				} 
				else if (input == 'n')
				{
					printf("The plane flys by and you just sit there and watch it!\n");
					PlayerLazyness -= 200;
				}
		}
		
		/*Set Previous event ID*/
		previousEventID = eventID;
		
		/*reset event id with rand*/
		/*eventID = rand() % (maxEventID + 1);*/
		
		
		/*Increment Event up by one and check to see if it is at the end or not*/
		if(IncrementEventID) {
			eventID = eventID + 1;
			if (eventID > maxEventID) {
				eventID = -2;
			}
		}
		
		/*If previous event was less than starting value then make sure we go back to starting value*/
		if (previousEventID + 1 < -1){
			eventID = -1;
		}
		
		if (PlayerHealth <= 0) {
			eventID = -3;
		}
		if (PlayerLazyness <= 0) {
			eventID = -4;
		}
		
		/*make it so that if you quit it quits and doesnt require you to press enter again*/
		if(input != 'q'){
			printf("\nPress Enter to continue.\n");
			getchar();
		}
		getchar();
		
	}while(input != 'q');
	
	
	return 0;
}