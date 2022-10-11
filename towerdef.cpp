#include<iostream>
using namespace std;

#include"src/equipment.h"
#include"src/character.h"
#include"src/environment.h"

int main()
{
    system("clear");

    Weapon sword;

    cout << "accuract: " << sword.accuracy;

    Soldier knight;

    cout << "\nKnight's health is: " << knight.health;

    Tower tower1;

    tower1.range = 10;

    cout << "\nTower range is: " << tower1.tRange(1);

    Quarry quarry1;


    for(int i; i<3;i++)
        {
            quarry1.miner[i] = Worker();
        }
    
        cout << "\nQuarry generated " << quarry1.generateGold() << " gold";

    Worker miner1;

    cout << "\nPickaxe efficiency: " << miner1.pickaxe.efficiency;

    return 0;
}