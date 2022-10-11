#pragma once
#include "entity.h"
#include <iostream>
using namespace std; 

class Environment: public Entity
{
    public:
    Environment():Entity()
    {}
};

class Map: public Environment
{
    public:

    int width, height, tile[50][50][5];

    Map():Environment()
    {
        width=50;
        height=50;
    }

    int getID()
    {
        return id;
    }
};

class MapComponent: public Environment
{
    public:

    int x, y, level, price;
    
    MapComponent():Environment()
    {
        x = 0;
        y = 0;
        level = 1;
        price = 0;
    }

    void levelUp()
    {
        level += 1;
    }
};

class Trap: public MapComponent
{
    public:

    int damage, AOE;

    Trap():MapComponent()
    {
        damage = 1;
        AOE = 0;
    }

    void placeTrap(int posx, int posy)
    {
        x = posx;
        y = posy;
    }

    int getID()
    {
        return id;
    }
};

class Tower: public MapComponent
{
    public:

    int range;
    Soldier ranger[3];

    Tower():MapComponent()
    {
        range = 5;
    }

    int getID()
    {
        return id;
    }

    int tRange(int i)
    {
        return range+ranger[i].weapon.range;
    }

};

class Barracks: public MapComponent
{
    public:

    int range;

    Barracks():MapComponent()
    {
        range = 5;
    }

    Soldier unit[3];

    void deployUnit(int i, int posx, int posy)
    {
        unit[i].x = posx;
        unit[i].y = posy;
    }

    int getID()
    {
        return id;
    }
};

class Quarry: public MapComponent
{
    public:

    int oreQuality;
    float accidentChance;
    Worker miner[3];

    Quarry():MapComponent()
    {
        oreQuality=1;
        accidentChance = 0.5;
        /*for(int i; i<3;i++)
        {
            miner[i] = Worker();
        }*/
    }

    
    int generateGold()
    {
        int sum=0;
        for(int i = 0; i<3;i++)
        {
            sum += oreQuality+ (miner[i].efficiency + miner[i].pickaxe.efficiency); 
        }

        return sum;
    }

    int getID()
    {
        return id;
    }
};