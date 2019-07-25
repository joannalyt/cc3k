#include "floor.h"
#include "character.h"
#include "player.h"
#include "enemy.h"
#include "chamber.h"
#include "item.h"
#include "gold.h"
#include "potion.h"
#include <vector>//?
#include <iotream>//? 
#include <fstream>
#include <string>
#include <memory>
#include <utility>
#include <cstdlib>

using namespace std;

Floor::Floor(int level, string file): level{level},player{nullptr},enemies{nullptr},
chambers{nullptr},potions{nullptr},golds{nullptr}{
	ifstream ifs{file};
	string s;
	while (getline(ifs, s))	{
    vector <char> line;
    for( int i = 0; i< s.length(); i++)
    {
    	line.emplace_back(s.at(i));
    }
    display.emplace_back(line);
	} 
}

void Floor:: printFloor()
{  
	for(int i= 0; i < display.size())
		for ( int j = 0; j < display[i].size())
			cout << display[i][j];
	cout << endl;	
}


void Floor::genGold() {
  int chamberid;
  int goldtype;
  for (int i = 0; i < 10; i++) {
    chamberid = rand() % 5; //
    vector<int> cor = chambers[chamberid]->findRandom();
    display[cor[0]][cor[1]] = 'G';
    goldtype = rand() % 8;
    if (goldtype == 0 || goldtype == 1 || goldtype == 2 || goldtype == 3 || goldtype == 4) {
       golds.emplace_back(make_shared<Gold> (cor[0], cor[1], "normal", 'G', 1, true));
    } else if (goldtype == 5 || goldtype == 6) {       
       golds.emplace_back(make_shared<Gold> (cor[0], cor[1],"small", 'G', 2, true));
    } else {
       golds.emplace_back(make_shared<Gold> (cor[0], cor[1], "dragon hoard", 'G', 6, false));
    }
  }
}

   
 void Floor::genPlayer()
 {
 	int chamberid = rand() % 5; //
    players->setId(id);
    vector<int> cor = theChamber[chamberid]->findRandom();
    display[cor[0]][cor[1]] = '@';
    players->set_x(cor[0]);
    players->set_y(cor[1]); 

 }

 void Floor::genStair()
 {
 	int chamberid = rand() % 5;
    while(chamberid == players->getId())
    { 
        chamberid = rand() % 5;
    }
    theChamber[id]->findRandom();
    display[cor[0]][cor[1]] = '\\';
    
 }
 void Floor::genPotion()
 {
 	int chamberid;
	for (int i = 0; i < 10; i++) {
    id = rand() % 5; //generate a random num from 0-4
    vector<int> cor = chambers[chamberid]->findRandom();
    display[cor[0]][cor[1]] = 'P';
    int type = rand() % 6; //generate a random num from 0-5
    if (type == 0) 
    {
    potions.emplace_back(make_shared<Potion> (cor[0], cor[1],"RH", 'P', 10));
    } 
    else if (type == 1) 
    {
    potions.emplace_back(make_shared<Potion> (cor[0], cor[1],"BD", 'P', 5));
    } 
    else if (type == 2)
    {
    potions.emplace_back(make_shared<Potion> (cor[0], cor[1],"BA", 'P', 5));    
    } 
    else if (type == 3) 
    {
    potions.emplace_back(make_shared<Potion> (cor[0], cor[1],"WA", 'P', -5));
    } 
    else if (type == 4) 
    {
    potions.emplace_back(make_shared<Potion> (cor[0], cor[1],"PH", 'P', -10));    
    } 
    else 
    {
    potions.emplace_back(make_shared<Potion> (cor[0], cor[1],"WD", 'P', -5));
    }
  }
 }  
 void Floor::genEnemy()
 {
 	
 }



