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
			cout << theDisplay[i][j];
	cout << endl;	
}

void Floor::createFloor()
{
if()
}



