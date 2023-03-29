#ifndef BOSS_H
#define BOSS_H

#include <iostream>
#include <string>
#include "Hero.h"
#include "Monster.h"

using namespace std;

class Hero;

class Boss {

public:

    Boss();

    string m_name;
    int m_hp;
    int m_defensepower;
    int m_attackpower;
    
    int m_energyvalue;

    void m_damage(Hero *hero); // damage to hero

    void m_getdamage(Hero *hero, Weapon *weapon); // get hurt from the hero

    bool getuniqueskill(Hero *hero); // accumulate energy value

    void useuniqueskill(Hero *hero); // use unique skill

};
#endif