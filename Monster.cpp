#include<iostream>
#include"Monster.h"
#include<string>
#include<iostream>


using namespace std;

Monster::Monster()
{
    m_name = "PIPIXIA";
    m_hp = 350;
    m_attackpower = 65;
    m_defensepower = 40;

}

// monster hurt hero
void Monster::m_damage(Hero *hero)
{
    int hurt;
    hurt = m_attackpower - hero->m_defensepower;

}

// monster get damage from hero
void Monster::m_getdamage(Hero *hero, Weapon *weapon)
{
    if (weapon->getCrit() == true)
    {
        int gethurt;
        gethurt = hero->m_attackpower + 2 * weapon->getBaseDamage() - m_defensepower;
        m_hp = m_hp - gethurt;
    }
    else
    {
        int gethurt;
        gethurt = hero->m_attackpower + weapon->getBaseDamage() - m_defensepower;
        m_hp = m_hp - gethurt;
    }
    
}