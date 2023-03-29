#ifndef WEAPON_H
#define WEAPON_H

#include <string>
using namespace std;

//Abstract Classes
class Weapon
{
public:
	// base damage
	virtual int getBaseDamage() = 0;

	// suck blood
	virtual int getSuckBlood() = 0;


	// crit
	virtual bool getCrit() = 0;


	string m_name; // name
	int m_attackpower; // attack power
};
#endif