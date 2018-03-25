#include <iostream>
#include <ctime>
#include <cstdlib>
#include "startMenu.hpp"
#include "character.hpp"
#include "vampire.hpp"
#include "barbarian.hpp"
#include "blueMen.hpp"
#include "medusa.hpp"
#include "harryPotter.hpp"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    srand(time(NULL));
    int choice = 1;
    bool p1Defeated = false;
    bool p2Defeated = false;
    while(choice == 1)
    {
        int p1;
        int p2;
        int damage;
        int rounds = 2;
        Character *player1;
        Character *player2;
        p1 = startMenu();
        if(p1 == 1)
        {
            player1 = new Vampire("Vampire", 1, 18, false);
            cout << "Character 1 is a vampire." << endl;
            cout << endl;
        }
        else if(p1 == 2)
        {
            player1 = new Barbarian("Barbarian", 0, 12, false);
            cout << "Character 1 is a barbarian." << endl;
            cout << endl;
        }
        else if(p1 == 3)
        {
            player1 = new BlueMen("Blue Men", 3, 12, false);
            cout << "Character 1 is blue men." << endl;
            cout << endl;
        }
        else if(p1 == 4)
        {
            player1 = new Medusa("Medusa", 3, 8, false);
            cout << "Character 1 is medusa." << endl;
            cout << endl;
        }
        else if(p1 == 5)
        {
            player1 = new HarryPotter("Harry Potter", 0, 10, false);
            cout << "Character 1 is Harry Potter." << endl;
            cout << endl;
        }

        p2 = startMenu();
        if(p2 == 1)
        {
            player2 = new Vampire("Vampire", 1, 18, false);
            cout << "Character 2 is a vampire." << endl;
            cout << endl;
        }
        else if(p2 == 2)
        {
            player2 = new Barbarian("Barbarian", 0, 12, false);
            cout << "Character 2 is a barbarian." << endl;
            cout << endl;
        }
        else if(p2 == 3)
        {
            player2 = new BlueMen("Blue Men", 3, 12, false);
            cout << "Character 2 is blue men." << endl;
            cout << endl;
        }
        else if(p2 == 4)
        {
            player2 = new Medusa("Medusa", 3, 8, false);
            cout << "Character 2 is medusa." << endl;
            cout << endl;
        }
        else if(p2 == 5)
        {
            player2 = new HarryPotter("Harry Potter", 0, 10, false);
            cout << "Character 2 is Harry Potter." << endl;
            cout << endl;
        }

        //Confirm characters
        cout << "Player 1: " << player1->getType() << endl;
        cout << "Player 2: " << player2->getType() << endl;

        //Clear screen
        cout <<"\033[2J\033[1;1H";

        cout << "Player 1 attacks first..." << endl;

        for(int i = 0; i < rounds; i++)
        {
            cout << "Round " << i + 1 << ": " << endl;
            //Player 1 attacks
            damage = player1->attack();
            //Player 2 defends
            player2->defense(damage);
            //Check if player died
            p2Defeated = player2->die();
            if(p2Defeated == false)
            {
                //Player 2 attacks
                damage = player2->attack();
                //Player 1 defends
                player1->defense(damage);
                cout << endl;
            }
            //Check if player 1 was defeated
            p1Defeated = player1->die();

            //If player 1 defeated
            if(p1Defeated == true)
            {
                cout << player2->getType() << " wins!" << endl;
                cout << endl;
                break;
            }
                //If player 2 defeated
            else if(p2Defeated == true)
            {
                cout << player1->getType() << " wins!" << endl;
                cout << endl;
                break;
            }
        }
        //End menu
        cout << "Would you like to play again?" << endl;
        cout << "1. Play again\n";
        cout << "2. Exit the game\n";
        bool validData = false;
        while(!validData)
        {
            cin >> choice;
            if(cin.fail())
           {
               cout << "Error! Please choose a valid option!" << endl;
              cin.clear();
                cin.ignore();
            }
            else if(choice != 1 && choice != 2)
            {
               cout << "Error! Please choose a valid option!" << endl;
               cin.clear();
               cin.ignore();
           }
           else if(choice == 2)
          {
              cout << "Goodbye!" << endl;
              validData = true;
          }
          else if(choice == 1)
          {
                validData = true;
          }
       }
     //Deallocate memory
      delete player1;
      delete player2;
    }
    return 0;
}