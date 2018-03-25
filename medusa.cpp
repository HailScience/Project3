#include <iostream>
#include <cstdlib>
#include <ctime>
#include "character.hpp"
#include "medusa.hpp"

using std::cout;
using std::endl;

Medusa::Medusa(string type, int armor, int strength, bool defeated) : Character(type, armor, strength, defeated)
{
}

int Medusa::getArmor()
{
    return armor;
}

int Medusa::getStrength()
{
    return strength;
}

int Medusa::rollDiceAttack()
{
    int dieNumber = 2;
    totalRoll = 0;
    for(int i = 0; i < dieNumber; i++)
    {
        totalRoll += (rand() % 6 + 1);
    }
    return totalRoll;
}

int Medusa::rollDiceDefense()
{
    totalRoll = 0;
    totalRoll += (rand() % 6 + 1);
    return totalRoll;
}

int Medusa::attack()
{
    damage = rollDiceAttack();
    if(damage == 12)
    {
        cout << "Medusa used glare, causing " << damage << " damage points." << endl;
        damage = 100;
    }
    else
    {
        cout << "The Medusa attacks, causing " << damage << " damage points." << endl;
    }
    return damage;
}

void Medusa::defense(int attack)
{
    //Display defender details
    cout << "Medusa defends with " << armor << " armor and " << strength << " strength points." << endl;
    //Return defense dice roll
    int counter = rollDiceDefense();
    cout << "Medusa counters with " << counter << " defense points." << endl;
    if(attack != 100)
    {
        actualDamage = attack - counter;
    }
        //If other Medusa uses glare
    else
    {
        actualDamage = attack;
    }
    //If no damage occurs
    if(actualDamage <= 0)
    {
        cout << "Medusa took no hits!" << endl;
        cout << "Strength remains at: " << strength << endl;
        cout << "Armor remains at: " << armor << endl;
        cout << "Total inflicted damage: 0" << endl;
    }
        //If hit does not penetrate armor
    else if(actualDamage > 0 && actualDamage <= armor)
    {
        actualDamage -= armor;
        cout << "Medusa's armor withstood the attack!" << endl;
        cout << "Medusa strength: " << strength << endl;
        cout << "Medusa armor: " << armor << endl;
        cout << "Total inflicted damage: 0" << endl;
    }
        //If other Medusa uses glare
    else if(actualDamage == 100)
    {
        cout << "Medusa died from the other Medusa's glare!" << endl;
        strength = 0;
        actualDamage = 12 - counter - armor;
        cout << "Medusa strength: " << strength << endl;
        cout << "Medusa armor: " << armor << endl;
        cout << "Total inflicted damage: 12" << endl;
        defeated = true;
    }
        //If armor is no match for damage
    else if(actualDamage > armor)
    {
        //Subtract armor
        actualDamage -= armor;
        //Adjust strength
        strength -= actualDamage;
        //If Medusa survives
        if(strength > 0)
        {
            cout << "Medusa is hit!" << endl;
            cout << "Medusa strength: " << strength << endl;
            cout << "Medusa armor: " << armor << endl;
            cout << "Total inflicted damage: " << actualDamage << endl;
        }
            //If Blue Men die
        else if(strength <= 0)
        {
            cout << "Medusa has died!" << endl;
            cout << "Medusa strength: 0" << endl;
            cout << "Medusa armor: " << armor << endl;
            cout << "Total inflicted damage: " << actualDamage << endl;
            defeated = true;
        }
    }
}

string Medusa::getType()
{
    return type;
}

bool Medusa::die()
{
    return defeated;
}
