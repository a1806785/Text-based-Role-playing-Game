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
        cout << endl;
        hero->use_weapon(tulong);
    }
    else
    {
        cout << endl;
        hero->use_weapon(icesword);
    }
    
    // create a monster
    Monster* monster = new Monster;

    cout << endl;
    
    cout << "***The first level: fight monster.***" << endl;
    
    // display HP
    cout << "Hero: " << hero->m_name << "   HP: " << hero->m_hp << endl;
    cout << "Monster: " << monster->m_name << "   HP: " << monster->m_hp << endl;
    
    cout << endl;

    int round = 1; // the number of rounds

    cout << "The hero will fight the monster" << endl;

    getchar();

    // hero fight boss
    while (true)
    {
        // cout << "Please press the Enter key to continue." << endl;

        int choice;
        
        cout << "1. attack" << endl;
        cout << "2. quit" << endl;
        cin >> choice;
        
        if (choice == 1)
        {
            // getchar(); // ask the user to press the Enter key to continue

            cout << "*****The " << round << " round*****" << endl;
        
            // determine if the game is over
            if (hero->m_hp <= 0)
            {
                cout << "Hero is dead, game over!" << endl;
                break;
            }
            else
            {
            // Hero attacks monster
                if (weapon_choice == 1)
                {
                    hero->m_damage(monster, tulong);
                    monster->m_getdamage(hero, tulong);
                }
                else
                {
                    hero->m_damage(monster, icesword);
                    monster->m_getdamage(hero, icesword);
                }
                
            }
        
            if (monster->m_hp <= 0)
            {
                cout << "Monster is dead, you win!" << endl;
                break;
            }
            else
            {
                // monster attacks hero
                monster->m_damage(hero);
                hero->m_getdamage(monster);
            }
            
        
            if (hero->m_hp < 0)
            {
                cout << "Hero: " << hero->m_name << "   HP: 0" << endl;
                cout << "Monster: " << monster->m_name << "   HP: " << monster->m_hp << endl;
            }
            else if (monster->m_hp < 0)
            {
                cout << "Hero: " << hero->m_name << "   HP: " << hero->m_hp << endl;
                cout << "Monster: " << monster->m_name << "   HP: 0" << endl;
            }
            else
            {
                cout << "Hero: " << hero->m_name << "   HP: " << hero->m_hp << endl;
                cout << "Monster: " << monster->m_name << "   HP: " << monster->m_hp << endl;
            }
        
            round++;
        }
        else
        {
            cout << "You lose the game!" << endl;
            break;
        }
    }


    cout << endl;

    // create a boss
    Boss* boss = new Boss;
    
    cout << "***The second level: fight boss.***" << endl;
    
    // display HP
    cout << "Hero: " << hero->m_name << "   HP: " << hero->m_hp << endl;
    cout << "Boss: " << boss->m_name << "   HP: " << boss->m_hp << endl;

    round = 1; // the number of rounds
    
    cout << endl;
    cout << "The hero will fight the boss" << endl;
    cout << endl;

    // ask the user to press the Enter key to continue
    getchar();

    // hero fight boss
    while (true)
    {
        
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

    delete monster;
    delete hero; 
    delete boss;

    return 0;
}