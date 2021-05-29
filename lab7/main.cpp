#include <iostream>
#include "pawnshop.h"

using namespace std;

int main()
{
    Pawnshop pawnshop;
    pawnshop.input();
    unsigned int choice = 100;
    while(choice != 0)
    {
        cout << "1 - Add to human list" << endl << "2 - Add to item list" << endl << "3 - Change info" << endl
             << "4 - Delete info" << endl << "5 - Save current info" << endl << "6 - Show all" << endl
             << "7 - Take something" << endl << "8 - Return something" << endl 
             << "9 - Check assessed price of all items in pawnshop" << endl << "0 - Exit" << endl;
        cout << "Enter your choice: ";
        pawnshop.check(&choice);
        while(choice < 0 || choice > 9)
        {
            cout << "Incorrect input, try again: ";
            pawnshop.check(&choice);
        }
        switch (choice)
        {
        case 1:
            cout << endl;
            pawnshop.addToHumanList();
            cout << endl;
            break;
        case 2:
            cout << endl;
            pawnshop.addToItemList();
            cout << endl;
            break;
        case 3:
            cout << endl;
            pawnshop.changeInfo();
            cout << endl;
            break;
        case 4:
            cout << endl;
            pawnshop.deleteSmth();
            cout << endl;
            break;
        case 5:
            pawnshop.saveInfo();
            cout << endl;
            break;
        case 6:
            cout << endl;
            pawnshop.showAll();
            cout << endl;
            break;
        case 7:
            cout << endl;
            pawnshop.takeSmth();
            cout << endl;
            break;
        case 8:
            cout << endl;
            pawnshop.returnSmth();
            cout << endl;
            break;
        case 9:
            cout << endl;
            pawnshop.checkPrice();
            cout << endl;
            break;
        default:
            break;
        }
    }
    return 0;
}