#include <iostream>
#include <cstdlib>
#include <ctime>
#include "character.hpp"
#include "harryPotter.hpp"

using std::cout;
using std::endl;

HarryPotter::HarryPotter(string type, int armor, int strength, bool defeated) : Character(type, armor, strength, defeated)
{
    hogwarts = 1;
}

int HarryPotter::getArmor()
{
    return armor;
}

int HarryPotter::getStrength()
{
    return strength;
}

int HarryPotter::rollDiceAttack()
{
    int dieNumber = 2;
    totalRoll = 0;
    for(int i = 0; i < dieNumber; i++)
    {
        totalRoll += (rand() % 6 + 1);
    }
    return totalRoll;
}

int HarryPotter::rollDiceDefense()
{
    int dieNumber = 2;
    totalRoll = 0;
    for(int i = 0; i < dieNumber; i++)
    {
        totalRoll += (rand() % 6 + 1);
    }
    return totalRoll;
}

int HarryPotter::attack()
{
    damage = rollDiceAttack();
    cout << "Harry Potter attacks, causing " << damage << " damage points." << endl;
    return damage;
}

void HarryPotter::defense(int attack)
{
    //Display defender details
    cout << "Harry Potter defends with " << armor << " armor and " << strength << " strength points." << endl;
    //Return defense dice roll
    int counter = rollDiceDefense();
    cout << "Harry Potter counters with " << counter << " defense points." << endl;
    if(attack != 100)
    {
        actualDamage = attack - counter;
    }
        //If Medusa uses glare
    else
    {
        actualDamage = attack;
    }
    //If no damage occurs
    if(actualDamage <= 0)
    {
        cout << "Harry Potter took no hits!" << endl;
        cout << "Strength remains at: " << strength << endl;
        cout << "Armor remains at: " << armor << endl;
        cout << "Total inflicted damage: 0" << endl;
    }
        //If Medusa uses glare 1st time
    else if(actualDamage == 100 && hogwarts == 1)
    {
        cout << "Harry Potter died from Medusa's glare!" << endl;
        cout << "Harry Potter uses *Hogwarts* for another life!" << endl;
        strength = 20;
        hogwarts = 0;
        actualDamage = 12 - counter - armor;
        cout << "Harry Potter strength: " << strength << endl;
        cout << "Harry Potter armor: " << armor << endl;
        cout << "Total inflicted damage: 12" << endl;
    }
        //If Medusa uses glare 2nd time
    else if(actualDamage == 100 && hogwarts == 0)
    {
        cout << "Harry Potter died from Medusa's glare!" << endl;
        strength = 0;
        actualDamage = 12 - counter - armor;
        cout << "Harry Potter strength: " << strength << endl;
        cout << "Harry Potter armor: " << armor << endl;
        cout << "Total inflicted damage: 12" << endl;
        defeated = true;
    }
        //If armor is no match for damage (likely)
    else if(actualDamage > armor)
    {
        //Subtract armor
        actualDamage -= armor;
        //Adjust strength
        strength -= actualDamage;
        //If Harry Potter survives
        if(strength > 0)
        {
            cout << "Harry Potter is hit!" << endl;
            cout << "Harry Potter strength: " << strength << endl;
            cout << "Harry Potter armor: " << armor << endl;
            cout << "Total inflicted damage: " << actualDamage << endl;
        }
            //If Harry Potter dies with special
        else if(strength <= 0 && hogwarts == 1)
        {
            cout << "Harry Potter has died!" << endl;
            cout << "Harry Potter uses *Hogwarts* for another life!" << endl;
            strength = 20;
            hogwarts = 0;
            cout << "Harry Potter strength: " << strength << endl;
            cout << "Harry Potter armor: " << armor << endl;
            cout << "Total inflicted damage: " << actualDamage << endl;
        }
            //If Harry Potter dies without special
        else if(strength <= 0 && hogwarts == 0)
        {
            cout << "Harry Potter has died!" << endl;
            cout << "Harry Potter strength: 0" << endl;
            cout << "Harry Potter armor: " << armor << endl;
            cout << "Total inflicted damage: " << actualDamage << endl;
            defeated = true;
        }
    }
}

string HarryPotter::getType()
{
    return type;
}

bool HarryPotter::die()
{
    return defeated;
}
