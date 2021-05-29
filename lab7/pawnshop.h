#ifndef PAWNSHOP_H
#define PAWNSHOP_H

#include <iostream>
#include <vector>

using namespace std;

class Pawnshop
{
public:
    struct Item
    {
        string itemName;
        unsigned int humanID;
        unsigned int assessedMoney;
        unsigned int moneyToHuman;
    };

    struct Human
    {
        string firstname, lastname;
        unsigned int passport;
        string history;
    };
    
    vector<Item> itemList;
    vector<Human> humanList;

    void check(unsigned int *a);
    void input();
    void addToItemList();
    void addToHumanList();
    void changeInfo();
    void deleteSmth();
    void saveInfo();
    void showAll();
    void takeSmth();
    void returnSmth();
    void checkPrice();
};


#endif