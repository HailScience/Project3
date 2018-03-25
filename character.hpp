#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using std::string;

class Character
{
protected:
    string type;
    int armor;
    int strength;
    int damage;
    int actualDamage;
    bool defeated;
    int totalRoll;

public:
    Character(string type, int armor, int strength, bool defeated);
    ~Character();
    virtual int getArmor() =0;
    virtual int getStrength() =0;
    virtual int attack() =0;
    virtual void defense(int attack) =0;
    virtual string getType() =0;
    virtual bool die() =0;
    virtual int rollDiceAttack() =0;
    virtual int rollDiceDefense() =0;

};

#endif