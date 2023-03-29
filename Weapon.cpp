#include<iostream>
#include"guandao.h"
using namespace std;
#include<string>

// Weapon::Weapon()
// {
// 	string m_name = "guandao";
// 	// int m_attackpower = 50;
// 	int m_recoverhp = m_attackpower / 2;
// }

int Weapon::getBaseDamage()
{
    return m_attackpower;
}

// int guandao::gethp()
// {
// 	int m_recoverhp = m_attackpower / 2; 
//     // p->m_hp = p->m_hp + m_recoverhp;
//     return m_recoverhp;
// }