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
            assert((a < 0) == false);
        }
    }
    file.close();
    ofstream file2("test.txt");
    if(file2.is_open())
        file2 << "iphone " << 1200 << ' ' << 1300 << ' ' << 700 << endl << "amazing " << 0 << ' ' << 413 << ' ' << 123;
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
    file2 << "Leo " << "Galante " << 1234123 << ' ' << "amazing " << "morkovka " << 0 << ' ' << 123;
    file.close();
}

void testAddToHumanList()
{
    ifstream file("test.txt");
    if(file.is_open())
        while(!file.eof())
            p.addToHumanList(&file);
    assert(p.humanList[6].firstname == "Leo");
    assert(p.humanList[7].passport == 123);
    file.close();

    ofstream file2("test.txt");
    if(file2.is_open())
        file.clear();
    file2 << 3 << ' ' << 1 << ' ' << 10 << ' ' << 1 << ' ' << 50 << ' ' << 2 << ' ' 
        << 1300 << ' ' << 1200 << endl << 3 << ' ' << 2 << ' ' << 10 << ' ' << 4 << ' ' << 0 << ' ' << 123321
        << endl << 1 << ' ' << 1 << ' ' << 1 << ' ' << 700 << ' ' << 12000;
    file.close();
}

void testChangeInfo()
{
    ifstream file("test.txt");
    if(file.is_open())
        while(!file.eof())
            p.changeInfo(&file);

    assert(p.itemList[1].moneyToHuman == 1200);
    assert(p.humanList[4].passport == 123321);
    file.close();

    ofstream file2("test.txt");
    if(file2.is_open())
        file.clear();
    file2 << 10 << ' ' << 1 << ' ' << 10 << ' ' << 0 << ' ' << ' ' << 10 << ' ' << 1 << ' ' << 10 << ' ' << 0 << ' ' 
        << 10 << ' ' << 2 << ' ' << 10 << ' ' << 0 << ' ' << 10 << ' ' << 2 << ' ' << 10 << ' ' << 0;
    file.close();
}

void testDeleteInfo()
{
    ifstream file("test.txt");
    if(file.is_open())
        while(!file.eof())
            p.deleteSmth(&file);

    assert(p.itemList.size() == 4);
    assert(p.humanList.size() == 4);
    file.close();

    ofstream file2("test.txt");
    if(file2.is_open())
        file2.clear();
    file2.close();
}

void testShowAll()
{
    ofstream file("test.txt");
    if(file.is_open())
        p.showAll(&file);
    file.close();

    ifstream file2("test.txt");
    if(file2.is_open())
    {
        string temp;
        file2 >> temp;
        assert(temp == "Item");
        file2 >> temp;
        assert(temp == "list:");
        while(!file2.eof())
            file2 >> temp;
        assert(temp == "Empty");
    }
    file2.close();

    file.open("test.txt");
    if(file.is_open())
        file.clear();
    file.close();
}

void testCheckPrice()
{
    ofstream file("test.txt");
    if(file.is_open())
        p.checkPrice(&file);
    file.close();

    ifstream file2("test.txt");
    if(file2.is_open())
    {
        string temp;
        file2 >> temp;
        assert(temp == "Assessed");
        while(!file2.eof())
            file2 >> temp;
        assert(temp == "$12507");
    }
    file2.close();

    file.open("test.txt");
    if(file.is_open())
        file.clear();
    file << ' ' << 0 << ' ' << 0 << endl << 0 << ' ' << 1 << ' ' << 0 << ' ' << 1;
    file.close();
}

void testTakeSmth()
{
    ifstream file("test.txt");
    if(file.is_open())
        while(!file.eof())
            p.takeSmth(&file);

    assert(p.itemList[0].humanID == 23451);
    assert(p.humanList[1].history == "Kiwi");
    file.close();

    ofstream file2("test.txt");
    if(file2.is_open())
        file2.clear();
    file2  << 2 << ' ' << 1 << ' ' << 2 << ' ' << 1;
    file2.close();
}

void testReturnSmth()
{
    ifstream file("test.txt");
    if(file.is_open())
        while(!file.eof())
            p.returnSmth(&file);
    
    assert(p.itemList[3].humanID == 0);
    assert(p.humanList[2].history == "Empty");
    file.close();

    ofstream file2("test.txt");
    if(file2.is_open())
        file2.clear();
    file2 << 2123;
    file2.close();
}

void testSaveInfo()
{
    p.saveInfo();
    ifstream file("newItems.txt");
    if(file.is_open())
    {
        string temp;
        file >> temp;
        assert(temp == "Banana");
        file >> temp;
        assert(temp == "23451");
        while(!file.eof())
            file >> temp;
        assert(temp == "10");
    }
    file.close();
    file.open("newPeople.txt");
    if(file.is_open())
    {
        string temp;
        file >> temp;
        assert(temp == "Sam");
        file >> temp;
        assert(temp == "Winchester");
        while(!file.eof())
            file >> temp;
        assert(temp == "Empty");
    }
    file.close();
}

int main()
{
    testInput();
    testCheck();
    testAddToItemList();
    testAddToHumanList();
    testChangeInfo();
    testDeleteInfo();
    testShowAll();
    testCheckPrice();
    testTakeSmth();
    testReturnSmth();
    testSaveInfo();
    return 0;
}
