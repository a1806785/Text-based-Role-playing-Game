#include "IceSword.h"

#include <ctime>

IceSword::IceSword()
{
    m_attackpower = 40;
    m_name = "IceSword";
    critRate = 80;
}

// base damage
int IceSword::getBaseDamage()
{
    return m_attackpower;
}

// don't suck blood
int IceSword::getSuckBlood()
{
    return 0;
}

// crit
bool IceSword::getCrit()
{
    if (isCrit(critRate) == true)
    {
        
        return true;
    }
    return false;
}

// determine whether to suck blood
bool IceSword::isCrit(int rate)
{
    // create a random number between 1 and 100
    srand((unsigned)time(NULL));
    int num = rand() % 100 + 1;
    if (num <= rate)
    {
        // crit if the random number is between 1 and 25
        return true;
    }
    return false;
}