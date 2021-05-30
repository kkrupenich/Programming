#include "pawnshop.h"
#include <iostream>
#include <fstream>

using namespace std;

void Pawnshop::check(unsigned int *a, ifstream *in)
{
    bool useCin = in == nullptr;
    char inpStr[1024];
    char buffer = 0;
    if(useCin)
    {
        while(true)
        {
            buffer = 0;
            if((scanf("%1023[^\n]%c",inpStr,&buffer) != 2) || buffer != '\n')
                getchar();
            else if((sscanf(inpStr,"%u%c",&*a,&buffer) != 1) || buffer != '\n')
                printf("Incorrect input. Try again: ");
            else
                break;
        }
    }
    else
        *in >> *a;
}

void Pawnshop::input()
{
    fstream fin;
    fin.open("people.txt");
    if(!fin.is_open())
    {
        cout << "Cant open file";
        exit(1);
    }
    else
    {
        while(!fin.eof())
        {
            string firstname, lastname, history;
            unsigned int passport;
            fin >> firstname >> lastname >> passport >> history;
            humanList.push_back({ firstname, lastname, passport, history });
        }
    }
    fin.close();
    
    fin.open("items.txt");
    if(!fin.is_open())
    {
        cout << "Cant open file";
        exit(2);
    }
    else
    {
        while(!fin.eof())
        {
            string itemName;
            unsigned int humanID;
            unsigned int assessedMoney, moneyToHuman;
            fin >> itemName >> humanID >> assessedMoney >> moneyToHuman;
            itemList.push_back({ itemName, humanID, assessedMoney, moneyToHuman });
        }
    }
}

void Pawnshop::addToItemList(ifstream *in)
{
    bool useCin = in == nullptr;
    string itemName;
    unsigned int assessedMoney = 0, moneyToHuman = 0;

    cout << "Enter item name: ";
    (useCin ? cin : *in) >> itemName;

    cout << "Enter assessed money: ";
    if(useCin) check(&assessedMoney, nullptr);
    else (*in) >> assessedMoney;
    while(assessedMoney <= 0)
    {
        cout << "Incorrect input, try again: ";
        if(useCin) check(&assessedMoney, nullptr);
        else (*in) >> assessedMoney;
    }

    cout << "Enter moneyToHuman ( < assessed money ): ";
    if(useCin) check(&moneyToHuman, nullptr);
    else (*in) >> moneyToHuman;
    while(moneyToHuman <= 0 || moneyToHuman > assessedMoney)
    {
        cout << "Incorrect input, try again: ";
        if(useCin) check(&moneyToHuman, nullptr);
        else (*in) >> moneyToHuman;
    }

    itemList.push_back({ itemName, 0, assessedMoney, moneyToHuman });
}

void Pawnshop::addToHumanList(ifstream *in)
{
    bool useCin = in == nullptr;

    string firstname, lastname;
    unsigned int passport;

    cout << "Enter first and lastname: ";
    (useCin ? cin : *in) >> firstname >> lastname;
    cout << "Enter passport data: ";
    if (useCin) check(&passport, nullptr);
    else (*in) >> passport;
    while(passport <= 0)
    {
        cout << "Incorrect input, try again: ";
        if(useCin) check(&passport, nullptr);
        else (*in) >> passport;
    }

    humanList.push_back({ firstname, lastname, passport, "Empty" });
}

