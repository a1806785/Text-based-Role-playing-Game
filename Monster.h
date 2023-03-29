#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>

#include <string>
#include "Boss.h"
#include "Hero.h"
#include "Weapon.h"

using namespace std;

class Hero;

class Monster
{
public:
	Monster();
    void m_damage(Hero *hero); // monster hurt hero
    void m_getdamage(Hero *hero, Weapon *weapon); // monster get damage from hero
    string m_name;

    int m_hp;
    int m_attackpower;
    int m_defensepower;

};

#endif