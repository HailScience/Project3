#include <iostream>
#include <cstdlib>
#include <ctime>
#include "character.hpp"
#include "blueMen.hpp"

using std::cout;
using std::endl;

BlueMen::BlueMen(string type, int armor, int strength, bool defeated) : Character(type, armor, strength, defeated)
{
    mobResult = 0;
}

int BlueMen::getArmor()
{
    return armor;
}

int BlueMen::getStrength()
{
    return strength;
}

int BlueMen::rollDiceAttack()
{
    int dieNumber = 2;
    totalRoll = 0;
    for(int i = 0; i < dieNumber; i++)
    {
        totalRoll += (rand() % 10 + 1);
    }
    return totalRoll;
}

int BlueMen::rollDiceDefense()
{
    totalRoll = 0;
    if(mobResult == 0)
    {
        int dieNumber = 3;
        for(int i = 0; i < dieNumber; i++)
        {
            totalRoll += (rand() % 6 + 1);
        }
    }
    else if(mobResult == 1)
    {
        int dieNumber = 2;
        for(int i = 0; i < dieNumber; i++)
        {
            totalRoll += (rand() % 6 + 1);
        }
    }
    else if(mobResult == 2)
    {
        totalRoll += (rand() % 6 + 1);
    }
    return totalRoll;
}

int BlueMen::attack()
{
    damage = rollDiceAttack();
    cout << "The Blue Men attack, causing " << damage << " damage points." << endl;
    return damage;
}

void BlueMen::defense(int attack)
{
    //Display defender details
    cout << "The Blue Men defend with " << armor << " armor and " << strength << " strength points." << endl;
    //Return defense dice roll
    int counter = rollDiceDefense();
    cout << "The Blue Men counter with " << counter << " defense points." << endl;
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
        cout << "The Blue Men took no hits!" << endl;
        cout << "Strength remains at: " << strength << endl;
        cout << "Armor remains at: " << armor << endl;
        cout << "Total inflicted damage: 0" << endl;
    }
    //If hit does not penetrate armor
    else if(actualDamage > 0 && actualDamage <= armor)
    {
        actualDamage -= armor;
        cout << "The Blue Men's armor withstood the attack!" << endl;
        cout << "Blue Men strength: " << strength << endl;
        cout << "Blue Men armor: " << armor << endl;
        cout << "Total inflicted damage: 0" << endl;
    }
    //If Medusa uses glare
    else if(actualDamage == 100)
    {
        cout << "The Blue Men died from Medusa's glare!" << endl;
        strength = 0;
        actualDamage = 12 - counter - armor;
        cout << "Blue Men strength: " << strength << endl;
        cout << "Blue Men armor: " << armor << endl;
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
        //If Blue Men survive
        if(strength > 0)
        {
            cout << "The Blue Men are hit!" << endl;
            cout << "Blue Men strength: " << strength << endl;
            cout << "Blue Men armor: " << armor << endl;
            cout << "Total inflicted damage: " << actualDamage << endl;
        }
            //If Blue Men die
        else if(strength <= 0)
        {
            cout << "The Blue Men has died!" << endl;
            cout << "Blue Men strength: 0" << endl;
            cout << "Blue Men armor: " << armor << endl;
            cout << "Total inflicted damage: " << actualDamage << endl;
            defeated = true;
        }
    }

    //Mob
    if(strength <= 8 && strength > 4)
    {
        mobResult = 1;
    }
    else if(strength <=4 && strength > 0)
    {
        mobResult = 2;
    }
}

string BlueMen::getType()
{
    return type;
}

bool BlueMen::die()
{
    return defeated;
}

