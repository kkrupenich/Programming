#include "main.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "math.h"

void test_factorial()
{
    assert(factorial(2) == 2);
    assert(factorial(3) == 6);
    assert(factorial(1) == 1);
    assert(factorial(5) == 120);
}
void test_calcRight()
{
    assert(calcRight(1,1,3) == 1);
    assert(calcRight(5,5,2) == 0.089631);
    assert(calcRight(3,2,1) == 0.933333);
}
void test_positiveIntegerInput()
{
    assert(positiveIntegerInput("!") == 0);
    assert(positiveIntegerInput("123") == 1);
    assert(positiveIntegerInput("1") == 1);
    assert(positiveIntegerInput("0") == 0);
    assert(positiveIntegerInput("abdsa") == 0);
    assert(positiveIntegerInput("10af") == 0);
    assert(positiveIntegerInput("1486168416486518416.548447") == 0);
    assert(positiveIntegerInput("0.01") == 0);
    assert(positiveIntegerInput("-0.01") == 0);
}
void test_FloatInput()
{
    assert(FloatInput("!") == 0);
    assert(FloatInput("123") == 1);
    assert(FloatInput("1") == 1);
    assert(FloatInput("0") == 1);
    assert(FloatInput("abdsa") == 0);
    assert(FloatInput("10af") == 0);
    assert(FloatInput("1486168416486518416.548447") == 0);
    assert(FloatInput("0.01") == 1);
    assert(FloatInput("-0.01") == 1);
}

#undef main

int main()
{
	test_factorial();
	return 0;
}
