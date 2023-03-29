#include <iostream>
#include "Hero.h"
#include "Weapon.h"

Hero::Hero()
{
    m_name = "";
    m_attackpower = 85;
    m_defensepower = 60;
    m_hp = 550;
}

// chang name
void Hero::setName(string name)
{
    m_name = name;
}


// use weapon
void Hero::use_weapon(Weapon *weapon)
{
    this->weapon = weapon;
    std::cout << m_name << " use " << weapon->m_name << std::endl;
}

// attack monster
void Hero::m_damage(Monster *monster, Weapon *weapon)
{
    if (weapon->m_name == "Tulong")
    {
        // damage
        int hurt;
        hurt = m_attackpower + weapon->getBaseDamage() - monster->m_defensepower;
        
        // suck blood
    	int addHp = weapon->getSuckBlood();
        
        if (addHp > 0)
    	{
    		cout << "The hero's weapon triggers the blood sucking effect, and the hero increases " << addHp << " HP" << endl;
    	}
    
        m_hp = m_hp + addHp;
    }
    else
    {
        if ((weapon->getCrit()) == true)
        {
            // damage
            int hurt;
            hurt = m_attackpower + 2 * weapon->getBaseDamage() - monster->m_defensepower;
            
            cout << "The hero’s weapon triggers the critical strike effect, the damage value to the monster is " << hurt << endl;
        }
        else
        {
            // damage
            int hurt;
            hurt = m_attackpower + weapon->getBaseDamage() - monster->m_defensepower;
        }
    }

}

// Hero get damage from Monster
void Hero::m_getdamage(Monster *monster)
{
    int gethurt;
    gethurt = monster->m_attackpower - m_defensepower;
    m_hp = m_hp - gethurt;
}

// attack monster
void Hero::m_damage(Boss* boss, Weapon* weapon)
{
    
    
    if (weapon->m_name == "Tulong")
    {
        // damage
        int hurt;
        hurt = m_attackpower + weapon->getBaseDamage() - boss->m_defensepower;
        
        // suck blood
    	int addHp = weapon->getSuckBlood();
        
        if (addHp > 0)
    	{
    		cout << "The hero's weapon triggers the blood sucking effect, and the hero increases " << addHp << " HP" << endl;
    	}
    
        m_hp = m_hp + addHp;
    }
    
}

// Hero get damage from Boss
void Hero::m_getdamage(Boss* boss)
{
    int gethurt;
    gethurt = boss->m_attackpower - m_defensepower;
    m_hp = m_hp - gethurt;
}