#include "main.h"
#include <assert.h>
#include <stdio.h>

void test_centre(char text[],int sent[])
{
	centre(text,sent);
	assert(sent[0] == 47);
	assert(sent[1] == 58);
	assert(sent[2] == 50);
	assert(sent[3] == 58);
	assert((40 - sent[0] / 2) == 17);
	assert((40 - sent[1] / 2) == 11);
	assert((40 - sent[2] / 2) == 15);
	assert((40 - sent[3] / 2) == 11);
}

#undef main

int main()
{
	char text[] = "Far beyond the mountains and tresses of the sea."
    "Dark horizons black will rumble with the voice of prophecy."
    "We are standing steadfast against a gathering dark."
    "As our battle-iron flashes countless foul beasts will fall.";
	int sent[4] = {0,0,0,0};
	test_centre(text, sent);
	return 0;
}