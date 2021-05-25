#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "math.h"

int numberE;

int factorial(int n)
{
    if(n < 0) return 0;
    if (n == 0) return 1;
    else return n * factorial(n-1);
}

float calcRight(float x, int n, float E)
{
	int i;
	float result = 0, right = 0;
	for (i = 1; i <= n || abs(sin(x) - right) <= E; i++)
    {
		if (2 * i - 1 > 42) return result;
        right += pow(-1, (i-1)) * (pow(x, (2*i-1)) / factorial(2*i-1));
		if (i == n) result = right;
		if (abs(sin(x) - right) <= E && numberE == 0) numberE = i;
	}
	return result;
}

int positiveIntegerInput(char buffer[])
{
    int i = 0, result;
    for (; buffer[i] != '\0'; i++)
    {
        if (i > 8) return 0;
        if (buffer[i] > '9' || buffer[i] < '0') return 0;
    }
	result = atoi(buffer);
	if (result == 0) return 0;
    return 1;
}

int FloatInput(char buffer[])
{
	int i;
		
	if (strlen(buffer) > 20) return 0;
	for (i = 0; i<strlen(buffer); i++)
	{
		if ((buffer[i] > '9' || buffer[i] < '0') && buffer[i] != '.' && buffer[i] != '-') return 0;
	}
    return 1;
}


int main()
{
    float x, E;
    int n;
	char buffer[128];

    printf("Enter integer N:\n");
	scanf("%s", buffer);
    while (positiveIntegerInput(buffer) == 0)
    {
		printf("Incorrect input! Enter positive integer number (<9 digits)!\n");
		scanf("%s", buffer);
	}
	n = atoi(buffer);

    printf("Enter float X:\n");
	scanf("%s", buffer);
    while (FloatInput(buffer) == 0)
    {
		printf("Incorrect input! Enter float number (<9 digits)!\n");
		scanf("%s", buffer);
	}
	x = atof(buffer);


	printf("Enter float E:\n");
	scanf("%s", buffer);
    while (FloatInput(buffer) == 0)
    {
		printf("Incorrect input! Enter real number (<9 digits)!\n");
		scanf("%s", buffer);
	}
	E = atof(buffer);
	E = abs(E);
    printf("left = %f, right = %f\n", sin(x), calcRight(x,n, E));
	printf("When N = %d\n", numberE);

    return 0;
}
