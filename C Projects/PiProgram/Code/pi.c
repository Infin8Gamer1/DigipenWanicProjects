/******************************
FileName: Pi.c
Name: Jacob Holyfield
Date: 9/26/18
Brief Description: The Functions used to calculate Pi

note: -Werror treats all warnings as errors, use this when you want to make sure there are no warnings.
gcc -Wall -Wextra -O -ansi -pedantic -o pi.exe main.c pi.c
*******************************/
/*sqrt*/
#include <math.h>
#include <stdio.h> /* scanf, printf */

/* Calculates PI using a quarter circle */
double circle_pi(int rectangles)
{
	double RectWidth =  2.0 / rectangles;
	double TotalArea = 0;
	int i = 0;
	
	while (i < rectangles){
		double midPoint = (i * RectWidth) + (RectWidth/2.0);
		
		double height = sqrt((2.0*2.0) - (midPoint*midPoint));
		
		double area = height * RectWidth;
		
		/*Debug Stuff*/
		/*printf("midPoint = %f, %i\n", midPoint, i);
		printf("Area = %f, %i\n", area, i); 
		printf("height = %f, %i\n", height, i); */
		
		
		TotalArea += area;
		i += 1;
	}
	
	return TotalArea;
}


/* Calculates PI using a series */
double leibniz_pi(int iterations)
{
	double Numerator = 1;
	double Denominator = 1;
	double Pi = 0;
	int i;
	
	for (i = 0; i < iterations; i++){
		/*Check if i is even*/
		if(i%2 == 0){
			Pi += Numerator / Denominator;
		} else{
			Pi -= Numerator / Denominator;
		}
		Denominator += 2;
	}
	
	return Pi * 4;
}