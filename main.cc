#include <iostream>
#include <sstream>
#include <memory>
#include <vector>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include "item.h"
#include "gold.h"
#include "potion.h"
#include "player.h"
#include "enemy.h"
#include "character.h"
#include "floor.h"
#include "chamber.h"

using namespace std;

int main(int argc, char* argv[]) {
	if(argc <= 1)
	{
	while(1) {
   	cout << "Welcome to CCK3+!" << endl;
    //prompt to generate player
    cout << "Please choose a character." << endl;
    cout << "h: human." << endl;
    cout << "d: dwarf." << endl;
    cout << "e: elf." << endl;
    cout << "o: orc." << endl;
	
  
 	auto newfloor = make_shared<Floor>();
 	char race;
 	cin >> race;
	while(1) {
    if (race == 'h') {
      newfloor->genPlayer(make_shared<Human> ());
      break;
    } else if (race == 'd') {
      newfloor->genPlayer(make_shared<Dwarf> ());
      break;
    } else if (race == 'e') {
      newfloor->genPlayer(make_shared<Elf> ());
      break;
    } else if (race == 'o') {
      newfloor->genPlayer(make_shared<Orc> ());
      break;
    }
    else {
      cout << "Please enter a valid command for players" << endl;
      cin >> race;
    }
  }
    newfloor->genChamber();
    newfloor->genPlayer(); 
    newfloor->genStair();
    newfloor->genPotion();
    newfloor->genGold();
    newfloor->genEnemy();
    newfloor->printFloor();

    cout << "Here are the commands you use:" << endl;
    cout << "DIR: no, so, ea, we, ne, se, sw, nw" << endl;
    cout << "USE POTION: u <direction>" << endl;
    cout << "ATTACK ENEMY: a <direction>" << endl;
    cout << "RESET GAME: r" << endl;
    cout << "QUIT: q" << endl;
    string c; 
    while (cin >> c)
    {

    if (command == "no" ||command ==  "so" ||command ==  "ea"
   ||command ==  "we" ||command ==  "ne" ||command ==  "se" ||command ==  "sw" ||command ==  "nw")
    {
    	
    }
    }
}
