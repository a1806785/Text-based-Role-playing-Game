#ifndef HERO_H
#define HERO_H

#include <string>
#include "Boss.h"
#include "Monster.h"
#include "Weapon.h"

using namespace std;

class Boss;
class Monster;

class Hero
{
public:
    // Constructor
    Hero();

    // chang name
    void setName(string name);

    // attack power
    int m_attackpower;

    // defense
    int m_defensepower;

    // HP
    int m_hp;
    
    // Name
    string m_name;

    // weapon
    Weapon *weapon;

    // use weapon
    void use_weapon(Weapon *weapon);

    // attack monster
    void m_damage(Monster *monster, Weapon *weapon);
    
    // get hurt from the monster
    void m_getdamage(Monster *monster);

    // attack boss
    void m_damage(Boss *boss, Weapon* weapon);
    
    // get hurt from the boss
    void m_getdamage(Boss *boss);

};
#endif