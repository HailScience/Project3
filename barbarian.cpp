#include <iostream>
#include <cstdlib>
#include <ctime>
#include "character.hpp"
#include "barbarian.hpp"

using std::cout;
using std::endl;

/******************************************************************
 * Description: Set specific details for Barbarian character
 *****************************************************************/
Barbarian::Barbarian(string type, int armor, int strength, bool defeated) : Character(type, armor, strength, defeated)
{

}
/******************************************************************
 * Description: Returns armor
 *****************************************************************/
int Barbarian::getArmor()
{
    return armor;
}
/******************************************************************
 * Description: Returns strength points
 *****************************************************************/
int Barbarian::getStrength()
{
    return strength;
}
/******************************************************************
 * Description: Attack dice roll
 *****************************************************************/
int Barbarian::rollDiceAttack()
{
    int dieNumber = 2;
    totalRoll = 0;
    for(int i = 0; i < dieNumber; i++)
    {
        totalRoll += (rand() % 6 + 1);
    }
    return totalRoll;
}
/******************************************************************
 * Description: Defense dice roll
 *****************************************************************/
int Barbarian::rollDiceDefense()
{
    int dieNumber = 2;
    totalRoll = 0;
    for(int i = 0; i < dieNumber; i++)
    {
        totalRoll += (rand() % 6 + 1);
    }
    return totalRoll;
}
/******************************************************************
 * Description: Attack function
 *****************************************************************/
int Barbarian::attack()
{
    damage = rollDiceAttack();
    cout << "The Barbarian attacks, causing " << damage << " damage points." << endl;
    return damage;
}
/******************************************************************
 * Description: Defense function
 *****************************************************************/
void Barbarian::defense(int attack)
{
    //Display defender details
    cout << "The Barbarian defends with " << armor << " armor and " << strength << " strength points." << endl;
    //Return defense dice roll
    int counter = rollDiceDefense();
    cout << "The Barbarian counters with " << counter << " defense points." << endl;
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
        cout << "The Barbarian took no hits!" << endl;
        cout << "Strength remains at: " << strength << endl;
        cout << "Armor remains at: " << armor << endl;
        cout << "Total inflicted damage: 0" << endl;
    }
    //If Medusa uses glare
    else if(actualDamage == 100)
    {
        cout << "The Barbarian died from Medusa's glare!" << endl;
        strength = 0;
        actualDamage = 12 - counter - armor;
        cout << "Barbarian strength: " << strength << endl;
        cout << "Barbarian armor: " << armor << endl;
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
        //If Barbarian survives
        if(strength > 0)
        {
            cout << "The Barbarian is hit!" << endl;
            cout << "Barbarian strength: " << strength << endl;
            cout << "Barbarian armor: " << armor << endl;
            cout << "Total inflicted damage: " << actualDamage << endl;

        }
        //If Barbarian dies
        else if(strength <= 0)
        {
            cout << "The Barbarian has died!" << endl;
            cout << "Barbarian strength: 0" << endl;
            cout << "Barbarian armor: " << armor << endl;
            cout << "Total inflicted damage: " << actualDamage << endl;
            defeated = true;
        }
    }
}
/******************************************************************
 * Description: Returns type of character
 *****************************************************************/
string Barbarian::getType()
{
    return type;
}
/******************************************************************
 * Description: Death function
 *****************************************************************/
bool Barbarian::die()
{
    return defeated;
}


