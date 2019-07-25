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
  for (int i = 0; i < 10; i++) { //generate 10 gold
    chamberid = rand() % 5; //
    vector<int> pos = chambers[chamberid]->findRandom();
    display[pos[0]][pos[1]] = 'G';
    goldtype = rand() % 8;
    if (goldtype <= 4) { //5/8 normal
       golds.emplace_back(make_shared<Gold> (pos[0], pos[1], "normal", 'G', 1, true));
    } else if (goldtype <= 6) {//2/8 small       
       golds.emplace_back(make_shared<Gold> (pos[0], pos[1],"small", 'G', 2, true));
    } else {//1/8 dragon
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
	int count_dragon;
	count_dragon = 0;
	for(int i = 0; i < 10; i++){
		if(golds[i]->getGold() == 6){//dragon hoard
			golds[i]->setIspickable(0);
			count_dragon++;
			while(true){
				int possibility = rand()%8;
				if(possibility == 0){
					if(display[golds[i]->get_x()-1][golds[i]->get_y()-1] == '.'){
						display[golds[i]->get_x()-1][golds[i]->get_y()-1] = 'D';
						auto d = make_shared<Dragon> (golds[i]->get_x()-1,golds[i]->get_y()-1,golds[i]);
						enemies.emplace_back(d);
						break;
					}
				} else if(possibility == 1){
					if(display[golds[i]->get_x()-1][golds[i]->get_y()] == '.'){
						display[golds[i]->get_x()-1][golds[i]->get_y()] = 'D';
						auto d = make_shared<Dragon> (golds[i]->get_x()-1,golds[i]->get_y(),golds[i]);
						enemies.emplace_back(d);
						break;
					}
				} else if(possibility == 2){
					if(display[golds[i]->get_x()-1][golds[i]->get_y()+1] == '.'){
						display[golds[i]->get_x()-1][golds[i]->get_y()+1] = 'D';
						auto d = make_shared<Dragon> (golds[i]->get_x()-1,golds[i]->get_y()+1,golds[i]);
						enemies.emplace_back(d);
						break;
					}
				} else if(possibility == 3){
					if(display[golds[i]->get_x()][golds[i]->get_y()-1] == '.'){
						display[golds[i]->get_x()][golds[i]->get_y()-1] = 'D';
						auto d = make_shared<Dragon> (golds[i]->get_x(),golds[i]->get_y()-1,golds[i]);
						enemies.emplace_back(d);
						break;
					}
				} else if(possibility == 4){
					if(display[golds[i]->get_x()][golds[i]->get_y()+1] == '.'){
						display[golds[i]->get_x()][golds[i]->get_y()+1] = 'D';
						auto d = make_shared<Dragon> (golds[i]->get_x(),golds[i]->get_y()+1,golds[i]);
						enemies.emplace_back(d);
						break;
					}
				} else if(possibility == 5){
					if(display[golds[i]->get_x()+1][golds[i]->get_y()-1] == '.'){
						display[golds[i]->get_x()+1][golds[i]->get_y()-1] = 'D';
						auto d = make_shared<Dragon> (golds[i]->get_x()+1,golds[i]->get_y()-1,golds[i]);
						enemies.emplace_back(d);
						break;
					}
				} else if(possibility == 6){
					if(display[golds[i]->get_x()+1][golds[i]->get_y()] == '.'){
						display[golds[i]->get_x()+1][golds[i]->get_y()] = 'D';
						auto d = make_shared<Dragon> (golds[i]->get_x()+1,golds[i]->get_y(),golds[i]);
						enemies.emplace_back(d);
						break;
					}
				} else{
					if(display[golds[i]->get_x()+1][golds[i]->get_y()+1] == '.'){
						display[golds[i]->get_x()+1][golds[i]->get_y()+1] = 'D';
						auto d = make_shared<Dragon> (golds[i]->get_x()+1,golds[i]->get_y()+1,golds[i]);
						enemies.emplace_back(d);
						break;
					}
				}
			}
		}
	}
	for(int i = 0; i < 20 - count_dragon; i++){//generate other enemies
		int chamberNum = rand()%5;
		int enemyNum = rand()%18;
		if(enemyNum < 4){//werewolf
			vector<int> pos = chambers[chamberNum]->findRandom();
			auto w = make_shared<Werewolf> (pos[0], pos[1]);
			enemies.emplace_back(w);
		} else if(enemyNum < 7){//vampire
			vector<int> pos = chambers[chamberNum]->findRandom();
			auto v = make_shared<Vampire> (pos[0], pos[1]);
			enemies.emplace_back(v);
		} else if(enemyNum < 12){//goblin
			vector<int> pos = chambers[chamberNum]->findRandom();
			auto g = make_shared<Golblin> (pos[0], pos[1]);
			enemies.emplace_back(g);
		} else if(enemyNum < 14){//troll
			vector<int> pos = chambers[chamberNum]->findRandom();
			auto t = make_shared<Troll> (pos[0], pos[1]);
			enemies.emplace_back(t);
		} else if(enemyNum < 16){//phoenix
			vector<int> pos = chambers[chamberNum]->findRandom();
			auto p = make_shared<Phoenix> (pos[0], pos[1]);
			enemies.emplace_back(p);
		} else{//merchant
			vector<int> pos = chambers[chamberNum]->findRandom();
			auto m = make_shared<Merchant> (pos[0], pos[1]);
			enemies.emplace_back(m);
		}
	}
}