void Pawnshop::changeInfo(ifstream *in)
{
    bool useCin = in == nullptr;

    unsigned int choice;
    cout << "1 - Items" << endl << "2 - People" << endl << "0 - Exit" << endl << "Enter your choice: ";
    if(useCin) check(&choice, nullptr);
    else (*in) >> choice;
    while(choice < 0 || choice > 2)
    {
        cout << "Incorrect input, try again: ";
        if(useCin) check(&choice, nullptr);
        else (*in) >> choice;
    }
    
    if(choice == 1)
    {
        for(unsigned int i = 0; i < itemList.size(); i++)
            cout << i << " - " << itemList[i].itemName << endl;

        unsigned int index;
        cout << "Enter which item u want to change: ";
        if(useCin) check(&index, nullptr);
        else (*in) >> index;
        while(index < 0 || index > itemList.size())
        {
            cout << "Incorrect input, try again: ";
            if(useCin) check(&index, nullptr);
            else (*in) >> index;
        }
        
        cout << "1 - assessed money: " << itemList[index].assessedMoney << endl;
        cout << "2 - money to human: " << itemList[index].moneyToHuman << endl;
        cout << "0 - Exit" << endl;
        cout << "Enter what do u want to change in " << itemList[index].itemName << "?: ";
        if(useCin) check(&choice, nullptr);
        else (*in) >> choice;
        while(choice < 0 || choice > 2)
        {
            cout << "Incorrect input, try again: ";
            if(useCin) check(&choice, nullptr);
            else (*in) >> choice;
        }

        unsigned int money = 0;
        switch (choice)
        {
        case 1:
            cout << "Enter new assessed money: ";
            if(useCin) check(&money, nullptr);
            else (*in) >> money;
            while(money < itemList[index].moneyToHuman)
            {
                cout << "Incorrect input, try again: ";
                if(useCin) check(&money, nullptr);
                else (*in) >> money;
            }
            itemList[index].assessedMoney = money;
            break;
        case 2:
            cout << "Enter new money to human: ";
            if(useCin) check(&money, nullptr);
            else (*in) >> money;
            while(money > itemList[index].assessedMoney)
            {
                cout << "Incorrect input, try again: ";
                if(useCin) check(&money, nullptr);
                else (*in) >> money;
            }
            itemList[index].moneyToHuman = money;
            break;
        default:
            break;
        }
        return;
    }
    else if(choice == 2) 
    {
        for(unsigned int i = 0; i < humanList.size(); i++)
            cout << i << " - " << humanList[i].firstname << " " << humanList[i].lastname << endl;

        unsigned int index;
        cout << "Enter whome u want to change: ";
        if(useCin) check(&index, nullptr);
        else (*in) >> index;
        while(index < 0 || index > humanList.size())
        {
            cout << "Incorrect input, try again: ";
            if(useCin) check(&index, nullptr);
            else (*in) >> index;
        }
        
        bool checkHistory = false;
        if(humanList[index].history != "Empty")
            checkHistory = true;
        cout << "You can change only passport data" << endl;
        cout << "Enter new passport data: ";
        unsigned int pass;
        if(useCin) check(&pass, nullptr);
        else (*in) >> pass;
        while(pass <= 0)
        {
            cout << "Incorrect input, try again: ";
            if(useCin) check(&pass, nullptr);
            else (*in) >> pass;
        }
        humanList[index].passport = pass;
        if(checkHistory)
        {
            for(unsigned int i = 0; i < itemList.size(); i++)
            {
                if(itemList[i].itemName == humanList[index].history)
                    itemList[i].humanID = humanList[index].passport;
            }
        }
    }
    else
        return;
}

void Pawnshop::deleteSmth(ifstream *in)
{
    bool useCin = in == nullptr;

    unsigned int choice;
    cout << "1 - Items" << endl << "2 - People" << endl << "Enter your choice: ";
    if(useCin) check(&choice, nullptr);
    else (*in) >> choice;
    while(choice < 0 || choice > 2)
    {
        cout << "Incorrect input, try again: ";
        if(useCin) check(&choice, nullptr);
        else (*in) >> choice;
    }

    if(choice == 1)
    {
        for(unsigned int i = 0; i < itemList.size(); i++)
            cout << i << " - " << itemList[i].itemName << endl;

        cout << "Choose what u want to delete?: ";
        if(useCin) check(&choice, nullptr);
        else (*in) >> choice;
        while(choice < 0 || choice > itemList.size())
        {
            cout << "Incorrect input, try again: ";
            if(useCin) check(&choice, nullptr);
            else (*in) >> choice;
        }

        for(unsigned int i = 0; i < humanList.size(); i++)
        {
            if(humanList[i].history == itemList[choice].itemName)
                humanList[i].history = "Empty";
        }

        auto iter = itemList.cbegin();
        itemList.erase(iter + choice);
        itemList.resize(itemList.size() - 1);
        
        cout << "List after deleting:" << endl;
        for(unsigned int i = 0; i < itemList.size(); i++)
            cout << itemList[i].itemName << endl;
    }
    else if(choice == 2)
    {
        for(unsigned int i = 0; i < humanList.size(); i++)
            cout << i << " - " << humanList[i].firstname << " " << humanList[i].lastname << endl;

        cout << "Choose what u want to delete?: ";
        if(useCin) check(&choice, nullptr);
        else (*in) >> choice;
        while(choice < 0 || choice > humanList.size())
        {
            cout << "Incorrect input, try again: ";
            if(useCin) check(&choice, nullptr);
            else (*in) >> choice;
        }

        for(unsigned int i = 0; i < itemList.size(); i++)
        {
            if(itemList[i].humanID == humanList[choice].passport)
                itemList[i].humanID = 0;
        }

        auto iter = humanList.cbegin();
        humanList.erase(iter + choice);
        humanList.resize(humanList.size() - 1);
        
        cout << "List after deleting:" << endl;
        for(unsigned int i = 0; i < humanList.size(); i++)
            cout << humanList[i].firstname << " " << humanList[i].lastname << endl;
    }
    else
        return;
}

