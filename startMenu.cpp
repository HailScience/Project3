#include <iostream>
#include "startMenu.hpp"

using std::cin;
using std::cout;
using std::endl;

int startMenu()
{
    //Display options
    cout << "Please choose a character for combat: " << endl;
    cout << "1. Vampire\n";
    cout << "2. Barbarian\n";
    cout << "3. Blue Men\n";
    cout << "4. Medusa\n";
    cout << "5. Harry Potter\n";

    bool validData = false;
    int choice;

    while(!validData)
    {
        cin >> choice;
        if(cin.fail())
        {
            cout << "Error! Please choose a valid option!" << endl;
            cin.clear();
            cin.ignore();
        }
        else if(choice < 1 || choice > 5)
        {
            cout << "Error! Please choose a valid option!" << endl;
            cin.clear();
            cin.ignore();
        }
        else
        {
            validData = true;
            return choice;
        }
    }
}