#include "main.h"
#include <assert.h>
#include <stdio.h>

void test_arr(int array[], char buffer[])
{
    arr(array,buffer);
    assert(array[0] == 7);
    assert(array[1] == 3);
    assert(array[4] == 4);
    assert(array[23] == 3);
    assert(array[25] == 2);
}
#undef main

int main()
{
	char buffer[103] = "abcdefghijklmnopqrstuvwxyz hellow world and ljkadfjhasld bbxlakdfhj qweuppioqru fxlamzfjashdhf yqhgrwe";
    int array[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    test_arr(array, buffer);
    return 0;
}