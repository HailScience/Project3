#include <iostream>
#include <cstdlib>
#include <ctime>
#include "character.hpp"
#include "vampire.hpp"

using std::cout;
using std::endl;

/******************************************************************
 * Description: Set specific details for Vampire character
 *****************************************************************/
Vampire::Vampire(string type, int armor, int strength, bool defeated) : Character(type, armor, strength, defeated)
{

}
/******************************************************************
 * Description: Returns armor
 *****************************************************************/
int Vampire::getArmor()
{
    return armor;
}
/******************************************************************
 * Description: Returns strength points
 *****************************************************************/
int Vampire::getStrength()
{
    return strength;
}
/******************************************************************
 * Description: Attack dice roll
 *****************************************************************/
int Vampire::rollDiceAttack()
{
    totalRoll = (rand() % 12 + 1);
    return totalRoll;
}
/******************************************************************
 * Description: Defense dice roll
 *****************************************************************/
int Vampire::rollDiceDefense()
{
    totalRoll = (rand() % 6 + 1);
    return totalRoll;
}
/******************************************************************
 * Description: Attack function
 *****************************************************************/
int Vampire::attack()
{
    damage = rollDiceAttack();
    cout << "The Vampire attacks, causing " << damage << " damage points." << endl;
    return damage;
}
/******************************************************************
 * Description: Defense function
 *****************************************************************/
void Vampire::defense(int attack)
{
    //Display defender details
    cout << "The Vampire defends with " << armor << " and " << strength << " strength points." << endl;

    //Charm
    charm = rand() % 2 + 1;
    if(charm == 1)
    {
        cout << "The Vampire has charmed the opponent! The opponent does not attack!" << endl;
        cout << "Vampire strength: " << strength << endl;
        cout << "Vampire armor: " << armor << endl;
        cout << "Total inflicted damage: 0" << endl;
    }
    else
    {
        //Return defense dice roll
        int counter = rollDiceDefense();
        cout << "The Vampire counters with " << counter << " defense points." << endl;
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
            cout << "The Vampire took no hits!" << endl;
            cout << "Strength remains at: " << strength << endl;
            cout << "Armor remains at: " << armor << endl;
            cout << "Total inflicted damage: 0" << endl;
        }
            //If armor withstands attack
        else if(actualDamage == armor)
        {
            actualDamage -= armor;
            cout << "The Vampire's armor withstood the attack!" << endl;
            cout << "Vampire strength: " << strength << endl;
            cout << "Vampire armor: " << armor << endl;
            cout << "Total inflicted damage: 0" << endl;
        }
            //If Medusa uses glare
        else if(actualDamage == 100)
        {
            cout << "The Vampire died from Medusa's glare!" << endl;
            strength = 0;
            actualDamage = 12 - counter - armor;
            cout << "Vampire strength: " << strength << endl;
            cout << "Vampire armor: " << armor << endl;
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
            //If Vampire survives
            if(strength > 0)
            {
                cout << "The Vampire is hit!" << endl;
                cout << "Vampire strength: " << strength << endl;
                cout << "Vampire armor: " << armor << endl;
                cout << "Total inflicted damage: " << actualDamage << endl;
            }
                //If Vampire dies
            else if(strength <= 0)
            {
                cout << "The Vampire has died!" << endl;
                cout << "Vampire strength: 0" << endl;
                cout << "Vampire armor: " << armor << endl;
                cout << "Total inflicted damage: " << actualDamage << endl;

                defeated = true;
            }
        }
    }

}
/******************************************************************
 * Description: Returns type of character
 *****************************************************************/
string Vampire::getType()
{
    return type;
}
/******************************************************************
 * Description: Death function
 *****************************************************************/
bool Vampire::die()
{
    return defeated;
}


