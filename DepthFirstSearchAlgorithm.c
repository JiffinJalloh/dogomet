#include<stdio.h>
#define BUFFERSIZE 100

/*Declare a 2 Dimensional array for the adjacency mattrix;
  and a 1 Dimensional array for the visited nodes;*/

int AdjacentMatrix[BUFFERSIZE][BUFFERSIZE], visited[BUFFERSIZE], numberOfVertices;
/* the Depth first search algorithm*/
void DepthFirstAlgorithm(int i)
{
	int j;
	printf("\nVisited %d nodes\n\n", i);
	visited[i] = 1;

	for (j = 0; j<numberOfVertices; j++)
		if (!visited[j] && AdjacentMatrix[i][j] == 1)
			DepthFirstAlgorithm(j);
}

void main()
{
	int i, j;
	char RerunOption[3];
	do
	{
	printf("Enter number of vertices:");
	scanf("%d", &numberOfVertices);


	printf("\nEnter adjecency matrix of the graph: \n");
	for (i = 0; i<numberOfVertices; i++)
		for (j = 0; j<numberOfVertices; j++)
			scanf("%d", &AdjacentMatrix[i][j]);

	/*The algorithm was tested with the following adjacency mattrices
	  with 11 vertices

	         0 1 1 1 0 0 0 0 0 0 0
	         1 0 0 0 1 0 0 0 0 0 0
	         1 0 0 0 0 0 1 1 0 0 0
	         1 0 0 0 1 1 1 0 0 0 0
	         0 1 0 0 0 1 0 0 0 0 0
	         0 0 0 0 1 0 0 0 0 1 0
	         0 0 1 1 0 0 0 0 1 1 0
	         0 0 1 0 0 0 0 0 1 0 0
	         0 0 0 0 0 0 1 1 0 0 1
	         0 0 0 0 0 1 1 0 0 0 1
	         0 0 0 0 0 0 0 0 0 1 1
	

	before the itration begins visited is iniatilised to Zero*/

	for (i = 0; i<numberOfVertices; i++)
		visited[i] = 0;

	DepthFirstAlgorithm(0);
	printf("\n\nType yes to rerun? or Any other character to exit: ");
	scanf("%s", RerunOption);
	printf("\n\n\n");

	} while (strcmp(RerunOption, "yes") == 0);
	return 0;
}