#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"

int checkInput(char buffer[])
{
    int i = 0;
    for (; buffer[i] != '\0'; i++)
    {
        if (i > 8)
        {
            printf("Too big number! Try again!\n");
            return 0;
        }
        if (buffer[i] > '9' || buffer[i] < '0') return 0;
    }
    return 1;
}

void printLabyrinth(int n, int **labyrinth)
{
	int i, j;
	printf("Printing labyrinth:\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d ", labyrinth[i][j]);
		}
		printf("\n");
	}
}

void pathFinder(int i, int j, int **labyrinth, int n)
{
    while (1)
	{
		if (i == 0 || i == n - 1 || j == 0 || j == n - 1)
		{
			labyrinth[i][j] = 3;
			break;
		}
		else if (labyrinth[i + 1][j] != 0 && labyrinth[i - 1][j] != 0 && labyrinth[i][j + 1] != 0 && labyrinth[i][j - 1] != 0)
		{
			labyrinth[i][j] = 3;
			break;
		}
		else if (labyrinth[i + 1][j] == 0)
		{
			labyrinth[i][j] = 3;
			pathFinder(i + 1, j, labyrinth, n);
		}
		else if (labyrinth[i - 1][j] == 0)
		{
			labyrinth[i][j] = 3;
			pathFinder(i - 1, j, labyrinth, n);
		}
		else if (labyrinth[i][j + 1] == 0)
		{
			labyrinth[i][j] = 3;
			pathFinder(i, j + 1, labyrinth, n);
		}
		else if (labyrinth[i][j - 1] == 0)
		{
			labyrinth[i][j] = 3;
			pathFinder(i, j - 1, labyrinth, n);
		}
	}
}

int way(int n, int **labyrinth)
{
	int i, j;
	int path = 0;
	for(i = 0; i < n; i++)
		if(labyrinth[i][0] == 3 || labyrinth[i][n-1] == 3)
			path++;
	for(j = 1; j < n - 1; j++)
		if(labyrinth[0][j] == 3 || labyrinth[n-1][j] == 3)
			path++;
	return path;
}

int main()
{
	int **labyrinth;
	int n = 0;
    int i, j;
	char buffer[128];
	int path = 0;

    printf("Enter size of labyrinth: ");
	scanf("%s", buffer);
    while (checkInput(buffer) == 0)
	{
		printf("Incorrect input! Enter positive integer number (<9 digits)!\n");
		scanf("%s", buffer);
	}
	n = atoi(buffer);

	srand(time(NULL));
    labyrinth = (int **)malloc(n * sizeof(int *));
	if(labyrinth == NULL)
	{
		printf("error");
		exit(1);
	}
	for (i = 0; i < n; i++)
	{
		labyrinth[i] = (int *)malloc(n * sizeof(int));
		if(labyrinth == NULL)
		{
			printf("error");
			exit(1);
		}
		for (j = 0; j < n; j++)
        {
				labyrinth[i][j] = rand()%2;
        }
	}
	printLabyrinth(n, labyrinth);

    printf("Select the starting point (it should be zero):\n");
	while(1)
	{	
		scanf("%s", buffer);
    	while (checkInput(buffer) == 0)
		{
			printf("Incorrect I! Enter positive integer number (<9 digits)!\n");
			scanf("%s", buffer);
		}
		i = atoi(buffer);

		scanf("%s", buffer);
    	while (checkInput(buffer) == 0)
		{
			printf("Incorrect J! Enter positive integer number (<9 digits)!\n");
			scanf("%s", buffer);
		}
		j = atoi(buffer);

		if(labyrinth[i][j] == 1) printf("This pole is 1, choose zero idiot\n");
		else break;
	}

	pathFinder(i, j, labyrinth, n);
	printLabyrinth(n, labyrinth);
	path = way(n, labyrinth);
	if(path == 0)
		printf("There is no way");
	else
		printf("there is %d way(s)", path);

    for (i = 0; i < n; i++)
		free(labyrinth[i]);
	free(labyrinth);
    return 0;
}