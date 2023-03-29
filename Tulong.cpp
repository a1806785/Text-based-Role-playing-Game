#include "Tulong.h"

Tulong::Tulong()
{
	m_attackpower = 20;
	m_name = "Tulong";
}

// base damage
int Tulong::getBaseDamage()
{
	return m_attackpower;
}

// suck blood
int Tulong::getSuckBlood()
{
	return m_attackpower * 0.5;  
}

// don't crit
bool Tulong::getCrit()
{
	return false;
}