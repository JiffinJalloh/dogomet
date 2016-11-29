#include <stdio.h>
#define CONSTANT 100

/*A function to get the greatest common divisor for two numbers say a and b*/

int getGcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return getGcd(b, a % b);
}

/*A function to rotate an array of N elements M times */

void RotateArrayByNTimes(int *x_array, int numberOfArrayElements, int numberOfRotations) {
	int i, j, k, temp;
	int	gcd = getGcd(numberOfRotations, numberOfArrayElements);

	for (i = 0; i < gcd; i++) {
		temp = x_array[i];
		j = i;
		while (1) {
			k = j + numberOfArrayElements;
			if (k >= numberOfRotations)
				k = k - numberOfRotations;
			if (k == i)
				break;
			x_array[j] = x_array[k];
			j = k;
		}
		x_array[j] = temp;
	}
}

int main(){

	int i, numberOfRotation, numberOfArrayElements, x_array[CONSTANT];
	char RerunOption[3];
	printf("This program takes an array of integers and rotate them N times\n\n");
	/*Request for the number of elements in the array*/
	do
	{
	printf("Please Enter Array length : ");
	scanf("%d", &numberOfArrayElements);

	printf("\nPlease Enter %d numbers for this array :\n", numberOfArrayElements);
	for (i = numberOfArrayElements - 1; i >= 0; i--)
		scanf("%d", &x_array[i]);

	printf("\nThe Original Array Entered\n : ");
	for (i = numberOfArrayElements - 1; i >= 0; i--){
		printf("%d ", x_array[i]);
	}
	/*The number of rotation should not be a negative number*/
	do
	{
		printf("\n\nNote: the number should not be negative");
		printf("\n\nPlease Enter the number of times you want to Rotate the Array : ");
		scanf("%d", &numberOfRotation);
		if (numberOfRotation > numberOfArrayElements)
			numberOfRotation = (numberOfRotation%numberOfArrayElements);

	} while ((numberOfRotation < 0));
		
	RotateArrayByNTimes(x_array, numberOfRotation, numberOfArrayElements);

	printf("\nRotated Array\n\n");
	for (i = numberOfArrayElements - 1; i >= 0; i--){
		printf("%d ", x_array[i]);
	}
	printf("\n\nThe Array was rotated %d times\n",numberOfRotation );
	printf("\n\nType yes to rerun? or Any other character to exit: ");
	scanf("%s", RerunOption);
	printf("\n\n\n");

    }while (strcmp(RerunOption, "yes") == 0);

	return 0;
}