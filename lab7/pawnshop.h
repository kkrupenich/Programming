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

    void check(unsigned int *a, ifstream *in);
    void input(); 
    void addToItemList(ifstream *in);
    void addToHumanList(ifstream *in);
    void changeInfo(ifstream *in);
    void deleteSmth(ifstream *in);
    void saveInfo();
    void showAll(ofstream *out);
    void takeSmth(ifstream *in);
    void returnSmth(ifstream *in);
    void checkPrice(ofstream *out);
};

#endif