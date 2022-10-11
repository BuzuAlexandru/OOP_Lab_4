#pragma once
#include "entity.h"
#include "equipment.h"
#include <iostream>
using namespace std; 

class Character: public Entity
{
    public:

    int health;

    Character():Entity()
    {
        health = 100;
    }

    void takeDmg(int dmg)
    {
        health -= dmg;
    }
};

class Player: public Character
{
    public:

    int coins;

    Player():Character()
    {
        coins = 0;
    }

    void coinSpend(int cost)
    {
        coins -= cost;
    }

    void coinGet(int gold)
    {
        coins += gold;
    }

    int getID()
    {
        return id;
    }
};

class Worker: public Character
{
    public:

    int efficiency;
    Tool pickaxe;

    Worker():Character()
    {
        efficiency = 50;
    }

    int getID()
    {
        return id;
    }

    void getHeal(int heal)
    {
        health += heal;
    }
};

class Unit: public Character
{
    public:

    int x, y, armor, dexterity, strength;
    Weapon weapon;

    Unit():Character()
    {
        x=0;
        y=0;
        armor=1;
        dexterity=1;
        strength=1;
    }

    int hit()
    {
        return strength + weapon.power * weapon.integrity / 100;
    }
};

class Soldier: public Unit
{
    public:

    Soldier():Unit()
    {}

    void getHeal(int heal)
    {
        health += heal;
    }

    int getID()
    {
        return id;
    }
};

class Enemy: public Unit
{
    public:

    int mvSpeed, goldValue, dmgValue;

    Enemy():Unit()
    {
        mvSpeed=1;
        goldValue=10;
        dmgValue=1;
    }

    void moveUp()
    {
        x -= 1;
    }

    void moveDown()
    {
        x += 1;
    }

    void moveRight()
    {
        y += 1;
    }

    void moveLeft()
    {
        y -= 1;
    }

    int getID()
    {
        return id;
    }
};