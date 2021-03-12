#include "main.h"
#include <assert.h>
#include <stdio.h>

void test_checkInput()
{
	assert(checkInput("!") == 0);
	assert(checkInput("123") == 1);
	assert(checkInput("1") == 1);
	assert(checkInput("0") == 1);
	assert(checkInput("abdsa") == 0);
	assert(checkInput("10af") == 0);
}

#undef main

int main()
{
	test_checkInput();
	return 0;
}