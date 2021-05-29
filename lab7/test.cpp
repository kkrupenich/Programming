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


int main()
{
    testInput();
    return 0;
}