void Pawnshop::saveInfo()
{
    ofstream fout;
    fout.open("newItems.txt");
    if(!fout.good())
        ofstream out("newItems.txt");
    for(unsigned int i = 0; i < itemList.size(); i++)
    {
        fout << itemList[i].itemName << " " << itemList[i].humanID << " " << itemList[i].assessedMoney << " "
             << itemList[i].moneyToHuman << endl;
    }
    fout.close();

    fout.open("newPeople.txt");
    if(!fout.good())
        ofstream out("newPeople.txt");
    for(unsigned int i = 0; i < humanList.size(); i++)
    {
        fout << humanList[i].firstname << " " << humanList[i].lastname << " " << humanList[i].passport
             << " " << humanList[i].history << endl;
    }
    fout.close();
}

void Pawnshop::showAll(ofstream *out)
{
    bool useCout = out == nullptr;

    (useCout ? cout : *out) << "Item list:" << endl;
    for(unsigned int i = 0; i < itemList.size(); i++)
    {
        (useCout ? cout : *out) << i + 1 << " - " << itemList[i].itemName << ", ";
        if(itemList[i].humanID == 0)
            (useCout ? cout : *out) << "No one" << endl;
        else
            (useCout ? cout : *out) << itemList[i].humanID << endl;
    }
    (useCout ? cout : *out) << endl << "People list:" << endl;
    for(unsigned int i = 0; i < humanList.size(); i++)
    {
        (useCout ? cout : *out) << i + 1 << " - " << humanList[i].firstname << " " << humanList[i].lastname << ", ";
        (useCout ? cout : *out) << "current item: " << humanList[i].history << endl;
    }
}

double profit = 0;

void Pawnshop::takeSmth(ifstream *in)
{
    bool useCin = in == nullptr;

    bool checkEmpty = false;
    for(unsigned int i = 0; i < humanList.size(); i++)
    {
        if(humanList[i].history == "Empty")
        {
            checkEmpty = true;
            break;
        }
    }
    if(!checkEmpty)
    {
        cout << "There in no one person who can take any item" << endl;
        return;
    }
    checkEmpty = false;
    for(unsigned int i = 0; i < itemList.size(); i++)
    {

        if(itemList[i].humanID == 0)
        {
            checkEmpty = true;
            break;
        }
    }
    if(!checkEmpty)
    {
        cout << "There is no item that can be taken" << endl;
        return;
    }
    
    unsigned int humanChoice;
    for(unsigned int i = 0; i < humanList.size(); i++)
        cout << i << " - " << humanList[i].firstname << " " << humanList[i].lastname << endl;

    cout << "Choose who will take an item?: ";
    if(useCin) check(&humanChoice, nullptr);
    else (*in) >> humanChoice;
    while(humanChoice < 0 || humanChoice > humanList.size() || humanList[humanChoice].history != "Empty")
    {
        if(humanList[humanChoice].history != "Empty")
        {
            cout << "This one already has an item" << endl;
            cout << "Choose another one: ";
            if(useCin) check(&humanChoice, nullptr);
            else (*in) >> humanChoice;
        }
        else
        {
            cout << "Incorrect input, try again: ";
            if(useCin)check(&humanChoice, nullptr);
            else (*in) >> humanChoice;
        }
    }

    unsigned int itemChoice;
    if(useCin)
        for(unsigned int i = 0; i < itemList.size(); i++)
            cout << i << " - " << itemList[i].itemName << endl;

    cout << "Choose what " << humanList[humanChoice].firstname << " will take?: ";
    if(useCin) check(&itemChoice, nullptr);
    else (*in) >> itemChoice;
    while(itemChoice < 0 || itemChoice > itemList.size() || itemList[itemChoice].humanID != 0)
    {
        if(itemList[itemChoice].humanID != 0)
        {
            cout << "This one already has an item" << endl;
            cout << "Choose another one: ";
            if(useCin) check(&itemChoice, nullptr);
            else (*in) >> itemChoice;
        }
        else
        {
            cout << "Incorrect input, try again: ";
            if(useCin) check(&itemChoice, nullptr);
            else (*in) >> itemChoice;
        }
    }

    itemList[itemChoice].humanID = humanList[humanChoice].passport;
    humanList[humanChoice].history = itemList[itemChoice].itemName;
    
    for(unsigned int i = 0; i < itemList.size(); i++)
    {
        if(itemList[i].humanID != 0)
            profit = profit + itemList[i].assessedMoney - itemList[i].moneyToHuman;
    }
    if(useCin) cout << "Current profit of pawnshop is: $" << profit << endl;
}

