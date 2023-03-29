#ifndef TULONG_H
#define TULONG_H

#include "Weapon.h"
#include <string>
using namespace std;

class Tulong : public Weapon
{
public:
	Tulong();

	// base damage
	virtual int getBaseDamage();

	// suck blood
	virtual int getSuckBlood();
	
	// crit
	virtual bool getCrit();

	// suck rate
	int suckRate;

};
#endif