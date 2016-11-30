#include <stdio.h>
#include<stdlib.h>

int main(void)
{
	int number, max, j, k,length, i;
	int *x_array;
	char RerunOption[3];

	printf("This program removes duplicate numbers inside the array\n\n");
	do
	{
	printf("\nEnter array length : ");
	scanf("%d",&length);
	
	/*Allocate memory for the array dynamically*/
	x_array = (int*)malloc(length*sizeof(int));
	
	printf("\nEnter %d numbers \n",length);
	
	for (i = 0; i < length; i++)
	     scanf("%d", &x_array[i]);

	/*Removing duplicate numbers from the array*/
	for (i = 0; i < length; i++)
	{
		for (j = i + 1; j < length;)
		{
			if (x_array[j] == x_array[i])
			{
				for (k = j; k < length; k++)
				{
					x_array[k] = x_array[k + 1];
				}
				length--;
			}
			else
				j++;
		}
	}
	for (i = 0; i < length; i++)
	{
		printf("%d ", x_array[i]);
	}

	printf("\n\nType yes to rerun? or Any other character to exit: ");
	scanf("%s", RerunOption);
	printf("\n\n");

	} while (strcmp(RerunOption, "yes") == 0);
	printf("\n\n");
	free(x_array);
	return 0;
	
}

