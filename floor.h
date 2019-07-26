#ifndef FLOOR_H
#define FLOOR_H
#include <string>
#include <vector>
#include <memory>
#include "player.h"
#include "enemy.h"
#include "chamber.h"
#include "gold.h"
#include "potion.h"

/*class Player;
class Enemy;

class Potion;
class Gold;*/
//class Chamber;

class Floor{
	int level;
	std::shared_ptr<Player> player;
	std::vector<std::vector<char>> display;
	std::vector<std::shared_ptr<Enemy>> enemies;
	std::vector<std::shared_ptr<Chamber>> chambers;
	std::vector<std::shared_ptr<Potion>> potions;
	std::vector<std::shared_ptr<Gold>> golds;
	char origSymbol;
	bool hasWon;
public:
	Floor(int level, std::string file = "default.txt");
	void printFloor();//add display msg
	void genGold();
	void genPlayer(std::shared_ptr<Player> pp);
	void genStair();
	void genPotion();
	void genChamber();
	void genEnemy();
	std::vector<int> checkTile(std::string dir);//returns position after moving player to dir
	bool movePlayer(std::string dir);
	int getLevel();
	void setLevel(int level);
	void sethasWon(bool won);
	bool hasLost();
	int getGold();
	void setAction(std::string action);
	bool checkDisplay (int x, int y, char c);

	//void createFloor();
};








#endif
