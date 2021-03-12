#include <stdio.h>
#include "main.h"
#include <stdlib.h>

int checkInput(char buffer[])
{
    int i = 0;
    for (; buffer[i] != '\0'; i++)
    {
        if (i > 3)
        {
            printf("Too big number! Try again!\n");
            return 0;
        }
        if (buffer[i] > '9' || buffer[i] < '0') return 0;
    }
    return 1;
}

void sum(int floor, int windowCount, int balconyCount)
{
    float sum = 0;
    sum = sum + windowCount*100 + balconyCount*3*100;
    if(floor > 1) sum*=1.15;
    sum += balconyCount*150;
    printf("Square of zasteklenie is %f(m^2)", (balconyCount*3 + windowCount)*2.15*1.5);
    printf("\nSum of steklopaket is $%f", sum);
}
void info()
{
    printf("\nShort information about the company");
}

int main()
{
    int floor, windowCount, balconyCount;
    char buffer[128];
    printf("Enter an integer floor number:\n");
    do
    {
        scanf("%s", buffer);
    } while (checkInput(buffer) == 0);
    floor = atoi(buffer);
    printf("Enter an integer widnow number:\n");
    do
    {
        scanf("%s", buffer);
    } while (checkInput(buffer) == 0);
    windowCount = atoi(buffer);
    printf("Enter an integer balcony number:\n");
    do
    {
        scanf("%s", buffer);
    } while (checkInput(buffer) == 0);
    balconyCount = atoi(buffer);
    sum(floor, windowCount, balconyCount);
    info();
    return 0;
}