#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include <iostream>
#include "character.hpp"

class Barbarian : public Character
{
public:
    Barbarian(string type, int armor, int strength, bool defeated);
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
