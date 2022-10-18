#include<iostream>
#include<cstdlib>
#include<ctime>
#include <unistd.h>
using namespace std;

#include"src/equipment.h"
#include"src/character.h"
#include"src/environment.h"

Map map=Map();

Player player=Player();
int n = rand()%5 + 10;
Enemy* enemy;
int towNR = rand()%3 + 1;
Tower* archerTower;
int brkNr = rand()%3 + 2;
Barracks* barrack;

void endGame()
{
    free(enemy);
    free(archerTower);
    free(barrack);
    for(int i=0;i<map.height;i++)
        free(map.tile[i]);
    free(map.tile);
    exit(0);
}

void turn(int t)
{
    while(t > 0)
    {
        //usleep(100000);
        t--;

        for(int i=0;i<towNR;i++)
            for(int k=0;k<3;k++)
                archerTower[i].ranger[k].hasShot=false;

        int tdmg;

        for(int i=0;i<towNR;i++)
            for(int k=0;k<3;k++)
                for(int j=0;j<n;j++)
                    if(enemy[j].isAlive() && archerTower[i].inRange(enemy[j],k))
                        {
                            tdmg = archerTower[i].ranger[k].hit();
                            enemy[j].takeDmg(tdmg); 
                            if(enemy[j].health<0)
                                enemy[j].kill();
                            cout<<"\nEnemy "<<j+1<<", HP: "<<enemy[j].health<<"/"<<enemy[j].maxHealth<<" pos: "<<enemy[j].x<<", took "<<tdmg<<" dmg from archer "<<k+1<<" of tower "<<i+1;
                        }    
                            
        for(int i=0;i<n;i++)
        {
            if(enemy[i].isAlive())
            {
                enemy[i].moveRight();
                if(enemy[i].x==map.width)
                {
                    player.takeDmg(enemy[i].dmgValue);
                    enemy[i].kill();
                    cout<<"\nEnemy "<<i+1<<" passed through you defense.";
                }
                if(player.health<=0)
                        {
                            cout<<"\nEnemies have breached the castle. Game ended.";
                            endGame();
                        }
            }
        }
        int deathCount=0;

        for(int i=0;i<n;i++)
        {
            if(not enemy[i].isAlive())
                deathCount++;
        }

        if(n==deathCount)
        {
            cout<<"\nNo more enemies on the map. Player health "<<player.health<<"/"<<player.maxHealth;
            endGame();
        }  
    }
}



int main()
{
    system("clear");

    srand(time(NULL));
    
    map.tile=(int**)malloc(map.height*sizeof(int*));
    for(int i=0;i<map.height;i++)
        map.tile[i]=(int*)malloc(map.width*sizeof(int));

    enemy = (Enemy*)malloc(n*sizeof(Enemy));

    archerTower = (Tower*)malloc(towNR*sizeof(Tower));

    barrack = (Barracks*)malloc(brkNr*sizeof(Barracks));

    for(int i=0;i<n;i++)
        {
            enemy[i] = Enemy();
            enemy[i].y = rand()%map.height;
            cout<<"\nEnemy "<<i+1<<": "<< enemy[i].health;
        }


    for(int i=0;i<towNR;i++)
    {
        archerTower[i] = Tower(rand()%map.width,rand()%map.height);
        cout<<"\nCreated archer tower at x: "<<archerTower[i].x<<" y: "<<archerTower[i].x;
    }

    int choice;
    bool option;

    turn(100);

    return 0;
}