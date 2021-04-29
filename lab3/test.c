#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int positiveIntInput(char buffer[])
{
	int i = 0, result;
	for (; buffer[i] != '\0'; i++)
	{
		if (i > 8)
			return 0;
		if (buffer[i] > '9' || buffer[i] < '0')
			return 0;
	}
	result = atoi(buffer);
	if (result == 0)
		return 0;
	return 1;
}

void sortArrAscendingOrder(int *arr, int arrSize)
{
	int i, j, temp;
	for (i = 0; i < arrSize; i++)
	{
		for (j = i + 1; j < arrSize; j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int main()
{
	int n, m;
	int **arr;
	int tempArr[128];
	char buffer[128];
	int tempArrInd;
	int i, j, i1, j1;
	printf("Enter N (positive integer):\n");
	scanf("%s", buffer);
	while (positiveIntInput(buffer) == 0)
	{
		printf("Incorrect input! Enter positive integer number (<9 digits)!\n");
		scanf("%s", buffer);
	}
	n = atoi(buffer);
	printf("Enter M (positive integer):\n");
	scanf("%s", buffer);
	while (positiveIntInput(buffer) == 0)
	{
		printf("Incorrect input! Enter positive integer number (<9 digits)!\n");
		scanf("%s", buffer);
	}
	m = atoi(buffer);

	arr = (int **)malloc(n * sizeof(int *));
	if (arr == NULL)
	{
		printf("Allocation ERROR");
		return 1;
	}
	for (i = 0; i < n; i++)
	{
		arr[i] = (int *)malloc(m * sizeof(int));
		if (arr[i] == NULL)
		{
			printf("ALLOCATION ERROR");
			exit(1);
		}
		for (j = 0; j < m; j++)
		{
			printf("Enter arr[%d][%d] (positive integer):\n", i + 1, j + 1);
			scanf("%s", buffer);
			while (positiveIntInput(buffer) == 0)
			{
				printf("Incorrect input! Enter positive integer number (<9 digits)!\n");
				scanf("%s", buffer);
			}
			arr[i][j] = atoi(buffer);
		}
	}

	printf("Printing array:\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	printf("\n");
	for (j = 0; j < m; j++)
	{
		i1 = 0, j1 = j, tempArrInd = 0;
		while (i1 < n && j1 < m)
		{
			tempArr[tempArrInd] = arr[i1][j1];
			tempArrInd++;
			i1++;
			j1++;
		}
		sortArrAscendingOrder(tempArr, tempArrInd);
		i1 = 0, j1 = j, tempArrInd = 0;
		while (i1 < n && j1 < m)
		{
			arr[i1][j1] = tempArr[tempArrInd];
			tempArrInd++;
			i1++;
			j1++;
		}
	}

	for (i = 0; i < n; i++)
	{
		i1 = i, j1 = 0, tempArrInd = 0;
		while (i1 < n && j1 < m)
		{
			tempArr[tempArrInd] = arr[i1][j1];
			tempArrInd++;
			i1++;
			j1++;
		}

		sortArrAscendingOrder(tempArr, tempArrInd);
		i1 = i, j1 = 0, tempArrInd = 0;
		while (i1 < n && j1 < m)
		{
			arr[i1][j1] = tempArr[tempArrInd++];
			i1++;
			j1++;
		}
	}

	printf("Final array\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("%d ", arr[i][j]);
		}

		printf("\n");
	}

	/*
	Clearing mem
	*/
	for (i = 0; i < n; i++)
		free(arr[i]);
	free(arr);
	return 0;
}