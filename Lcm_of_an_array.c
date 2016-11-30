#include <stdio.h>
#include<stdlib.h>

/*Function to compute the LCM of an array of n numbers*/

int Function_lcm(int a, int b)
{
	int Gcd = ComputeGcd(a, b);
	return (a*b) / Gcd;
}

int main()
{
	int *x_array, i, ArrayLength, LcmOfNumers = 1;
	char RerunOption[3];

    printf("This program takes an array of integers and find their LCM\n\n");
	do
	{
	printf("Please Enter array length : ");
	scanf("%d", &ArrayLength);
    
	/*Allocate memory for the array dynamically*/
	x_array = (int*)malloc(ArrayLength*sizeof(int));
	
	printf("\nEnter %d numbers to calculate their lcm : ", ArrayLength);
	for (i = 0; i < ArrayLength; i++)
		scanf("%d", &x_array[i]);
	for (i = 0; i < ArrayLength; i++)
		LcmOfNumers = Function_lcm(LcmOfNumers, x_array[i]);

	printf("\nThe LCM for the %d numbers you entered is %d \n\n", ArrayLength, LcmOfNumers);
	printf("\n\nType yes to rerun? or Any other character to exit: ");
	scanf("%s", RerunOption);
	printf("\n\n\n");

	} while (strcmp(RerunOption, "yes") == 0);
	free(x_array);
	return 0;
}

/* Function to Compute the greatest common divisor for two numbers say a and b*/

int ComputeGcd(int a, int b)
{
	int y;
	if (a > b)
	{
		y = a;
		a = b;
		b = y;
	}
	if (b%a == 0)
		return a;
	else
	{

		return ComputeGcd(b%a, a);
	}
}
