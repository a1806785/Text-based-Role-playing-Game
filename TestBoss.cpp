#include <iostream>
#include "Hero.h"
#include "Boss.h"
#include "Monster.h"
#include "Weapon.h"
#include "Tulong.h"
#include "IceSword.h"

using namespace std;

int main()
{
    // create a hero
    Hero* hero = new Hero;

    // ask the user to enter a name
    string name;
    cout << "Enter a name: ";
    cin >> name;
    hero->setName(name);
    cout << endl;

    // create a boss
    Boss* boss = new Boss;
    
    // create a weapon
    Weapon * tulong = new Tulong;
    Weapon * icesword = new IceSword;
    
    int weapon_choice;
    cout << "Please choose a weapon" << endl;
    cout << "1. Tulong" << endl;
    cout << "2. IceSword" << endl;
    cin >> weapon_choice;
    
    if (weapon_choice == 1)
    {
        hero->use_weapon(tulong);
    }
    else
    {
        hero->use_weapon(icesword);
    }

    // display HP
    cout << "Hero: " << hero->m_name << "   HP: " << hero->m_hp << endl;
    cout << "Boss: " << boss->m_name << "   HP: " << boss->m_hp << endl;

    int round = 1; // the number of rounds

    cout << "The hero will fight the boss" << endl;

    // ask the user to press the Enter key to continue
    getchar();

    // hero fight boss
    while (true)
    {
        // cout << "Please press the Enter key to continue." << endl;
        // getchar(); // ask the user to press the Enter key to continue
        
        int choice;
        
        cout << "1. attack" << endl;
        cout << "2. quit" << endl;
        cin >> choice;
        
        if (choice == 1)
        {
            cout << "*****The " << round << " round*****" << endl;

            // determine if the game is over
            if (hero->m_hp <= 0)
            {
                cout << "Hero is dead, game over!" << endl;
                break;
            }
            else
            {
                
                // Hero attacks boss
                if (weapon_choice == 1)
                {
                    hero->m_damage(boss, tulong);
                    boss->m_getdamage(hero, tulong);
                }
                else
                {
                    hero->m_damage(boss, icesword);
                    boss->m_getdamage(hero, icesword);
                }
            }
    
            if (boss->m_hp <= 0)
            {
                cout << "Boss is dead, you win!" << endl;
                break;
            }
            else
            {
                // boss attacks hero
                // determine whether the boss uses skill
                if (boss->getuniqueskill(hero) == true)
                {
                    boss->useuniqueskill(hero);
                }
                else
                {
                    boss->m_damage(hero);
                    hero->m_getdamage(boss);
                }
            }
    
            if (hero->m_hp < 0)
            {
                cout << "Hero: " << hero->m_name << "   HP: 0" << endl;
                cout << "Boss: " << boss->m_name << "   HP: " << boss->m_hp << endl;
            }
            else if (boss->m_hp < 0)
            {
                cout << "Hero: " << hero->m_name << "   HP: " << hero->m_hp << endl;
                cout << "Boss: " << boss->m_name << "   HP: 0" << endl;
            }
            else
            {
                cout << "Hero: " << hero->m_name << "   HP: " << hero->m_hp << endl;
                cout << "Boss: " << boss->m_name << "   HP: " << boss->m_hp << endl;
            }
    
            round++;
        }
        else
        {
            cout << "You lose the game!" << endl;
            break;
        }
    }

        

    delete boss;
    delete hero;

    return 0;
}