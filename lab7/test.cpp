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
    ifstream file("test.txt");
    unsigned int a;
    if(file.is_open())
    {
        while(!file.eof())
        {
            p.check(&a, &file);
            assert(a < 0 == false);
        }
    }
    file.close();
    ofstream file2("test.txt");
    if(file2.is_open())
        file2 << "iphone " << 1200 << ' ' << 700 << endl << "amazing " << 413 << ' ' << 123;
    file.close();
}

void testAddToItemList()
{
    ifstream file("test.txt");
    if(file.is_open())
        while(!file.eof())
            p.addToItemList(&file);

    assert(p.itemList[6].itemName == "iphone");
    assert(p.itemList[7].moneyToHuman == 123);
    file.close();

    ofstream file2("test.txt");
    if(file2.is_open())
        file2.clear();
    file2 << "Egor " << "Krupenich " << 1234123 << "amazing " << "boy " << 123;
    file.close();
}

void testAddToHumanList()
{
    ifstream file("test.txt");
    if(file.is_open())
        while(!file.eof())
            p.addToHumanList(&file);
    assert(p.humanList[6].firstname == "Egor");
    assert(p.humanList[7].passport == 123);
    file.close();

    ofstream file2("test.txt");
    if(file2.is_open())
        file.clear();
    file.close();
}

int main()
{
    testInput();
    testCheck();
    testAddToItemList();
    testAddToHumanList();
    return 0;
}