#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include <iostream>
#include "character.hpp"

class Vampire : public Character
{
public:
    Vampire(string type, int armor, int strength, bool defeated);
    int getArmor();
    int getStrength();
    int rollDiceAttack();
    int rollDiceDefense();
    int attack();
    void defense(int attack);
    string getType();
    bool die();

private:
    int charm;
};

#endif