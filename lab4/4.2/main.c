#include <stdio.h>
#include "main.h"

/* counting letters, finding max percent(k), printing the percentage of letters */
int arr(int array[], char buffer[])
{
    int i = 0, k = 0;
    for(i = 0; i < 26; i++)
        array[i] = 0;
    for(i = 0; i < 103; i++)
    {
        if (buffer[i] != ' ')
            {
                array[buffer[i]- 'a']++;
                k++;
            }
    }
    putchar('\n');
    for(i = 0; i < 26; i++)
    {
        array[i] = array[i] * 100 / k ;
    }
    k = 0;
    for(i = 0; i < 26; i++)
    {
        if(array[i] > k)
        {
            k = array[i];
        }
    }
    for(i = 0; i < 26; i++)
        printf("%c - %d\n",buffer[i], array[i]);
    putchar('\n');
    return k;
}

/* printing vertical histogram */
void gist(int array[], int k)
{
    int i = 0, j = 0;
    printf("Vertical histogram\n");
    for(i = 99 - k; i < 100; i++)
    {
        for(j = 0; j < 26; j++)
        {
            if(i < 100 - array[j])
                printf(". ");
            else
                printf("* ");
        }
        putchar('\n');
    }
    printf("a b c d e f g h i j k l m n o p q r s t u v w x y z");
}

int main()
{
    int k = 0;
    int array[26];
    char buffer[103];
    FILE *file = fopen("text.txt", "r");
    if (!file)
	{
		printf("File can not be opened or not found.\n");
		return 1;
	}
    fgets(buffer, 104, file);
    printf("%s\n", buffer);
    fclose(file);
    k = arr(array, buffer);
    gist(array, k);
    return 0;
}