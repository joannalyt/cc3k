#include "floor.h"
#include "character.h"
#include "player.h"
#include "enemy.h"
#include "chamber.h"
#include "item.h"
#include "gold.h"
#include "potion.h"
#include <iotream>//? 
#include <fstream>
#include <string>
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

void Floor:: printFloor(){  
	for(int i= 0; i < display.size(); i++){
		for ( int j = 0; j < display[i].size(); j++){
			cout << display[i][j];
		}
		cout << endl;	
	}
}


void Floor::genGold() {
  int chamberid;
  int goldtype;
  for (int i = 0; i < 10; i++) {
    chamberid = rand() % 5; //
    vector<int> pos = chambers[chamberid]->findRandom();
    display[pos[0]][pos[1]] = 'G';
    goldtype = rand() % 8;
    if (goldtype <= 4) {
       golds.emplace_back(make_shared<Gold> (pos[0], pos[1], "normal", 'G', 1, true));
    } else if (goldtype <= 6) {       
       golds.emplace_back(make_shared<Gold> (pos[0], pos[1],"small", 'G', 2, true));
    } else {
       golds.emplace_back(make_shared<Gold> (pos[0], pos[1], "dragon hoard", 'G', 6, false));
    }
  }
}

   
 void Floor::genPlayer(){
 	int chamberid = rand() % 5; //
    players->setId(id);
    vector<int> pos = theChamber[chamberid]->findRandom();
    display[pos[0]][pos[1]] = '@';
    players->set_x(pos[0]);
    players->set_y(pos[1]); 

 }

 void Floor::genStair(){
 	int chamberid = rand() % 5;
    while(chamberid == players->getId())
    { 
        chamberid = rand() % 5;
    }
    theChamber[id]->findRandom();
    display[pos[0]][pos[1]] = '\\';
    
 }

 void Floor::genPotion(){
 	int chamberid;
	for (int i = 0; i < 10; i++) {
    id = rand() % 5; //generate a random num from 0-4
    vector<int> pos = chambers[chamberid]->findRandom();
    display[pos[0]][pos[1]] = 'P';
    int type = rand() % 6; //generate a random num from 0-5
    if (type == 0) {
    potions.emplace_back(make_shared<Potion> (pos[0], pos[1],"RH", 'P', 10));
    } 
    else if (type == 1) {
    potions.emplace_back(make_shared<Potion> (pos[0], pos[1],"BD", 'P', 5));
    } 
    else if (type == 2){
    potions.emplace_back(make_shared<Potion> (pos[0], pos[1],"BA", 'P', 5));    
    } 
    else if (type == 3) {
    potions.emplace_back(make_shared<Potion> (pos[0], pos[1],"WA", 'P', -5));
    } 
    else if (type == 4) {
    potions.emplace_back(make_shared<Potion> (pos[0], pos[1],"PH", 'P', -10));    
    } 
    else {
    potions.emplace_back(make_shared<Potion> (pos[0], pos[1],"WD", 'P', -5));
    }
  }
 }  

void Floor::genChamber(){
	for(int id = 1; id < 6; id++){
		auto c = make_shared<Chamber> (id, display);
		chambers.emplace_back(c);
	}
}

void Floor::genEnemy(){
	
}


