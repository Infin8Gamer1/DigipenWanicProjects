/******************************************************************************
FileName: main.c
Author: Jacob Holyfield
Date: 9/26/18

Brief Description:
  This file contains the main function for the pi assignment. It is used as
  a "driver" to test the circle_pi function and the leibniz_pi function.

gcc -Wall -Wextra -O -ansi -pedantic -o pi.exe main.c pi.c
******************************************************************************/
#include <stdio.h> /* scanf, printf */
#include "pi.h"

int main(void)
{
  int i; /* loop counter */

    /* Print out table header */
  printf("Approximations for pi\n");
  printf("Iterations      Circle Method   Leibniz Method\n");
  printf("----------------------------------------------\n");

    /* Print out values for each set of numbers */
  for (i = 1; i <= 1000000; i *= 10)
  {
      /* Calculate PI with both methods */
    double pi_circle = circle_pi(i);
    double pi_leibniz = leibniz_pi(i);

      /* Print the results of the calculations */
    printf("%10i%20.12f%16.12f\n", i, pi_circle, pi_leibniz);
  }

  return 0; /* Return to the OS */
}
