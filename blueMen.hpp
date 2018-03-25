#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include <iostream>
#include "character.hpp"

class BlueMen : public Character
{
public:
    BlueMen(string type, int armor, int strength, bool defeated);
    int getArmor();
    int getStrength();
    int rollDiceAttack();
    int rollDiceDefense();
    int attack();
    void defense(int attack);
    string getType();
    bool die();

private:
    int mobResult;
};

#endif
