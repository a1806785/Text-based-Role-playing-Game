#ifndef ICESWORD_H
#define ICESWORD_H

#include "Weapon.h"

class IceSword : public Weapon
{
public:
    // constructor
    IceSword();
    
    // get base damage
    virtual int getBaseDamage();
    
    // get suck blood
    virtual int getSuckBlood();
    
    // get crit
    virtual bool getCrit();
    
    // crit rate
    int critRate;
    
    // determine whether to crit
    bool isCrit(int rate);
};
#endif