void Pawnshop::returnSmth(ifstream *in)
{
    bool useCin = in == nullptr;

    bool checkReturn = false;
    for(unsigned int i = 0; i < itemList.size(); i++)
    {
        if(itemList[i].humanID != 0)
        {
            checkReturn = true;
            break;
        }
    }
    if(!checkReturn)
    {
        cout << "There in no item that can be returned" << endl;
        return;
    }
    checkReturn = false;
    for(unsigned int i = 0; i < humanList.size(); i++)
    {
        if(humanList[i].history != "Empty")
        {
            checkReturn = true;
            break;
        }
    }
    if(!checkReturn)
    {
        cout << "There is no one who can return anything" << endl;
        return;
    }

    unsigned int humanChoice;
    for(unsigned int i = 0; i < humanList.size(); i++)
        cout << i << " - " << humanList[i].firstname << " " << humanList[i].lastname << endl;

    cout << "Choose who will return any item?: ";
    if(useCin) check(&humanChoice, nullptr);
    else (*in) >> humanChoice;
    while(humanChoice < 0 || humanChoice > humanList.size() || humanList[humanChoice].history == "Empty")
    {
        if(humanList[humanChoice].history == "Empty")
        {
            cout << "This one has nothing" << endl;
            cout << "Choose another one: ";
            if(useCin) check(&humanChoice, nullptr);
            else (*in) >> humanChoice;
        }
        else
        {
            cout << "Incorrect input, try again: ";
            if(useCin) check(&humanChoice, nullptr);
            else (*in) >> humanChoice;
        }
    }

    unsigned int itemChoice;
    for(unsigned int i = 0; i < itemList.size(); i++)
        cout << i << " - " << itemList[i].itemName << endl;

    cout << "Choose what " << humanList[humanChoice].firstname << " will return?: ";
    if(useCin) check(&itemChoice, nullptr);
    else (*in) >> itemChoice;
    while(itemChoice < 0 || itemChoice > itemList.size() || itemList[itemChoice].humanID == 0)
    {
        if(itemList[itemChoice].humanID == 0)
        {
            cout << "This one has another item" << endl;
            cout << "Choose another one: ";
            if(useCin) check(&itemChoice, nullptr);
            else (*in) >> itemChoice;
        }
        else
        {
            cout << "Incorrect input, try again: ";
            if(useCin) check(&itemChoice, nullptr);
            else (*in) >> itemChoice;
        }
    }

    itemList[itemChoice].humanID = 0;
    humanList[humanChoice].history = "Empty";
}

void Pawnshop::checkPrice(ofstream *out)
{
    bool useCout = out == nullptr;

    double price = 0;
    for(unsigned int i = 0; i < itemList.size(); i++)
    {
        if(itemList[i].humanID == 0)
        {
            price += itemList[i].assessedMoney;
        }
    }
    (useCout ? cout : *out) << "Assessed price of all items in pawnshop is: $" << price << endl;
}