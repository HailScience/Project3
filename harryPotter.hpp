#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include <iostream>
#include "character.hpp"

class HarryPotter : public Character
{
public:
    HarryPotter(string type, int armor, int strength, bool defeated);
    int getArmor();
    int getStrength();
    int rollDiceAttack();
    int rollDiceDefense();
    int attack();
    void defense(int attack);
    string getType();
    bool die();

private:
    int hogwarts;
};

#endif