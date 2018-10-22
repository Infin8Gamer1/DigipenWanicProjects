/********************
FileName: Pi.h
Name: Jacob Holyfield
Date: 9/26/18
Brief Description: The Header file for the Functions used to calculate Pi

note: -Werror treats all warnings as errors, use this when you want to make sure there are no warnings.
gcc -Wall -Wextra -O -ansi -pedantic -o pi.exe main.c pi.c
*********************/

/* Calculates PI using a quarter circle */
double circle_pi(int rectangles);

/* Calculates PI using a series */
double leibniz_pi(int iterations);