#include <stdio.h>
#include "main.h" 

void centre(char text[], int sent[])
{
    int i = 0, j = 0, k = 0, m = 0;

    for (i = 0; i < 4; i++)
    {
        for(; text[m] != '.'; m++)
        {
            sent[i]++;
        }
        m++;
        for(k = 0; k < (40 - sent[i] / 2); k++)
        {
            putchar(' ');
        }
        while (text[j] != '.')
        {
            printf("%c",text[j]);
            j++;
        }
        j++;
        printf(".\n");
    }
}

int main()
{
    char text[] = "Far beyond the mountains and tresses of the sea."
    "Dark horizons black will rumble with the voice of prophecy."
    "We are standing steadfast against a gathering dark."
    "As our battle-iron flashes countless foul beasts will fall."; 
    int sent[4] = {0,0,0,0};
    centre(text, sent);
    return 0;
}
