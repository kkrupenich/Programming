#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int checkInput(char buffer[])
{
    int i = 0;
    for (; buffer[i] != '\0'; i++)
    {
        if (i > 2)
        {
            printf("Too big number! Try again!\n");
            return 0;
        }
        if (buffer[i] > '9' || buffer[i] < '0') return 0;
    }
    return 1;
}
void checkAnswer(int number)
{
    if(number == 0)
    {
        printf("zero");
        return;
    }
    switch(number/100)
    {
    case 1:
        printf("one hundred ");
        break;
    case 2:
        printf("two hundred ");
        break;
    case 3:
        printf("three hundred ");
        break;
    case 4:
        printf("four hundreed ");
        break;
    case 5:
        printf("five hundred ");
        break;
    case 6:
        printf("six hundred ");
        break;
    case 7:
        printf("seven hundred ");
        break;
    case 8:
        printf("eight hundred ");
        break;
    case 9:
        printf("nine hundred ");
        break;
    default: 
        break;
    }
    switch(number%100)
    {
        case 10:
            printf("ten");
            return;
        case 11:
            printf("eleven");
            return;
        case 12:
            printf("twelve");
            return;
        case 13:
            printf("thirteen");
            return;
        case 14:
            printf("fourteen");
            return;
        case 15:
            printf("fifteen");
            return;
        case 16:
            printf("sixteen");
            return;
        case 17:
            printf("seventeen");
            return;
        case 18:
            printf("eighteen");
            return;
        case 19:
            printf("nineteen");
            return;
        default:
            break;
    }
    switch(number/10%10)
    {
        case 2:
            printf("twenty ");
            break;
        case 3:
            printf("thirty ");
            break;
        case 4:
            printf("fourty ");
            break;
        case 5:
            printf("fifty ");
            break;
        case 6:
            printf("sixty ");
            break;
        case 7:
            printf("seventy ");
            break;
        case 8:
            printf("eighty ");
            break;
        case 9:
            printf("ninety ");
            break;
        default:
            break;
    }
    switch(number%10)
    {
        case 1:
            printf("one");
            break;
        case 2:
            printf("two");
            break;
        case 3:
            printf("three");
            break;
        case 4:
            printf("four");
            break;
        case 5:
            printf("five");
            break;
        case 6:
            printf("six");
            break;
        case 7:
            printf("seven");
            break;
        case 8:
            printf("eight");
            break;
        case 9:
            printf("nine");
            break;
        default:
            break;
    }
}
int main()
{
    int number;
    char buffer[128];
    printf("Enter an integer number from 0 to 999:\n");
    do
    {
        scanf("%s", buffer);
    } while (checkInput(buffer) == 0);
    number = atoi(buffer);
    checkAnswer(number);
    return 0;
}