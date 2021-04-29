#include "main.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void test_checkInput()
{
	assert(checkInput("!") == 0);
	assert(checkInput("123") == 1);
	assert(checkInput("1") == 1);
	assert(checkInput("0") == 1);
	assert(checkInput("abdsa") == 0);
	assert(checkInput("10af") == 0);
}

void test_pathFinder(int **labyrinth)
{
	pathFinder(1,1,labyrinth,3);
	assert(labyrinth[1][0] == 3);
	assert(labyrinth[1][1] == 3);
}

void test_way(int **labyrinth)
{
	assert(way(3,labyrinth) == 1);
}

#undef main

int main()
{
	int i = 0, n = 3;
	int **labyrinth;
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
	}
	labyrinth[0][0] = 0;
	labyrinth[0][1] = 1;
	labyrinth[0][2] = 0;
	labyrinth[1][0] = 0;
	labyrinth[1][1] = 0;
	labyrinth[1][2] = 1;
	labyrinth[2][0] = 0;
	labyrinth[2][1] = 1;
	labyrinth[2][2] = 0;
	test_checkInput();
	test_pathFinder(labyrinth);
	test_way(labyrinth);
	for (i = 0; i < n; i++)
		free(labyrinth[i]);
	free(labyrinth);
	return 0;
}