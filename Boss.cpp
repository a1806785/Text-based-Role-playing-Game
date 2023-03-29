#include<iostream>
#include"Boss.h"
#include<string>
#include<iostream>


using namespace std;

Boss::Boss()
{
    m_name = "Godzilla";
    m_hp = 550;
    m_attackpower = 90;
    m_defensepower = 70;
    m_energyvalue = 0;
}

// Boss damage Hero
void Boss::m_damage(Hero *hero)
{
    int hurt;
    hurt = m_attackpower - hero->m_defensepower;
    m_energyvalue = hurt + m_energyvalue;
}

// Boss get damage from Hero
void Boss::m_getdamage(Hero *hero, Weapon *weapon)
{
    if (weapon->getCrit() == true)
    {
        int gethurt;
        gethurt = hero->m_attackpower + 2 * weapon->getBaseDamage() - m_defensepower;
        m_hp = m_hp - gethurt;
        cout << "The hero’s weapon triggers the critical strike effect, the damage value to the monster is " << gethurt << endl;
    }
    else
    {
        int gethurt;
        gethurt = hero->m_attackpower + weapon->getBaseDamage() - m_defensepower;
        m_hp = m_hp - gethurt;
    }
}

// Boss use unique skill
void Boss::useuniqueskill(Hero *hero)
{
    hero->m_hp = hero->m_hp / 2 ;
}

// determine Boss whether to use skill
bool Boss::getuniqueskill(Hero *hero)
{
    if(m_energyvalue >= 100)
    {
        
        cout << "BOSS use the unique skill!" << endl;
        
        m_energyvalue = m_energyvalue - 100;
        return true;
    }
    return false;
}
