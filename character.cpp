#include "character.hpp"

Character::Character(string type, int armor, int strength, bool defeated)
{
    this->type = type;
    this->armor = armor;
    this->strength = strength;
    this->defeated = defeated;
}
Character::~Character()
{

}