#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include <iostream>
#include "character.hpp"

class Medusa : public Character
{
public:
    Medusa(string type, int armor, int strength, bool defeated);
    int getArmor();
    int getStrength();
    int rollDiceAttack();
    int rollDiceDefense();
    int attack();
    void defense(int attack);
    string getType();
    bool die();
};

#endif