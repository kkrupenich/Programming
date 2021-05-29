#include <iostream>
#include <assert.h>
#include "pawnshop.h"
#include <vector>
#include <fstream>

using namespace std;

Pawnshop p;

void testInput()
{
    p.input();
    assert(p.itemList.size() == 6);
    assert(p.itemList[2].itemName == "Banana");
    assert(p.humanList.size() == 6);
    assert(p.humanList[5].passport == 51234);
}
void testCheck()
{
    unsigned int a;
    p.check(&a);
    assert(a < 0 == false);
}

int main()
{
    testInput();
    testCheck();
    return 0;
}
