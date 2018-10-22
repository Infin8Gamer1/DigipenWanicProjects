/******************************************************************************
Filename: array.c
Author: Jacob Holyfield
Date: 10/17/2018
Brief Description: A file that has vector math and array stuff
gcc -O -Wall -Wextra -ansi -pedantic main1.c array.c -o array1
******************************************************************************/

/*Given an array, reverse the order of the elements in the array. Do not create another array in the function.*/
void reverse_array(int a[], int size)
{
	/*setup vars*/
	int i, temp;
	
	/*loop through  half of the array*/
	for(i = 0; i < size/2; i++){
		/*store value of current element in temp*/
		temp = a[i];
		/*set the element to the element on the inverse side of the array*/
		a[i] = a[size - 1 - i];
		/*set the element on the inverse of the array to the temp value AKA a[i]*/
		a[size - 1 - i] = temp;
	}
}

/*Given three arrays, add the elements of the first two arrays and put the sum in the third array.*/
void add_arrays(const int a[], const int b[], int c[], int size)
{
	/*setup vars*/
	int i;
	
	/*loop through the arrays and add a and b for each part of c*/
	for(i = 0; i < size; i++){
		c[i] = a[i] + b[i];
	}
}

/*Given an array and a multiplier, multiply each element by the multiplier.*/
void scalar_multiply(int a[], int size, int multiplier)
{
	/*setup vars*/
	int i;
	
	/*Loop through array and multiply by the scaler*/
	for(i = 0; i < size; i++){
		a[i] = a[i] * multiplier;
	}
}

/*Given two arrays, determine the dot product (multiply each corresponding element and sum the products). Return the value.*/
int dot_product(const int a[], const int b[], int size)
{
	/*setup vars*/
	int i, output = 0;
	
	/*loop through arrays and multiply each component and add the result to the output*/
	for(i = 0; i < size; i++){
		output += a[i] * b[i];
	}
	
	return output;
}

/*Given three arrays, determine the cross product of the first two.
The cross product is another array and will be placed into the third array. The size of all three arrays will always be 3.*/
void cross_product(const int a[], const int b[], int c[])
{
	/*Do cross prod math*/
	c[0] = a[1]*b[2] - a[2]*b[1];
	c[1] = -(b[2]*a[0] - b[0]*a[2]);
	c[2] = a[0]*b[1] - a[1]*b[0];
}
